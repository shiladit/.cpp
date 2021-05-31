#include <iostream>
using namespace std;

int main()
{
	long cur_costpergame, discount, min_costpergame, budget;
	cin >> cur_costpergame >> discount >> min_costpergame >> budget;

	long no_of_games = 0;
	
	while(budget-cur_costpergame >= 0)
	{
		budget = budget - cur_costpergame;
		++no_of_games;
		
		if((cur_costpergame - discount) <= min_costpergame)
			cur_costpergame = min_costpergame;
		else
			cur_costpergame = cur_costpergame - discount;
	}

	cout << no_of_games << endl;
}
