//shiladitya
#include <iostream>
#include <string>

using namespace std;

bool check_happy(string s){

	int len = s.length();

	for(int i=1;i<len-1;i++){
		if((s[i] == s[i-1]) || (s[i] == s[i+1]))
			;
		else
			return false;
	}

	if(s[0] == s[1] && s[len-1] == s[len-2])
		return true;
	else
		return false;
}

int main(){

	int t;
	cin >> t;

	while(t--){

		int len;
		cin >> len;
		string s;
		cin >> s;

		bool happy = check_happy(s);

		if(happy)
			cout << "YES\n";
		else{

			bool flag = false;
	        int freq[26];

	        for(int i=0;i<26;i++)
	            freq[i] = 0;

	        for(int j=0;j<s.length();j++){
	            if(s[j] == '_')
	                flag = true;
	            else
	                freq[s[j]-'A'] += 1;
	        }

	        for(int k=0;k<26;k++){
	            if(freq[k] == 1){
	                flag = false;
	                break;
	            }
	        }

	        
	        if(flag == true)
	            cout << "YES" << endl;
	        else
	            cout << "NO" << endl;
			
		}
	}
}

		