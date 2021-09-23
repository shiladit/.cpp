#include <iostream>
#include <string>
using namespace std;

int start_index; // stores starting index of max palindromic substring
int max_pal_len; // length of max palindromic substring 

int ** init_dptable(string s, int len_s)
{
	int **arr = (int **)malloc(sizeof(int *)*len_s);

	/* Initialize dp table */
	for(int i=0;i<len_s;i++)
	{
		arr[i] = (int *)malloc(sizeof(int *)*len_s);
		for(int j=0;j<len_s;j++)
		{
			/* string starts and ends
			at same position, means it
			will always be a palindrome
			*/
			if(i == j)
			{
				arr[i][i] = 1;
			}
			/* for all i greater than j
			i.e. representing all strings that
			start at i and ends at j,impossible
			*/
			else if(i>j)
			{
				arr[i][j] = 0;
			}
			/* for strings of length 2,
			we look if first and last character
			is same, if yes, its a palindrome,
			else no.
			*/
			else if((i+1) == j)
			{
				if(s[i] == s[j])
				{
					start_index = i;
					max_pal_len = 2;
					arr[i][j] = 1;
				}
				else
				{
					arr[i][j] = 0;
				}
			}
			else
				arr[i][j] = -100; /* dummy value, not computed yet */
		}
	}
	return arr;
}

void solve_dptable(int ** arr,string s,int max_len)
{
	/* considering substring sizes >= 3 */
	for(int len=3;len<=max_len;len++)
	{
		for(int start_x=0;start_x<max_len-len+1;start_x++)
		{
			int end_x = start_x + len - 1;
			if((arr[start_x+1][end_x-1] == 1) && (s[start_x] == s[end_x]))
			{
				arr[start_x][end_x] = 1;
				if( len > max_pal_len)
				{
					start_index = start_x;
					max_pal_len = len;
				}
			}
		}
	} 
}

void print_dptable(int ** arr,int len)
{
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	string s;
	cin >> s;
	int len_s = s.length();

	assert(len_s);
	max_pal_len = 1; // initial value

	int **dp_table = init_dptable(s,len_s);
	//print_dptable(dp_table,len_s);
	solve_dptable(dp_table,s,len_s);
	
	if(max_pal_len > 1)
	{
		cout << "The Longest Palindromic Substring is: "
	 	<< s.substr(start_index,max_pal_len) << endl;
	}
	else
		cout << "All substrings are of length 1" << endl;
}
