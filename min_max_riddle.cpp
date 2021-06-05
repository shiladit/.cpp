#include <iostream>
#include <climits>
#include <vector>
using namespace std;

/* PARTIALLY SOLVED - because of timeout issue
This can be done using stacks also, but the process is complicated */

#define DUMMY_VAL INT_MAX

void print_matrix(vector < vector <long> > table)
{
	for(int i=0;i<table.size();i++)
	{
		for(int j=0;j<table[0].size();j++)
		{
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

void compute(vector <long> arr)
{
	int len = arr.size();

	vector < vector <long> > table(len, vector <long> (len+1));
	/* initialize table vector */
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<(len+1);j++)
		{
			if(j == 1)
				table[i][j] = arr[i];	
			else
				table[i][j] = DUMMY_VAL;
		}
	}
	
	/* Computing Window sizes from previously computed values */
	for(int j=2;j<(len+1);j++)
	{
		for(int i=0;i<len;i++)
		{
			int index = i + j - 1; // starting index + (window size-1)
			if(index < len)
			{
				if(arr[index] < table[i][j-1])
					table[i][j] = arr[index];
				else
					table[i][j] = table[i][j-1];
			}
		}
	}

	/* DEBUG
	print_matrix(table);
	*/
	
	vector <long> ans;
	for(int j=1;j<(len+1);j++)
	{
		int max_val_in_col = table[0][j];
		for(int i=1;i<len;i++)
		{
			if(table[i][j] != INT_MAX && (table[i][j] > max_val_in_col))
				max_val_in_col = table[i][j];
		}

		ans.push_back(max_val_in_col);
	}

	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	cout << endl;

	return;
}

int main()
{
	long n,temp;
	cin >> n;
	
	vector <long> arr;
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	compute(arr);

	return 0;
}
	
