
/* https://www.evernote.com/client/snv?noteGuid=f9e55a78-d609-43ab-80d4-860183500e45&noteKey=4415117d85cbb065&sn=https%3A%2F%2Fwww.evernote.com%2Fshard%2Fs337%2Fsh%2Ff9e55a78-d609-43ab-80d4-860183500e45%2F4415117d85cbb065&title=HackerRank */




#include <bits/stdc++.h>
using namespace std;

int find_mono_decrease(vector <int> arr){
    priority_queue <int, vector <int> , greater <int> > pq;

    int sum =0;
    int diff = 0;

    for(int i=0;i<arr.size();i++){
        if(!pq.empty() && pq.top() < arr[i]){
            diff = arr[i]-pq.top();
            sum = sum + diff;
            pq.pop();
            pq.push(arr[i]);
        }
            pq.push(arr[i]);
    }

    return sum ;
}

int find_mono_increase(vector <int> arr){
    priority_queue <int> pq;

    int sum =0;
    int diff = 0;

    for(int i=0;i<arr.size();i++){
        if(!pq.empty() && arr[i] < pq.top()){
            diff = pq.top()-arr[i];
            sum = sum + diff;
            pq.pop();
            pq.push(arr[i]);
        }
            pq.push(arr[i]);
    }

    return sum;
}

int main() {
    int size;
    cin >> size;

    vector <int> arr;

    while(size--){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int a = find_mono_decrease(arr); 
    int b = find_mono_increase(arr);

//     cout << a << " -- " << b << endl;

    cout << min(a,b) << endl;
}
