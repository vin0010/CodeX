#include<iostream>
#include<stdlib.h>
using namespace std;
void alloc2(int** p) {
   *p = (int*)malloc(sizeof(int));
   **p = 10;
}
void alloc1(int* p) {
   p = (int*)malloc(sizeof(int));
   *p = 10;
}

int main(){
   int x=99;
   // int *p=&x;
   int *p;
   // cout<<endl<<*p;//value is undefined
   cout<<endl<<p<<":"<<*p;//value is undefined
   alloc1(p);
   cout<<endl<<p<<":"<<*p;//value is undefined
   alloc2(&p);
   cout<<endl<<p<<":"<<*p;//will print 10
   free(p);
   return 0;
}