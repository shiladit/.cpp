#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

string rearrange(string s)
{	
	int n = s.length();
	unordered_map <char,int> freq;

	/* Traverse string and keep count of char freq */
	for(int i=0;i<n;i++)
	{
		freq[s[i]]++;
	}

	/* Max Heap that will store the character with the max
	frequency at the top of the heap */
	priority_queue < pair <int,char> > heap;

	unordered_map <char,int> :: iterator it;
	int max_freq = 0;

	for(it=freq.begin(); it != freq.end(); it++)
	{
		char c = it->first;
		int count = it->second;

		if(count > max_freq)
			max_freq = count;

		heap.push(make_pair(count,c));
	}

	/* if any characters is present more than ceil(n/2) + 1 time,
	then its not possible to rearrange characters, we return -1 */

	if(max_freq >= (ceil(n/2)+1))
		return "Not Possible";

	pair <int,char> swapped_out = make_pair(-1,'#');
	string build_str = "";

	/* Pop top element, ie most freq character from heap, decrease its
	count and store it in a temporary variable (swapped_out) so that
	it is not used the next time. Take the next most frequent character
	from the heap, do the same for this. Insert swapped_out into the 
	heap again, so that it can used next time */
	while(!heap.empty())
	{
		pair <int,char> temp = heap.top();
		heap.pop();

		build_str += temp.second;
		temp.first--;

		/* insert into heap, if count of char > 0 */
		if(swapped_out.first > 0)
			heap.push(swapped_out);

		swapped_out = temp;
	}

	return build_str;
}

int main()
{
	string s;
	cin >> s;

	cout << rearrange(s) << endl;

	return 0;
}
