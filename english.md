# Easy-HTML-MAKER

![img](https://img.shields.io/github/issues/SongZihui-sudo/EasyHtml-language-HTML-MAKER)
![img](https://img.shields.io/badge/-Easyhtml-blue)
![img](https://img.shields.io/badge/author-szh-red)
![img](https://tse2-mm.cn.bing.net/th/id/OIP-C.EwgonFYrdaUF5ofu4YNougHaD4?pid=ImgDet&rs=1)
[ENGLISH](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/english.md)

## About
Regarding this tool, it can have the following tags (```#```,```url```,```img```,```---```,```___` ``,```>```.```::```,```,***) articles are parsed into html.
It can be used to generate web pages in batches, of course, you can use it to build your small website for the main purpose.
## Getting Started

### Prerequisites
(Optional) Install git

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
Or download the source code directly and compile it.
#### Compile with IDE
#### Use makefile to compile
Enter the ```make``` command or the ```mingw32-make``` command in the terminal to get the compiled binary file.
## Running the tests
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
text-align: center; /*Center the text inside the div*/
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
<a href="../About/contact_me.html"> contact me </a><br>
<br>
<a href="expand/pi-dashboard/index.php"> pi-dashboard</a><br>
<br>
<a href="expand/Weather.io/index.html"> Weather.io</a><br>
<br>
This Website made by <a href="https://githubfast.com/SongZihui-sudo/e-Conversion-html-maker"> e-Conversion html maker </a><br>
</div></body></html>
```

## Using it
Tags supported by the converter:
```
Title tag: #
Image tag: img picture link
Link label: url URL name
Code block label:
Three` means start
Three * means the end
The content in the middle represents the code
Quote tags>
Divider label --- one more line
Emphasize (bold) __ two_
Expansion label :: Expansion name
```
### Tag syntax
Title tag #
For the title, add a pound sign (#) in front of a word or phrase.
The number of \# represents the level of the title.
For example   
\# XXXXX
   
Image tag img
To insert a picture is to add img before the link of the picture, for example img https://githubcom

Link label url
Insert the link is in the hyperlink syntax code: url link name

Code block label
Start \`\`\`, end \*\*\*.
Insert the code snippet between these two tags.
For example  
\`\`\`
#include<iostream>

using namespace std;

int main(){
cout<<"hello world";
return 0;
}

\*\*\*

Quote label \>
To create a quote, add a> symbol before the paragraph.
For example:    
```> hello world```

Dividing line label \---
To create a dividing line, you can enter ```---``` in a blank line

Emphasize label ___
If you want to bold a sentence or phrase, you can add ```___```;(_*3) before the phrase

Expand tags ::
If you want to add an extension to the page, add before the extension name::
For example:
```
:: pi-dashboard
```
All supported extensions are in expand_list.conf in conf under the Website folder.
### Step
### Firstly configure the EmakeFile file
Very simple, the syntax is below.
The main purpose is to set the entry of the original file and the storage directory of the generated file, as well as whether to open the extension, and the theme directory to be used (may be improved in the future).
### Secondly compile and run files
There will be binary files in the warehouse, but they may not be up to date.
So you can use the above method under LINUX and WINDOWS to compile.
### Thirdly run file
Enter at the command line
```./easyhtml```Run the executable file.
After that you can enter two commands
```emake``` Convert the files in the source directory (note: the file suffix is ​​.eh)
```quit``` Quit the program
## End
## About the 2021-12-29 update
Made some changes
The EMAKEFILE file is added first, which is intended to be able to complete the conversion of HTML in batches without having to select each time it is converted.
### These simple syntaxes also exist in the EMAKEFILE file
Note: No need to add file name suffix
1. Define variables
The data type of ```var``` is a string, which can be used to store file addresses, etc. Syntax ```var str```
The data type of ```int``` is a short integer number, which is mainly used to set the output html file name in batches ```int num```
2. for
Syntax ``` for i```
Decrease i times i
3. Static declares when using variables
```var str static str```
4. ```#INPUTFILE``` Enter the file address, do not need to be accurate to the file, just go to the upper directory.
``` #INPUTFILE var``` or ``` #INPUTFILE ../md```
5. ```#OUTPUTFILE``` output file address
``` #OUTPUTFILE var``` or ```#OUTPUTFILE ../html/test ```
6. The address of the theme selected by ```#THEME```, the syntax is the same as above.
7. ```#EXPAND``` Whether to open the expansion function Turn on ON Turn off OFF
8. ```//``` comment Usage: // space content
Secondly, the writing method of image labels has also been changed.
Change to the format of ```img picture link ```
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
## About the editor
This editor is currently a module. In this tool, it provides a preview function, input the corresponding label, that is, print out the corresponding html statement on the terminal.
Enter ``` wq``` to exit, save the sentence or phrase you entered too much.
Enter ```q``` to exit directly without saving, what you entered.
Delete and add functions will be added later
