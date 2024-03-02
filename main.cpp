/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


static int slices = 16;
static int stacks = 16;
GLfloat objAngle = 0.0;
GLint angulo = 0;
GLint tam = 3;
GLint velocidade = 1;
/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double b = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,1,0);
    //SOL
    glPushMatrix();
        glTranslated(0,0,-60);
        glRotated(a,0,0,1);
        glRotated(-90,0,1,0);
        glutSolidSphere(tam,slices,stacks);
    glPopMatrix();

    glColor3d(0.431,0.380,0.265);
    //MERCURIO
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(angulo*1.59,0,0,1);
        glTranslated(4.5,0,0);
        glRotated(a,0,0,1);
        glRotated(-90,0,1,0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
    //VÊNUS
    glColor3d(0.631, 0.373, 0.094);
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(angulo*1.17,0,0,1);
        glTranslated(8,0,0);
        glRotated(a,0,0,1);
        glRotated(-90,0,1,0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    //TERRA
    glColor3d(0.149, 0.208 , 0.447);
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(angulo*1,0,0,1);
        glTranslated(12,0,0);
        glRotated(a,0,0,1);
        glRotated(-90,0,1,0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    //MARTE
    glColor3d(0.686, 0.294 , 0.122);
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(angulo*0.8,0,0,1);
        glTranslated(16,0,0);
        glRotated(a,0,0,1);
        glRotated(-90,0,1,0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    //JUPITER
    glColor3d(0.400, 0.204 , 0.078);
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(angulo*0.43,0,0,1);
        glTranslated(20,0,0);
        glRotated(a,0,0,1);
        glRotated(-90,0,1,0);
        glutSolidSphere(2,slices,stacks);
    glPopMatrix();
    //SATURNO
    glColor3d(0.784, 0.659 , 0.549);
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(angulo*0.32,0,0,1);
        glTranslated(24,0,0);
        glRotated(a,0,0,1);
        glRotated(-90,0,1,0);
        glutSolidSphere(2,slices,stacks);
    glPopMatrix();
    //anel
    glColor3d(0.984, 0.959 , 0.849);
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(angulo*0.32,0,0,1);
        glTranslated(24,0,0);
        glRotated(-60,-30,1,0);
        glScalef(1,1.5,0.1);
        glutSolidTorus(0.3,2.5,slices,stacks);
    glPopMatrix();
    //URANO
    glColor3d(0.816, 0.973 , 0.973);
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(angulo*0.22,0,0,1);
        glTranslated(28,0,0);
        glRotated(a,0,0,1);
        glRotated(-90,0,1,0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();
    //NETUNO
    glColor3d(0.188, 0.263 , 0.729);
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(angulo*0.18,0,0,1);
        glTranslated(32,0,0);
        glRotated(a,0,0,1);
        glRotated(-90,0,1,0);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    glColor3d(1,1,1);
    //orbita 1
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(0,-0,0,0);
        glutSolidTorus(0.01,4.5,slices,stacks);
    glPopMatrix();
    //orbita 2
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(0,-0,0,0);
        glutSolidTorus(0.01,8,slices,stacks);
    glPopMatrix();
    //orbita 3
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(0,-0,0,0);
        glutSolidTorus(0.01,12,slices,stacks);
    glPopMatrix();
    //orbita 4
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(0,-0,0,0);
        glutSolidTorus(0.01,16,slices,stacks);
    glPopMatrix();
    //orbita 5
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(0,-0,0,0);
        glutSolidTorus(0.01,20,slices,stacks);
    glPopMatrix();
    //orbita 6
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(0,-0,0,0);
        glutSolidTorus(0.01,24,slices,stacks);
    glPopMatrix();
    //orbita 7
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(0,-0,0,0);
        glutSolidTorus(0.01,28,slices,stacks);
    glPopMatrix();
    //orbita 8
    glPushMatrix();
        glTranslated(0,0,-50);
        glRotated(0,-0,0,0);
        glutSolidTorus(0.01,32,slices,stacks);
    glPopMatrix();




    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>2 && stacks>2)
            {
                slices--;
                stacks--;
            }
            break;

        case 'i':
            velocidade +=1;
            break;
        case 'o':
            velocidade -=1;
            break;
        case 'k':
            tam +=1;
            break;
        case 'l':
            tam -=1;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    angulo+=velocidade;
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 0.0f, 40.0f, -1.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,0);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
