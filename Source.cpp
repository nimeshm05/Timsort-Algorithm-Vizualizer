#include<GL/glut.h>
#include<iostream>

#define max 64
#define run 32

struct color {
	int r, g, b;
};
color x[] = { {0,0,1},
{1,0,0},
{0,1,0},
{0,0,1},
{1,1,0},
{0,1,1},
{1,0,1} 
};

struct line {
	int len;
	color c;
};
line ln[max], sortln[max], temp[max];

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, max * 10 + 100, 0, 550);
	glLineWidth(3);
	drawlines();
	glutSwapBuffers();
	sort();
}

void randomize() {
	int a;
	for (int i = 0; i < max; i++) {
		ln[i].len = (rand() % 500);
		a = rand() % 7;
		ln[i].c = x[a];
	}
}

void choice(int ch) {
	sorttype = ch;
	display();
}

int main(int argc, char** argv) {
	randomize();
	for (int i = 0; i < max; i++)
		sortln[i] = ln[i];
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowPosition(250, 50);
	glutInitWindowSize(900, 600);
	glutCreateWindow("sort");
	glutCreateMenu(choice);
	glutAddMenuEntry("Merge sort", 0);
	glutAddMenuEntry("Insertion sort", 1);
	glutAddMenuEntry("Timsort", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
