
 #define GLAD_GL_IMPLEMENTATION
 #include <glad/gl.h>
 #define GLFW_INCLUDE_NONE
 #include <GLFW/glfw3.h>


 #include <stdlib.h>
 #include <stddef.h>
 #include <stdio.h>


 static void error_callback(int error, const char* description)
 {
	 fprintf(stderr, "Error: %s\n", description);
 }

 static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
 {
	 if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		 glfwSetWindowShouldClose(window, GLFW_TRUE);
 }

 int main(void)
 {
	 glfwSetErrorCallback(error_callback);

	 if (!glfwInit())
		 exit(EXIT_FAILURE);

	 glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	 glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	 glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	 GLFWwindow* window = glfwCreateWindow(640, 480, "Sample Program", NULL, NULL);
	 if (!window)
	 {
		 glfwTerminate();
		 exit(EXIT_FAILURE);
	 }

	 glfwSetKeyCallback(window, key_callback);

	 glfwMakeContextCurrent(window);
	 gladLoadGL(glfwGetProcAddress);
	 glfwSwapInterval(1);



	 while (!glfwWindowShouldClose(window))
	 {
		 glfwSwapBuffers(window);
		 glfwPollEvents();
	 }

	 glfwDestroyWindow(window);

	 glfwTerminate();
	 exit(EXIT_SUCCESS);
 }
