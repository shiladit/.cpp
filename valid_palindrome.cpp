#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s)
{
    int l = 0;
    int r = s.length()-1;
    
    while(l < r)
    {
        if(s[l] != s[r])
            return false;
        else
        {
            l++;
            r--;
        }
    }
    
    return true;
}

bool isPalindrome(string s)
{
    string temp = "";

    /* Take input string and concatenate
    all alpha-numeric characters from the
    string into a new one */
    for(int i=0;i<s.length();i++)
    {
        char c = tolower(s[i]);
	/* Alpha-Numeric check */
        if(isalnum(c))
            temp += c;
    }

    return checkPalindrome(temp); 
}

int main()
{
	string s;
	cin >> s;

	if(isPalindrome(s))
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}
