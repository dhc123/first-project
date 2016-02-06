// first-project.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <GL/glut.h>//VC6.0��ͷ�ļ�Ϊ#include <glut.h>
#include <math.h>
const float n = 0.0005;//ȷ��������
//��ʼ���ڵ�
const GLfloat X_pos[4] = { 0.0f,0.5f,0.4f,0.0f };
const GLfloat Y_pos[4] = { 0.5f,0.75f,0.2f,-0.5f };
//����de Casteljau�㷨���������ϵ������
float bezierX(float t)
{
	if (t < 0 || t>1)return 0.0f;//�ж�t��������[0,1]��
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
	//���ƿ��ƶ����	
	int i;
	float j;
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < 4; i++)
		glVertex2f(X_pos[i], Y_pos[i]);	
	for (i = 0; i < 4; i++)
	    glVertex2f(-X_pos[i], Y_pos[i]);
	glEnd;
	//����Bezier����
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

	glutCreateWindow("Bezier����");

	glutDisplayFunc(&myDisplay);

	glutMainLoop();

	return 0;

}

