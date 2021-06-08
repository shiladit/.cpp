#include <iostream>
#include <cmath>
using namespace std;

int numSquares(int n)
{
	/* if number is already a perfect square, we
	obviously return 1 */
	if(n - (floor(sqrt(n))*floor(sqrt(n))) == 0)
		return 1;

	/* we can't break these down into smaller perfect squares */
	if(n==1 || n==2 || n==3)
	{
		return n;
	}

	/* initial max result, any number can
	 be represented by square of all 1's */
	int result = n;

	/* for each partition of i^2 and (n-i^2) we compute
	store in result, compare it and take the minimum */
	for(int i=1;i<=n;i++)
	{
		if((i*i) > n)
			break;
		else
			result = min(result, numSquares(i*i) + numSquares(n-(i*i)));
	}

	return result;
}

int main()
{
	int n;
	cin >> n;
	cout << numSquares(n) << endl;
	return 0;
}
