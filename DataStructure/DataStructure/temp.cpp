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
//	if (a > b) return 1; //a>b �̸� 1 ��ȯ
//	else if (a < b) return -1; //a<b �̸� -1 ��ȯ
//	else return 0;	//a=b �̸� 0 ��ȯ
//}
//
//void attach(int coef, int exp, polyPointer *ptr){
//	polyPointer temp;
//	temp = (polyPointer)malloc(sizeof(*temp));
//	//malloc�� ���޸𸮿��� ���� �Ҵ� �޾� �ּ� �ִ� �Լ���� �����ϱ�
//	//�� ���� ��ü�� �ƴ� �ּ�
//	temp -> coef = coef; //temp����ü�� ���Ҵ�
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
//			if (sum) attach(sum, a->expon, &rear); //sum�� 0�� �ƴϸ� attach
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
//	// a �� polyPointer
//	a = (polyPointer)malloc(sizeof(*a));
//
//	inA >> n;
//	node = a; 
//	//���� ��ĭ�� �̵��ϸ� temp�� �޴´�
//	for (int i = 0; i < n; i++) {
//		inA >> coef; inA >> expon;
//		attach(coef, expon, &node); // temp���� node�� ����
//	}
//	node->link = NULL; //����ü ���κ� link�� NULL�� (NULL�� ���ǹ� �Ǵ�)
//	dummy = a;
//	//1. a���� �����Ⱚ�� ����ִ�.
//	//2. dummy�� �����갪�� �����ϴ� dummy ����(dummy ������ free(dummy==�����갪) ����)
//	//3. a = a->link �ؼ� �����갪 ���� ����Ʈ�� ��ũ�帮��Ʈ �����ϰ� ����
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
//	printf("������а� 2022117156 �ڻ���\n");
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