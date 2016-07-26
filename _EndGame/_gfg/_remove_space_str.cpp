#include<iostream>
using namespace std;
int main (){
	string str = "spa c e s";
	//getline(cin, str);
	cout<<"\n" << str<<"\n";
	int count=0;
	for (int i =0 ; i<str.length(); i++) {
		if (str[i] != ' ') {
			//str[i] = str[i+1];
			str[count] = str[i];
			count++;
		}
	}
	str[count]='\0';
	cout<<"\n" << count<<"\n";
	cout<<"\n" << str<<"\n";
}