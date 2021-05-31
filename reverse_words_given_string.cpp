#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string s;
	cin >> s;

	stack <string> stk;

	int x=0;
	int y=0;

	while(y < s.length())
	{
		if(s[y] == '.')
		{
			string temp = s.substr(x,(y-x));
			y++;
			x = y;
			stk.push(temp);
		}
		else
			y++;
	}
	
	/* last word insertion */
	stk.push(s.substr(x,(y-x)));

	while(!stk.empty())
	{
		string temp = stk.top();
		stk.pop();
		if(stk.empty())
			cout << temp << endl;
		else
			cout << temp << ".";
	}
}
