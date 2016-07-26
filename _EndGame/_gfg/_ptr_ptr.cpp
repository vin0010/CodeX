#include<iostream>
#include<stdlib.h>
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
void modify(node *i){
    for(node *prev=NULL,*current=i;current!=NULL;){
        if(current->val%2==1){
            if(prev!=NULL)
                prev->next=current->next;
            else
                head=current->next;
        }
        else
            prev=current;
        current=current->next;  
    }
}
void ptrmodify(node** i){
    for(node** current=i;*current!=NULL;){
        node* entry = *current;
        if(entry->val%2==1){
            *current=entry->next;
            free(entry);   
        }
        else{
            current=&entry->next;
        }
    }
}
void ptrmodify1(node*** i){
    cout<<endl<<i;
    cout<<endl<<*i;
    cout<<endl<<**i;
    cout<<endl<<(**i)->val;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int len=8;
    for(int i=len-1;i>=0;i--){
        node *temp = new node;
        temp->val=arr[i];
        temp->next=head;
        head=temp;
    }
    print(head);
    // modify(head);
    cout<<endl<<head;
    node **temp =&head; 
    node ***temp1 =&temp; 
    ptrmodify(&head);
    // ptrmodify1(temp1);
    print(head);
    return 0;
}