//#include <iostream>
//#include <fstream>
//#include <string>
//#define MAX_STACK_SIZE 100
//#define MAX_EXPR_SIZE 100
//
//using namespace std;
///**
//* lparen은 stack에선 precedence 가장 낮고 expression에서 토큰으로 가져올 때 가장 높음
//*/
//typedef enum {
//	lparen, rparen, plus, minus, times, divide, mod, eos, operand
//} precedence;
//precedence stack[MAX_STACK_SIZE]; //스택초기화
//int intStack[MAX_STACK_SIZE];
//
///**precedence*/
//static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };//in-stack_precedence
//static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };//incoming_precedence
//
//char expr[MAX_EXPR_SIZE]; char expr2[MAX_EXPR_SIZE]; // string expression
//int top = -1;
//
//void getInput() {
//	fstream in("in1.txt"); int n = 0;
//	while (!in.eof()) {
//		in >> expr[n++];
//	}
//}
//void getInput2() {
//	fstream in("in2.txt"); int n = 0;
//	while (!in.eof()) {
//		in >> expr2[n++];
//	}
//}
//precedence stackEmpty() {
//	printf("스택이 비었습니다.\n");
//	exit(EXIT_FAILURE);
//}
//precedence pop() {
//	if (top == -1) {
//		return stackEmpty();
//	}
//	return stack[top--];
//}
//int popInt() {
//	if (top == -1) {
//		return stackEmpty();
//	}
//	return intStack[top--];
//}
///**
//* precedence 자료형 stack에 push하는 함수
//* stack[++top] = item;
//* @param {precedence} item
//*/
//void push(precedence item) {
//	stack[++top] = item;
//}
//void pushInt(int input) {
//	intStack[++top] = input;
//}
//void print_token(precedence pop) {
//	switch (pop) {
//	case precedence::plus: printf("+"); break;
//	case precedence::minus: printf("-"); break;
//	case times: printf("*"); break;
//	case divide: printf("/"); break;
//	case mod: printf("%%"); break; //모듈러 연산자는 2개 써야 출력됨
//	}
//}
//precedence get_token(char* symbol, int* n, char expr[]) {
//	*symbol = expr[(*n)++]; //expr 은 스트링
//	switch (*symbol) {
//	case '(': return lparen;
//	case ')': return rparen;
//	case '+': return ::plus;
//	case '-': return ::minus;
//	case '*': return times;
//	case '/': return divide;
//	case '%': return mod;
//	case '\0': return eos;
//	default: return operand;
//	}
//}
//
//void P1() { //infix notation to postfix notation 
//	getInput();
//
//	char symbol; //오퍼랜드, 오퍼레이터 등 의미가 있는 symbol
//	precedence token;
//	int n = 0; //char[] 문자열 리스트 인덱스 이동에 사용
//	stack[++top] = eos;
//
//	for (token = get_token(&symbol, &n, expr); token != eos;
//		token = get_token(&symbol, &n, expr))
//	{ // 조건문 token != eos 가 거짓이면 ( token == eos 이면 ) for문 탈출
//		if (token == operand) // token이 숫자면
//			printf("%c", symbol); //바로출력
//		else if (token == rparen) { //토큰이 ) 이면
//			while (stack[top] != lparen) { // ( 나오기 전까지
//				print_token(pop());
//			}// stack pop하고 출력
//			pop(); // ( 출력하지말고 del
//		}
//		else { //토큰이 operator이면 
//			/*incoming precedence가 in stack precedence보다 크면 push,
//				작으면 icp가 큰 값일때까지 pop하고 print*/
//			while (isp[stack[top]] >= icp[token])
//				print_token(pop());
//			//그렇지 않으면 token push
//			push(token);
//		}
//	}//eos 나올때까지 스택에 있는 operator 전부 pop하기
//	while ((token = pop()) != eos) {
//		print_token(token);
//	}
//	printf("\n");
//}
//
//void P2() { //postfix expression evaluation
//	getInput2();
//	precedence token; char symbol; int op1, op2; int n = 0;
//	top = -1; //top 다시 초기화
//	token = get_token(&symbol, &n, expr2); //우선 토큰 1개 받음
//	while (token != eos) {
//		if (token == operand)
//			pushInt(symbol - '0');
//		else {
//			op2 = popInt(), op1 = popInt();
//			switch (token) {
//			case precedence::plus:
//				pushInt(op1 + op2); break;
//			case precedence::minus:
//				pushInt(op1 - op2); break;
//			case times:
//				pushInt(op1 * op2); break;
//			case divide:
//				pushInt(op1 / op2); break;
//			case mod:
//				pushInt(op1 % op2);
//			}
//		}
//		token = get_token(&symbol, &n, expr2);
//	}
//	printf("%d", popInt());
//}
//
//int main() {
//	printf("문제 1: "); P1();
//	printf("문제 2: "); P2();
//	return 0;
//}