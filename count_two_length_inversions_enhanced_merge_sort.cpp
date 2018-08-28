/* https://www.geeksforgeeks.org/counting-inversions/ */

#include <bits/stdc++.h>

using namespace std;

int merge_array(vector <int> arr,int temp[],int low,int mid,int high){
	
	int i=low;
	int j=mid;
	int k=low;

	int count=0;

	while((i <=mid-1) && (j<=high)){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
			
		}
		else{
			temp[k++]= arr[j++];
			count = mid-i;
			
		}

	}



	while(i <=mid-1){
	
		temp[k++] = arr[i++];
	}

	while(j <=high){
		temp[k++] = arr[j++];
	}



	for(int i=low;i<=high;i++)
		arr[i]=temp[i];

	return count;

}

int mergesort(vector <int> arr, int low,int high){
	int mid = (low+high)/2;
	int inv_count =0;
	int temp[100];

	if(high > low){

	inv_count+= mergesort(arr,low,mid);
	inv_count+= mergesort(arr,mid+1,high);

	inv_count+= merge_array(arr,temp,low,mid,high);
	
	}

	return inv_count;

}




int main() {
	int size,temp;
	cin >> size;

	vector <int> arr;

	while(size--){
		cin >> temp;
		arr.push_back(temp);
	}
	
	cout << mergesort(arr,0,arr.size()-1) << endl;
}