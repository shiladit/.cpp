/* https://www.geeksforgeeks.org/print-all-jumping-numbers-smaller-than-or-equal-to-a-given-value/ */

#include <bits/stdc++.h>

using namespace std;

void bfs(int x,int i){
	queue <int> q;

	q.push(i);

	while(!q.empty()){
		int num = q.front();
		q.pop();

		if(num <=x){
			cout << num << " ";
			int last_dig = num%10;

			if(last_dig == 0)
				q.push((num*10)+(last_dig+1));
			else if(last_dig ==9)
				q.push((num*10)+(last_dig-1));
			else{
				q.push((num*10)+(last_dig-1));
				q.push((num*10)+(last_dig+1));
			}
		}
	}
}


void print_jumping(int x){

	cout << "0" << " " ;
	for(int i=1;i<10 && i<=x ;i++)
		bfs(x,i);
}

int main() {
	int x=30;
	print_jumping(x);

	cout << endl;

}