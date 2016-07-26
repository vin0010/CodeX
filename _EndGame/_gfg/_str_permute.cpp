//
#include<iostream>
using namespace std;
void permute_string(string pre,string str){
	if(0==str.length()){
		cout<<endl<<pre;
	}else{
		for(int i=0;i<str.length();i++){
			permute_string(pre+str[i],str.substr(0,i)+str.substr(i+1));
		}
	}
}
int main (){
	string str="123";
	permute_string("",str);
	return 0;
}