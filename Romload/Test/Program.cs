using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    internal class Program
    {
        static void Main(string[] args)
        {
            foreach (var item in SerialPort.GetPortNames())
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
        }
    }
}
