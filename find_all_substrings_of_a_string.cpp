#include <iostream>

using namespace std;

void find_all_substrings(string s1){

	int count = 0;
	for(int i=0;i<s1.length();i++){
		for(int len=1;len <=s1.length()-i;len++){
			cout << s1.substr(i,len) << "\n";
			count++;
		}
	}
	cout << endl << count<< endl;

}

int main() {

	string s1;
	cin >> s1;
	find_all_substrings(s1);

}