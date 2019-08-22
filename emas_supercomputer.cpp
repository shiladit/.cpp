//shiladitya
#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)
#define mod (1000*1000*1000+7)
#define vi vector < int >
#define vl vector < ll >
#define vvi vector < vector <int> >
#define vvc vector < vector <char> > 
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

using namespace std;
vvc grid(15);
int n,m;

bool issafe(int x,int y){
	if(x >=0 && x <n && y >=0 && y <m)
		return true;
	else
		return false;
}

int find_plus(int x,int y) {

	bool flag = false;
	int area = 1;
	int i=1;
	int j=1;

	while(!flag){

		int count = 0;
		
		//UP
		if(issafe(x-i,y) && grid[x-i][y] == 'G')
			count++;

		//RIGHT
		if(issafe(x,y+j) && grid[x][y+j] == 'G')
			count++;
		
		//DOWN
		if(issafe(x+i,y) && grid[x+i][y] == 'G')
			count++;

		//LEFT
		if(issafe(x,y-j) && grid[x][y-j] == 'G')
			count++;

		if(count == 4){
			area = area + 4;
			i++;
			j++;
		}
		else
			flag = true;
	}

	return area;

}

bool compare(pair <int,pair<int,int> > a,pair <int,pair<int,int> > b){
	if(a.first > b.first)
		return true;
	else
		return false;
}

/* ***********************************************************************************************************************/


bool overlapping(pair <int, pair<int,int> > a,pair <int, pair<int,int> > b){

	bool visited[15][15];

	int x = a.second.first;
	int y = a.second.second;

	int g = b.second.first;
	int h = b.second.second;


	//Initializing the visited matrix

	f(i,0,15)
	   f(j,0,15)
	   		visited[i][j] = false;

	visited[x][y] = true;

	int area_tillnow = 1;
	int i=1;
	int j=1;


	// Filling the first plus of the grid

	while(area_tillnow < a.first){

		visited[x-i][y] =true;

		visited[x][y+j] =true;
		
		visited[x+i][y] =true;
		
		visited[x][y-j] =true;

		area_tillnow += 4;
		i++;
		j++;
	}

	// Checking if there are any overlaps or not, if overlaps return true

	area_tillnow = 1;
	i=1;
	j=1;

	visited[g][h] = true;

	while(area_tillnow < b.first){

		if(visited[g-i][h] == true)
			return true;

		if(visited[g][h+j] == true)
			return true;
		
		if(visited[g+i][h] == true)
			return true;
		
		if(visited[g][h-j] == true)
			return true;

		area_tillnow += 4;
		i++;
		j++;
	}
	return false;
}


/* ***********************************************************************************************************************/


int main() {
	
cin >> n >> m;

f(i,0,n){
	string s;
	cin >> s;
	for(int j=0;j<s.length();j++)
		grid[i].push_back(s[j]);
}

vector <pair <int, pair<int,int> > > arr; 

for(int i=0;i<n-1;i++)
	for(int j=0;j<m-1;j++){
		if(grid[i][j] == 'G'){
			int initial_area = 1;
			int area = find_plus(i,j);

			while(initial_area <= area){
				arr.push_back(make_pair(initial_area,make_pair(i,j)));
				initial_area += 4;
			}
		}
	}

sort(arr.begin(),arr.end(),compare);

vector <pair <int, pair<int,int> > > :: iterator it;
pqueue max_heap;

/* Checking */

// for(it=arr.begin();it!=arr.end();it++){
// 	pair <int, pair<int,int> > p = *it;
// 	cout << p.first << " --> " <<  p.second.first << "," << p.second.second << endl; 
// }

for(int i=0;i<arr.size();i++)
	for(int j=0;j<arr.size();j++) {
		if(i != j){
			pair <int, pair<int,int> > p1 = arr[i];
			pair <int, pair<int,int> > p2 = arr[j];

			if(overlapping(p1,p2) == false)
				max_heap.push(p1.first * p2.first);
		}
	}

cout << max_heap.top() << endl;
}



/*DEBUG

for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		cout << << endl;

cout << << << endl;

*/

