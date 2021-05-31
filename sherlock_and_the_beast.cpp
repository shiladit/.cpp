//shiladitya
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s(n,'5');

        if(n%3 == 0)
            cout << s << endl;
        else if (n < 5 || n ==7)
            cout << "-1" << endl;
        else {
            int len_5 = n;
            int len_3 = 0;

            bool flag = false;

            int len = n;

            while(len_3 < n && len_5 >=0 && len > 0){

            	if(len >= 5){
                	s.replace(len-5,5,"33333");
                	len_3 += 5;
                	len_5 -= 5;
                	len = len -5;
                }

                if(len_3 >= 0 && len_5 >= 0 && (len_3%5 ==0) && (len_5%3 == 0)){
                    flag = true;
                    break;
                }
            }

            if(flag)
                cout << s << endl;
            else
                cout << "-1" << endl;
        }
    }
}