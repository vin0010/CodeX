#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

void allocate(int* a){
	int x=100;
	//*a=*(&x);
	//*a=*(&x);
	*a=100;
	cout<<endl<<a;
	cout<<endl<<*a;
}
void change(char **a,char *a1,char *a2){
	//*c++;
	cout<<endl<<"a:"<<*a;
	cout<<endl<<"a1:"<<a1;
	cout<<endl<<"a2:"<<a2;
}
void get(int **arr){

}
void update(string *s){
	*s="vin";
}
int main (){
	// char *a1="a1";
	// char *a2="a2";
	char *a;
	// a=a1;
	// cout<<endl<<a;
	//change(&a,a1,a2);
	int** arr=new int*[2];
	int arr1[] = {1,2,3};
	int arr2[] = {4,5,6};
	arr[0]=arr1;
	arr1[1]=5;
	int* array=new int[2];
	//cout<<endl<<arr[0][1];
	int temp=10;
	//int *x=&temp;
	allocate(&temp);
	cout<<endl<<temp;
	//arr{1,2};
	return 0;
}