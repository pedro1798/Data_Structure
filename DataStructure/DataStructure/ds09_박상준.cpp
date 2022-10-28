//#include <iostream>
//#include <string>
//#include <format>
//#include <fstream>
//#include <cstdlib>
//
//using namespace std;
//
//typedef struct {
//	int key;
//}element;
//
//element* stack;
//int capacity = 1;
//int top = -1;
//int stackSize;
//void StackFull() {
//	stack = (element*)realloc(stack, 2 * capacity * sizeof(*stack));
//	capacity *= 2;
//}
//element StackEmpty() {
//	exit(EXIT_FAILURE);
//}
//element pop() {
//	if (top == -1)
//		return StackEmpty();
//	return stack[top--];
//}
//void push(int item) {
//	if (top >= capacity - 1)
//		StackFull();
//	stack[++top].key = item;
//}
//// 스택 반으로 줄이기
//// if (capacity / 2 == top + 1)
//
//void StackCutHalf() {
//	if (capacity / 2 == top + 1) {
//		stack = (element*)realloc(stack, capacity / 2 * sizeof(*stack));
//		capacity /= 2;
//	}
//}
//void P1() {
//	string c;
//	stack = (element*)malloc(sizeof(element) * capacity);
//	fstream in("in.txt");
//	while (!in.eof()) { //eof 전까지 반복수행 a 1 0 이렇게 들어감
//		in >> c;
//		if (c == "a") {
//			in >> c;
//			if (top == capacity - 1) {
//				StackFull();
//			}
//			int c2 = stoi(c); //str에서 int로 형변환
//			push(c2);
//		}
//		else if (c == "d") {
//			pop();
//			StackCutHalf();
//		}
//	}
//	for (int i = 0; i <= top; i++) {
//		printf("%d ", stack[i].key);
//	}
//}
//
//int cq[5]; string q; int front = 0; int rear = 0;
//
//void add(string a) {
//	if (front - (rear + 1) % 5 == 1)
//	{
//		cq[rear] = stoi(a);
//		printf("queue full ");
//		for (int i = front; i <= rear; i++) {
//			printf("%d ", cq[i]);
//		}
//		exit(EXIT_FAILURE);
//	}
//	if (rear > 5) {
//		rear = (rear + 1) / 6;
//	}
//	cq[rear++] = stoi(a);
//}
//int del() {
//	return cq[front++]; //FIFO
//}
//void P2() { //front, rear 초깃값 0
//	fstream in("in.txt");
//	while (!in.eof()) { // a 10 a 2 a 9 d d a 5
//		in >> q;
//		if (q == "a") {
//			in >> q;
//			add(q);
//		}
//		if (q == "d")
//		{
//			if (front == 0 && rear == 0) {
//			}
//			else {
//				del();
//			}
//		}
//	}
//	for (int i = front; i < rear; i++) {
//		printf("%d ", cq[i]);
//	} // 9 5
//}
//int main() {
//	printf("문제 1: "); P1();
//	printf("\n문제 2: "); P2();
//}