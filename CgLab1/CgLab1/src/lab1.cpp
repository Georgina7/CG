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
        glColor3f(0, 0, 212);
        glVertex2f(-0.55f, 0.35f);
        glVertex2f(-0.55f, 0.25f);
        glVertex2f(-0.45f, 0.25f);
        glVertex2f(-0.45f, -0.35f);
        glVertex2f(0.45f, -0.35f);
        glVertex2f(0.45f, 0.25f);
        glVertex2f(0.55f, 0.25f);
        glVertex2f(0.55f, 0.35f);
 
        glEnd();

        //Semicircle  code
        float RADIUS = 0.1;
        float DEGREE_TO_RAD = 3.14 / 180;
        float CIRCLE_HEIGHT = 0.35;

        glBegin(GL_LINE_LOOP);
        //glVertex2f(0.5, 0.35);
        glColor3f(0, 0, 212);
        int M_IN_DEGREE = 180;
        int N_IN_DEGREE = 0;
        for (int nR = N_IN_DEGREE; nR <= M_IN_DEGREE; nR++)
        {
            float fY = sin((float)nR * DEGREE_TO_RAD) * CIRCLE_HEIGHT + 0.35;
            float fX = cos((float)nR * DEGREE_TO_RAD) * CIRCLE_HEIGHT;

            glVertex2f(fX, fY);
        }
 
        glEnd();

        //Door Rectangle
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 255, 0);
        glVertex2f(-0.1f, 0.15f);
        glVertex2f(-0.1f, -0.35f);
        glVertex2f(0.1f, -0.35f);
        glVertex2f(0.1f, 0.15f);
        glEnd();

        //Window 1
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 255, 0);
        glVertex2f(-0.4f, 0.15f);
        glVertex2f(-0.4f, -0.1f);
        glVertex2f(-0.2f, -0.1f);
        glVertex2f(-0.2f, 0.15f);
        //glColor3f(0.0f, 0.1f, 0.1f);
        glEnd();

        //Window 2
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 255, 0);
        glVertex2f(0.2f, 0.15);
        glVertex2f(0.2f, -0.1f);
        glVertex2f(0.4f, -0.1f);
        glVertex2f(0.4f, 0.15f);
        glEnd();

        //Window Bars 1
        //Vertical
        glBegin(GL_LINES);
        glColor3f(0, 0, 212);
        glVertex2f(-0.3f, 0.15f);
        glVertex2f(-0.3f, -0.1f);
        glEnd();
        //Horizontal
        glBegin(GL_LINES);
        glColor3f(0, 0, 212);
        glVertex2f(-0.4f, 0.025f);
        glVertex2f(-0.2f, 0.025f);
        glEnd();

        //Window Bars 2
        //Vertical
        glBegin(GL_LINES);
        glColor3f(0, 0, 212);
        glVertex2f(0.3f, 0.15f);
        glVertex2f(0.3f, -0.1f);
        glEnd();
        //Horizontal
        glBegin(GL_LINES);
        glColor3f(0, 0, 212);
        glVertex2f(0.4f, 0.025f);
        glVertex2f(0.2f, 0.025f);
        glEnd();
        

        //circle
        int i;
        float PI = 3.142;
        GLfloat x = 0.065f;
        GLfloat y = -0.1f;
        GLfloat radius = .015f;
        int triangleAmount = 40;
        GLfloat twicePi = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(61, 143, 174);
        glVertex2f(x, y);
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount)));

        }
        glEnd();

        //circle
        
        GLfloat k = 0.55f;
        GLfloat m = 0.75f;
        GLfloat rad = 0.2f;
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(k, m);
        int R = 255;
        int G = 201;
        int B = 0;
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(k + (rad * cos(i * twicePi / triangleAmount)),
                m + (rad * sin(i * twicePi / triangleAmount)));
            R -= 4;
            G -= 4;
            glColor3ub(R, G, B);
        }
        glEnd();

        //circle

        GLfloat l = 0.60f;
        GLfloat n = 0.80f;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0, 0, 0);
        glVertex2f(l, n);
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(l + (rad * cos(i * twicePi / triangleAmount)),
                n + (rad * sin(i * twicePi / triangleAmount)));
        }
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}