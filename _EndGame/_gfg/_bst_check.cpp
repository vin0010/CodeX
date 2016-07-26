#include<iostream>
#include<limits.h>
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
int checkifbst(node* i,int min,int max){
	if(i!=NULL){
		if(i->val>min && i->val<max)
			return checkifbst(i->left,min,i->val) && checkifbst(i->right,i->val,max); 
		else
			return 0;
	}
	return 1; 
}
int main(){
	int arr[]={50,30,70,20,40,60,80,90},len=8;
	for(int i=0;i<len;i++){
		root=insert(root,arr[i]);
	}
	inorder(root);
	cout<<endl<<"BST?:"<<checkifbst(root,INT_MIN,INT_MAX);
	root->right->right->val=10;
	cout<<endl<<"BST?:"<<checkifbst(root,INT_MIN,INT_MAX);
	// cout<<endl<<INT_MAX;
	// cout<<endl<<INT_MIN;
	return 0;
}