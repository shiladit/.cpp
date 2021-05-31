//shiladitya
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;

	set <string> set1;
	map <string,int> umap;

	for(int i=0;i<n;i++){
		string s;
		cin >> s;

		umap[s]++;

		if(umap[s] > 1){
			cout << s << " " << umap[s] << endl;
			continue;
		}

		bool flag = false;

		for(int j=s.length();j>0;j--){
			string s1;
			s1 = s.substr(0,j);

			if(set1.find(s1) != set1.end() && s1.length() == s.length()){
				
				cout << s1 << endl;
				flag = true;

				break;
			}
			else if (set1.find(s1) != set1.end() && s1.length() < s.length()){
				cout << s.substr(0,j+1) << endl;
				flag = true;
				break;
			}
			else
				set1.insert(s1);
		}

		if(!flag)
			cout << s[0] << endl;

	}
}