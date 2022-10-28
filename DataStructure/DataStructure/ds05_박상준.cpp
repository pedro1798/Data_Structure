//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int pattern(int** s, int* keyArr, int rows, int cols, int keys) {
//	int zero = 0, a, b;
//	for (int i = 0; i < rows; i++) {
//		10x10 2차원 배열에 키의 개수가 3개면 cols[7] 까지만 읽기
//		for (int j = 0; j <= cols - keys; j++) {
//			for (int k = j; k < j + keys; k++) {
//				m 배열에 저장된 키와 cols의 요소를 비교
//				if (s[i][k] == keyArr[zero]) {
//					zero++; // 값이 같다면 계속 비교
//				}
//				if (zero == keys) { //키를 다 찾으면
//					printf("(%d, %d)", i, j); //키가 시작하는 인덱스 출력
//					return 0;
//				}
//			}
//			zero = 0; //값이 다른경우 zero 초기화
//		}
//	}
//	if (zero < keys) {
//		printf("(-1, -1)");
//	}//키가 발견되지 않으면 (-1, -1) 출력
//}
//int main() {
//	fstream in("in.txt"); fstream key("key.txt");
//
//	int rows = 0, cols = 0; int keys = 0; int* keyArr;
//	in >> rows; in >> cols;
//
//	int** s; //2차원 배열 포인터
//
//	s = (int**)malloc(sizeof(int*) * rows);
//
//	for (int i = 0; i < rows; i++) {
//		s[i] = (int*)malloc(sizeof(int) * cols);
//	}
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			in >> s[i][j];
//		}
//	}
//	key >> keys;
//	keyArr = (int*)malloc(sizeof(int) * keys);
//	for (int i = 0; i < keys; i++) {
//		key >> keyArr[i];
//	}
//	pattern(s, keyArr, rows, cols, keys);
//}
