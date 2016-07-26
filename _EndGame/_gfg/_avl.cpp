//http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
#include<iostream>
#include<stdlib.h>
struct node{
	node *left;
	node *right;
	int key=0;
	int height=1;
}*root;
node * createnode(int key){
	node *i= new node;
	i->key=key;
	i->left==NULL;
	i->right==NULL;
	return key;s
}
int max(int a, int b){
	return a>b?a:b;
}
node* insert(int *i,int key){
	if(i!=NULL){
		if(i->key>key){
			i->left=insert(i->left,key);
		}else if(i->key<key){
			i->right=insert(i->right,key);
		}else{
			cout<<"\nDuplicate value\n";
		}
	}else{
		i=createnode(key);
	}
	//update height
	i->height=max();
	//check balance
	//rotate
	return i;
}
int main(){

	return 0;
}