# W2-Develop-Board-For-Arduino
此项目目的在于将W2 开发板适配至Arduino IDE或Arduino CLI

## #0 适配所需文件
### 硬件定义
　　为使IDE能够对用户的各种操作进行不同的反应，例如编译、上传等  ，Arduino需要一些参数和固定的“recipe”来对不同的硬件进行不同的编译、链接、生成二进制文件等操作，这些recipe，在用户选择编译或上传之后，自动执行。  

　　这些recipe是存储在每个不同的开发板的硬件定义中的，因此Arduino对于某一个硬件需要最基本的两个文件进行支持，即：  
- ***board.txt***  
- ***platform.txt***  

　　这两个文件中均采用了“key=value”键值对的定义方式，如W2.name=W2则标识了开发板的名称ID，有了这样的键值对，我们就可以在执行各项动作的时候，使用被花括号包裹的，类似于这样的{W2.name}的属性，这个整体，在使用的时候就会自动替换成字符串“W2”，除一些自己定义的属性以外，有很多IDE提供的，可以直接使用的自动属性，例如{build_path}就会在编译过程中被替换为编译工程的目录  

下面对两个文件各自的功能进行解释  
  
***platform.txt：***  
　　该文档表明了在IDE进行各种操作的时候，所需要的参数 ：例如“recipe.c.o.pattern”则表明了IDE在编译c文档到目标文件的时候所进行的操作  
　　实际上，platform如同一个流程图，详细的描述了从源文件到一个可以执行的二进制的过程：  
<img src="http://124.71.173.197:8080/%E6%B5%81%E7%A8%8B.png" alt="流程" title="流程">
  
　　***编译参数详解：***  
　　在编译过程中，为了方便，直接将待编译的源文件汇编到等待链接的目标文件（ELF格式），而并不生成预处理和汇编代码，在此期间，利用GCC进行编译的时候，会用到以下参数：  
  
  -EL：生成小端序代码  
  **-msoft-float**：不要使用浮点协处理器指令  
  **-march**：指定架构  
  -std：指定语言标准  
  **-G**：优化数据存储  
  -c：编译但不链接  
  -O3：编译优化  
  其中加粗部分为MIPS架构的专用指令  
  
***board.txt:***  
　　该文档表明了以下两点：  
1）该开发板的详细信息，名称ID和架构，以及编译工具链等  
2）在IDE按照上述platform.txt中的recipe进行操作的时候，可能会用到的各种参数（有些参数是自定义的，有些参数的key和value是IDE自动生成的）  

⚠**注意**：  
1）在编译时，若想加入汇编文件，文件扩展名为大写S  
2）多文件混合编译，需要对C和汇编的函数加上 extern "C"  

### 交叉编译工具链

　　Arduino的官方开发板板载芯片大多采用的是avr架构，而许多第三方开发板也采用的是avr架构或者是arm架构的芯片，在Arduino所提供的“Contributed”标识的第三方硬件表中，其大部分是由Arduino开发板改造而成，基本上也就是沿用了avr架构，此外，由意法半导体所制造的stm32等芯片也被广泛使用，使用stm32芯片的开发板又或是如微软索尼等公司定制的开发板芯片的指令集架构基本上采用了arm架构  

　　而W2开发板所采用的，则是MIPS架构，虽然和avr，arm同属精简指令集，但是仍需要一套完全不同的交叉编译工具链，因此需要一套适用于MIPS的编译工具，此次适配采用的是MIPS公司提供的["GCC Bare Metal Toolchain”](http://codescape.mips.com/components/toolchain/2017.10-07/index.html)  
官网对于该工具的描述如下：
> “The Codescape GNU Tools for MIPS Bare Metal. This is a software engineer's cross-development system for MIPS processors, intended for statically linked embedded applications running on bare metal CPUs or light-weight operating systems.”  

此编译工具链存放在tools for compile文件夹下，其使用方式可以参照recipe提供的各项参数，或登陆官网  

### 上传工具
**简介**  

　　由于W2芯片独有的操作界面和架构，所以二进制文件的上传方式需要一个独立的工具在目录中，上传工具存放于“Romload/Romload/bin/Debug”文件夹下，而Romload则存放了编写该工具的整个项目文件，其中.cs文件是上传工具的源代码  
  
　　该工具由C#写成，在预置了.Net Framework框架的Windows系统上可以使用，Windosw10及以上的系统框架版本较高可以稳定使用  
使用方式：  
　　该工具后面的第一个参数必须是待上传bin文件的完整路径，在其后可以添加选项。
　　在开发板端口未被占用，且处于菜单时，上传工具可以自动寻找开发板的端口并自动上传，在IDE中，自动添加了参数，上传完成后将自动运行上传的程序，该参数是可选的。  
  
这是正常运行的输出：  
<img src="http://124.71.173.197:8080/%E6%AD%A3%E5%B8%B8.png" width="100px" alt="正常" title="正常">  
当开发板未连接或未Reset导致不在菜单时：  
<img src="http://124.71.173.197:8080/%E6%9C%AA%E9%87%8D%E7%BD%AE.png" width="100px" alt="未重置" title="重置">  
当开发板的端口可能被占用的时候：  
<img src="http://124.71.173.197:8080/%E5%8D%A0%E7%94%A8.png" width="100px" alt="占用" title="占用">  
该工具也提供了一些上传时的选项和帮助菜单，使用--help或-h调出帮助。  

## 1 IDE的版本要求
**Arduino IDE 1.5版本及以上**  
由于官方文档表示，第三方贡献的硬件在安装时需要一个特定的文件夹结构  
而1.5版本前后其结构并不相同，因此该适配仅支持1.5及以后的版本或者是Arduino的命令行应用  
  
## 2 安装方式
安装第三方硬件有两种方式：  
1）离线安装：将工具，硬件定义文件按照官方指定的文件夹层次放在Arduino的安装文件夹下，此方法过于繁杂且与当前的文件夹层次并不相符。如若需要离线安装，请将硬件定义文档和工具等单独下载并有序重新排列。  
2）将硬件管理的Json添加到Arduino的首选项中，然后在硬件管理器中安装，该硬件管理Json的网址是    ["http://124.71.173.197:8080/package_w2_index.json"](http://124.71.173.197:8080/package_w2_index.json)  
  
## 3 函数库
### 注册中断函数
函数库中提供了一个注册中断的函数：  
```cpp
typedef void (*IrFuncPtr)(void);
void attachInterrupt(IrFuncPtr p);
```
将自定义的中断函数传入该函数中，在发生中断时，将执行该部分的代码。  
此外，也可以直接定义一个名为`void user_interrupt()`的函数，如果定义了该函数，则不需要使用`attachInterrupt()`函数。  
### 串口库
