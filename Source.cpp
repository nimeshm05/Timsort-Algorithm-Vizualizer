#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 520
#define run 32

int k = 0;

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

int min = 0, count = 0, finished = 0;
int sorttype = 0, inptype = 0;
void drawlines();

void delay() {
	int i = 999999;
	while (i--);
}

void merge(int l, int m, int r) {
	int i = l, j = m + 1, k = l;
	while (i <= m && j <= r) {
		if (sortln[i].len <= sortln[j].len)
		{
			temp[k].c.r = sortln[i].c.r;
			temp[k].c.g = sortln[i].c.g;
			temp[k].c.b = sortln[i].c.b;
			temp[k].len = sortln[i].len;
			i++; k++;
		}
		else
		{
			temp[k].c.r = sortln[j].c.r;
			temp[k].c.g = sortln[j].c.g;
			temp[k].c.b = sortln[j].c.b;
			temp[k].len = sortln[j].len;
			j++; k++;
		}
	}
	while (i <= m) {
		temp[k].c.r = sortln[i].c.r;
		temp[k].c.g = sortln[i].c.g;
		temp[k].c.b = sortln[i].c.b;
		temp[k].len = sortln[i].len;
		i++; k++;
	}
	while (j <= r) {
		temp[k].c.r = sortln[j].c.r;
		temp[k].c.g = sortln[j].c.g;
		temp[k].c.b = sortln[j].c.b;
		temp[k].len = sortln[j].len;
		j++; k++;
	}
	for (i = l; i <= r; i++) {
		sortln[i].c.r = temp[i].c.r;
		sortln[i].c.g = temp[i].c.g;
		sortln[i].c.b = temp[i].c.b;
		sortln[i].len = temp[i].len;
		glClear(GL_COLOR_BUFFER_BIT);
		drawlines();
		glutSwapBuffers();
	}
}

void insertionSort(int beg, int end)
{
	int i, j;
	line temp;
	for (i = beg + 1; i <= end; i++)
	{
		temp = sortln[i];
		j = i - 1;
		while (j >= beg && sortln[j].len > temp.len)
		{
			sortln[j + 1] = sortln[j];
			j = j - 1;
			glClear(GL_COLOR_BUFFER_BIT);
			drawlines();
			glutSwapBuffers();
		}
		sortln[j + 1] = temp;
		glClear(GL_COLOR_BUFFER_BIT);
		drawlines();
		glutSwapBuffers();
	}
}

int minimum(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

void timSort(int n)
{
	int i, size, beg, mid, end;
	for (i = 0; i < n; i += run) {
		insertionSort(i, minimum((i + 31), (n - 1)));
		glFlush();
		glutSwapBuffers();
	}
	for (size = run; size < n; size = 2 * size)
	{
		for (beg = 0; beg < n; beg += 2 * size)
		{
			mid = beg + size - 1;
			end = minimum((beg + 2 * size - 1), (n - 1));
			merge(beg, mid, end);
			glFlush();
			glutSwapBuffers();
		}
	}
}

void drawlines() {
	int start = 50;
	for (int i = 0; i < max; i++) {
		glColor3f(sortln[i].c.r, sortln[i].c.g, sortln[i].c.b);
		glBegin(GL_LINES);
		glVertex2f(start, 10);
		glVertex2f(start, 10 + sortln[i].len);
		glEnd();
		start += 10;
	}
}

void front() {
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2i(220, 500);
	char msg1[] = "Timsort Algorithm Visualizer";
	for(int i = 0; i < strlen(msg1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);
	}

	glRasterPos2i(220, 400);
	char msg2[] = "PRESS ENTER TO SEE";
	for (int i = 0; i < strlen(msg1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg2[i]);
	}

	glRasterPos2i(220, 370);
	char msg3[] = "THE VISUALIZATION";
	for (int i = 0; i < strlen(msg1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg3[i]);
	}

	glRasterPos2i(120, 300);
	char msg4[] = "Team Members:";
	for (int i = 0; i < strlen(msg1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg4[i]);
	}

	glColor3f(0.0, 0.0, 1.0);
	glRasterPos2i(120, 250);
	char msg5[] = "Nimesh Mohanakrishnan";
	for (int i = 0; i < strlen(msg1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg5[i]);
	}

	glColor3f(0.0, 0.0, 1.0);
	glRasterPos2i(120, 230);
	char msg6[] = "4VV18CS093";
	for (int i = 0; i < strlen(msg1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg6[i]);
	}

	glColor3f(0.0, 0.0, 1.0);
	glRasterPos2i(120, 200);
	char msg7[] = "Mohammed Hussam Khatib";
	for (int i = 0; i < strlen(msg1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg7[i]);
	}

	glColor3f(0.0, 0.0, 1.0);
	glRasterPos2i(120, 180);
	char msg8[] = "4VV18CS079";
	for (int i = 0; i < strlen(msg1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg8[i]);
	}
}

void display() {
	if (k == 0) {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0, 600, 0, 600);
		front();
		glFlush();
		glutSwapBuffers();
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0, max * 10 + 100, 0, 550);
		glLineWidth(3);
		drawlines();
		timSort(sizeof(sortln) / sizeof(sortln[0]));
		glFlush();
		glutSwapBuffers();
	}
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 13)
		k = 1;
}

void randomize() {
	int a;
	for (int i = 0; i < max; i++) {
		ln[i].len = (rand() % 500);
		a = rand() % 7;
		ln[i].c = x[a];
	}
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	randomize();
	for (int i = 0; i < max; i++)
		sortln[i] = ln[i];
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Timsort Algorithm Vizualizer");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
