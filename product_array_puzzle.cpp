#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int size,temp;
	    cin >> size;
	    vector <int> arr;
	    
	    int val =1;
	    for(int i=0;i<size;i++){
	        cin >> temp;
	        arr.push_back(temp);
	        val = val * temp;
	    }
	    
	    for(int i=0;i<arr.size();i++){
	        cout << val/arr[i] << " ";
	    }
	    
	    cout << endl;
	}
}