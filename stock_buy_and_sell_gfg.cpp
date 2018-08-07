#include <bits/stdc++.h>

using namespace std;

int main() {

    int T,N,temp;

    cin >> T;

    while(T){
        cin >> N;

        vector <int> arr;

        for(int i=0;i<N;i++){
            cin >> temp;
            arr.push_back(temp);
        }
        int i=0;
        int j=1;
        while(i < N-1 ){
            int temp = i;
            // cout << temp << endl;
            while(arr[i]<arr[j]){
                i++;
                j++;
            }

            if(temp != i)
                cout << "(" << temp << " " << i << ") " ;

            i=j;
            j=i+1;
        }

        cout << endl;


        T--;
        }
    
}