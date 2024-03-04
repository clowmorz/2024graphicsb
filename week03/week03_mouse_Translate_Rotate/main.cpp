#include <GL/glut.h>
#include <stdio.h>
float teapotX=0,teapotY=0;
float angle=0;///���ਤ��
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��
    glPushMatrix();/// �ƥ��x�}
    glTranslatef(teapotX,teapotY,0);///��y�в���
    glRotatef(angle,0,0,1);///z�b
    glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();

}
int method =1;///1:���� 2:����
int oldX=0,oldY=0;
void mouse (int button,int state,int x,int y)
{
    ///teapotX=(x-150)/150.0;
    ///teapotY=-(y-150)/150.0;
    oldX=x;
    oldY=y;
}
void motion(int x,int y)
{
    if(method==1) {
            angle += x-oldX;
    }else if(method==2){
        teapotX += (x-oldX)/150.0;
        teapotY -= (y-oldY)/150.0;
    }
    oldX=x;
    oldY=y;
    display();

}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='e') method=1;///����rotate
    if(key=='w') method=2;///����translate
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

     glutCreateWindow("week03_mouse_glTranslatef");

     glutDisplayFunc(display);
     glutMouseFunc(mouse);///�o�@��A�]�wmouse�禡
     glutMotionFunc(motion);///�]�wmotion��motion�ʧ@
     glutKeyboardFunc(keyboard);

      glutMainLoop();
}