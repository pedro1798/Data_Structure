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
//	if (!ptr1) return ptr2; //ptr1이 null이면 ptr2 리턴
//	if (!ptr2) return ptr1; //ptr2이 null이면 ptr1 리턴
//	/*neither list is empty, find end of first list*/ 
//	/* 두 리스트 모두 비어있지 않으면 첫번째 리스트의 끝을 찾기*/
//	for (temp = ptr1; temp->link; temp = temp->link);
//	/*link end of first to start of second*/
//	/*temp를 temp->link == null일 때 까지 뒤로 이동*/
//	temp->link = ptr2; //ptr1의 끝에 ptr2 붙이기
//}
//
//listNode* first; listPointer save; // first 주솟값 저장(출력 위해서)
//listPointer temp; int count = 0;
//
//void P1() {
//	fstream in("in.txt");
//	temp = (listPointer)malloc(sizeof(*temp)); //쓰레기값
//	save = temp; //처음 주소 저장
//	first = temp; // temp의 주소를 first에 넣기
//	first->link = NULL;
//	while (!in.eof()) {
//		::count++;
//		temp = (listPointer)malloc(sizeof(*temp)); //쓰레기값
//		in >> temp->data;
//		temp->link = NULL;
//		concatenate(first, temp); //first가 NULL이 아니어야함
//
//		for (int i = 0; i < ::count; i++) {
//			first = first->link; //first는 dummy임 (과제 제출하고 처리하기)
//			printf("%d ", first->data);
//		}
//		first = save; //first 포인터 save로 초기화
//		printf("\n"); //줄띄우기
//	} 
//}
//void P2() { // 15 20 10 1
//	listPointer dummy; listPointer insert;
//
//	dummy = first;
//	first = first->link;
//	free(dummy); //링크드리스트 first는 더이상 dummy 아님
//
//	insert = (listPointer)malloc(sizeof(*insert));
//	insert->data = -1;
//	insert->link = NULL; //삽입할 노드 생성
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
//	printf("2022117156 독어독문학과 박상준\n");
//	printf("문제 1: \n");  P1();
//	printf("문제 2: \n"); P2();
//}