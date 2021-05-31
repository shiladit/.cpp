#include <bits/stdc++.h>
using namespace std;

#define modulo 1000000007

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
	find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
	s.end()
	);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(str.substr(start));
	return tokens;
}

long countArray(int n, int k, int x)
{
	/*
	ends_x at index i, keeps count of how many sequences
	i can create of length i+1, that ends with x
	ends_any at index i, keeps count of how many sequences i can
	create of length i+1, that ends with anything other than x
	*/
	long long ends_x[n];
	long long ends_any[n];

	/* if array starts with 1 and ends with other than 1, then
	ends_x[0] will be initialized to 0, because a single length
	array can't have starting index as x*/
	/* if x is also 1, then it is a possibility and hence ends_x[0]
	will be 1 */
	if(x == 1)
		ends_x[0] = 1;
	else
		ends_x[0] = 0;

	/* array of length 1, can end with anything other than 1, if x != 1
	if x == 1, then it can't be */
	if(x == 1)
		ends_any[0] = 0;
	else
		ends_any[0] = 1;

	for(long i = 1; i < n ; i++)
	{
		/* no. of arrays of length i+1, ending at x is same
		as no. of arrays of length i that didn't end at x */
		ends_x[i] = ends_any[i-1] % modulo;

		/* no. of arrays of length i+1, which ends with anything
		other than x is equal to the no. of arrays of length i ending
		with x multiplied by all possible values other than itself (k-1)
		+
		no. of arrays of length i ending with anything other than x
		multiplied by all possible values other than x and itself (k-2)
		*/
		ends_any[i] = (ends_x[i-1] * (k-1) + ends_any[i-1] * (k-2)) % modulo;
	}

	long long result = ends_x[n-1];
	result = result % modulo;

	return result;
}

int main()
{
	string first_multiple_input_temp;
	getline(cin, first_multiple_input_temp);
	vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

	int n = stoi(first_multiple_input[0]);
	int k = stoi(first_multiple_input[1]);
	int x = stoi(first_multiple_input[2]);

	//cout << n << " " << k << " " << x << endl;
	cout << countArray(n, k, x) << endl;

	return 0;
}
