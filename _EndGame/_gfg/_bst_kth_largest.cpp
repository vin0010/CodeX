//http://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
	node *left;
	node *right;
	int val;
}*root;
void inorder(node *i){
	if (i!=NULL){
		inorder(i->left);
		cout<<i->val<<" ";
		inorder(i->right);
	}
}
node* insert(node *i, int val){
	if (i==NULL){
		i = new node;
		i->val=val;
	} else if (i->val<val){
		i->right=insert(i->right,val);
	} else if (i->val>val){
		i->left=insert(i->left,val);
	}
	return i;
}
int kth_largest(node *i,int* k){
	if(i!=NULL && *k!=0){
		cout<<endl<<"iterate"<<*k;
		int left = kth_largest(i->left,k);
		*k=*k-1;
		if(*k==0){
			cout<<"\n"<<"kth:"<<i->val;

			return i->val;
		}
		int right = kth_largest(i->right,k);
		return left ? left : right;
	}
	return 0;
}
void test(node *i,int k){
	if (i!=NULL){
		test(i->left,k);
		k=k-1;
		if(k==0)
			cout<<"------"<<i->val<<"------"<<endl;
		test(i->right,k);
	}
}
void kth_largest1(node *i,int k,int& count){
	if(i!=NULL && count<=k){
		cout<<endl<<"1iterate"<<k<<"--"<<count;
		kth_largest1(i->right,k,count);
		count++;
		if(k==count){
			cout<<"\n"<<"kth-:"<<i->val;
		}
		kth_largest1(i->left,k,count);
	}
}
void kth_largest2(node *i,int k,int& count){
	if(i!=NULL && count<=k){
		cout<<endl<<"2iterate"<<k<<"--"<<count;
		kth_largest2(i->left,k,count);
		count++;
		if(k==count){
			cout<<"\n"<<"kth-:"<<i->val;
		}
		kth_largest2(i->right,k,count);
	}
}
int kth_largest3(node *i,int* k){
	if(i!=NULL && *k>=0){
		cout<<endl<<"3iterate"<<*k;
		int left = kth_largest3(i->left,k);
		*k=*k-1;
		if(*k==0){
			// cout<<"\n"<<"kth-:"<<i->val;
			return i->val;
		}
		int right = kth_largest3(i->right,k);
		return left ? left : right;
	}
	return 0;
}
int main(){
	int arr[]={50,30,70,20,40,60,80,90},len=8,k=3,count1=0,count2=0;
	for(int i=0;i<len;i++){
		root=insert(root,arr[i]);
	}
	cout<<endl<<"Inorder:";
	inorder(root);
	cout<<endl;
	int* kth=NULL;//=(int*)malloc(sizeof(int));
	// cout<<endl<<"Ptr:"<<kth_largest(root,&k)<<endl;
	kth_largest1(root,k,count1);
	cout<<endl<<"\n\n";
	kth_largest2(root,k,count2);
	cout<<endl<<"\n\n";
	int temp=3;
	cout<<endl<<"Yoohoo:"<<kth_largest3(root,&temp);
	// test(root,4);
	return 0;
}