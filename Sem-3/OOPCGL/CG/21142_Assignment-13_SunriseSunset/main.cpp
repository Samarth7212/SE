#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

// Sky(blue): 0.35, 0.6, 0.9
// Sky(reddish orange): 0.81, 0.88, 0
// Sun(orange): 1, 0.53, 0
// Sun(yellow): 1, 1, 0

void init()
{
	glutInitWindowPosition(100, 50);			  // Window position set
	glutInitWindowSize(900, 500);				  // Window size set.
	glutCreateWindow("SunRise-SunSet Animation"); // Window created with given name
}

float ypos = 0; // Y position- To be used to change colour
int sunrise = 1;

//Initial colour values for sun and sky
float Suncolor = 0;
float skyR = 0.35;
float skyG = 0.6;
float skyB = 0.9;

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
{
	glColor3f(1, 1 + Suncolor, 0);
	int i;
	int triangleAmount = 35; //# of triangles used to draw circle

	// GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.1412;

	glBegin(GL_TRIANGLE_FAN);
	// glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();
	glFlush();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity(); // It will reset the coordinate system
	// Draw stuff on the frame buffer and then flush it on the screen

	// Sky
	glColor3f(skyR, skyG, skyB);
	glBegin(GL_POLYGON);
	glVertex2f(900, 500);
	glVertex2f(0, 500);
	glVertex2f(0, 0);
	glVertex2f(900, 0);
	glEnd();

	// Sun
	drawFilledCircle(450, ypos, 90);

	// Hills
	glColor3f(0.55, 0.37, 0);
	glBegin(GL_POLYGON);
	// Left triangle
	glVertex2f(240, 360);
	glVertex2f(0, 90);
	glVertex2f(0, 0);
	glVertex2f(400, 0);
	glEnd();
	glBegin(GL_POLYGON);
	// Right triangle
	glVertex2f(700, 365);
	glVertex2f(490, 0);
	glVertex2f(900, 0);
	glVertex2f(900, 70);

	glEnd();
	glBegin(GL_TRIANGLES);
	// Right triangle
	glVertex2f(450, 120);
	glVertex2f(370, 0);
	glVertex2f(570, 0);
	glEnd();
	glutSwapBuffers();
}

void Timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(500 / 60, Timer, 0);


	switch (sunrise)
	{
	case 1:
		if (ypos < 410)
		{
			ypos = ypos + 0.35;
		}
		else
		{
			sunrise = 0;
		}
		if (ypos > 360)
		{
			Suncolor = -0.47;
		}
		else
		{
			Suncolor = 0;
		}
		if (ypos > 370)
		{
			skyR = 0.81;
			skyG = 0.88;
			skyB = 0;
		}
		break;

	case 0:
		if (ypos > 0)
		{
			ypos = ypos - 0.35;
		}
		else
		{
			sunrise = 1;
		}
		if (ypos < 30)
		{
			skyR = 0.35;
			skyG = 0.6;
			skyB = 0.9;
		}
		break;
	}
}

void Reshape(int w, int h)
{
	glViewport(0, 0, 900, 500);//View port
	glMatrixMode(GL_PROJECTION);//Setting current matrix mode
	glLoadIdentity();//replacing the current matrix with the identity matrix.
	gluOrtho2D(0, 900, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	init();

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutTimerFunc(0, Timer, 0);
	glutMainLoop();
}
