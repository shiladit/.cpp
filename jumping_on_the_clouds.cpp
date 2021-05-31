//shiladitya
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)


using namespace std;

int arr[1000];

int step(int pos,int end,int count){

	if(pos >= end)
		return count;
	else if (arr[pos] == 1)
		return 1000;
	else
		return min(step(pos+1,end,count+1),step(pos+2,end,count+1));
}

int main() {
    int n;
    cin >> n;

    f(i,0,n)
        cin >> arr[i];

    cout << step(0,n-1,0) << endl;
    
}