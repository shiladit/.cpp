//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {

	vector <int> pos;
	int n;
	cin >> n;

	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		if(x%2 == 1)
			pos.push_back(i);
	}

	if(pos.size()%2 == 1)
		cout << "NO\n";
	else{
		
		int count = 0;
		int i; int j;

		for(i=0,j=1;j<pos.size();){
			count = count + 2*(pos[j]-pos[i]);
			i = i+2;
			j = j+2;
		}

		cout << count << endl;
	}
}