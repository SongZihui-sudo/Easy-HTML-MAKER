# E-转换-HTML生成器 使用文档

url https://github.com/SongZihui-sudo/e-Conversion-html-maker/releases 发行版

说明：

v2.0 版本目前为稳定版本，在翻译标签时并没有明显bug。但是目前还不支持叠加使用标签

v1.0 原始版本在翻译代码块标签时和在正文中使用一些符号时，会产生明显bug。

## 	开始使用 - 安装

1. 可选 安装 git。

### Linux 

使用如下命令

```
sudo git clone https://github.com/SongZihui-sudo/e-Conversion-html-maker
***

### Windows

```
git clone https://github.com/SongZihui-sudo/e-Conversion-html-maker
***

2. 下载源码后，可以使用g++编译源码使用，也可以直接打开二进制程序使用。

## 关于语言

#### 标题标签 

与原Markdown中的标签相同，都为n个#，由个数来划分为n级标题。

实例：
input ：### 大家好
output：<h3>大家好</h3>


### 图像标签

与原Markdown中的相同。

实例：

input : ![img](https://images.pexels.com/photos/9428520/pexels-photo-9428520.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=650&w=940)
   
output : ![img](https://images.pexels.com/photos/9428520/pexels-photo-9428520.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=650&w=940)

### 链接标签

与原Markdown略有不同。

原:[name](url)

改为 url 网址（url） name

实例：
input : url s-zh.space my website
output : <a href = "s-zh.space">my website</a>

### 代码块标签

与原Markdown不同

原 三个`
现改为了两部分
三个`表示代码块的开始部分，三个*表示代码块的结束部分
实例：

input 
三个`
```
#include<iostream>
   int main(){
      cout<<"hello world";
      return 0;
}
***
三个*
output
<pre>
   #include<iostream>
   int main(){
   	cout<<"hello world";
   	return 0;
   }
</pre>

## 关于主题

该功能目前还不完善，只是可以切换背景，哈哈哈。。。。。。。

## 其他一些说明

在程序中进行文件名输入时，并不需要输入后缀（不要忘，不要忘，不要忘）。
还有就是要顶格书写

   

   

   
