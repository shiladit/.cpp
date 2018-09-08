#include <bits/stdc++.h>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) {
    
    vector <int> arr(32,0);
    
    int i = arr.size()-1;

    while(n !=0){
        int temp = n%2;
        arr[i--] = temp;
        n = n/2;
    }
    
    long number=0;
    int j=0;
    
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i] == 0){
            number += 1 * pow(2,j);
        }
        j++;
    }
        

    return number;
}

int main()
{

    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;

        long result = flippingBits(n);
        cout << result << "\n";
    }

    return 0;
}

