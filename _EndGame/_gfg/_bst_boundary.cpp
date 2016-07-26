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
int height(node *i){
	if(i!=NULL){
		int left=height(i->left);
		int right=height(i->right);
		return left>right?left+1:right+1;
	}
	return 0;
}
void leftViewUtil(node *i,int level,int* firsttime){
	if(i!=NULL){
		if(*firsttime<level){
			cout<<"-"<<i->val;
			*firsttime=level;
		}
		leftViewUtil(i->left,level+1,firsttime);
		leftViewUtil(i->right,level+1,firsttime);
	}
}
void rightViewUtil(node *i,int level,int* firsttime){
	if(i!=NULL){
		cout<<endl<<"Level:"<<level<<" flag:"<<*firsttime<<" node:"<<i->val;
		if(*firsttime==level){
			cout<<"-"<<i->val;
			*firsttime=level-1;
		}
		rightViewUtil(i->right,level+1,firsttime);
		rightViewUtil(i->left,level+1,firsttime);
	}
}
void leftView(node *i){
	int maxlevel=0;
	leftViewUtil(i,1,&maxlevel);
}
void rightView(node *i){
	int maxlevel=height(root);
	rightViewUtil(i,1,&maxlevel);
}
void printLeaves(node* i){
	if(i!=NULL){
		if(i->left==NULL && i->right==NULL){
			cout<<endl<<"--"<<i->val;
		}
		printLeaves(i->left);
		printLeaves(i->right);
	}
}
void printLeftView(node *i){
	if(i!=NULL){
		if(i->left){
			cout<<"--"<<i->val;
			printLeftView(i->left);
		}else if(i->right){
			cout<<"--"<<i->val;
			printLeftView(i->right);
		}else{
			//cout<<"-"<<i->val;
		}
	}
}
void printRightView(node* i){
	if(i!=NULL){
		if(i->right!=NULL){
			cout<<"--"<<i->val;
			printRightView(i->right);
		}else if(i->left!=NULL){
			cout<<"--"<<i->val;
			printRightView(i->right);
		}else{
			cout<<"-"<<i->val;
		}
	}
}
void printRightViewBottomUp(node* i){
	if(i!=NULL){
		if(i->right!=NULL){
			printRightViewBottomUp(i->right);
			cout<<"--"<<i->val;
		}else if(i->left!=NULL){
			printRightViewBottomUp(i->right);
			cout<<"--"<<i->val;
		}
	}
}
int main(){
	int arr[]={50,30,70,20,40,35,45,75},len=8;
	for(int i=0;i<8;i++){
		root=insert(root,arr[i]);
	}
	inorder(root);
	//cout<<endl<<"Height:"<<height(root);
	// cout<<endl<<"Left:";
	// leftView(root);
	// cout<<endl<<"Right:";
	// rightView(root);

	// cout<<endl<<"Leaves:";
	// cout<<endl<<"Left:";
	printLeftView(root);
	printLeaves(root);
	printRightViewBottomUp(root);
	// cout<<endl<<"Right:";
	// printRightView(root);
	// cout<<endl<<"RightBU:";
	cout<<endl;
	// cout<<"Right and right"<<root->right->val<<"-"<<root->right->right->val;
	// cout<<endl;
	return 0;
}