/* https://practice.geeksforgeeks.org/problems/interleaved-strings/1 */

#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
bool fun(int i,int j,int k, string A, string B, string C){
    
    if(k == C.size())
        return true;
    
    if(i == A.size() && j == B.size())
        return false;
    
    if(A[i] == C[k] && B[j] == C[k])
        return fun(i+1,j,k+1,A,B,C) || fun(i,j+1,k+1,A,B,C);
    
    if(A[i] == C[k])
        return fun(i+1,j,k+1,A,B,C);
    
    if(B[j] == C[k])
        return fun(i,j+1,k+1,A,B,C);
        
    return false;
        
}


bool isInterleave(string A, string B, string C) 
{
    int i=0;
    int j=0;
    int k=0;
    
    return fun(i,j,k,A,B,C);
}