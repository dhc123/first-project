// first-project.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <GL/glut.h>//VC6.0中头文件为#include <glut.h>
#include <math.h>
const float n = 0.0005;//确定画点间隔
//初始化节点
const GLfloat X_pos[4] = { 0.0f,0.5f,0.4f,0.0f };
const GLfloat Y_pos[4] = { 0.5f,0.75f,0.2f,-0.5f };
//利用de Casteljau算法计算曲线上点的坐标
float bezierX(float t)
{
	if (t < 0 || t>1)return 0.0f;//判断t的输入在[0,1]间
	float X = t*t*t*X_pos[0] + 3 * t*t*(1 - t)*X_pos[1] + 3 * t*(1 - t)*(1 - t)*X_pos[2] + (1 - t)*(1 - t)*(1 - t)*X_pos[3];
	return X;
}

float bezierY(float t)
{
	if (t < 0 || t>1)return 0.0f;
	float Y = t*t*t*Y_pos[0] + 3 * t*t*(1 - t)*Y_pos[1] + 3 * t*(1 - t)*(1 - t)*Y_pos[2] + (1 - t)*(1 - t)*(1 - t)*Y_pos[3];
	return Y;
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//绘制控制多边形	
	int i;
	float j;
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < 4; i++)
		glVertex2f(X_pos[i], Y_pos[i]);	
	for (i = 0; i < 4; i++)
	    glVertex2f(-X_pos[i], Y_pos[i]);
	glEnd;
	//绘制Bezier曲线
	glColor3f(1.0f, 0.0f, 0.0f);	
	glBegin(GL_LINES);
	for (j = 0.0; j < 1.0; j = j + n)
	{
		glVertex2f(bezierX(j), bezierY(j));
		glVertex2f(-1 * bezierX(1-j), bezierY(1-j));
	}
	glEnd();	
	glFlush();
}

int main(int argc, char *argv[])

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowPosition(100, 100);

	glutInitWindowSize(1000, 1000);

	glutCreateWindow("Bezier曲线");

	glutDisplayFunc(&myDisplay);

	glutMainLoop();

	return 0;

}

