#include <bits/stdc++.h>

using namespace std;

#define ROW 9
#define COL 10

struct Point {
	int x;
	int y;
};

void print_v(int arr[ROW][COL]){
	
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << " - -- - - - - - \n";

}

bool isvalid(int x,int y){
	if(x >= 0 && x <ROW && y >=0 && y <COL)
		return true;
	else
		return false;
}

int BFS(int mat[ROW][COL],Point s,Point d){

	int visited[ROW][COL] = {{0}};

	int distance[ROW][COL] ;

	for(int i=0;i<ROW;i++)
		for(int j=0;j<COL;j++)
			distance[i][j] = INT_MAX;

	queue <pair <int,int> > q;
	
	q.push(make_pair(s.x,s.y)); //Inserting source vertex to the queue
	distance[s.x][s.y] = 1;

	int x[4] = {1,0,0,-1};
	int y[4] = {0,1,-1,0};

	while(!q.empty()){
		pair <int,int> p = q.front();
		q.pop();
		
		//if(p.first == d.x && p.second == d.y) //We have reached destination
		// 	result.push();

		for(int i=0;i<4;i++){
			if(isvalid(p.first+x[i],p.second+y[i]) && mat[p.first+x[i]][p.second+y[i]] == 1 && visited[p.first+x[i]][p.second+y[i]] == 0){
				visited[p.first+x[i]][p.second+y[i]] = 1;

				distance[p.first+x[i]][p.second+y[i]] = min(distance[p.first][p.second] + 1,distance[p.first+x[i]][p.second+y[i]]); 
				q.push(make_pair(p.first+x[i],p.second+y[i]));
			}
		}

	}

	cout << "Printing Visited Matrix\n";

	print_v(visited);
	
	cout << "Printing Distance Matrix\n";

	print_v(distance);

	return distance[d.x][d.y];

}


int main() 
{ 
    int mat[ROW][COL] = 
    { 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
        { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 }, 
        { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 } 
    }; 
  
    Point source = {0, 0}; 
    Point dest = {8, 9}; 
  
    int dist = BFS(mat, source, dest); 
  
    if (dist != INT_MAX) 
        cout << "Shortest Path is " << dist << endl ; 
    else
        cout << "Shortest Path doesn't exist" << endl; 
  
    return 0; 
} 



