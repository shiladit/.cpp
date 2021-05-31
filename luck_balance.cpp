//shiladitya
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n,k;
    cin >> n >> k;

    int sum = 0;
    vector <int> luck;
    int imp = 0;

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;

        if(b == 1){
            imp++;
            luck.push_back(a);
        }
        
        sum += a;
    }

    sort(luck.begin(),luck.end());

    int sum_luck =0;

    for(int i=0;i<(imp-k);i++)
        sum_luck += luck[i];

    cout << sum - (2*sum_luck) << endl;
}