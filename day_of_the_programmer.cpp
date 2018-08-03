#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
void solve(int year) {
    
    bool greg = false;
    bool julian = false;
    
    if(year > 1917)
        greg = true;
    else 
        julian = true;
    
    bool leap = false;
    
    if(greg == true){
        if((year%400 == 0) || (year%4 ==0 && year%100 !=0))
            leap = true;
    }
    else{
        if(year%4 ==0 )
            leap = true;        
    }
     

    if(leap == true )
        cout << "12.09." << year << endl;
    else{
        if(year != 1918)
            cout << "13.09." << year << endl;
        else
            cout <<"26.09." << year << endl;
    }


}

int main()
{
    
    int year;
    cin >> year;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(year);

    return 0;
}

