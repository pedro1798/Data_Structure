//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int pattern(int** s, int* keyArr, int rows, int cols, int keys) {
//	int zero = 0, a, b;
//	for (int i = 0; i < rows; i++) {
//		10x10 2���� �迭�� Ű�� ������ 3���� cols[7] ������ �б�
//		for (int j = 0; j <= cols - keys; j++) {
//			for (int k = j; k < j + keys; k++) {
//				m �迭�� ����� Ű�� cols�� ��Ҹ� ��
//				if (s[i][k] == keyArr[zero]) {
//					zero++; // ���� ���ٸ� ��� ��
//				}
//				if (zero == keys) { //Ű�� �� ã����
//					printf("(%d, %d)", i, j); //Ű�� �����ϴ� �ε��� ���
//					return 0;
//				}
//			}
//			zero = 0; //���� �ٸ���� zero �ʱ�ȭ
//		}
//	}
//	if (zero < keys) {
//		printf("(-1, -1)");
//	}//Ű�� �߰ߵ��� ������ (-1, -1) ���
//}
//int main() {
//	fstream in("in.txt"); fstream key("key.txt");
//
//	int rows = 0, cols = 0; int keys = 0; int* keyArr;
//	in >> rows; in >> cols;
//
//	int** s; //2���� �迭 ������
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
