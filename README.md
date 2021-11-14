# e-Conversion-html-maker
# E-转换-网页-生成工具
一个可以将markdown转换成HTML的工具。 
欢迎来访s-zh.space，用这个工具制作的网站。   
[使用文档](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/Use_documentation.md)  
相应的HTML会存在相应的文件夹中  
文件结构  
输入ps命令
```
e-htmlmaker
|
————Blog:you content
|
————About: about youself
|
————theme: wensite's theme
|
————md: markdown file
```
加入主题切换功能   
目前是有两种背景主题可供选择  
一种是以自定义的纯色背景主题  
还有一种是自定义图片为背景的主题  
# 重构了现有代码，也改变一些标签的写法如下：    
```
标题标签：#
图像标签：![img]()
链接标签：url 网址 名称
代码块标签：
三个` 表示开始  
三个* 表示结束  
中间的内容表示代码  
```
# demo
markdown
```
# Song_Zihui’s_Website 

Every problems has its Solution

## Welcome

url ../About/About.html About Me 

url ../Blog/Blog.html Blog 

url ../About/contact_me.html contact me  

This Website made by 
url https://github.com/SongZihui-sudo/e-Conversion-html-maker e-Conversion html maker 

```
HTML CODE
```
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
 <title>S-zh.space</title>
</head>
<body background="https://images.pexels.com/photos/783944/pexels-photo-783944.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=650&w=940">
<h1> Song_Zihui’s_Website </h1>
<br><h1></h1> 
<br>Every problems has its Solution
<br>
<br><h2> Welcome</h2>
<br><h2></h2>
<br><a href="../About/About.html"> About Me</a>
<br>
<br><a href="../Blog/Blog.html"> Blog</a>
<br>
<br><a href="../About/contact_me.html"> contact me </a>
<br>
<br>
<br>This Website made by 
<br><a href="https://github.com/SongZihui-sudo/e-Conversion-html-maker"> e-Conversion html maker </a>
<br></body></html>

```
