//#include <iostream>
//#include <fstream>
//
//using namespace std;
//typedef struct listNode *listPointer; 
//
//typedef struct listNode{
//	int data;
//	listPointer link;
//};
//
//listPointer concatenate(listPointer ptr1, listPointer ptr2) {
//	listPointer temp;
//	if (!ptr1) return ptr2; //ptr1�� null�̸� ptr2 ����
//	if (!ptr2) return ptr1; //ptr2�� null�̸� ptr1 ����
//	/*neither list is empty, find end of first list*/ 
//	/* �� ����Ʈ ��� ������� ������ ù��° ����Ʈ�� ���� ã��*/
//	for (temp = ptr1; temp->link; temp = temp->link);
//	/*link end of first to start of second*/
//	/*temp�� temp->link == null�� �� ���� �ڷ� �̵�*/
//	temp->link = ptr2; //ptr1�� ���� ptr2 ���̱�
//}
//
//listNode* first; listPointer save; // first �ּڰ� ����(��� ���ؼ�)
//listPointer temp; int count = 0;
//
//void P1() {
//	fstream in("in.txt");
//	temp = (listPointer)malloc(sizeof(*temp)); //�����Ⱚ
//	save = temp; //ó�� �ּ� ����
//	first = temp; // temp�� �ּҸ� first�� �ֱ�
//	first->link = NULL;
//	while (!in.eof()) {
//		::count++;
//		temp = (listPointer)malloc(sizeof(*temp)); //�����Ⱚ
//		in >> temp->data;
//		temp->link = NULL;
//		concatenate(first, temp); //first�� NULL�� �ƴϾ����
//
//		for (int i = 0; i < ::count; i++) {
//			first = first->link; //first�� dummy�� (���� �����ϰ� ó���ϱ�)
//			printf("%d ", first->data);
//		}
//		first = save; //first ������ save�� �ʱ�ȭ
//		printf("\n"); //�ٶ���
//	} 
//}
//void P2() { // 15 20 10 1
//	listPointer dummy; listPointer insert;
//
//	dummy = first;
//	first = first->link;
//	free(dummy); //��ũ�帮��Ʈ first�� ���̻� dummy �ƴ�
//
//	insert = (listPointer)malloc(sizeof(*insert));
//	insert->data = -1;
//	insert->link = NULL; //������ ��� ����
//
//	listPointer tempFirst = first;
//
//	int max = 0; listPointer maxIndex = NULL;
//	for (int i = 0; i < ::count; i++) {
//		if (tempFirst->data > max) {
//			max = tempFirst->data;
//			maxIndex = tempFirst;
//			tempFirst = tempFirst->link;
//		}
//	}
//	insert->link = maxIndex->link;
//	maxIndex -> link = insert;
//
//	for (int i = 0; i < ::count+1; i++) {
//		printf("%d ", first->data);
//		first = first->link;
//	}
//}
//int main() {
//	printf("2022117156 ������а� �ڻ���\n");
//	printf("���� 1: \n");  P1();
//	printf("���� 2: \n"); P2();
//}