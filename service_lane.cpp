#include <iostream>
using namespace std;

int arr[100000];

int main(){
    int n,t;
    cin >> n >> t;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr[i] = x;
    }

    while(t--){
        int a,b;
        cin >> a >> b ;

        int min_val = 9999999;

        for(int j=a;j<=b;j++){
            if(arr[j] < min_val)
                min_val = arr[j];
        }
        cout << min_val << endl;
    }   
}