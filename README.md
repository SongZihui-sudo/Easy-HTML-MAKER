# EasyHtml-language-HTML-MAKER
<div>
</div>
<div align='center'><a href='https://www.hit-counts.com/'><img src='http://www.hit-counts.com/counter.php?t=MTQ2MDE2OA==' border='0' alt=''></a><BR><a href='https://www.glowgraphics.co.uk/'>logo design</a></div>

![img](https://img.shields.io/github/issues/SongZihui-sudo/EasyHtml-language-HTML-MAKER)
![img](https://img.shields.io/github/stars/SongZihui-sudo/EasyHtml-language-HTML-MAKER)        
	
可在[wiki](https://github.com/SongZihui-sudo/EasyHtml-language/wiki)中查看支持的主题与拓展,以及与之相关的其他项目。 

如果您想贡献代码代码[CONTRIBUTING](https://github.com/SongZihui-sudo/EasyHtml-language/blob/main/CONTRIBUTING.md)    

[使用文档](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/Use_documentation.md) [ENGLISH](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/english.md)   

 一个可以将类markdown语言转换成HTML的工具。您可以用它来搭建您自己的博客，哈哈哈
 
```
标题标签：#
图像标签：![img]()
链接标签：url 网址 名称
代码块标签：
三个` 表示开始  
三个* 表示结束  
中间的内容表示代码  
引用标签 > 
分割线标签 --- 再单独一行
强调（加粗） __ 两个_
主题标签 #theme 主题名    
拓展标签 #expand 拓展名
``` 

## Getting Started   

### Prerequisites  
（可选）安装git       

### Installing    
linux  
```
sudo git clone https://github.com/SongZihui-sudo/EasyHtml-language-HTML-MAKER    
```
and then input command    
```
sudo chmod 777 EasyHtml-language-HTML-MAKER
```
windows
```
git clone https://github.com/SongZihui-sudo/EasyHtml-language-HTML-MAKER
```
或者直接下载源码，编译。   
#### 使用IDE编译
#### 使用makefile编译    
在终端输入```make```命令或者```mingw32-make```命令即可得到编译生成的二进制文件。
### Running the tests    
### DEMO   
MARKDOWN     
```
#theme default

# Song Zihui’s Website 

Every problems has its Solution

## Welcome
---

url ../About/About.html About Me 

url ../Blog/Blog.html Blog 

url ../About/contact_me.html contact me  

#expand pi-dashboard

#expand Weather.io

This Website made by 
url https://githubfast.com/SongZihui-sudo/e-Conversion-html-maker e-Conversion html maker     

```
HTML     
```
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
 <title>S-zh.space</title>
 <script type="text/javascript" src="https://v1.cnzz.com/z_stat.php?id=1280598106&web_id=1280598106"></script>
<style>body {background-color: #dea829;}
     div{
	    text-align: center; /*让div内部文字居中*/
	    border-radius: 20px;
	    width: 300px;
	    margin: auto;
	    position: absolute;
	    top: 0;
	    left: 0;
	    right: 0;
	    bottom: 0;
}
</style></head>
<body>
<div><br>
<br>
<h1>Song Zihui’s Website </h1><br>
<br>
Every problems has its Solution<br>
<br>
<h2>Welcome</h2><br>
<hr><br>
<br>
<a href="../About/About.html"> About Me </a><br>
<br>
<a href="../Blog/Blog.html"> Blog </a><br>
<br>
<br>
<a href="../About/contact_me.html"> contact me  </a><br>
<br>
<a href="expand/pi-dashboard/index.php"> pi-dashboard</a><br>
<br>
<a href="expand/Weather.io/index.html"> Weather.io</a><br>
<br>
This Website made by <br>
<a href="https://githubfast.com/SongZihui-sudo/e-Conversion-html-maker"> e-Conversion html maker     </a><br>
</div></body></html>
```
	
## 截图
[截图](https://github.com/SongZihui-sudo/EasyHtml-language/blob/main/screen_shot/readme.md)    
	
## development   
继续完善拓展与主题功能。   
