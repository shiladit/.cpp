#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count1 = 0;
bool flag = false;

bool lexi(string &a, string &b){
	if(a < b)
		return true;
	else
		return false;
}

void check_same(string s){
	int i=0;
	int j=s.length()-1;

	while(i<j){
		if((s[i] != s[j]) && (i != j))
			return;
		// if(s[i] != s[i+1])
		// 	return;

		i++;
		j--;
	}

	if(i==j)
		count1 += 1;
	else
		count1 += j;

	return ; 
}

int match(string s1,string s2){
	int i = 0;

	while((i < s1.length()) && (i < s2.length())){
		
		if(s1[i] != s2[i])
			return i;
		i++;
	}

	return i;
}


int main(){
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector <string> prefix;

	for(int i=0;i<n;i++){
		string x = s.substr(i,n);
		prefix.push_back(x);
	}

	sort(prefix.begin(),prefix.end(),lexi);

	int lcp[n];
	lcp[0] = 0;

	for(int i=1;i<n;i++)
		lcp[i] = match(prefix[i-1],prefix[i]);

	for(int i=0;i<n;i++)
		cout << lcp[i] << " ";
	cout << endl;
	

	count1 = n;

	for(int i=0;i<prefix.size();i++){
		string s1 = prefix[i];
		int len = s1.length();
		flag = false;

		for(int j=len;j>lcp[i] && j>1;j--){
			string s2 = s1.substr(0,j);

			cout << s2 << endl;

			check_same(s2);

			if(flag){
				cout << "Count: " << count1 << endl;
				break;
			}

			cout << "Count: " << count1 << endl;

		}
	}

	cout << count1 << endl;
}