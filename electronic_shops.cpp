#include <iostream>
#include <vector>

using namespace std;

int main() {
    long b,n,m;
    cin >> b >> n >> m;

    vector <int> v1;
    vector <int> v2;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }

    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        v2.push_back(x);
    }

    int max_b = 0;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(v1[i] + v2[j] > max_b && v1[i] + v2[j] <= b)
                max_b = v1[i] + v2[j];
        }

    if(!max_b)
        cout << -1 << endl;
    else
        cout << max_b << endl;
}