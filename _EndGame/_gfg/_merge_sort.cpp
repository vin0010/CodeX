//http://geeksquiz.com/merge-sort/
#include<iostream>
using namespace std;
void printArray(int a[], int size)
{
    for (int i=0; i < size; i++)
        cout<<a[i]<<"-";
    cout<<"\n";
}
void merge(int a[], int l, int m, int h){
    int n1=m-l+1;
    int n2=h-m;
	int L[n1];
	int R[n2];
	int i,j,k;
    cout<<endl<<"Left size:"<<n1<<"\tRight size:"<<n2<<"\t Low:"<<l<<"\t Mid:"<<m<<"\t High:"<<h;
	for(i=0;i<n1;i++)
		L[i]=a[i+l];
	for(j=0;j<n2;j++)
		R[j]=a[j+m+1];

	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
		} else{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while (i<n1){
		a[k]=L[i];
		i++; k++;
	}
	while (j<n2){
		a[k]=R[j];
		j++; k++;
	}
}
void _merge(int arr[], int l, int m, int h, int b[]){
    int n1=m-l+1;
    int n2=h-m;
    int i,j,k;
    i=l;j=m+1;k=l;
    cout<<endl<<"Left size:"<<n1<<"\tRight size:"<<n2<<"\t Low:"<<l<<"\t Mid:"<<m<<"\t High:"<<h;
    while(i<n1 && j<(n2+m+1)){
        cout<<endl<<"Coming in  i::"<<i<<" j::"<<j<<endl;
        if(arr[i]<=arr[j]){
            cout<<endl<<"~Swaping:"<<arr[k]<<"--------to-------"<<arr[j]<<endl;
            int temp = arr[k];
            arr[k]=arr[i];
            arr[i]=temp;
            i++;
        } else{
            cout<<endl<<"Swaping:"<<arr[k]<<"---------in--------"<<arr[j]<<endl;
            int temp = arr[k];
            arr[k]=arr[j];
            arr[j]=temp;
            j++;
        }
        k++;
        printArray(arr,7);
    }
}
void merge_sort(int a[], int l, int h,int b[]){
    if(l<h){
        int m = (l+h)/2;
        merge_sort(a,l,m,b);
        merge_sort(a,m+1,h,b);
        // merge(a,l,m,h);
        _merge(a,l,m,h,b);
    }
}
int main(){
    int arr[]={13, 12, 11, 10, 7, 6, 5};
    int b[]={13, 12, 11, 10, 7, 6, 5};
    cout<<endl;
    printArray(arr,7);
    //int arr
    merge_sort(arr,0,6,b);
    // merge_sort(arr,0,6);
    cout<<endl;
    printArray(arr,7);
	return 0;
}