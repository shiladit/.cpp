#include<bits/stdc++.h>

using namespace std;

int cal_max_l(int l[],int size){
	int max = -INT_MAX;
	for(int i=0;i<size;i++)
		if(l[i]> max)
			max =l[i];

	return max;
}
int cal_min_r(int r[],int size){
	int min = INT_MAX;
	for(int i=0;i<size;i++)
		if(r[i]< min)
			min =r[i];

	return min;
}

int main() {
	int size;
	cin >> size;
	int l[size];
	int r[size];
	for(int u=0;u<size;u++)
		cin >> l[u];


	for(int u=0;u<size;u++)
		cin >> r[u];

	int max_l,min_r;

	max_l= cal_max_l(l,size) ;
	min_r= cal_min_r(r,size);

	if(max_l <=min_r)
		cout << "0" << endl;
	else {
		int it=0;
		int local_max = -INT_MAX;
		int local_min = INT_MAX; 
		while(l[it] != max_l){
			if(l[it]>local_max)
				local_max = l[it];

			if(r[it] <local_min)
				local_min = r[it];

			it++;
		}

		if(local_min>local_max)
			cout  << local_min ;
		else
			cout << local_max;
	}
}