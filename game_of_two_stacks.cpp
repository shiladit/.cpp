#include<bits/stdc++.h>

using namespace std;

int main() {
	int G;
	cin >> G ; 
	while (G) {
	int m_size,n_size, x;
	cin >> m_size >> n_size >> x;

	int m[m_size],n[n_size];

	for(int i=0;i<m_size;i++)
		cin >> m[i];


	for(int i=0;i<n_size;i++)
		cin >> n[i];

	int sum_m[m_size];
	int sum_n[n_size];

	int sum=0;
	for(int i=0;i<m_size;i++){
		sum= sum + m[i];
		sum_m[i] = sum;
	}

	sum=0;
	for(int i=0;i<n_size;i++){
		sum= sum + n[i];
		sum_n[i] = sum;
	}

	int count_n =0;
	for(int i=0;i<n_size;i++){
		if(sum_n[i] <= x)
			++count_n;
	}
	int imt_sum = sum_n[count_n-1];
	// cout << imt_sum << endl;

	int count = count_n;
	int u=0;
	while(1) {
		if((imt_sum+m[u] > x) && ((imt_sum-n[count_n-1])+m[u] >x))
			break;
		else
		{
			if(((imt_sum-n[count_n-1])+m[u]) <=x){
				imt_sum = (imt_sum-n[count_n-1])+m[u];
				u++;
				while(u != m_size){
					
					count++;
					u++;
				}
			count_n--;
			count--;	
		}
		}
	}

	cout << count << endl;



	G--;
	
	}
}