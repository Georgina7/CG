#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
using namespace std;

int main(void)
{
    GLFWwindow* window;
    int HEIGHT = 600;
    int WIDTH = 600;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WIDTH, HEIGHT, "Polygons Test", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //Rectangle code
        glBegin(GL_LINE_LOOP);
        glVertex2f(-0.55f, 0.35f);
        glVertex2f(-0.55f, 0.25f);
        glVertex2f(-0.45f, 0.25f);
        glVertex2f(-0.45f, -0.35f);
        glVertex2f(0.45f, -0.35f);
        glVertex2f(0.45f, 0.25f);
        glVertex2f(0.55f, 0.25f);
        glVertex2f(0.55f, 0.35f);
        glColor3f(1, 1, 1);
        glColor3f(255, 255, 255);
        glEnd();

        //Semicircle  code
        float RADIUS = 0.1;
        float DEGREE_TO_RAD = 3.14 / 180;
        float CIRCLE_HEIGHT = 0.35;

        glBegin(GL_LINE_LOOP);
        //glVertex2f(0.5, 0.35);
        int M_IN_DEGREE = 180;
        int N_IN_DEGREE = 0;
        for (int nR = N_IN_DEGREE; nR <= M_IN_DEGREE; nR++)
        {
            float fY = sin((float)nR * DEGREE_TO_RAD) * CIRCLE_HEIGHT + 0.35;
            float fX = cos((float)nR * DEGREE_TO_RAD) * CIRCLE_HEIGHT;

            glVertex2f(fX, fY);
        }
        glColor3f(1, 1, 1);

        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}