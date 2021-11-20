# E-conversion-HTML-generation tool  
EasyHtml language    
[Use documentation](https://github.com/SongZihui-sudo/EasyHtml-language/blob/main/Use_documentation_english.md) [中文](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/README.md)   
A tool that can convert markdown to HTML. Welcome to visit s-zh.space, a website made with this tool.
Use document ENGLISH
The corresponding HTML will be stored in the corresponding folder
File structure
Enter the ps command 
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
## Add theme switching function
Add theme switching function
Improve the use of theme functions.
There are two themes in the theme folder.
The effect is as shown below   
background is a picture   
![img](https://pcsdata.baidu.com/thumbnail/e8838a97fo92ae672a4a759827e87949?fid=224912513-16051585-253462236053462&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-aH%2BcUg8%2BSfLhKQRPyFKbjuy0I2o%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=522531740795592441&dp-callid=0&time=1637143200&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video)  
show in centure  
![img](https://pcsdata.baidu.com/thumbnail/f31747a02h0227b6ae76ffa4b631f2fa?fid=224912513-16051585-581443497161907&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-tREA0mQy3V16fN3L9Ge83Xpt6EU%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=522490943581668263&dp-callid=0&time=1637143200&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video)    
Use the theme tag in the first line of the md file to select the theme. (The specific use is as follows)    
## About the nested use of tags   
It's not perfect yet, uh, hahaha   
It only supports one-level nesting of title tags and link tags.   
'###' github url https://github.com Github   
And the nested use of title tags in the body   
E.g:   
Welcome to visit url https://github.com github haha....    
## Expand function
Use extended tags
#expand Extension
You can add other open source projects (or link to other open source projects) on your website    
Currently supported extensions:    
[pi-dashboard](https://github.com/nxez/pi-dashboard) 
# Refactored the existing code, and also changed the writing of some tags as follows:    
```
Title tag: #
Image tag: ![img]()
Link label: url URL name
Code block label:
Three` means start
Three * means the end
The content in the middle represents the code
Quote tags>
Divider label --- one more line
Emphasis (bold) __ two_ 
```
## demo
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
HTML
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

