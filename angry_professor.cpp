//shiladitya
#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int n,k;
		cin >> n >> k;
		int students = 0;

		for(int i=0;i<n;i++){
			int x; cin >> x;
			if(x <= 0)
				students++;
		}

		if(students < k)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
