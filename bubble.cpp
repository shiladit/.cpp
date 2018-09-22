#include <bits/stdc++.h>

using namespace std;

void swap_val(int *a,int *b){
	int temp = *a;
	*a=*b;
	*b= temp;

}

int main() {
	int arr[10] = {-1,-4,5,60,7,10,-100,22,36,999};

	for(int i=0;i<10;i++){
		for(int j=i;j<10;j++){
			if(i != j && arr[i]>arr[j])
				swap_val(&arr[i],&arr[j]);
		}
	}

	for(int i=0;i<10;i++)
		cout << arr[i] << " ";

	cout << endl;
}