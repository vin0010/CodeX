//http://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/
#include<iostream>
using namespace std;
void permute(string prefix, strng *str, int i, int j){
	if(str.length()==0)
		cout<<endl<<prefix;
	else{
		for (int cnt=0;cnt<i;cnt++) {
			for (int cnt=0;cnt<i;cnt++) {
				permute(prefix+str[cnt], str.substr(0,cnt)+str.substr(cnt+1));
			}
		}
	}
}
int main (){
	string arr[3][3]  = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
	cout<<"\n______________________________________\n";
	//cout<<"\n"<<arr.length<<"\n";
	cout<<"\n"<<arr[0][0]<<"\n";
	cout<<"\n"<<arr[1][0]<<"\n";
}