# E-conversion-HTML generator using documentation    
# EASYHTML LANGUAGE   
[中文](https://github.com/SongZihui-sudo/e-Conversion-html-maker/blob/main/Use_documentation.md)  

[Release ](https://githubfast.com/SongZihui-sudo/e-Conversion-html-maker/releases)

illustrate:
Based on the v2.0 version, the v2.1 version has improved almost all markdown tags (some changes have been made)

The v2.0 version is currently a stable version, and there are no obvious bugs when translating tags. But currently does not support the use of overlay tags

The original version of v1.0 caused obvious bugs when translating code block tags and when using some symbols in the text. 

## Getting started installation  

1. Optional install git. 

### Linux 

command  

```
sudo git clone https://githubfast.com/SongZihui-sudo/e-Conversion-html-maker
```

### Windows  

```
git clone https://githubfast.com/SongZihui-sudo/e-Conversion-html-maker
```

2. After downloading the source code, you can use g++ to compile the source code for use, or you can directly open the binary program for use.   

## About language 

The keywords are as follows:
1. Title tag: #
2. Image tag: ‘![img]()’
3. Link label: url
4. Code block label: three `means start
   *** means the end
5. Emphasize the label: __
6. Quote tag:>
7. Dividing line label: ---
8. Theme tag #theme 

### illustrate 

#### Title tag

It is the same as the tags in the original Markdown. They are all n #, divided into n-level headings by the number.

Examples:
input ：### Hello everyone
output: <h3>Hello everyone</h3>


### Image tags

Same as the original Markdown.

Examples:

input: ![img](https://images.pexels.com)
   
output: ![img](https://images.pexels.com)

### Link label

It is slightly different from the original Markdown.

Original: [name](url)

Change to url URL (url) name

Examples:
input: url s-zh.space my website
output: <a href = "s-zh.space">my website</a>

### Code block label

Different from the original Markdown

Original three`
Now changed to two parts
Three `s represent the beginning of the code block, and three *s represent the end of the code block
Examples:

input
Three`
```
#include<iostream>
   int main(){
      cout<<"hello world";
      return 0;
}
***
Three*
output
<pre>
   #include<iostream>
   int main(){
   cout<<"hello world";
   return 0;
   }
</pre>
```
### Dividing line label
--- Three minus signs on a separate line
input ：---
output: </hr>

### Emphasize tags
__ Two_ spaces content
input: __ XXXXXX
output: <strong>XXXXXX</strong>

### Quote tags
'>' a>
input:> hello world
output: <blockquote>hello world</blockquote>

### Topic tags
#theme Theme name
The theme name is the name of the file in the theme folder    
## About the nested use of tags   

It's not perfect yet, uh, hahaha   
It only supports one-level nesting of title tags and link tags.     
Syntax: Title tag (multiple #) spaces Link tag (url) spaces URL (or directory) spaces name    
For example:   
'###' github url https://github.com Github       

Embed a hyperlink in the body:   
Syntax: body url URL (url) name   
example:     
welcome to visit url https://github.com github hahah.....   

## About the topic

This function is not perfect at present, hahaha. . . . . . .

## Some other instructions

When entering the file name in the program, there is no need to enter the suffix (don't forget, don't forget, don't forget).
# important
All sentences should be written in the top case, especially sentences with keywords. 
