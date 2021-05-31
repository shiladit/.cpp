//shiladitya

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	for(int test=1;test<=t;test++){
		string s;
		cin >> s;

		int k;
		cin >> k;

		int len = s.length();

		int count = 0;

		for(int i=0;i<(len-k+1);i++){
			if(s[i] == '-'){
				for(int j=i;j<k+i;j++)
					if(s[j] == '+')
						s[j] = '-';
					else
						s[j] = '+';

				count++;
			}
		}

		bool flag = false;

		for(int i=len-k+1;i<len;i++){
			if(s[i] == '-'){
				flag = true;
				break;
			}
		}

		cout << "Case #" <<test << ": ";

		if(flag)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << count << endl;


	}
}