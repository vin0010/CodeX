//
#include<iostream>
using namespace std;

void printArray(int a[], int size)
{
    for (int i=0; i < size; i++)
        cout<<a[i]<<"-";
    cout<<"\n";
}
void max_heap(int arr[],int i){

}
void max_heapify(int arr[],int n){
	for(int i=(n/2)-1;i>=0;i--){
		cout<<endl<<arr[i];//<<":"<<arr[(2*i)+1]<<":"<<arr[(2*i)+2];
	}
}
void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main (){
	int arr[]={5,3,17,10,84,19,6,22,9};
	printArray(arr,sizeof(arr)/sizeof(arr[0]));
	max_heapify(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}