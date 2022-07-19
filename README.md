# W2-Develop-Board-For-Arduino
将W2 开发板适配至Arduino IDE或Arduino CLI  
## 0 适配所需文件
### 硬件定义文件
为使IDE能够对用户的各种操作进行不同的反应，  
Arduino需要一些参数和固定的“recipe”来对不同的硬件进行不同的编译、链接、生成二进制文件等操作  
  
因此Arduino对于某一个硬件需要最基本的两个文件进行支持，即：  
**board.txt**  
**platform.txt**  
文件中均采用了“key=value”键值对的定义方式  
下面对两个文件进行解释  
  
platform.txt：  
该文档表明了在IDE进行各种操作的时候，所需要的参数  
例如“recipe.c.o.pattern”则表明了IDE在编译c文档到目标文件的时候所进行的操作  
  
board.txt:  
该文档表明了以下两点：  
1）该开发板的详细详细，名称ID和架构，以及编译工具链等  
2）在上述platform.txt在进行操作的时候，可能会用到的各种参数（有些参数是自定义的，有些参数的key和value是IDE自动生成的）  

### 交叉编译工具链

Arduino的官方开发板板载芯片大多采用的是avr架构，而许多第三方开发板也采用的是avr架构或者是arm架构的芯片  
在Arduino所提供的“Contributed”标识的第三方硬件表中，其大部分是由Arduino开发板改造而成，基本上也就是沿用了avr架构  
此外，由意法半导体所制造的stm32等芯片也被广泛使用，使用stm32芯片的开发板或是如微软索尼等公司定制的开发板芯片的指令集架构基本上采用了arm架构  

而W2开发板所采用的，则是MIPS架构，虽然和avr，arm同属精简指令集，但是仍需要一套完全不同的交叉编译工具链  
因此需要一套适用于MIPS的编译工具，此次适配采用的是MIPS公司提供的["GCC Bare Metal Toolchain”](http://codescape.mips.com/components/toolchain/2017.10-07/index.html)  
官网描述如下：
“The Codescape GNU Tools for MIPS Bare Metal. This is a software engineer's cross-development system for MIPS processors, intended for statically linked embedded applications running on bare metal CPUs or light-weight operating systems.”  
此编译工具链存放在tools for compile文件夹下  

### 上传工具
**简介**  
由于W2芯片独有的操作界面和架构，所以二进制文件的上传方式需要一个独立的工具。  
在目录中，上传工具存放于“Romload/Romload/bin/Debug”文件夹下，而Romload则存放了编写该工具的整个项目文件，其中.cs文件是上传工具的源代码  
该工具由C#写成，在预置了.Net Framework框架的Windows系统上可以使用，Windosw10及以上的系统框架版本较高可以稳定使用  
  
**使用**  
编译：  
首先ino文件将被编译成.o文件

多文件的注意事项：  


## 1 IDE的版本要求
**Arduino IDE 1.5版本及以上**  
由于官方文档表示，第三方贡献的硬件在安装时需要一个特定的文件夹结构  
而1.5版本前后其结构并不相同，因此该适配仅支持1.5及以后的版本或者是Arduino的命令行应用  
  
## 2 安装方式
安装第三方硬件有两种方式：  
1）离线安装：将工具，硬件定义文件按照官方指定的文件夹层次放在Arduino的安装文件夹下，此方法过于繁杂且与当前的文件夹层次并不相符。如若需要离线安装，请将硬件定义文档和工具等单独下载并有序重新排列。  
2）将硬件管理的Json添加到Arduino的首选项中，然后在硬件管理器中安装  
  
## 3 硬件定义文件中的细节详述
### 编译参数（flags）与编译的“recipe”
待补充......
### 上传工具的使用
待补充......
