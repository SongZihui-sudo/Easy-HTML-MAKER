# OpenGL学习 OpenGL环境配置
url https://learnopengl-cn.github.io/01%20Getting%20started/03%20Hello%20Window/ 一个很好的教程网站
## 关于OpenGL
OpenGL本身并不是一个API，它仅仅是一个由Khronos组织制定并维护的规范(Specification)。规范的具体实现最是由各个显卡厂商实现的。
img https://learnopengl-cn.github.io/img/01/01/opengl.jpg
## 配置OpenGL环境
### 配置GLFW 与 glad 
### GLFW
url https://github.com/glfw/glfw/releases/download/3.3.6/glfw-3.3.6.bin.WIN32.zip 32位下载链接
最好下载32位的版本，64位可能会有一些问题。
下载完后解压。
可以得到
img https://pcsdata.baidu.com/thumbnail/1d0cedd8am05d6f187d839ec9cefaa0b?fid=3125802318-16051585-130720250415078&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-JhZLMrUIFHP3cxvVnWHy94GADG8%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=87417812020389280&dp-callid=0&time=1641290400&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video
这些文件
IDE我选择了VS2017，可以任选
在VS中新建一个工程
img https://pcsdata.baidu.com/thumbnail/0bea20226me584162243a04536d6d6b8?fid=3125802318-16051585-335457992857205&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-spGRAoCl8wLLRyG9HEKtnXx6M3Q%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=87462279073030318&dp-callid=0&time=1641290400&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video
然后打开文件所在的文件夹
新建出include和lib两个文件夹
img https://pcsdata.baidu.com/thumbnail/b013491d2v8a0dc9f10eb1b5a3b6fff6?fid=3125802318-16051585-660741239604933&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-prgEJAGPRfJVXj%2BTbwJ%2FjDMwAms%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=87503499270988480&dp-callid=0&time=1641290400&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video
在解决方案下的属性进行配置
C/C++ 常规 填入include
img https://pcsdata.baidu.com/thumbnail/90a701f03te0d439e20d214d1a8c1186?fid=3125802318-16051585-763173784561248&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-J1516R%2FtroU47ksdPemHWbQVb7E%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=87538920679548815&dp-callid=0&time=1641290400&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video
链接器-常规-附加库目录 填入lib
img https://pcsdata.baidu.com/thumbnail/42565ecfaje87bcda01c688a8095a03c?fid=3125802318-16051585-141244025989518&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-6R804m3JzFwQ0vDpk6d%2BULP7Wz0%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=87575250792654745&dp-callid=0&time=1641290400&bus_no=26&size=c300_u300&quality=100&vuk=-&ft=video
链接器-输出-附加依赖项填入 glfw3.lib glfw3_mt.lib glfw3dll.lib
img https://pcsdata.baidu.com/thumbnail/b2152d2d5ke6fd6b4a5bec4e474ebafa?fid=3125802318-16051585-201489156442923&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-ACxsfoL5WFuPmmduyoj0E97gTX4%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=87611333065245032&dp-callid=0&time=1641290400&bus_no=26&size=c300_u300&quality=100&vuk=-&ft=video
到刚刚下载的glfw的文件夹下把include文件夹下的文件复制到项目文件夹下的include中。
在下载的glfw文件夹中找到相应VS版本的文件。
例如：VS2017就选择lib-vc2017
把那些文件都复制到项目文件夹的lib文件夹中。
### GLAD
url https://glad.dav1d.de/ glad的在线平台
Language 选择C/C++
Profile 选择core
API下gl 可以选择最新版本
之后是得到一个压缩包，下载下来。
得到这些文件。
img https://pcsdata.baidu.com/thumbnail/24efe4eaao5e21315f82b0341fda03df?fid=3125802318-16051585-837834949131180&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-y%2BNRg4Qxtd9vvuBnf1LeDScVomk%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=87769624150591533&dp-callid=0&time=1641290400&bus_no=26&size=c1600_u1600&quality=100&vuk=-&ft=video
把src中的glad.c放到项目文件夹与main.cpp在同一个目录下。
include下的文件（glad和KHR两个文件夹）复制到项目的include的文件夹下。
进行测试：
```


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glBindVertexArray(0); // no need to unbind it every time 
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
***
如果屏幕上出现一个三角形，则环境配置成功。
img https://pcsdata.baidu.com/thumbnail/3c8d29b13nde840a9b79f91b10968119?fid=3125802318-16051585-466801189607147&rt=pr&sign=FDTAER-yUdy3dSFZ0SVxtzShv1zcMqd-XBoKM4L9cnR10nR%2FCFSIt6hWuyc%3D&expires=2h&chkv=0&chkbd=0&chkpc=&dp-logid=87839613284686545&dp-callid=0&time=1641290400&bus_no=26&size=c300_u300&quality=100&vuk=-&ft=video