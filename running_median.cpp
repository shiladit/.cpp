/* Printing running median of a stream of integers using Heaps */

#include <bits/stdc++.h>

using namespace std;

int main() {

	priority_queue <float> max_heap;
	priority_queue <float,vector <float>, greater <float> > min_heap;

	float median =0;

	float size,temp;
	cin >> size;

	cin >> temp;
	size--;

	max_heap.push(temp);
	median = temp;

	printf("%0.1f\n", temp); 

	while(size--){

		cin >> temp;

		if(max_heap.size() > min_heap.size()){
			if(temp<median){
				float v= max_heap.top();
				max_heap.pop();
				min_heap.push(v);
				max_heap.push(temp);
				
			}
			else
				min_heap.push(temp);
				
			median = (min_heap.top() + max_heap.top())/2;
		}

		else if(max_heap.size() < min_heap.size()){
			if(temp>median){
				float v= min_heap.top();
				min_heap.pop();
				max_heap.push(v);
				min_heap.push(temp);
				
			}
			else
				max_heap.push(temp);

			median = (min_heap.top() + max_heap.top())/2;
			
		}

		else if(min_heap.size() == max_heap.size()){
			if(temp < median){
				max_heap.push(temp);
				median = max_heap.top();

			}
			else{
				min_heap.push(temp);
				median = min_heap.top();
			}

		}

		else 
			;

		printf("%0.1f\n", median);

	}



}