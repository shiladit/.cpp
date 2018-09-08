/* https://www.geeksforgeeks.org/given-two-unsorted-arrays-find-pairs-whose-sum-x/ */

#include <bits/stdc++.h>
using namespace std;

bool compare (pair <long,long> &a,pair <long,long> &b){
	if (a.first < b.first)
		return true;
	else
		return false;
}

int main() {
	long t;
	cin >> t;
	while(t--){
	    long n,m,temp,sum;
	    cin >> n >> m >> sum;
	    
	    vector <long> arr1;
	    
	    set <long> s;
	    
	    for(int i=0;i<n;i++){
	        cin >> temp;
	        s.insert(temp);
	    }
	    
	    vector <pair <long,long> > result; 

	    for(int i=0;i<m;i++){
	        cin >> temp;
	        if(s.find(sum-temp) !=s.end())
	            result.push_back(make_pair(sum-temp,temp));
	        
	    }


	    if(result.size() == 0)
	    	cout << -1 << endl;
	    else {
	    	sort(result.begin(),result.end(),compare);
	    	for(int i=0;i<result.size();i++){
	    		pair <long,long> p = result[i];
	    		if(i != result.size()-1)
	    			cout << p.first << " " << p.second << ", ";
	    		else
	    			cout << p.first << " " << p.second;
	    	}
	    	cout << endl;
	    }
	}
	
	return 0;
}