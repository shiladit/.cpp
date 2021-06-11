#include <iostream>
#include <string>
using namespace std;

/* args are: string, k pairs of parentheses,
l_p is no. of left brackets and r_p is no. of
right brackets */
void gen_par(string s, int k, int l_p, int r_p)
{
	/* :Bad Case:
	1. no. of right brackets are more than left brackets
	2. no. of left brackets are more than k
	3. no. of right brackets are more than k
	*/
	if(r_p > l_p || l_p > k || r_p > k)
		return;

	if(l_p == k && r_p == k)
	{
		cout << s << endl;
		return;
	}

	/* we can only put right brackets only when
	we have more left brackets than right brackets
	*/
	if(l_p > r_p)
	{
		gen_par(s + ")", k, l_p, r_p+1);
		gen_par(s + "(", k, l_p+1, r_p);
	}
	else
		gen_par(s + "(", k, l_p+1, r_p);

	return;
}

int main()
{
	int k;
	cin >> k;
	gen_par("",k,0,0);

	return 0;
}
