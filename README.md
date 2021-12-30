# EasyHtml-language-HTML-MAKER
 
## 关于 2021-12-29 更新     
首先加入了EMAKEFILE文件，意在可以批量完成对HTML的转换而不用在每次转换时都要进行选择。    
### 在EMAKEFILE文件中也存在这一些简单的语法    
注意：不用添加文件名后缀     
1、定义变量     
```var```的数据类型为字符串，可以用此来存放文件地址等 语法```var str```    
```int```的数据类型为短整型数字，主要用来批量设置输出的html文件名 ```int num```     
2、for     
语法 ``` for i```     
递减i次i     
3、static 在使用变量时要进行声明      
```var str     static str```    
4、```#INPUTFILE``` 输入文件地址，不用精确到文件，到上层目录即可。    
``` #INPUTFILE var``` or ``` #INPUTFILE ../md```    
5、```#OUTPUTFILE``` 输出文件地址    
``` #OUTPUTFILE var``` or ```#OUTPUTFILE ../html/test ```   
6、```#THEME``` 选择的主题的地址，语法同上。   
7、```#EXPAND``` 是否打开拓展功能 打开 ON 关闭 OFF   
其次是也改变了图像标签的写法。   
改为 ```img 图片链接 ```的格式   
e.g.
```
var name3
name3 ../md
static name3
#INPUTFILE name3 
var name
var name2
name2 ../theme/default
name ../html/test
int i
i 1
static i
for i
// Declare before using variables
static name
name ++
++ i
#OUTPUTFILE name
static name2
#THEME name2
#EXPAND ON
```
<div align='center'><a href='https://www.hit-counts.com/'><img src='http://www.hit-counts.com/counter.php?t=MTQ2MDE2OA==' border='0' alt=''></a><BR><a href='https://www.glowgraphics.co.uk/'>logo design</a></div>   
	
[关于EASYHTML编辑器](https://github.com/SongZihui-sudo/easyhtmleaitor)      
	
![img](https://img.shields.io/github/issues/SongZihui-sudo/EasyHtml-language-HTML-MAKER)
	
可在[wiki](https://github.com/SongZihui-sudo/EasyHtml-language/wiki)中查看支持的主题与拓展,以及与之相关的其他项目。 

如果您想贡献代码代码[CONTRIBUTING](https://github.com/SongZihui-sudo/EasyHtml-language/blob/main/CONTRIBUTING.md)    

[使用文档](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/Use_documentation.md) [ENGLISH](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/english.md)   

 一个可以将类markdown语言转换成HTML的工具。您可以用它来搭建您自己的博客，哈哈哈！        

转换器支持的标签:
```
标题标签：#
图像标签：img 图片的链接
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
[ABOUT THE PROBLEM OF CAN NOT OPEN THE FIEL OR CAN NOT CREAT THE HTML FILE](https://github.com/SongZihui-sudo/EasyHtml-language-HTML-MAKER/issues/7)     
```
sudo git clone -b https://github.com/SongZihui-sudo/EasyHtml-language-HTML-MAKER/tree/Linux    
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
# Song Zihui’s Website 

Every problems has its Solution

## Welcome
---

url ../About/About.html About Me 

url ../Blog/Blog.html Blog 

url ../About/contact_me.html contact me  

#expand pi-dashboard

#expand Weather.io

This Website made by url https://githubfast.com/SongZihui-sudo/e-Conversion-html-maker e-Conversion html maker     

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
This Website made by <a href="https://githubfast.com/SongZihui-sudo/e-Conversion-html-maker"> e-Conversion html maker     </a><br>
</div></body></html>
```
	
## 截图
[截图](https://github.com/SongZihui-sudo/EasyHtml-language/blob/main/screen_shot/readme.md)    
	
## development   
继续完善拓展与主题功能。   
