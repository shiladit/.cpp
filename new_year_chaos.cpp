//shiladitya
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector <int> arr(n);

		for(int i=0;i<n;i++)
			cin >> arr[i];

		int count =0;

		bool flag = false;

		for(int j=n-1;j>=0;j--){
			if((arr[j]-(j+1)) > 2){
				flag = true;
				break;
			}
			for(int i=j-1;i>=0;i--){
				if(arr[i] > arr[j])
					count++;
			}
		}
		

		if((count > (2*n)) || flag)
			cout << "Too chaotic" << endl;
		else
			cout << count << endl;

	}
}