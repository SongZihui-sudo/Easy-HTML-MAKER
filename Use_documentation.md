# E-转换-HTML生成器 使用文档
[ENGLISH](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/Use_documentation_english.md)

url https://githubfast.com/SongZihui-sudo/e-Conversion-html-maker/releases 发行版

说明：
v2.1 版本在v2.0版本基础上，完善了几乎所有的markdown标签（个别有所改变）

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
关键词如下：   
1.标题标签：#     
2.图像标签：‘![img]()’     
3.链接标签：url      
4.代码块标签：三个` 表示开始    
            *** 表示结束  
5.强调标签：__  
6.引用标签：>  
7.分割线标签：---  
8. 主题标签 #theme
### 说明

#### 标题标签 

与原Markdown中的标签相同，都为n个#，由个数来划分为n级标题。

实例：
input ：### 大家好
output：<h3>大家好</h3>


### 图像标签

与原Markdown中的相同。

实例：

input : ![img](https://images.pexels.com)
   
output : ![img](https://images.pexels.com)

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
```
### 分割线标签
--- 三个减号 再单独的一行里
input ：---
output ： </hr>

### 强调标签
__ 两个_ 空格 内容
input : __ XXXXXX
output : <strong>XXXXXX</strong>

### 引用标签
'>' 一个>
input：> hello world
output: <blockquote>hello world</blockquote>

### 主题标签  
#theme 主题名  
主题名为theme文件夹中文件的名称  

## 关于标签的嵌套使用   
目前还不完善，额，哈哈哈    
只是支持标题标签与链接标签的一层嵌套使用。  
语法：
标题标签（多个#）空格 链接标签（url） 空格 网址（或目录） 空格 名称 
例如：   
'###' url https://githubfast.com Github   
在正文中嵌入超链接：   
语法：正文 url 网址（url） 名称  
例子：   
welcome to visit url https://github.com github hahah.....     
## 关于主题

该功能目前还不完善，哈哈哈。。。。。。。

## 其他一些说明

在程序中进行文件名输入时，并不需要输入后缀（不要忘，不要忘，不要忘）.
# 重要
所有语句都要顶格书写，尤其带有关键词的语句。

   

   

   
