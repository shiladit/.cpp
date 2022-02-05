//https://www.geeksforgeeks.org/print-possible-strings-can-made-placing-spaces/

#include <iostream>
#include <string>

using namespace std;

void printpattern(string s, string buff, int i, int j)
{
	if(i == s.length())
	{
		buff[j] = '\0';
		cout << buff << endl;
		return;
	}

	buff[j] = s[i];
	printpattern(s,buff,i+1,j+1);

	buff[j] = ' ';
	buff[j+1] = s[i];
	printpattern(s,buff,i+1,j+2);

	return;
}

int main()
{
	string s;
	cin >> s;

	int n = s.length();

	char buff[2*n];

	buff[0] = s[0];

	printpattern(s,buff,1,1);

	return 0;
}