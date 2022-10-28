//#include <iostream>
//#include <fstream>
//#include <string>
//#define MAX_STACK_SIZE 100
//#define MAX_EXPR_SIZE 100
//
//using namespace std;
///**
//* lparen�� stack���� precedence ���� ���� expression���� ��ū���� ������ �� ���� ����
//*/
//typedef enum {
//	lparen, rparen, plus, minus, times, divide, mod, eos, operand
//} precedence;
//precedence stack[MAX_STACK_SIZE]; //�����ʱ�ȭ
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
//	printf("������ ������ϴ�.\n");
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
//* precedence �ڷ��� stack�� push�ϴ� �Լ�
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
//	case mod: printf("%%"); break; //��ⷯ �����ڴ� 2�� ��� ��µ�
//	}
//}
//precedence get_token(char* symbol, int* n, char expr[]) {
//	*symbol = expr[(*n)++]; //expr �� ��Ʈ��
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
//	char symbol; //���۷���, ���۷����� �� �ǹ̰� �ִ� symbol
//	precedence token;
//	int n = 0; //char[] ���ڿ� ����Ʈ �ε��� �̵��� ���
//	stack[++top] = eos;
//
//	for (token = get_token(&symbol, &n, expr); token != eos;
//		token = get_token(&symbol, &n, expr))
//	{ // ���ǹ� token != eos �� �����̸� ( token == eos �̸� ) for�� Ż��
//		if (token == operand) // token�� ���ڸ�
//			printf("%c", symbol); //�ٷ����
//		else if (token == rparen) { //��ū�� ) �̸�
//			while (stack[top] != lparen) { // ( ������ ������
//				print_token(pop());
//			}// stack pop�ϰ� ���
//			pop(); // ( ����������� del
//		}
//		else { //��ū�� operator�̸� 
//			/*incoming precedence�� in stack precedence���� ũ�� push,
//				������ icp�� ū ���϶����� pop�ϰ� print*/
//			while (isp[stack[top]] >= icp[token])
//				print_token(pop());
//			//�׷��� ������ token push
//			push(token);
//		}
//	}//eos ���ö����� ���ÿ� �ִ� operator ���� pop�ϱ�
//	while ((token = pop()) != eos) {
//		print_token(token);
//	}
//	printf("\n");
//}
//
//void P2() { //postfix expression evaluation
//	getInput2();
//	precedence token; char symbol; int op1, op2; int n = 0;
//	top = -1; //top �ٽ� �ʱ�ȭ
//	token = get_token(&symbol, &n, expr2); //�켱 ��ū 1�� ����
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
//	printf("���� 1: "); P1();
//	printf("���� 2: "); P2();
//	return 0;
//}