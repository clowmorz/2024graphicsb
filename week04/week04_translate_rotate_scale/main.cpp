#include <GL/glut.h>
float teapotX=0.5,teapotY=0;///放右邊
float angle=0;///旋轉角度
float s=0.3;///一開始是一倍的大小
void display()
{
    glClearColor(1,1,0.9,1);///R,G,B,A
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景
    glColor3f(0,1,0);
    glPushMatrix();///備份矩陣
        glTranslated(teapotX,teapotY,0);
        glRotated(angle++,0,0,1);
        glScalef(s,s,s);///縮放s倍
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();

}
void motion(int x,int y)
{
    s=1+(x-150)/150.0;///會變大變小的變數0~1~2
    display();///重畫畫面
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04_translate_rotate_Scalef");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMotionFunc(motion);///拖動motion的時候
      glutMainLoop();
}

