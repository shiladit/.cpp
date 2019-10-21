//shiladitya
#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vl vector < ll >
#define vvi vector < vector <int> >
#define vvc vector < vector <char> > 
// #define pqueue priority_queue< int >
// #define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;

int main(){
	string s;
	getline(cin,s);

	int count = 0;

	f(i,0,s.length())
		if(s[i] != ' ')
			count++;

	int row =  floor(sqrt(count));
	int column =  ceil(sqrt(count));

	bool turn = true;

	while(row*column < count){
		if(turn)
			row++;
		else
			column++;

		turn = !turn;
	}

	char arr[row][column];

	int i=0;
	int j=0;

	for(int k=0;k <s.length();k++){
		if(s[k] != ' ' && s[k] >= 'a' && s[k] <= 'z'){
			arr[i][j] =  s[k];
			j++;
		}

		if(j == column){
			i++;
			j = 0;
		}
	}

	for(int j=0;j<column;j++){
		for(int i=0;i<row;i++){
			if(arr[i][j] >= 'a' && arr[i][j] <= 'z')
				cout << arr[i][j] ;
			}
		cout << " ";
	}
} 