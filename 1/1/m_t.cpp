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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	//���汾��(Major)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	//�ΰ汾��(Minor)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //����GLFW����ʹ�õ��Ǻ���ģʽ(Core-profile)
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);		//�������û��������ڵĴ�С

	//����һ�����ڶ���
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//��ʼ��GLEW
	glewExperimental = GL_TRUE;		//GL_FALSE�Ļ����ܻ���ʹ��OpenGL�ĺ���ģʽʱ����һЩ����
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	//����OpenGL��Ⱦ���ڵĳߴ��С
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);		//ǰ�����������ƴ������½ǵ�λ�á��������͵��ĸ�����������Ⱦ���ڵĿ�Ⱥ͸߶ȣ����أ�

	//���ϻ���ͼ���ܹ������û�����
	while(!glfwWindowShouldClose(window))	//glfwWindowShouldClose����������ÿ��ѭ���Ŀ�ʼǰ���һ��GLFW�Ƿ�Ҫ���˳�������ǵĻ��ú�������true�ر�Ӧ�ó���
	{
		glfwPollEvents();	//glfwPollEvents���������û�д���ʲô�¼�������������롢����ƶ��ȣ���Ȼ����ö�Ӧ�Ļص�����������ͨ���ص������ֶ����ã�������һ������Ϸѭ���Ŀ�ʼ�����¼�������
		glfwSwapBuffers(window);	//glfwSwapBuffers�����ύ����ɫ���壨����һ��������GLFW����ÿһ��������ɫ�Ĵ󻺳壩������һ�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ��
	}

	glfwTerminate();//�ͷ�GLFW������ڴ�
    return 0;
}