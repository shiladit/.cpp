#include <iostream>
using namespace std;

int gcd(int a,int b)
{
	int temp = a;

	a = b%a;

	if(a == 0)
		return temp;

	b = temp;

	return gcd(a,b);
}

int main()
{
	int x,y;
	cin >> x >> y;

	if(x > y)
		swap(x,y);

	cout << gcd(x,y) << endl;

	return 0;
}