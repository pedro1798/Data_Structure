//#include <iostream>
//#include <fstream>
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX_TERMS 101
//using namespace std;
//
//typedef struct {
//	int col;
//	int row;
//	int value;
//} term;
//
//term a[MAX_TERMS]; term b[MAX_TERMS];
//
//void fastTranspose(term a[], term b[], int max_col) {
//	int* rowTerms;
//	int* startingPos;
//	rowTerms = (int*)malloc(sizeof(int*) * max_col);
//	startingPos = (int*)malloc(sizeof(int*) * max_col);
//	int i, j, numCols = a[0].col, numTerms = a[0].value;
//	//numCols: 행의 개수 numTerms: 항의 개수
//	b[0].row = numCols; b[0].col = a[0].row;
//	b[0].value = numTerms; //a = n x m 이면 b = m x n
//	if (numTerms > 0) { // 항이 0개가 아니면
//		for (i = 0; i < numCols; i++)
//			rowTerms[i] = 0; // rowTerms 0으로 초기화
//		for (i = 1; i <= numTerms; i++)//1부터 8까지 반복
//			rowTerms[a[i].col]++;
//		startingPos[0] = 1;
//		for (i = 1; i < numCols; i++)
//			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
//		//startingPos 초기화
//		for (i = 1; i <= numTerms; i++) { //matrix transposing
//			j = startingPos[a[i].col]++;
//			b[j].row = a[i].col; b[j].col = a[i].row; b[j].value = a[i].value;
//		}
//	}
//}
//;
//int main() {
//	fstream fp("m.txt");
//	int r, c, val = 0, count = 0, max = 0;; //count는 val의 개수
//	fp >> r; fp >> c;
//
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			fp >> val;
//			if (val != 0) { //읽은값을 파일에 저장
//				++count; //value의 개수
//				a[count].row = i; a[count].col = j; a[count].value = val;
//			} // i행 j열 value 
//		}
//	}
//	/*   r  c  v
//	a[0] 10 12 4
//	a[1] 0  0  5
//	a[2] 0  1  2
//	a[3] 1  0  7
//	a[4] 9  8  1 */
//	a[0].row = r; a[0].col = c; a[0].value = count; //구조체 0번 인덱스 할당함
//	//a.txt 값 읽기 끝
//	for (int i = 1; i <= count; i++) {
//		if (a[i].col > max) {
//			max = a[i].col;
//		}
//	}
//	fastTranspose(a, b, max);
//	ofstream HzWriteFile("out.txt");
//	for (int i = 0; i < count + 1; i++) {
//		printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
//	}
//	for (int i = 0; i < count + 1; i++) {
//		HzWriteFile << b[i].row << " " << b[i].col << " " << b[i].value << "\n";
//	}
//}
