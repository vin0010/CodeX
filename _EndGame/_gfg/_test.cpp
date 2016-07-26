#include<iostream>
using namespace std;
void get(int &c){
	cout<<endl<<c;
	c=100;
}
int main (){
	int c=10;
	get(c);
	cout<<endl<<c;
}