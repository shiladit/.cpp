#include <bits/stdc++.h>

using namespace std;

int find_num(vector <int> arr) {
    
    int sum = arr[0];
    
    for(int i=1;i<arr.size();i++)
        sum = sum^arr[i]; //XOR of two numbers always produce 0
    
    return sum;
    
}

int main() {
    int n,temp;
    cin >> n;
    
    vector <int> arr;
    
    for(int i=0;i<n;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    
    int num = find_num(arr);

    cout << num << endl;
}