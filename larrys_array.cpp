#include<bits/stdc++.h>

using namespace std;

bool rotation(vector <int> arr,int size) {
	int i=0;
	int j=2;
	bool flag= false;

	for(int x=0;x<size;x++){
		i=0;j=2;
		// cout << "i:" << i << "j:" << j <<"x:" << x << endl;
		while(j != size){
			while(arr[i]>arr[j] || arr[i]>arr[i+1]){
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = arr[j];
				arr[j] = temp; 
			}
			i++;
			j++;
		}

		// for(int i=0;i<size;i++)
		// 	cout << arr[i] << " ";

		// cout << endl;

		int count=0;
		for(int u=0;u<size-1;u++)
			if(arr[u]<arr[u+1])
				count++;

		if(count == (size-1)){
			cout << "YES" << endl;
			flag =true;
			return flag;
		}

	}

	return flag;


}

int main() {
	int T;
	cin >> T;
	while(T) {
		int size,val;
		cin >> size;
		vector <int> arr;
		for(int i=0;i<size;i++){
			cin >> val;
			arr.push_back(val);
		}

		bool flag;

		if(size > 2)
			 flag = rotation(arr,size);
		else ;

		if(!flag) 
			cout << "NO\n" ;


		T--;
	}
}