#include <iostream>
#include <map>
#include <vector>
using namespace std;

void show_flavors(map <long, vector <long> > flavors)
{
	map <long, vector <long> > :: iterator ptr;
	for(ptr = flavors.begin(); ptr != flavors.end(); ptr++)
	{
		vector <long> temp_vec = ptr->second;
		cout << ptr->first << " -----> " ;
		for(int x=0;x<temp_vec.size();x++)
		{
			cout << temp_vec[x] << " -> ";
		}
		cout << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		long money;
		cin >> money;
		long arr_size;
		cin >> arr_size;

		map <long,vector <long> > flavors;
		long temp;
		vector <long> input;

		for(int j=0;j<arr_size;j++)
		{
			cin >> temp;
			input.push_back(temp);
			flavors[temp].push_back(j+1); // storing index value for flavors
		}

		/* show_flavors(flavors); */

		for(int j=0;j<input.size();j++)
		{
			if(((money-2*input[j]) == 0)
			 && (flavors.find(money-input[j]) != flavors.end())
			 && (flavors[money-input[j]].size() > 1))
			{
				/* since we are outputting the results in ascending order, index comparison is
				   useless, we just print the first two indexes in the hash-map */
				cout << flavors[money-input[j]][0] << " " << flavors[money-input[j]][1] << endl;
				break;
			}

			else if(flavors.find(money-input[j]) != flavors.end() && (j+1 != flavors[money-input[j]][0]))
			{
				cout << (j+1) << " " << flavors[money-input[j]][0] << endl; // j+1 since index starting from 1
				break;
			}
		}
	}
}
