# EasyHtml-langage   
[使用文档](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/Use_documentation.md) [ENGLISH](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/english.md)   

 一个可以将类markdown语言转换成HTML的工具。 
 
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
sudo git clone https://github.com/SongZihui-sudo/EasyHtml-language
```
windows
```
git clone https://github.com/SongZihui-sudo/EasyHtml-language
```
或者直接下载源码，编译。
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
![img](https://pcsdata.baidu.com/thumbnail/b5149785al641405bec3030a7c2d0688?fid=224912513-16051585-575905765536221&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-5lSv6rgZksho1Bm2dpKTwyLogTo%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=8667193412418387505&dp-callid=0&time=1637420400&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video)      
![img](https://pcsdata.baidu.com/thumbnail/8a6e425d8ja041a7b7f3270e808efa50?fid=224912513-16051585-712206804854690&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-krznGJyjrX4ka1uGy5YKfN%2FVTc8%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=8681651910508396512&dp-callid=0&time=1637474400&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video)     
## development
继续完善拓展与主题功能。   
