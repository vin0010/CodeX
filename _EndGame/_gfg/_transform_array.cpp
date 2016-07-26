/*
	Chargebee Assignment-2
	All edge & corner cases covered.

	Time complexity: O(n)
	Space complexity: Auxilary space as per requirement(reult in new array)

	Run:g++ _transform_array.cpp -o ./_transform_array && ./_transform_array
	Sample input and output:
	
	//Normal input
	input:Size:5 Array:1 2 3 4 5
	output:14 13 12 11 10 

	//input with negative values
	input :Size:5 Array:-1 -2 3 4 5
	output:14 13 12 11 10

	//input with invlaid array size
	input :Size:-10
	output:Enter valid array size
*/

#include<iostream>
using namespace std;

void printArray(int a[], int size){
    for (int i=0; i < size; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
//This sub routine will get sum of entire array by traversing it only once.
int getSumOfArray(int arr[], int size){
	int sum=0;
	while(size--){
		sum=sum+arr[size];
	}
	return sum;
}
//This sub routine will print the result array as expected.
void printResultArray(int arr[],int size,int sum){
	int result[size],i=0;
	while(i<size){
		result[i]=sum-arr[i];
		i++;
	}
	printArray(result,size);
}

int main(){
	int size,i=0;
	cin>>size;
	if(size>100 || size<2){
		cout<<"\n Enter valid array size"<<endl; // min size of array 2 and max size of array 100
		return 0;
	}
	int arr[size];
	while(i<size){
		cin>>arr[i];
		i++;
	}
	printResultArray(arr,size,getSumOfArray(arr,size));
	return 0;
}