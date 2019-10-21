#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;

	while(q--){
		int a,b,c;
		cin >> a >> b >> c;

		if(abs(a-c) > abs(b-c))
			cout << "Cat B\n";
		else if(abs(a-c) < abs(b-c))
			cout << "Cat A\n";
		else
			cout << "Mouse C\n";
	}
}