#include<bits/stdc++.h>

using namespace std;

int main() {
	int size,k;
	cin >> size >> k;

	int ob_size = k;

	int q_x,q_y;
	cin >> q_x >> q_y;

	int t_i,t_j;
	int ob_x[k],ob_y[k];

	int i=0;
	while(k) {
		cin >> t_i >> t_j;
		ob_x[i] = t_i;
		ob_y[i] = t_j;

		i++;
		k--;
	}

	int min_up = 1;
	int min_down = size+1;
	int min_right = size+1;
	int min_left = 1;
	int min_up_left =1; 
	int min_up_right = size+1;
	int min_down_left =size+1;
	int min_down_right =size+1;

	
	for(int i=0;i<ob_size;i++){
		//UP
		if(ob_y[i] == q_y && ob_x[i] >= min_up && ob_x[i] < q_x)
			min_up = ob_x[i];
		//DOWN
		if(ob_y[i] == q_y && ob_x[i] <= min_down && ob_x[i] > q_x)
			min_down = ob_x[i];

		//RIGHT
		if(ob_x[i] == q_x && ob_y[i] <= min_right && ob_y[i] > q_y)
			min_right = ob_y[i];

		//LEFT
		if(ob_x[i] == q_x && ob_y[i] >= min_left && ob_y[i] < q_y)
			min_left = ob_y[i];
		
		//DIAGONAL
		if((abs(q_x-ob_x[i])) == (abs(q_y-ob_y[i]))){
			//UP-LEFT
			if( ob_x[i] < q_x && ob_y[i]>min_up_left && ob_y[i] < q_y)
				min_up_left = ob_y[i];
			//UP-RIGHT
			if( ob_x[i] < q_x && ob_y[i]<min_up_right && ob_y[i] > q_y)
				min_up_right = ob_y[i];

			//DOWN-LEFT
			if( ob_x[i] > q_x && ob_y[i]<min_down_left && ob_y[i] < q_y)
				min_down_left = ob_y[i];

			//DOWN-RIGHT
			if( ob_x[i] > q_x && ob_y[i]<min_down_right && ob_y[i] > q_y)
				min_down_right = ob_y[i];


		} 
			

	}

	// cout << min_up << endl;
	// cout << min_down << endl;
	// cout << min_right << endl;
	// cout << min_left << endl;
	// cout << min_up_left << endl;
	// cout << min_up_right << endl;
	// cout << min_down_left << endl;
	// cout << min_down_right << endl;

	int count = 0;
	count = (abs(q_x-min_up))+(abs(q_x-min_down))+ (abs(q_y-min_right))+ (abs(q_y-min_left)) + (abs(q_y-min_up_left)) +
	(abs(q_y-min_up_right)) +(abs(q_y-min_down_left)) + (abs(q_y-min_down_right)) -8 ;

	cout << count << endl;


}
