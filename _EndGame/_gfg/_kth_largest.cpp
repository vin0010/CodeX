//http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
#include<iostream>
#include<stdlib.h>
using namespace std;

void printArray(int *a, int size){
    for (int i=0; i < size; i++)
        cout<<a[i]<<"-";
    cout<<"\n";
}
void bubble(int *a,int size){
	while(size--){
		for (int current=0,next=1;current<size && next<=size;current++,next++){
			if(a[current]>a[next]){
				int temp=a[current];
				a[current]=a[next];
				a[next]=temp;
			}
		}
	}
}
int main (){
	int* arr= (int *)malloc(sizeof(int));
	int inp[]={1, 23, 12, 9, 30, 2, 50};
	for(int i=0;i<7;i++){
		arr[i]=inp[i];
	}
	cout<<endl;
	printArray(arr,7);
	bubble(arr,7);
	printArray(arr,3);
	return 0;
}