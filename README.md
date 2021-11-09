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
后续会加入主题切换功能
# 目前支持的markdown的标签  
```
#        多级标题
![img]() 图像标签
三个`    插入代码块
```
# demo
markdown
```
# XXXX’s_Website 

## Welcome



<a href ="About.html">About Me</a>



<a href="Blog.html">Blog</a>

![img](https://images.pexels.com/photos/9754/mountains-clouds-forest-fog.jpg?auto=compress&cs=tinysrgb&dpr=2&h=650&w=940)

<a href="contact me">contact me</a>



This Website made by e-Conversion html maker(<a href="https://github.com/SongZihui-sudo/e-Conversion-html-maker">ABOUT</a>).
```
HTML CODE
```
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
 <title>Document</title>
</head>
<body>
<h1>XXXX’s_Website<h1></h1>
<br>
<br><h2>Welcome</h2>
<br>
<br>
<br>
<br><a href ="About.html">About Me</a>
<br>
<br>
<br>
<br><a href="Blog.html">Blog</a>
<br>
<br><img src="https://images.pexels.com/photos/9754/mountains-clouds-forest-fog.jpg?auto=compress&cs=tinysrgb&dpr=2&h=650&w=940" />
<br>
<br><a href="contact me">contact me</a>
<br>
<br>
<br>
<br>This Website made by e-Conversion html maker(<a href="https://github.com/SongZihui-sudo/e-Conversion-html-maker">ABOUT</a>).</body>
</html>
```
screenshot
![图片](https://user-images.githubusercontent.com/77034643/140615856-f0de8294-abd8-40dc-9737-c7c02db8e3a8.png)
