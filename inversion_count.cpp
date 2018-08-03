#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int T,temp;
	cin >> T;

	while(T){
		int size;
		cin >> size;

		vector <int> arr;

		for(int i=0;i<size;i++){
			cin >> temp;
			arr.push_back(temp);
		}

		int count=0;

		for(int i=0;i<size;i++){
			for(int j=i+1;j<size;j++){
				if(i!=j) {
					if(arr[i]>arr[j])
						count++;
				}
			}
		}

		cout << count << endl;

	--T;
	}
}