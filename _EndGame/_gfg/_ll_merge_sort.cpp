//
#include<iostream>
using namespace std;
struct node {
	node *next;
	int val;
}*head;
void print(node *i){
	cout<<endl;
	while (i!=NULL){
		cout<<i->val<<"--";
		i = i->next;
	}
	cout<<endl;
}
node* getNode(node *head, int index){
	node *i = head;
	while(index--){
		i=i->next;
	}
	return i;
}
node* merge(node *i, int ll, int mm, int hh){
	node *l=getNode(i,ll);
	node *m=getNode(i,mm);
	node *high=getNode(i,hh);
	node *mid=m;
	node *front = 
	while((l!=NULL && l->val < mid->val) && (m!=NULL && m->val < high->val)){
		if(l->val<m->val){
			insert(l,ll);
			l=l->next;
		}else{
			insert(m,ll);
			m=m->next;
		}
	}
	return front;
}
void merge_ll(node *head){
	merge_ll(head,l,m);
	merge_ll(head,m,h);
	merge(head,l,m,h);
}
int main(){
	int arr[]={70,50,30,10,80,60,40,20};
	int len=8;
	for(int i=len-1;i>=0;i--){
		node *temp = new node;
		temp->val=arr[i];
		temp->next=head;
		head=temp;
	}
	print(head);
	// cout<<endl<<getNode(head,4)->val;
	return 0;
}