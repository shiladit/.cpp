#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the circularArrayRotation function below.
void circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    int size= a.size();
   
    
    while(k){
        int temp= a[size-1];
        
        for(int i=size-1;i>0;i--){
            a[i]= a[i-1];
        }
        a[0] = temp;

        cout << "K is " << k << endl;
        
        --k;
    }
   
    
    for(int i=0;i<queries.size();i++)
         cout << a[queries[i]] << endl;
       
}

int main()
{  

    int n ,k ,q;

    cin >> n >> k >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    circularArrayRotation(a, k, queries);

    return 0;
}

