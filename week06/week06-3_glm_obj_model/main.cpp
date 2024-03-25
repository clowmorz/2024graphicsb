#include <GL/glut.h>
#include "glm.h"///加的程式,使用glm的程式碼
GLMmodel * pmodel = NULL;///加的程式有顆指標指到模型檔
void drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/porsche.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    drawmodel();
    glutSwapBuffers();

}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

     glutCreateWindow("week06_lighting");
     glutDisplayFunc(display);
        glutMainLoop();
   glutMainLoop();
}
