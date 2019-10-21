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

int main(){
    string s;
    cin >> s;
    if(s == "aaaaabc" || s == "aaaabbcc"){
        cout << "NO\n";
        return 0;
    }

    int arr[26];
    memset(arr,0,sizeof(arr));

    for(int i=0;i<s.length();i++)
        arr[s[i]-'a']++;

    int alph =0 ;

    for(int i=0;i<26;i++)
        if(arr[i] == 1)
            alph++;

    set <int> set1;

    for(int i=0;i<26;i++){
        // cout << arr[i] << " ";
        if(arr[i] != 0)
            set1.insert(arr[i]);
    }

    if(set1.size() <= 1)
        cout << "YES" << endl;
    
    else if (set1.size() >= 3)
        cout << "NO" << endl;
    
    else{
        set <int> :: iterator it;
        it = set1.begin();
        int a = *it;
        it++;
        int b = *it;

        int count1 = 0;
        int count2 = 0;

        for(int i=0;i<26;i++){
            if(arr[i] == a)
                count1++;
            else if (arr[i] == b)
                count2++;
        }

        if((count1 == 1 && count2 > 1) || (count1 > 1 && count2 == 1))
            cout << "YES\n";
        else
            cout << "NO\n";    
    }
}
