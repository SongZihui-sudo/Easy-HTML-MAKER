# Easy-HTML-MAKER

> A static blog generator

![img](https://img.shields.io/github/issues/SongZihui-sudo/EasyHtml-language-HTML-MAKER) ![img](https://img.shields.io/badge/-Easyhtml-blue) ![img](https://img.shields.io/badge/author-szh-red)    
![img](https://tse2-mm.cn.bing.net/th/id/OIP-C.EwgonFYrdaUF5ofu4YNougHaD4?pid=ImgDet&rs=1)    
## [EasyCoding_editor](https://github.com/SongZihui-sudo/EasyCoding_editor)     
After the 1.0 version of the EasyCoding editor, the built-in Easy-HTML-MAKE supports html conversion.   
## About
Regarding this tool, it can put the following tags (````#```, ```url```, ```img```, ```---```, ```___` ``,```>```.```::``,```,***) articles, parsed into html.
It can be used to generate web pages in batches, of course, you can use it to build your small website for the main purpose.    
## Getting Started   

### Prerequisites  
(optional) install git     

### Installing    
If you are linux  
[ABOUT THE PROBLEM OF CAN NOT OPEN THE FIEL OR CAN NOT CREAT THE HTML FILE](https://github.com/SongZihui-sudo/EasyHtml-language-HTML-MAKER/issues/7)     
```
sudo git clone   
```
and then input command    
```
sudo chmod 777 EasyHtml-language-HTML-MAKER
```
windows
```
git clone https://github.com/SongZihui-sudo/EasyHtml-language-HTML-MAKER
```
Or download the source code directly and compile it.     
#### Compile with makefile   
Enter the ```make``` command or the ```mingw32-make``` command in the terminal to get the compiled binary file.    
## Running the tests        
### DEMO   
EASYHTML     
```
# Song Zihui’s Website 

Every problems has its Solution

## Welcome
---

url ../About/About.html About Me 

url ../Blog/Blog.html Blog 

url ../About/contact_me.html contact me  

:: pi-dashboard

:: Weather.io

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

## Using it  
Tags supported by the converter:    
````
Title Tag: #   
image tag: link to img image   
Link label: url URL name
Code block label:
Three ` to start
Three * means end
The content in the middle represents the code
Citation Tags >
Split line label --- one more line
Emphasis (bold) __ two_
extension tag :: extension name
````   
### Label syntax
#### title tag #    
Title, add a pound sign (#) in front of the word or phrase.    
The number of \# represents the level of the title.     
E.g      
\# XXXXX     
   
#### image tag img     
To insert a picture is to add img before the link of the picture, such as img https://githubcom     

#### link tag url    
Inserting a connection is in the hyperlink syntax code: url link name    

#### code block label    
Start \`\`\`, end \*\*\*.    
Insert between these two tags, the code snippet.     
E.g     
\`\`\`   
#include<iostream>     

using namespace std;   

int main(){     
cout<<"hello world";     
return 0;     
}     

\*\*\*  

#### Quote labels \>      
To create a citation, add a > sign before the paragraph.       
E.g:      
``` > hello world```     

#### Split line label \---     
To create a dividing line, you can enter ```---``` on a blank line     

#### Emphasis Label ___    
To bold a sentence or phrase, add ```___```;(_*3) before the phrase     

#### Extended tags ::    
To add an extension to the page, add :: before the extension name    
E.g:    
````    
:: pi-dashboard    
````    
All supported extensions are in expand_list.conf in the conf under the Website folder.    
### steps    
### Firstly Configure EmakeFile file    
It's simple, the syntax is below.    
It is mainly to set the entry of the original file and the storage directory of the generated file, as well as whether to open the extension, and the theme directory to be used (it may be improved in the future).    
### Secondly compile and run the file    
There will be binaries in the repository, but they may not be up to date.    
So you can use the above method to compile under LINUX and WINDOWS.    
### Thirdly run file    
Type in the command line    
```./easyhtml``` runs the executable.    
After that you can enter two commands    
```emake``` Convert the files in the source directory (note: the suffix of the file is .eh)    
```quit``` to exit the program   
##End  
## About the 2021-12-29 update
made some changes   
The EMAKEFILE file was added first, with the intention that the conversion of HTML can be done in batches without having to select each conversion.   
### These simple syntaxes also exist in EMAKEFILE files
Note: do not add filename suffix    
1. Define variables    
The data type of ```var``` is a string, which can be used to store file addresses, etc. Syntax ```var str```   
The data type of ```int``` is a short integer number, which is mainly used to set the output html file name in batches ```int num```   
2. for   
Syntax ``` for i```   
Decrement i times i   
3. Static must be declared when using variables   
````var str static str```   
4. ```#INPUTFILE``` Enter the file address, not the file, just go to the upper directory.   
```` #INPUTFILE var```` or ``` #INPUTFILE ../md```   
5. ```#OUTPUTFILE``` output file address   
```` #OUTPUTFILE var```` or ```#OUTPUTFILE ../html/test ```   
6. ```#THEME``` The address of the selected theme, the syntax is the same as above.   
7. ```#EXPAND``` Whether to open the expansion function Open ON Close OFF   
8. ````//``` Comment Usage: // Space Content   
The second is to also change the way the image label is written.   
Change to the format of ````img image link``   
e.g.    
````
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
name++
++i
#OUTPUTFILE name
static name2
#THEME name2
#EXPAND ON
````
### If you like, you can add a star to this project,,, lol
