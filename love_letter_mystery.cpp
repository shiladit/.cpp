//shiladitya
#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#include <set>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vl vector < ll >

using namespace std;

int check_pal(int *arr,int n){

    int i=0;
    int j=n-1;

    int sum = 0;

    while(i < j){
        sum += abs(arr[i]-arr[j]);
        i++;
        j--;
    }
    return sum;
}

int main(){
    int q;
    cin >> q;

    while(q--){
        string s;
        cin >> s;
        int n = s.length();

        int arr[n];

        for(int i=0;i<n;i++){
            arr[i] = s[i]-'a';
        }

        cout << check_pal(arr,n) << endl;
    }
}