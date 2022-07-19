using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Management;
using System.Threading;

namespace Uploader
{
    internal class Program
    {
        static void Main(string[] args)
        {
            if ((args.Length==0)|(args.Contains("-h")) | (args.Contains("--help")))
            {
                string help =
                    "Please run this tools with arguments\n" +
                    "Usage:\tUploader <fullpath> [options]\n" +
                    "\t\t-v\t--visible\t显示详细输入输出\n" +
                    "\t\t  \t--noreset\t寻找到W2开发板之后，不再次等待板重置，直接进入上载过程\n" +
                    "\t\t-h\t--help\t帮助菜单\n";
                Console.WriteLine(help);
                return;
            }

            bool vis;
            if ((args.Contains("-v")) | (args.Contains("--visible")))
            {
                vis=true;
            }
            else
            {
                vis=false;
            }


            SerialPort serialPort=null;
            for (int i = 0; i < 5; i++)
            {
                string order;
                switch (i)
                {
                    case 0: order = "st";
                        break;
                    case 1: order = "nd";
                        break;
                    case 2: order = "rd";
                        break;
                    default:order = "th";
                        break;
                }
                Console.WriteLine($"\nThe {i + 1}{order} time to find the serial port");
                serialPort = SearchPort();
                if (serialPort!=null)
                {
                    Console.WriteLine("Sucess");
                    break;
                }
                else
                {
                    Console.ForegroundColor= ConsoleColor.Red;
                    Console.WriteLine("Faild to find the board:\n\tCheck if the board is reset or connected");
                    Console.ForegroundColor = ConsoleColor.White;
                    if (i<4)
                    {
                        Console.WriteLine("Wait 3 seconds to search next time......");
                        Thread.Sleep(3000);
                    }
                    else
                    {
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        Console.WriteLine("Faild to find the board");
                    }
                }
            }
            if (serialPort==null)
            {
                Exception myException = new Exception("Upload faild");
                throw myException;
            }
            serialPort.Open();
            serialPort.ReadExisting();

            #region 等待重置开发板
            if (!(args.Contains("--noreset")))
            {
                serialPort.ReadExisting();
                Console.WriteLine("Wait For Reset the Board.......");
                StringBuilder stringBuilder = new StringBuilder();
                while (true)
                {
                    string tmp = serialPort.ReadExisting();
                    stringBuilder.Append(tmp);
                    //Console.Write(tmp);
                    if (stringBuilder.ToString().Contains("> v1.11 > "))
                    {
                        break;
                    }
                }

            }
            #endregion
            serialPort.Write("\n");
            Console.WriteLine("Wait Response From the Board");
            if(DelayForResponse(serialPort, "> v1.11 > ", 5, vis))
            {
                Console.ForegroundColor = ConsoleColor.Cyan;
                Console.WriteLine("Success");
                Console.ForegroundColor = ConsoleColor.White;
            }
            Console.WriteLine("Unlock the Flash");
            MemoryWriteWord(serialPort, "1F800B07", "A5");
            Console.WriteLine("Erasing the Flash");
            MemoryWriteWord(serialPort, "10300000", "A5");
            Console.WriteLine("Do Some previous action before unload");
            MemoryWriteWord(serialPort, "1f800004", "40");
            Console.WriteLine(args[0]);
            FileStream fileStream = new FileStream(args[0], FileMode.Open, FileAccess.Read);
            byte[] codes=new byte[fileStream.Length];
            fileStream.Read(codes, 0, (int)fileStream.Length);
            fileStream.Dispose();
            serialPort.Write("5");
            DelayForResponse(serialPort, "Address in hex> ", 1, vis);
            serialPort.Write("10000000\n");
            DelayForResponse(serialPort, "Waiting for binary image linked at 10000000", 1, vis);
            Console.WriteLine("Uploading.......");
            serialPort.Write(codes,0,codes.Length);

            #region 不显示控制台界面
            DelayForResponse(serialPort, "> v1.11 >", 1, vis);
            #endregion

            Console.WriteLine($"Load {codes.Length} bytes code to 10000000");
            MemoryWriteWord(serialPort, "1f800004", "0");
            Console.WriteLine("Serial port closed \nSystem resources disposed");
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("All Done!");
            Console.ForegroundColor = ConsoleColor.White;
            serialPort.Close();
            serialPort.Dispose();
        }
        static void MemoryWriteWord(SerialPort serialPort,string address,string value)
        {
            serialPort.Write("1");
            DelayForResponse(serialPort, "Address in hex>", 1, false);
            serialPort.Write(address+"\n");
            DelayForResponse(serialPort, "Value in hex>", 1, false);
            serialPort.Write(value+"\n");
            DelayForResponse(serialPort, "> v1.11 > ", 2, false);
            return;
        }
        static bool DelayForResponse(SerialPort serialPort, string contain, int timeOut, bool visible)
        {
            DateTime targetTime = DateTime.Now.AddSeconds(timeOut);
            StringBuilder stringBuilder = new StringBuilder();
            while (true)
            {
                string tmp = serialPort.ReadExisting();
                stringBuilder.Append(tmp);
                if (visible)
                {
                    Console.Write(tmp);
                }
                if (stringBuilder.ToString().Contains(contain))
                {
                    if (visible)
                    {
                        Console.Write("\n");
                    }
                    return true;
                }
                if (DateTime.Now>=targetTime)
                {
                    if (visible)
                    {
                        Console.Write("\n");
                    }
                    return false;
                }
            }
        }
        public static SerialPort SearchPort()
        {
            StringBuilder occupied = new StringBuilder("Port ");
            SerialPort serialPort = new SerialPort
            {
                BaudRate = 9600,
                DataBits = 8,
                Parity = Parity.None,
                StopBits = StopBits.One,
                ReadBufferSize = 8192
            };
            foreach (string item in SerialPort.GetPortNames())
            {
                serialPort.PortName=item;
                try
                {
                    serialPort.Open();
                    serialPort.Write("\n");
                }
                catch
                {
                    serialPort = null;
                    occupied.Append(item + " ");
                }
                finally{}
                if (serialPort!=null)
                {
                    if (DelayForResponse(serialPort, "> v1.11 > ", 1, false))
                    {
                        serialPort.Close();
                        return serialPort;
                    }
                }
            }
            if (serialPort != null)
            {
                serialPort.Close();
            }
            else
            {
                occupied.Append("occupied");
                Console.ForegroundColor= ConsoleColor.Red;
                Console.WriteLine(occupied);
                Console.ResetColor();
            }
            return null;
        }
    }
}
