#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>

#define PI acos(-1)
GLdouble speed=0;
GLfloat i = 0.0f;
GLfloat j = 0.0f;
GLfloat k = 0.0f;GLfloat l = 0.0f;
GLdouble c1=0.0;GLdouble c2=0.0;
GLboolean right = true;
GLboolean stop = false;
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void circle(GLfloat x, GLfloat y, GLfloat radius);
void drawCircle(GLdouble x, GLdouble y, GLfloat r, GLint steps);
void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void Timer(int value) {
	glutTimerFunc(30, Timer, 0);
	glutPostRedisplay();
}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
        //do something here
            //glLoadIdentity();


        break;
        case GLUT_KEY_DOWN:

        break;
        case GLUT_KEY_RIGHT:
            //glLoadIdentity();
            stop = true;
        break;
        case GLUT_KEY_LEFT:
            //glLoadIdentity();
            stop = false;
        break;
    }
    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON)
    {

        right=false;

    }
    if (button == GLUT_LEFT_BUTTON)
    {

        right=true;

    }
	glutPostRedisplay();
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}

void drawYacht(GLfloat x, GLfloat y, GLfloat z)
{
    glLoadIdentity();//Reset the current matrix

    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(33,33,33);
    glVertex2f(.2,-.1);
    glVertex2f(0,0);
    glVertex2f(1.3,0);
    glVertex2f(1.4,-.1);
    glEnd();
    //tail
    glBegin(GL_QUADS);
    glColor3ub(33,33,33);
    glVertex2f(1.3,-.1);
    glVertex2f(1.3,-0.05);
    glVertex2f(1.45,-0.05);
    glVertex2f(1.5,-.1);
    glEnd();
    //high
    glBegin(GL_QUADS);
    glColor3ub(37, 51, 55);
    glVertex2f(.3,0);
    glVertex2f(.55,.19);
    glVertex2f(.85,.19);
    glVertex2f(1.1,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(28, 124, 151);
    glVertex2f(.49,0.12);
    glVertex2f(.55,.17);
    glVertex2f(.83,.17);
    glVertex2f(.9,0.12);
    glEnd();

    //midhigh
    glBegin(GL_QUADS);
    glColor3ub(29, 47, 52);
    glVertex2f(.2,0);
    glVertex2f(.35,.1);
    glVertex2f(1.05,.1);
    glVertex2f(1.2,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(28, 124, 151);
    glVertex2f(.26,0.02);
    glVertex2f(.35,.08);
    glVertex2f(1.03,.08);
    glVertex2f(1.18,0.02);
    glEnd();


    //backmid
    glBegin(GL_QUADS);
    glColor3ub(33,33,33);
    glVertex2f(.7,0);
    glVertex2f(.8,.1);
    glVertex2f(1.15,.1);
    glVertex2f(1.35,-0.1);
    glEnd();

    glPopMatrix();
}

void display() {
    glClearColor(0.941, 0.866, 0.8, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glMatrixMode(GL_MODELVIEW);

	//sun
    glColor3ub(253,216,53);
    drawCircle(-0.1,0.15,.15,100);
    glColor3ub(255,179,0);
    drawCircle(-0.1,0.15,.13,100);
	glColor3ub(251,140,0);
    drawCircle(-0.1,0.15,.11,100);

    //clouds

    //clouds1
    glColor3ub(84,110,122);
    drawCircle(c1-0.6,.8,.12,100);
    drawCircle(c1-0.5,.8,.12,100);
    glColor3ub(96,125,139);
    drawCircle(c1-0.7,.8,.09,100);
    drawCircle(c1-0.6,.85,.12,100);

    //clouds2
    glColor3ub(96,125,139);
    drawCircle(c2+0.6,.6,.12,100);
    drawCircle(c2+0.5,.6,.09,100);
    glColor3ub(84,110,122);
    drawCircle(c2+0.7,.6,.09,100);
    drawCircle(c2+0.6,.65,.12,100);

//mountain1
    glBegin(GL_TRIANGLES);
    glColor3ub(85,139,47);
    glVertex2f(-.75,-.1);
    glVertex2f(-.4,.2);
    glVertex2f(.3,-.1);
    glEnd();
 //mountain2
    glBegin(GL_TRIANGLES);
    glColor3ub(56,142,60);
    glVertex2f(.3,-.1);
    glVertex2f(.6,.25);
    glVertex2f(1,-.1);
    glEnd();
//mountain3
    glBegin(GL_TRIANGLES);
    glColor3ub(46,125,50);
    glVertex2f(.6,-.1);
    glVertex2f(.8,.2);
    glVertex2f(1.3,-.1);
    glEnd();

    //mountain4
    glBegin(GL_TRIANGLES);
    glColor3ub(76,175,80);
    glVertex2f(-1.6,-.1);
    glVertex2f(-.75,.25);
    glVertex2f(0,-.1);
    glEnd();

    //mountain5
    glBegin(GL_TRIANGLES);
    glColor3ub(51,105,30);
    glVertex2f(-.2,-.1);
    glVertex2f(0.12,.22);
    glVertex2f(0.6,-.1);
    glEnd();
//mountain6
    glBegin(GL_TRIANGLES);
    glColor3ub(27,94,32);
    glVertex2f(0,-.1);
    glVertex2f(0.3,.24);
    glVertex2f(0.9,-.1);
    glEnd();

    //windmill-1
    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(-.62,-.1);
    glVertex2f(-.61,.2);
    glVertex2f(-.6,-.1);
    glEnd();

    drawCircle(-.61,.15,0.02,100);

    //windmill-2
    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(.3,-.1);
    glVertex2f(.31,.2);
    glVertex2f(.32,-.1);
    glEnd();
    drawCircle(.31,.15,0.02,100);
    //windmill-3
    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(0.7,-.1);
    glVertex2f(0.71,.2);
    glVertex2f(0.72,-.1);
    glEnd();
    drawCircle(.71,.15,0.02,100);
    //road
    glBegin(GL_QUADS);
    glColor3ub(128,222,234);
    glVertex2f(-2,-2);
    glVertex2f(-2,-.1);
    glVertex2f(2,-.1);
    glVertex2f(2,-2);
    glEnd();






    glLoadIdentity();//Reset the current matrix

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glTranslatef(-0.61f,0.15f,1.0f);
    glRotatef(i,0.0,0.0,1.0);
//w-1
    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(-0.01f, 0.0f);
    glVertex2f( 0.0f, 0.1f);
    glVertex2f( 0.01f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(-0.02f, 0.0f);
    glVertex2f( -0.09f, -0.05f);
    glVertex2f( 0.02f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(-0.02f, 0.0f);
    glVertex2f( 0.09f, -0.05f);
    glVertex2f( 0.02f, 0.0f);
    glEnd();
    glPopMatrix();

//w-2
    glLoadIdentity();//Reset the current matrix

    glPushMatrix();
    glTranslatef(0.31f,0.15f,1.0f);
    glRotatef(k,0.0,0.0,1.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(-0.01f, 0.0f);
    glVertex2f( 0.0f, 0.1f);
    glVertex2f( 0.01f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(-0.02f, 0.0f);
    glVertex2f( -0.09f, -0.05f);
    glVertex2f( 0.02f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(-0.02f, 0.0f);
    glVertex2f( 0.09f, -0.05f);
    glVertex2f( 0.02f, 0.0f);
    glEnd();

    glPopMatrix();//while glPopMatrix pops the top matrix off the stack

    //w-3
    glLoadIdentity();//Reset the current matrix

    glPushMatrix();
    glTranslatef(0.71f,0.15f,1.0f);
    glRotatef(l,0.0,0.0,1.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(-0.01f, 0.0f);
    glVertex2f( 0.0f, 0.1f);
    glVertex2f( 0.01f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(-0.02f, 0.0f);
    glVertex2f( -0.09f, -0.05f);
    glVertex2f( 0.02f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(38,50,56);
    glVertex2f(-0.02f, 0.0f);
    glVertex2f( 0.09f, -0.05f);
    glVertex2f( 0.02f, 0.0f);
    glEnd();

    glPopMatrix();

    drawYacht(speed-.6,-.3,0);

    if(!stop)
    {
       speed-=0.00001f;
        if(speed<=-2.0)
        {
            speed=-.4f;
        }
    }
    else if(stop)
    {
        speed = 0;
    }

    i+=0.07f;
    j+=1.0f;
    k+=0.1f;
    l+=0.03f;
	//cout<<x;
	//glFlush();  // Render now
	//glFlush();  // Render now

    if(!right)
    {
        c1+=0.0001;
        c2+=0.0001;
    }
    if(right)
    {
        c1-=0.0001;
        c2-=0.0001;
    }
	if(c1>1.00)
    {
        c1=-1.00;
    }
	if(c2>1.00)
    {
        c2=-.5;
    }
    if(c1<-1.00)
    {
        c1=-1.00;
    }
	if(c2<-1.00)
    {
        c2=-.5;
    }

	glutSwapBuffers();

    // Render now
	//glFlush();  // Render now
}

void drawCircle(GLdouble x, GLdouble y, GLfloat r, GLint steps)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    GLfloat angle;
    for(GLint i=0;i<=steps;++i)
    {
        angle = i *2.0f *PI / steps ;
        glVertex2f(cos(angle)*r+x,sin(angle)*r+y);

    }
    glEnd();
}



/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(800, 800);                // Initialize GLUT
	glutCreateWindow("OpenGL Landscape "); // Create a window with the given title
	   // Set the window's initial width & height
	glutDisplayFunc(display);
	initGL();
    glutIdleFunc(Idle); // Register display callback handler for window re-paint
    glutReshapeFunc(reshape);
    glutSpecialFunc(SpecialInput);
    //glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
