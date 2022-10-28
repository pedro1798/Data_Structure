//#include <iostream>
//#include <fstream>
//#include <cstdio>
//
//using namespace std;
//
//typedef struct polyNode* polyPointer;
//typedef struct polyNode {
//	int coef;
//	int expon;
//	polyPointer link;
//};
//polyPointer a, b;
//
//int COMPARE(int a, int b)
//{
//	if (a > b) return 1; //a>b 이면 1 반환
//	else if (a < b) return -1; //a<b 이면 -1 반환
//	else return 0;	//a=b 이면 0 반환
//}
//
//void attach(int coef, int exp, polyPointer *ptr){
//	polyPointer temp;
//	temp = (polyPointer)malloc(sizeof(*temp));
//	//malloc은 힙메모리에서 공간 할당 받아 주소 주는 함수라고 생각하기
//	//그 공간 자체가 아닌 주소
//	temp -> coef = coef; //temp구조체에 값할당
//	temp -> expon = exp;
//	(*ptr)->link = temp; 
//	*ptr = temp;
//}
//
//polyPointer padd(polyPointer a, polyPointer b) {
//	
//	polyPointer c; polyPointer rear; polyPointer temp; int sum;
//
//	rear = (polyPointer)malloc(sizeof(*rear));
//	c = rear;
//	while (a && b) {
//		switch (COMPARE(a->expon, b->expon)) {
//		case -1: //a > b
//			attach(b->coef, b->expon, &rear);
//			b = b->link;
//			break;
//		case 0: //a < b
//			sum = a->coef + b->coef;
//			if (sum) attach(sum, a->expon, &rear); //sum이 0이 아니면 attach
//			a = a->link; b = b->link; break;
//		case 1: // a == b
//			attach(a->coef, a->expon, &rear);
//			a = a->link;
//		}
//	}
//	for (; a; a = a->link) attach(a->coef, a->expon, &rear);
//	for (; b; b = b->link) attach(b->coef, b->expon, &rear);
//	rear -> link = NULL;
//	temp = c; c = c -> link; free(temp);
//	return c;
//}
//
//void P1() {
//	fstream inA("a.txt"); int n; int coef; int expon; 
//	polyNode* node; polyPointer dummy;
//	// a 는 polyPointer
//	a = (polyPointer)malloc(sizeof(*a));
//
//	inA >> n;
//	node = a; 
//	//노드는 한칸씩 이동하며 temp를 받는다
//	for (int i = 0; i < n; i++) {
//		inA >> coef; inA >> expon;
//		attach(coef, expon, &node); // temp값을 node에 붙임
//	}
//	node->link = NULL; //구조체 끝부분 link는 NULL로 (NULL로 조건문 판단)
//	dummy = a;
//	//1. a에는 쓰레기값이 들어있다.
//	//2. dummy로 쓰레깃값을 참조하는 dummy 생성(dummy 없으면 free(dummy==쓰레깃값) 못함)
//	//3. a = a->link 해서 쓰레깃값 없는 리스트로 링크드리스트 시작하게 설정
//	a = a->link;
//	free(dummy);
////#################################################################################################
//	fstream inB("b.txt"); int n2; int coef2; int expon2;
//	
//	polyNode* node2;
//	b = (polyPointer)malloc(sizeof(*b));
//
//	inB >> n2;
//	node2 = b;
//	for (int i = 0; i < n2; i++) {
//		inB >> coef2; inB >> expon2;
//		attach(coef2, expon2, &node2);
//	}
//	node2->link = NULL;
//	dummy = b;
//	b = b->link;
//	free(dummy);
////######################################################################################################
//
//	polyPointer c;
//	c = padd(a, b);
//	
//	printf("독어독문학과 2022117156 박상준\n");
//
//	while (c != NULL) {
//		printf("%d %d ", c->coef, c->expon);
//		c = c->link;
//	}
//}
//
//int main(){
//	P1();
//}