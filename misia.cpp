#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>

GLfloat angle = 0.0;
GLfloat objAngle = 0.0;
GLfloat objPosX = 0.0;
GLfloat objPosY = 0.0;
GLfloat objScale = 1.0;
GLint slices = 50;  // Variável para controlar o número de slices
GLint stacks = 50;  // Variável para controlar o número de stacks

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat posicao[] = {1.0, 1.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, posicao);

    // Define a cor de fundo como vermelho
    glClearColor(1.0, 0.0, 0.0, 1.0);
}

void Camera() {
    GLfloat eyex = 5.0 * sin(angle);
    GLfloat eyez = 5.0 * cos(angle);
    gluLookAt(eyex, 0.0, eyez,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    Camera();

    glTranslatef(objPosX, objPosY, 0.0);
    glRotatef(objAngle, 0.0, 1.0, 0.0);
    glScalef(objScale, objScale, objScale);

    // Define a cor da esfera como vermelho
    glColor3f(1.0, 0.0, 0.0);

    // Desenha a esfera
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glutWireSphere(0.5, slices, stacks);  // Utiliza as variáveis slices e stacks
    glPopMatrix();

    // Define a cor da esfera interna como azul
    glColor3f(0.0, 0.0, 1.0);

    // Desenha a esfera interna
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.35);
    glRotatef(1.0, 1.0, 1.0, 0.0);
    glutWireTorus(0.1, 0.2, slices, stacks);  // Utiliza as variáveis slices e stacks
    glPopMatrix();

    // Desenha o segundo olho
    glPushMatrix();
    glTranslatef(1.5, 0.0, 0.0);  // Move o olho para a direita
    glRotatef(objAngle, 0.0, 1.0, 0.0);  // Aplica a mesma rotação que o primeiro olho
    glScalef(objScale, objScale, objScale);  // Aplica a mesma escala que o primeiro olho

    // Define a cor da esfera como vermelho
    glColor3f(1.0, 0.0, 0.0);

    // Desenha a esfera
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glutWireSphere(0.5, slices, stacks);  // Utiliza as variáveis slices e stacks
    glPopMatrix();

    // Define a cor da esfera interna como azul
    glColor3f(0.0, 0.0, 1.0);

    // Desenha a esfera interna
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.35);
    glRotatef(1.0, 1.0, 1.0, 0.0);
    glutWireTorus(0.1, 0.2, slices, stacks);  // Utiliza as variáveis slices e stacks
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            angle -= 0.1;
            break;
        case 'd':
            angle += 0.1;
            break;
        case 'j':
            objPosX -= 0.1;
            break;
        case 'l':
            objPosX += 0.1;
            break;
        case 'i':
            objPosY += 0.1;
            break;
        case 'k':
            objPosY -= 0.1;
            break;
        case 'q':
            objAngle += 5;
            break;
        case 'e':
            objAngle -= 5;
            break;
        case 'z':
            objScale += 0.1;
            break;
        case 'x':
            if (objScale > 0.1) objScale -= 0.1;
            break;
        case '+':
            slices++;  // Aumenta o número de slices
            stacks++;  // Aumenta o número de stacks
            break;
        case '-':
            if (slices > 3 && stacks > 3) {  // Garante que o número mínimo de slices e stacks seja 3
                slices--;  // Diminui o número de slices
                stacks--;  // Diminui o número de stacks
            }
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Trab CG");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
