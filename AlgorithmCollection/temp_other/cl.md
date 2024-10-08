# 使用msvc的cl工具编译程序，以及 “fatal error C1034: iostream: 不包括路径集”等问题解决

最新推荐文章于 2023-07-24 15:31:14 发布

![](https://csdnimg.cn/release/blogv2/dist/pc/img/original.png)

[音柯路德](https://blog.csdn.net/weixin_41115751 "音柯路德") ![](https://csdnimg.cn/release/blogv2/dist/pc/img/newCurrentTime2.png) 于 2019-05-04 20:00:58 发布 ![](https://csdnimg.cn/release/blogv2/dist/pc/img/articleReadEyes2.png) 12383 ![](https://csdnimg.cn/release/blogv2/dist/pc/img/tobarCollect2.png) ![](https://csdnimg.cn/release/blogv2/dist/pc/img/tobarCollectionActive2.png) 收藏 33

文章标签： [cl](https://so.csdn.net/so/search/s.do?q=cl&t=all&o=vip&s=&l=&f=&viparticle=) [msvc](https://so.csdn.net/so/search/s.do?q=msvc&t=all&o=vip&s=&l=&f=&viparticle=) [不包括路径集](https://so.csdn.net/so/search/s.do?q=%E4%B8%8D%E5%8C%85%E6%8B%AC%E8%B7%AF%E5%BE%84%E9%9B%86&t=all&o=vip&s=&l=&f=&viparticle=)

版权声明：本文为博主原创文章，遵循 [CC 4.0 BY](http://creativecommons.org/licenses/by/4.0/) 版权协议，转载请附上原文出处链接和本声明。

本文链接：[https://blog.csdn.net/weixin\_41115751/article/details/89817123](https://blog.csdn.net/weixin_41115751/article/details/89817123)

版权

# 首先要安装vs2019(2015or2017都可以)

- **注意：在不同操作系统或不同 VS 版本，下文示例路径可能会稍有不同。**

- 添加`C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.20.27508\bin\Hostx64\x64`加入到环境变量

- 打开powershell或者cmd，输入cl  
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/20190504195125935.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTExNTc1MQ==,size_16,color_FFFFFF,t_70)  
  显示以上内容说明成功。接下来可以写一个小程施序试试。  
  通常会遇到以下问题  
  1、 “fatal error C1034: iostream: 不包括路径集”或“fatal error C1083: 无法打开包括文件: “corecrt.h”: No such file or directory”  
  解决方法：右键此电脑，选择“属性”，“高级系统设置”，“环境变量”。在下方的“系统变量”中选择变量 INCLUDE（**注意是大写**），若没有此变量，则选择“新建”，变量名为“INCLUDE”，变量值列在下方：  
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/2019050419561989.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTExNTc1MQ==,size_16,color_FFFFFF,t_70)  
  2、. fatal error LNK1104: 无法打开文件“libcpmt.lib”或者其他lib文件  
  解决办法： 解决方法为，右键此电脑，选择“属性”，“高级系统设置”，“环境变量”。在下方的“系统变量”中选择变量 LIB，若没有此变量，则选择“新建”，变量名为“LIB”，变量值列在下方：![在这里插入图片描述](https://img-blog.csdnimg.cn/20190504195755913.png)
  
  # 重启、重启、重启 powershell
  
  输入`cl a.cpp`  
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/20190504195938477.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTExNTc1MQ==,size_16,color_FFFFFF,t_70)



    



一般在windows下写一个c/c++的动态链接库，我们都是在visual studio或着visual c++这些ide里面进行编译和生成的，今天介绍，如何通过命令行来实现手动编译和生成动态链接库。

    首先，确保我们的系统中安装了visual studio 2019或着其他版本，这样，我们才可以使用命令行工具。

    开始->程序里面找到visual studio 2019这个文件夹，里面有命令行工具。找到"x64 Native Tools Command Prompt for VS 2019"，然后点击，打开一个cmd命令行。

    ![](https://img-blog.csdnimg.cn/20201203095028877.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ZlaW5pZmk=,size_16,color_FFFFFF,t_70)

    我们准备我们的两个简单的程序，一个是动态库，一个是调用动态库的程序：

    test.c

```cpp
#include <stdlib.h>__declspec(dllexport) int add(int a,int b){  return a + b;}
```

    main.c

```cpp
#include <stdio.h>extern int add(int a,int b); int main(){  int i = add(1,2);  printf("add(1,2)=%d\n",i);  return 0;}
```

    开始编译：

```bash
cl -c test.c
```

    在打开的cmd命令行中，切换到我们的项目目录下，然后运行cl指令：

     ![](https://img-blog.csdnimg.cn/20201203095713912.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ZlaW5pZmk=,size_16,color_FFFFFF,t_70)

    该命令执行之后，会生成一个test.obj文件，接着，我们运行链接命令：   

```bash
link -dll -out:test.dll test.obj
```

     ![](https://img-blog.csdnimg.cn/20201203095823414.png)

    从命令上，我们可以看出，会生成动态链接库test.dll，其实，同时还会生成test.lib,test.exp文件。

    ![](https://img-blog.csdnimg.cn/20201203095936487.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ZlaW5pZmk=,size_16,color_FFFFFF,t_70)

－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－

    以上两步操作，其实可以通过一个命令来完成，就是：

```bash
cl /LD test.c
```

     ![](https://img-blog.csdnimg.cn/20201203100127845.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ZlaW5pZmk=,size_16,color_FFFFFF,t_70)

    该命令可以直接生成动态链接库dll。

    我们还可以通过dumpbin命令，查看生成的动态库的信息：

```bash
dumpbin -exports test.dll
```

     ![](https://img-blog.csdnimg.cn/20201203100229780.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ZlaW5pZmk=,size_16,color_FFFFFF,t_70)

     有了动态链接库，我们接着利用这个动态链接库来生成main可执行程序。

```bash
cl main.c test.lib
```

    运行该命令，会生成main.exe程序，在命令行下，可以直接运行:main，就可以看到打印结果：

    ![](https://img-blog.csdnimg.cn/2020120310045957.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ZlaW5pZmk=,size_16,color_FFFFFF,t_70)

    以上就是在命令行下编译生成动态链接库的过程，如果你的系统里面没有cl指令，可能是没有安装visual studio或者visual c++，如果安装了，进入他自带的命令行工具，就有这些命令了。