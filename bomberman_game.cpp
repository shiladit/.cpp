#include <iostream>
// #define long ll
#define DIM 200

using namespace std;

long r,c,n;
int arr[DIM][DIM];
int g1[DIM][DIM];
int g2[DIM][DIM];
int g3[DIM][DIM];
int g4[DIM][DIM];

int arrx[4] = {1,0,-1,0};
int arry[4] = {0,1,0,-1};

bool issafe(int x,int y){
	if(x>=0 && x<r && y>=0 && y<c)
		return true;
	else
		return false;
}

int main() {

	cin >> r >> c >> n;
	int time = 0;

	for(int i=0;i<r;i++){
		string s;
		cin >> s;
		for(int j=0;j<c;j++){
			if(s[j] == '.')				
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			if(arr[i][j] == 1)
				g1[i][j] = 2;
		}
	time = 1;

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			g2[i][j] = g1[i][j] + 1;
		}
	time = 2;

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			if(g2[i][j] == 1 || g2[i][j] == 2)
				g3[i][j] = g2[i][j] + 1;
			
			}

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			if (g2[i][j] == 3){
				for(int k=0;k<4;k++){
					int x = i + arrx[k];
					int y = j + arry[k];
					if(issafe(x,y))
						g3[x][y] = 0;
				}
			}
		}

	time = 3;

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			g4[i][j] = g3[i][j] + 1;
		}

	time =4;


	if(n%4 == 1){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(g1[i][j] == 0)
					cout << ".";
				else
					cout << "O";
				// cout << g1[i][j];
			}
		cout << endl;
		}
	}
	else if (n%4 == 2){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(g2[i][j] == 0)
					cout << ".";
				else
					cout << "O";
				// cout << g2[i][j];
			}
		cout << endl;
		}

	}
	else if(n%4 == 3){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(g3[i][j] == 0)
					cout << ".";
				else
					cout << "O";
				// cout << g3[i][j];
			}
		cout << endl;
		}

	}
	else{
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(g4[i][j] == 0)
					cout << ".";
				else
					cout << "O";
				// cout << g4[i][j];
			}
		cout << endl;
		}

	}


}