#include<iostream>
#include<string.h>
using namespace std;
void permute(string prefix,string str){
	if (str.length()==0)
		cout<<endl<<prefix;
	else{
		for (int i=0;i<str.length();i++) {
			permute(prefix+str[i],str.substr(0,i)+str.substr(i+1));
		}
	}
}
int main (){
	string str  = "abcd";
	//cout<<str.substr(0,2);
	cout<<"\n______________________________________\n";
	permute("",str);
	//cout<<"\n"<<arr.length<<"\n";
}