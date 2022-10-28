//#include "string.h"
//#include <iostream>
//#include <fstream>
//#define _CRT_SECURE_NO_WARNINGS
//#define MAX_TERMS 100
//
//using namespace std;
//
//typedef struct {
//	int coef;
//	int expon;
//} polynomial;
//
//polynomial terms[MAX_TERMS];
//int avail = 0;
//
//
//int COMPARE(int a, int b) {
//	if (a > b) return 1; //a>b 이면 1 반환
//	else if (a < b) return -1; //a<b 이면 -1 반환
//	else return 0;	//a=b 이면 0 반환
//}
//void attach(int coef, int exp) {
//	if (avail >= MAX_TERMS) {
//		fprintf(stderr, "Too many terms in the polynomial\n");
//		exit(EXIT_FAILURE);
//	}
//	terms[avail].coef = coef;
//	terms[avail++].expon = exp;
//}
//void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD, polynomial terms[]) {
//	int coefficient;
//	*startD = avail;
//	// avail 인덱스 부터 결괏값 저장, startD는 avail 시작 가리키는 포인터.
//
//	while (startA <= finishA && startB <= finishB) {
//		switch (COMPARE(terms[startA].expon, terms[startB].expon)) {
//		case -1:  // a < b 
//			attach(terms[startB].coef, terms[startB].expon);
//			startB++;
//			break;
//		case 0: // a == b
//			coefficient = terms[startA].coef + terms[startB].coef;
//			if (coefficient) {
//				attach(coefficient, terms[startA].expon);
//			}
//			startA++;
//			startB++;
//			break;
//		case 1: // a > b
//			attach(terms[startA].coef, terms[startA].expon);
//			startA++;
//		}
//	}
//	for (; startA <= finishA; startA++) {
//		attach(terms[startA].coef, terms[startA].expon);
//	}
//	for (; startB <= finishB; startB++) {
//		attach(terms[startB].coef, terms[startB].expon);
//	}
//	*finishD = avail - 1;
//}
//int main() {
//	fstream a("a.txt");
//	fstream b("b.txt");
//	int startD, finishD, nA = 0, nB = 0;
//
//	a >> nA; b >> nB;
//
//	// 2 | 2 100 1 0
//	// 4 | 1 4 10 3 3 2 -1 0
//	// nA = 2 nB = 4
//
//	for (int i = 0; i < nA; i++) {
//		a >> terms[i].coef; a >> terms[i].expon;
//		avail++;
//	}
//	for (int i = nA; i < nA + nB; i++) {
//		b >> terms[i].coef; b >> terms[i].expon;
//		avail++;
//	}
//
//	padd(0, nA - 1, nA, nA + nB - 1, &startD, &finishD, terms);
//	//padd(int startA, int finishA, int startB, 
//	//int finishB, int* startD, int* finishD, polynomial terms[])
//
//	printf("%d ", finishD - startD + 1);
//	for (int i = startD; i <= finishD; i++) {
//		printf("%d ", terms[i].coef);
//		printf("%d ", terms[i].expon);
//	}
//}