// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	//主版本号(Major)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	//次版本号(Minor)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //告诉GLFW我们使用的是核心模式(Core-profile)
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);		//不允许用户调整窗口的大小

	//创建一个窗口对象
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//初始化GLEW
	glewExperimental = GL_TRUE;		//GL_FALSE的话可能会在使用OpenGL的核心模式时出现一些问题
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	//告诉OpenGL渲染窗口的尺寸大小
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);		//前两个参数控制窗口左下角的位置。第三个和第四个参数控制渲染窗口的宽度和高度（像素）

	//不断绘制图像并能够接受用户输入
	while(!glfwWindowShouldClose(window))	//glfwWindowShouldClose函数在我们每次循环的开始前检查一次GLFW是否被要求退出，如果是的话该函数返回true关闭应用程序
	{
		glfwPollEvents();	//glfwPollEvents函数检查有没有触发什么事件（比如键盘输入、鼠标移动等），然后调用对应的回调函数（可以通过回调方法手动设置）。我们一般在游戏循环的开始调用事件处理函数
		glfwSwapBuffers(window);	//glfwSwapBuffers函数会交换颜色缓冲（它是一个储存着GLFW窗口每一个像素颜色的大缓冲）它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上
	}

	glfwTerminate();//释放GLFW分配的内存
    return 0;
}