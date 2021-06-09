#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <char> dict;

void print_string(int index, int k, string s)
{
	if(index == k)
	{
		cout << s << endl;
		return;
	}

	for(int i=0;i<dict.size();i++)
	{
		string temp = s;
		temp += dict[i];
		print_string(index+1,k,temp);
	}
}

int main()
{
	dict.push_back('a');
	dict.push_back('b');

	int k;
	cin >> k;
	string s = "";
	print_string(0,k,s);

	return 0;
}
