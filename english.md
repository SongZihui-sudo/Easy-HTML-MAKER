# E-conversion-HTMLgeneration tool  
[Use documentation](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/Use_documentation.md) [CHINESE](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/README.md)   
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
There are currently two background themes to choose from
One is a custom solid color background theme
There is also a theme with a custom picture as the background
Refactored the existing code, and also changed the writing of some tags as follows:    
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

