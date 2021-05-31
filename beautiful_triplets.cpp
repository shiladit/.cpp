#include <iostream>
#include <map>
using namespace std;

/* Since input is in non-decreasing order and d is never negative,
 there is no need to keep track of index. Instead we keep track of
 the number of occurances. Because for multiple occurances, each will
 form a beautiful triplet if condition satisfies. */

map <int,int> numbers;

int is_beautifultriplet(int val,int diff)
{
	if (numbers.find(val+diff) == numbers.end())
		return 0;
	if (numbers.find(val+diff+diff) == numbers.end())
		return 0;

	return numbers[val];
}

int main()
{
	int n,d,temp;
	cin >> n >> d;

	for(int i=0;i<n;i++)
	{
		cin >> temp;
		if(numbers.find(temp) != numbers.end())
			numbers[temp]++;
		else
			numbers[temp] = 1;
	}

	map <int,int> :: iterator it;
	int count = 0;

	for(it = numbers.begin(); it != numbers.end(); it++)
	{
		count += is_beautifultriplet(it->first,d);
	}

	cout << count << endl;
}
