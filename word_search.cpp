#include <bits/stdc++.h>
using namespace std;

int arr_1[4] = {0,0,-1,1};
int arr_2[4] = {-1,1,0,0};
bool exist = false;
int n,m;

bool isSafe(int x, int y)
{
    if(x >=0 && x<n && y>=0 && y<m)
        return true;

    return false;
}

void call_dfs(int x, int y, int index, string word, vector < vector <bool> > visited, vector < vector <char> > board)
{
	if(index == word.length())
	{
		exist = true;
		return;
	}

	if(word[index] == board[x][y])
	{
		visited[x][y] = true;

		for(int j=0;j<4;j++)
		{
			if(isSafe(x+arr_1[j],y+arr_2[j])
				&& (visited[x+arr_1[j]][y+arr_2[j]] == false))
			{
				call_dfs(x+arr_1[j],y+arr_2[j],index+1,word,visited,board);
			}
		}
	}
	else
		return;
}

int main()
{
	cin >> n >> m;
	string temp;

	vector < vector <char> > board(n, vector <char> (m));
	vector < vector <bool> > visited(n, vector <bool> (m));

	for(int i=0;i<n;i++)
	{
		cin >> temp;
		for(int j=0;j<temp.length();j++)
		{
			board[i][j] = temp[j];
		}
	}

	string word;
	cin >> word;

	int start = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j] == word[start]) // first char of word matches, I start my dfs from here
			{
				call_dfs(i,j,start,word,visited,board);
			}

			if(exist == true)
				goto end;
		}
	}

end:
	if(exist)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}
