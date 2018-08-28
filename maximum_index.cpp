/* https://practice.geeksforgeeks.org/problems/maximum-index/0 */

#include <bits/stdc++.h>

using namespace std;

bool compare(const pair <long,long>  &a,const pair <long,long>  &b){

	return a.first <b.first;
}

void print_arr(vector <pair <long,long>  >arr){

	for(int i=0;i<arr.size();i++){
		pair <long,long> p =arr[i];
		cout << p.first << " -- " << p.second << endl;
	}


}

int main() {
	long t,size;

	cin >> t;

	while(t--){
		cin >> size;

		vector <pair <long,long> > arr;

		long temp;

		for(int i=0;i<size;i++){
			cin >> temp;
			arr.push_back(make_pair(temp,i));
		}

		sort(arr.begin(),arr.end(),compare);

		// print_arr(arr);

		int i=0;
		int j=1;

		long max_diff = -INT_MAX;


		while(j != arr.size()){
			pair <long,long> p1 = arr[i];
			pair <long,long> p2 = arr[j];

			if(p2.second > p1.second){
				long diff = p2.second - p1.second;
				if(diff > max_diff)
					max_diff = diff;

				j++;
			}
			else
			{
				i++;
				j++;
			}

		}

		if(max_diff == -INT_MAX)
			cout << "0" << endl;
		else
			cout << max_diff << endl;
		
	}

}