# E-转换-网页-生成工具  
EasyHtml language  
一个可以将markdown转换成HTML的工具。 
欢迎来访[我的博客](s-zh.space)，用这个工具制作的网站。   
[使用文档](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/Use_documentation.md) [ENGLISH](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/english.md)   
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
## 加入主题切换功能   
改善主题功能的使用。  
有两种主题在theme文件夹中。  
效果如下图  
![img](https://pcsdata.baidu.com/thumbnail/e8838a97fo92ae672a4a759827e87949?fid=224912513-16051585-253462236053462&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-aH%2BcUg8%2BSfLhKQRPyFKbjuy0I2o%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=522531740795592441&dp-callid=0&time=1637143200&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video)  
![img](https://pcsdata.baidu.com/thumbnail/f31747a02h0227b6ae76ffa4b631f2fa?fid=224912513-16051585-581443497161907&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-tREA0mQy3V16fN3L9Ge83Xpt6EU%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=522531740795592441&dp-callid=0&time=1637143200&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video)  
在md文件的第一行使用主题标签来选择主题。（具体使用如下）  
# 重构了现有代码，也改变一些标签的写法如下：    
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
```
# demo
markdown
```
#theme text_center

# Song_Zihui’s_Website 


Every problems has its Solution


## Welcome


url ../About/About.html About Me 


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
<div>
<br><h1> Song_Zihui’s_Website </h1>
<br>
<br>Every problems has its Solution
<br><h2> Welcome</h2>
<br>
<br><a href="../About/About.html"> About Me </a>
<br>
<br><a href="../Blog/Blog.html"> Blog </a>
<br>
<br><a href="../About/contact_me.html"> contact me  </a>
<br>
<br>This Website made by 
<br><a href="https://github.com/SongZihui-sudo/e-Conversion-html-maker"> e-Conversion html maker </a>
<br>
<br></div></body></html>
```
