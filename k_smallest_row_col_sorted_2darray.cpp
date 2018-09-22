#include <bits/stdc++.h>

using namespace std;

int kthSmallest(int arr[4][4],int size,int k){
	priority_queue <int,vector <int> , greater <int> > min_heap;

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
			min_heap.push(arr[i][j]);
		}

	int count =0 ;
	int top = -999;

	while(count != k){
		top = min_heap.top();
		min_heap.pop();
		count++;
	}

	return top;
}

int main() {
	int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  cout << "7th smallest element is " << kthSmallest(mat, 4, 7) << endl;
  return 0;
}