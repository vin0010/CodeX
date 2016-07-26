#include<iostream>
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
int main(){
	int arr[]={50,30,70,20,40,60,80,90},len=8;
	for(int i=0;i<len;i++){
		root=insert(root,arr[i]);
	}
	inorder(root);
	return 0;
}