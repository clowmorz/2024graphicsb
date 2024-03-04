#include <GL/glut.h>
#include <stdio.h>
float teapotX=0,teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景
    glPushMatrix();/// 備份矩陣
    glTranslatef(teapotX,teapotY,0);///把座標移動
    glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();

}
void mouse (int button,int state,int x,int y)
{
    teapotX=(x-150)/150.0;
    teapotY=-(y-150)/150.0;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

     glutCreateWindow("week03_mouse_glTranslatef");

     glutDisplayFunc(display);
     glutMouseFunc(mouse);///這一行，設定mouse函式

      glutMainLoop();
}
