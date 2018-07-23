#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
void findDigits(int n) {

    
    
    int count = 0;
    int number = n;
    
    while(n != 0){
        int temp = n%10;
       
        n = n/10;
        
        if((temp !=0) && (number%temp == 0))
            count++;
        
    }

cout << count<< endl;
}

int main()
{

    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;

        findDigits(n);      
    }

    return 0;
}

