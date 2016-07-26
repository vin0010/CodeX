#include<iostream>
using namespace std;
void check_palindrome(char);
struct node {
	node *prev;
	node *next;
	char val;
}*head,*tail;
void insert(char c){
	if (head==NULL) {
		head = new node;
		head->val = c;
		tail=head;
	}
	else{
		node *newtail = new node;
		newtail->val = c;
		tail->next = newtail;
		newtail->prev = tail;
		tail=newtail;
	}
}
void printfwd() {
	cout<< "\n Printing FWD:";
	struct node *i = head;
	while (i!=NULL) {
		cout<< "-" << i->val;
		i=i->next;
	}
}
void printback () {
	cout<< "\n Printing BWD:";
	struct node *i = tail;
	while (i!=NULL) {
		cout<< "-" << i->val;
		i=i->prev;
	}
}
int main() {
	string stream = "ababa";
	for (int count=0; count<=stream.length();count++) {
		//cout<<"\n"<<stream.substr(0,i);
		int pal=0;
		node *i=head;
		node *j=tail;
		insert(stream[count]);
		//printfwd();
		while (i!=j) {
			if (i->val!=j->val){
				pal=1;
				break;
			}
			i=i->next;
			j=j->prev;
		}
		if (pal ==1) {
			cout<<"\nNot a palindrome:"<< stream.substr(0,count);
		}else{
			cout<<"\nA palindrome:"<< stream.substr(0,count)	;
		}
	}
}