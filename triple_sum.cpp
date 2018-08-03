#include<bits/stdc++.h>

using namespace std;

int main() {
    int p,q,r;
    cin >> p >> q >> r;
    
    set <long> s;
    int temp;
    
    vector <long> arr1;
    vector <long> arr2;
    vector <long> arr3;
    
    for(int i=0;i<p ;i++){
        cin >> temp;
        if(s.find(temp) == s.end()){
            s.insert(temp);
            arr1.push_back(temp);
        }
            
    }

    sort(arr1.begin(),arr1.end());
    
    // set <long> :: iterator it ;
    
    // for(it = s.begin(); it != s.end(); it++)
    //     cout << *it << " ";
    // cout << endl;
    
    
    
    s.clear();
    
    for(int i=0;i<q ;i++){
        cin >> temp;
        if(s.find(temp) == s.end()){
            s.insert(temp);
            arr2.push_back(temp);
        }
    }

    sort(arr2.begin(),arr2.end());
    
    
    s.clear();
    
    for(int i=0;i<r ;i++){
        cin >> temp;
        if(s.find(temp) == s.end()){
            s.insert(temp);
            arr3.push_back(temp);
        }
    }
    
    sort(arr3.begin(),arr3.end());
   
    s.clear();
    
    long count1 =0;
    long count2 =0;
    long long int sum = 0;
    long last1 = 0;
    long last2 =0;
    long i=0;
    long j=0;
    long k=0;
    
    for(i=0;i<arr2.size();i++){
        for(j=last1;j<arr1.size();j++){
            if(arr2[i] >= arr1[j])
                count1++;
            else
                break;
            
            }  
        
        last1= count1;
        
        for(k=last2;k<arr3.size();k++){
            if(arr2[i] >= arr3[k])
                count2++;
            else
                break;  
           
        }
        last2 = count2;
        sum +=(count1*count2);
        // cout << sum << endl;
      
    }
    
    cout << sum << endl;
    
    
    return 0;
} 