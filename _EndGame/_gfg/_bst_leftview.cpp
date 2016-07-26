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
int height(node *i){
	if(i!=NULL){
		int left=height(i->left);
		int right=height(i->right);
		return left>right?left+1:right+1;
	}
	return 0;
}
int print_level(node *i,int height,int level){
	if(i!=NULL && height>=level){
		if(level==height){
			cout<<"-"<<i->val;
			height=INT_MAX;
		}else{
			int left=print_level(i->left,height,level+1);
			if (left==INT_MAX)
				return left;
			height=print_level(i->right,height,level+1);
		}
	}
	return height;
}
void leftViewUtil(node *i,int level,int* firsttime){
	if(i!=NULL){
		if(*firsttime<level){
			cout<<"-"<<i->val;
			*firsttime=level;
		}
		leftViewUtil(i->right,level+1,firsttime);
		leftViewUtil(i->left,level+1,firsttime);
	}
}
void leftView(node *i){
	int maxlevel=0;
	leftViewUtil(i,1,&maxlevel);
}
void printBoundaryLeft(node* i){
	if (i){
		if (i->left){
			// to ensure top down order, print the node
			// before calling itself for left subtree
			cout<<"--"<<i->val;
			printBoundaryLeft(i->left);
		}
		else if( i->right ){
			cout<<"-"<<i->val;
			printBoundaryLeft(i->right);
		}else{
			cout<<"-"<<i->val;
		}
	}
}
void printBoundaryRight(node *i){
	if(i!=NULL){
		if(i->right!=NULL){
			cout<<"-"<<i->val;
			printBoundaryRight(i->right);
		}
		else if(i->left!=NULL){
			cout<<"-"<<i->val;
			printBoundaryRight(i->left);
		}
	}
}
int main(){
	int arr[]={50,30,70,20,40,35,45,75},len=8;
	for(int i=0;i<len;i++){
		root=insert(root,arr[i]);
	}
	inorder(root);
	cout<<endl;
	for(int i=0;i<height(root);i++){
		//print_level(root,i,0);
		// cout<<endl;
	}
	cout<<endl<<"Left:";
	//leftView(root);
	printBoundaryLeft(root);
	cout<<endl<<"Right:";
	printBoundaryRight(root);
	
	cout<<endl<<root->right->right->val<<endl;
	return 0;
}