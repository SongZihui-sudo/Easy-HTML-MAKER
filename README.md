# e-Conversion-html-maker
# E-转换-网页-生成工具
一个可以将markdown转换成HTML的工具。 
A tool that can make Markdown to the Html.
欢迎来访s-zh.space，用这个工具制作的网站。  
Welcome to visite s-zh.space which is made by th is tool.
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
————index: wensite's index html
|
————theme: wensite's theme
|
————md: markdown file
```
加入主题切换功能   
目前是有两种背景主题可供选择  
一种是以自定义的纯色背景主题  
还有一种是自定义图片为背景的主题  
# 目前支持的markdown的标签  
```
#        多级标题
![img]() 图像标签
三个`    插入代码块
```
# demo
markdown
```
# Song_Zihui’s_Website 

Every problems has its Solution

## Welcome

<a href ="../About/About.html">About Me</a>

<a href="../Blog/Blog.html">Blog</a>

<a href="../About/contact_me.html">contact me</a>


This Website made by (<a href="https://github.com/SongZihui-sudo/e-Conversion-html-maker">e-Conversion html maker</a>).

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
<style>body{
    background:url(https://images.pexels.com/photos/844297/pexels-photo-844297.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=650&w=940) no-repeat;
}</style></head>
<body><h4>2021-11-10</h4><h1>Song_Zihui’s_Website<h1></h1>

<br>Every problems has its Solution
<br>
<br><h2>Welcome</h2>

<br><a href ="../About/About.html">About Me</a>
<br>
<br><a href="../Blog/Blog.html">Blog</a>
<br>
<br><a href="../About/contact_me.html">contact me</a>
<br>
<br>
<br>This Website made by (<a href="https://github.com/SongZihui-sudo/e-Conversion-html-maker">e-Conversion html maker</a>).
<br>
<br></body>
</html>
```
screenshot
![图片](![图片](https://user-images.githubusercontent.com/77034643/141147033-6e61a295-ad61-4e49-b724-1f8f66b5fb98.png)
)
