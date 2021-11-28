# EasyHtml-langage-HTML-MAKER

<div align='center'><a href='https://www.hit-counts.com/'><img src='http://www.hit-counts.com/counter.php?t=MTQ2MDE2OA==' border='0' alt=''></a><BR><a href='https://www.glowgraphics.co.uk/'>logo design</a></div>

You can view the supported themes and extensions, and other related projects in [wiki](https://github.com/SongZihui-sudo/EasyHtml-language/wiki).    

If you want to contribute code [CONTRIBUTING](https://github.com/SongZihui-sudo/EasyHtml-language/blob/main/CONTRIBUTING.md)    

[Use documentation](https://github.com/SongZihui-sudo/EasyHtml-language/blob/main/Use_documentation_english.md) [中文](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/README.md)   
A tool that can convert markdown-like languages into HTML.    
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
Theme tag #theme theme name   
Expansion tags #expand Expansion    
```
## Prerequisites   
(Optional) Install git   

### Installing  
linux
```
sudo git clone -b https://github.com/SongZihui-sudo/EasyHtml-language-HTML-MAKER/tree/Linux    
```
and then input command    
```
sudo chmod -R 777 EasyHtml-language-HTML-MAKER/
```
windows
```
git clone https://github.com/SongZihui-sudo/EasyHtml-language-HTML-MAKER
```
Or download the source code directly and compile it.      
#### Compile with IDE   
#### Use makefile to compile      
Enter the ```make``` command or the ```mingw32-make``` command in the terminal to get the compiled binary file.      
## Running the tests   
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
## screen  

[screen](https://github.com/SongZihui-sudo/EasyHtml-language/blob/main/screen_shot/readme.md)      
	
## development     
Continue to improve the expansion and theme functions.    
