#include <iostream>
#include <time.h>
#include <fstream>
#define MAX_COL 100
using namespace std;
//clock_t start, finish; double a;
int count = 0;
void recur(int n) {
	if (n % 2 == 1) { //n�� Ȧ���� ��
		if (n == 1 || n == 0) {
			printf("%d", ::count + 1);
			return;
		}
		n /= 2;
		::count++;
		recur(n);
	}
	if (n % 2 == 0) {
		if (n == 1 || n == 0) {
			printf("%d", ::count);
			return;
		}
		n /= 2;
		::count++;
		recur(n);
	}
}
void P1() {
	fstream in1("in1.txt"); 
	int n = 0;
	in1 >> n;
	printf("���� 1: ������� ����.\n");
	//recur(n);
}
//##################################################################################
typedef struct term{
	int row;
	int col;
	int value;
};
term a[MAX_COL]; term b[MAX_COL];
void fastTranspose(term a[], term b[]) {
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols; b[0].col = a[0].row;
	b[0].value = numTerms; //a[] = m x n, b[] = n x m, 0���ε��� �Ҵ�
	if (numTerms > 0) { //���� �����Ѵٸ� 
		for (i = 0; i < numCols; i++) {
			rowTerms[i] = 0; //rowTerms[] 0���� �ʱ�ȭ
		}
		for (i = 1; i <= numTerms; i++) {
			rowTerms[a[i].col]++; //rowTerms �� �ֱ�
		}
		startingPos[0] = 1; 
		for (i = 1; i < numCols; i++) { //Į������ 12���ϱ� 11����
			//����������
			startingPos[i] = startingPos[i-1] + rowTerms[i-1]; //�������ڵ�
		}
		for (i = 1; i <= numTerms; i++) {//���ǰ��� 3�� 1 2 3
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col; b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}
int** make2Array(int rows, int cols) {
	int** x, i;
	x= (int**)malloc(rows * sizeof(*x));
	for (i = 0; i < rows; i++) {
		x[i] = (int*)malloc(cols * sizeof(**x));
	}
	return x;
}
void P2() {
	int rows, cols; int** m;
	fstream in2("in2.txt");
	in2 >> rows; in2 >> cols;
	m = make2Array(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			in2 >> m[i][j]; //m�� ��Ʈ���� �Ҵ�
		}
	}
	int aIndexCount = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (m[i][j] != 0) {
				++aIndexCount;
				a[aIndexCount].row = i; a[aIndexCount].col = j; 
				a[aIndexCount].value = m[i][j];
			}
		}
	}
	a[0].row = rows; a[0].col = cols; a[0].value = aIndexCount;
	/*
	for (int i = 0; i <= aIndexCount; i++) {
		printf("%d %d %d", a[i].row, a[i].col, a[i].value);
		printf("\n"); �ߵ���
	}*/
	fastTranspose(a, b);
	printf("���� 2:\n");
	for (int i = 0; i <= aIndexCount; i++) {
		printf("%d %d %d", b[i].row, b[i].col, b[i].value);
		printf("\n");
	}
}
//##################################################################################
typedef struct listNode *listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};
void P3() {
	fstream in3("in3.txt");
	listPointer L; listPointer dummy;listPointer temp;
	L = (listPointer)malloc(sizeof(*L));
	dummy = L;
	while (!in3.eof()) {
		temp = (listPointer)malloc(sizeof(*temp));
		in3 >> temp->data;
		L->link = temp;
		L = temp;
	}
	L->link = NULL;

	L = dummy;
	L = L->link;
	free(dummy);
	printf("���� 3:\n");
	for (;L ;L= L->link) {
		printf("%d ", L->data);
	}
	printf("\n");
}
//##################################################################################
void P4() {
	printf("���� 4: ������� ����.\n");
}
//##################################################################################
int main() {
	printf("�к�: ������а� �й�: 2022117156 �̸�: �ڻ���\n");
	P1();
	P2();
	P3();
	P4();
}
