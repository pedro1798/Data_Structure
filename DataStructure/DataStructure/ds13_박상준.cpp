//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//typedef struct node* treePointer;
//typedef struct node {
//	int data;
//	treePointer leftChild, rightChild;
//};
//// 재귀로 이진트리 생성하기
//// 부모노드 포인터 매개변수로 
//treePointer recur(treePointer ptr) {
//	treePointer leftNode, rightNode;
//
//	leftNode = (treePointer)malloc(sizeof(*leftNode));
//	rightNode = (treePointer)malloc(sizeof(*rightNode));
//
//	if (ptr->data > 5) {	
//		ptr->leftChild = NULL; ptr->rightChild = NULL;
//		return ptr;
//	}
//	leftNode->data = ptr->data * 2; //node의 데이터에 ptr->data*2값 넣음
//	ptr->leftChild = recur(leftNode); //rightChild는 node를 가리킴
//
//	rightNode->data = ptr->data + 2;
//	ptr->rightChild = recur(rightNode); 
//
//	return ptr;
//}
//
//void inorder(treePointer ptr) {
//	if (ptr) {
//		inorder(ptr->leftChild);
//		printf("%d ", ptr->data);
//		inorder(ptr->rightChild);
//	}
//}
//int main() {
//	printf("2022117156 독어독문학과 박상준\n");
//	treePointer root;
//	root = (treePointer)malloc(sizeof(*root));
//	scanf_s("%d", &root->data);
//	recur(root);
//	inorder(root);
//}
//
////    2
////  4   4
//// 8 6 8 6