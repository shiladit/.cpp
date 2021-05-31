//shiladitya
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

int main() {
    ll n,k;
    cin >> n >> k;

    map <int,int> umap;
    vector <int> arr(n);

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        umap[x] = i; 
        arr[i] = x;
    }

    for (int i=0; i<n && k; ++i) {
    	if(arr[i] == (n-i))
    		continue;

    	int temp = umap[n-i];

    	swap(umap[n-i],umap[arr[i]]);
    	swap(arr[temp],arr[i]);

    	k--;
    }

    for(int i=0;i<arr.size();i++)
        cout << arr[i] << " ";

    cout << endl;

}