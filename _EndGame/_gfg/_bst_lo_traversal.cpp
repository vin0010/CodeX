#include<iostream>
#include<queue>
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
void levelorder(node* i){
	queue<node*> q;
	q.push(i);
	while (!q.empty()){
		i=q.front();
		if(i->left!=NULL)
			q.push(i->left);
		if(i->right!=NULL)
			q.push(i->right);

		cout<<"->"<<i->val;
		q.pop();
	}
}
void print_level(node *i,int height,int level){
	if(i!=NULL && height>=level){
		if(level==height)
			cout<<"-"<<i->val;
		else{
			print_level(i->left,height,level+1);
			print_level(i->right,height,level+1);
		}
	}
}
int height(node *i){
	if(i!=NULL){
		int left=height(i->left);
		int right=height(i->right);
		return left>right?left+1:right+1;
	}
	return 0;
}
int main(){
	int arr[]={50,30,70,20,40,35},len=6;
	//38 200 100 300 50 150 250 400 25 75 125 175 225 275 350 450 12 37 63 87 113 137 163 187 224 223 222 219 280 285 290 299 282 500 425 426 430 439 444
	for(int i=0;i<len;i++){
		root=insert(root,arr[i]);
	}
	inorder(root);
	cout<<endl;
	levelorder(root);
	cout<<endl<<"Height:"<<height(root)<<endl;
	for(int i=0;i<height(root);i++){
		print_level(root,i,0);
		cout<<endl;
	}
	cout<<endl;
	return 0;
}