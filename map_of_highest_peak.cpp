// leetcode
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 99999

int arr_x[4] = {0,0,-1,1};
int arr_y[4] = {1,-1,0,0};

bool isSafe(int x,int y,int m,int n)
{
    if(x>=0 && x<m && y>=0 && y<n)
        return true;

    return false;
}

void print_matrix(vector < vector <int> > &matrix,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout << matrix[i][j] << " ";
        
        cout << endl;
    }
}

vector < vector <int> > calculate(vector < vector <int> > &arr, queue <pair <int,int> > &Q)
{
    int m = arr.size();
    int n = arr[0].size();

    vector < vector <int> > result(m, vector <int> (n,MAX));

    /* process water bodies one by one */
    while(!Q.empty())
    {
        pair <int,int> p = Q.front();
        Q.pop();

        result[p.first][p.second] = 0;

        for(int i=0;i<4;i++)
        {
            int off_1 = p.first + arr_x[i];
            int off_2 = p.second + arr_y[i];
            if(isSafe(off_1,off_2,m,n))
            {
		/* if there is a water body adjacent, then its value needs to be 0, else we can make it 1 */
                if(arr[off_1][off_2] == 1)
                    result[off_1][off_2] = 0;
                else
                    result[off_1][off_2] = 1;
            }
        }
    }

    // fillup neighbouring cells from bottom to top, based on values of
    // neighbours
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(result[i][j] == MAX)
            {
                int loc_max = MAX;
                for(int itr=0;itr<4;itr++)
                {
                    int off_1 = i + arr_x[itr];
                    int off_2 = j + arr_y[itr];
                    if(isSafe(off_1,off_2,m,n) && result[off_1][off_2] != MAX)
                    {
                        loc_max = min(result[off_1][off_2],loc_max);
                    }
                }
                result[i][j] = 1+loc_max;
            }
        }
    }

    // update cell values based on neighbouring cells
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            // don't update values for water bodies
            if(result[i][j] != 0)
            {
                int loc_max = MAX;
                for(int itr=0;itr<4;itr++)
                {
                    int off_1 = i + arr_x[itr];
                    int off_2 = j + arr_y[itr];
                    if(isSafe(off_1,off_2,m,n))
                    {
                        loc_max = min(result[off_1][off_2],loc_max);
                    }
                }
                result[i][j] = 1+loc_max;
            }
        }
    }

    return result;
}

int main()
{
    int m,n,temp;
    cin >> m >> n;
    vector < vector <int> > arr(m, vector <int> (n));
    queue <pair <int,int> > Q;

    /* insert values of water bodies in a Q, process them
       one by one */
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> temp;
            arr[i][j] = temp;
            if(temp == 1)
                Q.push(make_pair(i,j));
        }
    }

    vector <vector <int> > result  = calculate(arr,Q);
    print_matrix(result,m,n);

    return 0;
}

