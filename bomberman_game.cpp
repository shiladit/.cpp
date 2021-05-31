#include <iostream>
#define dim 200

using namespace std;

long r,c,n;
int arr[dim][dim];

int offsetx[4] = { 0, 0, -1, 1};
int offsety[4] = { -1, 1, 0, 0};

bool issafe(int x,int y)
{
    if(x>=0 && x<r && y>=0 && y<c)
        return true;
    else
        return false;
}

void show_matrix(int x, int y)
{ 
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++) 
        {
            if(arr[i][j] == 0)
            {
                cout << ".";
            }
            else
            {
                cout << "O";
            }
        }
    cout << endl;
    }
}

bool will_explode(int x)
{
    if(++x == 4)
        return true;

    return false;
}

   
int main() {

    cin >> r >> c >> n;

    for(int i=0;i<r;i++)
    {
        string s;
        cin >> s;

        for(int j=0;j<c;j++)
        {
            if(s[j] == '.')
            {                
                arr[i][j] = 0; // empty
            }
            else
            {
                arr[i][j] = 2; // bomb
            }
        }
    }
    

    long time =2;

    /* Pattern repeats and hence this :-) */
    if(n > 100000)
	n = n%64;
    else if (n > 1000)
        n = n%32;
    else if (n > 100)
        n = n%16;

    while(time <= n)
    {
	bool visited[dim][dim] = { { false } };

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(will_explode(arr[i][j]))
                {
		    arr[i][j] = 0 ;
                    visited[i][j] = true ;

    		    for(int s=0;s<4;s++)
                    {
	                int a = offsetx[s];
	                int b = offsety[s];

                        if(issafe(i + a,j + b)
                           && (!will_explode(arr[i + a][j + b]))
                           && visited[i + a][j + b] == false)
                           {
                            arr[i + a][j + b] = 0;
                            visited[i + a][j + b] = true;
                           }
                    }
                    //cout << "Bombs found at: " << i << " "  << j << endl;
                }
		else if (visited[i][j] == false)
                         ++arr[i][j]; // increment bomb counter
            }
        }
    /*
    cout << "At time: " << time << endl;    
    show_matrix(r,c);
    */
    ++time;
    }
    /* Output */
    show_matrix(r,c);
}
