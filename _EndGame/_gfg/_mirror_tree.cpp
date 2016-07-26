//http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
#include<iostream>
struct node {node *left; node *right; int val; }*root;
using namespace std;
node* insert(node *i,int val){
	if(i==NULL){
		i=new node;
		i->val=val;
	} else if(i->val>val){
		i->left=insert(i->left,val);
	} else if(i->val<val){
		i->right=insert(i->right,val);
	}
	return i;
}
void inorder(node *i){
	if (i!=NULL){
		inorder(i->left);
		cout<<i->val<<"--";
		inorder(i->right);
	}
}
void mirror(node *i){
	if (i != NULL) {
		mirror(i->left);
		mirror(i->right);
		node *temp = i->left;
		i->left=i->right;
		i->right=temp;
	}
}
int main (){
	root=insert(root,10);
	root=insert(root,5);
	root=insert(root,15);
	root=insert(root,7);
	root=insert(root,3);
	// root=insert(root,17);
	// root=insert(root,12);
	cout<<endl;
	inorder(root);
	cout<<endl;
	mirror(root);
	inorder(root);
	cout<<endl;
}