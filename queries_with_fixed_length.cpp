//shiladitya
#include <iostream>
#include <vector>
#include <queue>

#define l long

using namespace std;



int main() {
	l n,t;
	cin >> n >>t; 

	vector <l> arr(n);

	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

while(t--){

	queue <l> q;

	l d;
	cin >> d;

	vector <l> max_win;

	for(int i=0;i<n;i++){

		if(i%d == 0 && !q.empty()){
			max_win.push_back(q.front());
			cout << "HI\n";
			q.pop();
		}

		while(!q.empty() && arr[i]>q.back()){
			cout << "OUT\n";
			q.pop();
		}

		q.push(arr[i]);

		
	}

	for(int i=0;i<max_win.size();i++)
		cout << max_win[i] << " ";
	cout << endl;
}



}
