/*
	Chargebee Assignment-1
	This program simply reverse odd words in a given string by considrering space as seperation points.
	All edge & corner cases covered.

	Time complexity: O(n)
	Space complexity: Not applicable(In place swap in string to avoid auxilary space)

	Run:g++ _reverse_odd_words.cpp -o ./_reverse_odd_words && ./_reverse_odd_words
	Sample input and output:
	
	//Normal input
	input:get busy living
	output:get ysub living

	//input with multiple spaces
	input :i   am in hotel
	output:i   ma in letoh

	//input starts with space
	input :i am busy
	output:i ma busy

	//input starts with multiple space
	input :   i am busy
	output:   i ma busy
*/
#include<iostream>
using namespace std;

//Method to optimally reverse a word in a string.
//begin is a strart index of word and end is end index.
void reverse(string &str, int begin, int end){
	while(begin<end){
		char temp=str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
}

//find th next space in a string after index 'begin'. if it doesnt exist, it will return 0.
//Multiple spaces will be considered as single space
int findnextspace(string str, int begin){
	while(!(str[begin]==' ' && str[begin+1]!=' ') && begin<str.length()){ // to avoid multiple spaces and consider them as single seperation between words
		begin++;
	}
	return begin;
}

//This function traverse the string only once and achieve desired output with O(n) time complexity
string reverse_odd_words(string str){
	if (!str.empty()){
		int i=0;
		if (str[0]==' ') { // edge case check for string starting with space
			while(str[i]==' '){
				i++;
			}
		}
		int end=-1,odd=1;
		for(;i<str.length();i++){
			if(str[i]==' '){
				if(str[i+1]!=' ' && odd%2==1){
					end=findnextspace(str,i+1);
					reverse(str,i+1,end-1);
					i= end;
					end=-1;
				}else if(str[i+1]!=' '){
					odd++;
				}
			}
		}
	}
	return str;
}
int main (){
	const int max_string_size = 16; //max size of string including null termination \0
	char str[max_string_size];
	std::cin.getline(str, max_string_size);
	string s(str);
	cout<<endl<<reverse_odd_words(s)<<endl;
	return 0;
}