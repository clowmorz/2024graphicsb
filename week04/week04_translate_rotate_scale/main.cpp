#include <GL/glut.h>
float teapotX=0.5,teapotY=0;///��k��
float angle=0;///���ਤ��
float s=0.3;///�@�}�l�O�@�����j�p
void display()
{
    glClearColor(1,1,0.9,1);///R,G,B,A
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�I��
    glColor3f(0,1,0);
    glPushMatrix();///�ƥ��x�}
        glTranslated(teapotX,teapotY,0);
        glRotated(angle++,0,0,1);
        glScalef(s,s,s);///�Y��s��
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();

}
void motion(int x,int y)
{
    s=1+(x-150)/150.0;///�|�ܤj�ܤp���ܼ�0~1~2
    display();///���e�e��
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04_translate_rotate_Scalef");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMotionFunc(motion);///���motion���ɭ�
      glutMainLoop();
}

