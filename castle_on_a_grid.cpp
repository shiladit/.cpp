//shiladitya
#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int n;
char arr[100][100];
int moves[100][100];
bool visited[100][100];	

int arrx[4]={-1,1,0,0}; //UP, DOWN, LEFT, RIGHT
int arry[4]={0,0,-1,1};

bool issafe(int x,int y){
	if(x<n && y<n)
		return true;
	else
		return false;
}

int main(){

	cin >> n;

	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		int len = s.length();

		for(int j=0;j<len;j++){
			arr[i][j] = s[j];
		}
	}

	int startx,starty,endx,endy;
	cin >> startx >> starty >> endx >> endy;

	// Preprocessing

	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++){
			moves[i][j] = 10000;
			visited[i][j] = false;
		}

	queue <pair <int,int> > q;
	q.push(make_pair(startx,starty));
	visited[startx][starty] = true;
	moves[startx][starty] = 0;

	int count = 0;

	while(!q.empty()){
		pair <int,int> cord = q.front();
		q.pop();
		int save1 = cord.first;
		int save2 = cord.second;

		count = moves[save1][save2];

		//UP

		int x = save1;
		int y = save2;

		while(issafe(x+arrx[0],y+arry[0]) && !visited[x+arrx[0]][y+arry[0]] && arr[x+arrx[0]][y+arry[0]] == '.' && moves[x+arrx[0]][y+arry[0]] > (count+1)){
			moves[x+arrx[0]][y+arry[0]] = count+1;
			visited[x+arrx[0]][y+arry[0]] = true;
			q.push(make_pair(x+arrx[0],y+arry[0]));
			x--;
		}

		// DOWN

		x = save1;
		y = save2;

		while(issafe(x+arrx[1],y+arry[1]) && !visited[x+arrx[1]][y+arry[1]] && arr[x+arrx[1]][y+arry[1]] == '.' && moves[x+arrx[1]][y+arry[1]] > (count+1)){
			moves[x+arrx[1]][y+arry[1]] = count+1;
			visited[x+arrx[1]][y+arry[1]] = true;
			q.push(make_pair(x+arrx[1],y+arry[1]));
			x++;
		}

		// LEFT

		x = save1;
		y = save2;

		while(issafe(x+arrx[2],y+arry[2]) && !visited[x+arrx[2]][y+arry[2]] && arr[x+arrx[2]][y+arry[2]] == '.' && moves[x+arrx[2]][y+arry[2]] > (count+1)){
			moves[x+arrx[2]][y+arry[2]] = count+1;
			visited[x+arrx[2]][y+arry[2]] = true;
			q.push(make_pair(x+arrx[2],y+arry[2]));
			y--;
		}

		// RIGHT

		x = save1;
		y = save2;

		while(issafe(x+arrx[3],y+arry[3]) && !visited[x+arrx[3]][y+arry[3]] && arr[x+arrx[3]][y+arry[3]] == '.' && moves[x+arrx[3]][y+arry[3]] > (count+1)){
			moves[x+arrx[3]][y+arry[3]] = count+1;
			visited[x+arrx[3]][y+arry[3]] = true;
			q.push(make_pair(x+arrx[3],y+arry[3]));
			y++;
		}
	}
	
	cout << moves[endx][endy] << endl;
}