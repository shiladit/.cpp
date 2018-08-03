#include <bits/stdc++.h>

using namespace std;

int main() {

	int T;
	cin >> T;

	while(T) {
		int size,temp;
		cin >> size;

		vector <int> arr;
		int count =0 ;
		int max_v = -INT_MAX;

		for(int i=0;i<size;i++){
			cin >> temp;
			if(temp <0){
				if(temp > max_v){
					max_v = temp;
				}
				count++;
			}
			arr.push_back(temp);
		}

		//All elems are negative
		if(count == arr.size()){
			cout << max_v << endl;
			return 0;
		}

		int max_s =0;
		int max_e =0;

		for(int i=0;i<arr.size();i++){
			max_e = max_e + arr[i];
			if(max_e < 0){
				max_e =0;
			}
			if(max_e> max_s){
				max_s = max_e;
			}
		}

		cout << max_s << endl;

		T--;

	}
}