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
		cout<<i->val<<"-";
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
int distancefromroot(node *i, int val, int dist){
	if (i!=NULL){
		if (i->val==val) {
			return dist;
		}
		int left=distancefromroot(i->left,val,dist+1);
		int right=distancefromroot(i->right,val,dist+1);
		return (left>right)?left:right;
	}
	return 0;
}
node* lca(node *i, int a,int b){
	if(i!=NULL){
		if (i->val==a || i->val==b){
			return i;
		}
		node *left=lca(i->left,a,b);
		node *right=lca(i->right,a,b);
		return (left !=NULL && right!=NULL) ? i: (left!=NULL ? left : right);
	}
	return i;
}
int distance(node *i, int a, int b){
	cout<<"\n --- "<<distancefromroot(root,a,0);
	cout<<"\n --- "<<distancefromroot(root,b,0);
	cout<<"\n --- "<<lca(root,a,b)->val;
}
int main(){
	int arr[]={50,30,70,20,40,60,80,90},len=8;
	for(int i=0;i<len;i++){
		root=insert(root,arr[i]);
	}
	inorder(root);
	cout<<endl;
	distance(root,30,90);
	cout<<endl;
	return 0;
}