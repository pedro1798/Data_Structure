//
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main() {
//    int num, num2;
//    int* v; int* v2;
//    fstream inA("a.txt"); fstream inB("b.txt");
//
//    inA >> num;
//
//    v = (int*)malloc(sizeof(int) * num);
//
//    inB >> num2;
//
//    v2 = (int*)malloc(sizeof(int) * num);
//
//    for (int i = 0; i < num; i++) {
//        inA >> v[i];
//    }
//
//
//    for (int i = 0; i < num2; i++) {
//        inB >> v2[i];
//    }
//    printf("독어독문학과 2022117156 박상준\n");
//
//    for (int i = 0; i < num; i++) {
//        for (int j = 0; j < num2; j++) {
//            if (v[i] == v2[j]) {
//                printf("%d ", v[i]);
//            }
//        }
//    }
//    printf("\nO(nm)");
//
//}
