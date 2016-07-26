//http://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
#include<iostream>
using namespace std;
struct node {
	node *next;
	int val;
}*head1,*head2;
void print(node *i){
	cout<<endl;
	while (i!=NULL){
		cout<<i->val<<"--";
		i = i->next;
	}
	cout<<endl;
}
node* merge(node *i, node *j){
	if(i==NULL)
		return j;
	if(j==NULL)
		return i;
	if(i->val<j->val){
		i->next=merge(i->next,j);
		return i;
	}else{
		j->next=merge(j->next,i);
		return j;
	}
}
int main(){
	// int arr[]={50,30,70,20,40}; //,60,80,90};
	int arr1[]={10,30,50,70};
	int arr2[]={20,40,60,80};
	int len=4;
	for(int i=len-1;i>=0;i--){
		node *temp = new node;
		temp->val=arr1[i];
		temp->next=head1;
		head1=temp;
	}
	for(int i=len-1;i>=0;i--){
		node *temp = new node;
		temp->val=arr2[i];
		temp->next=head2;
		head2=temp;
	}
	cout<<endl<<"Head1:";
	print(head1);
	cout<<endl<<"Head2:";
	print(head2);
	cout<<endl<<"Res:";
	print(merge(head1,head2));
	return 0;
}