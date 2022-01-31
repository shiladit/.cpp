#include <vector>
#include <iostream>
using namespace std;

/* Check no of nodes, reachable from every other node in graph */

#define INF 10000

int solution(vector<int> &A, vector<int> &B,int n) {

    int arr[n][n];

    for(int i=0;i<A.size();i++)
    {
        arr[A[i]][B[i]] = 100;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                arr[i][j] = 0;
            else if (arr[i][j] != 100)
                arr[i][j] = INF;
        }
    }


    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[k][j] != INF && arr[i][k] != INF)
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    for(int i=0;i<n;i++)
    {   
        int count = 0;

        for(int j=0;j<n;j++)
        {
            if(arr[j][i] == INF)
                break;
            else
                count++;
        }

        if(count == n)
            return i;
    }

    return -1;
}

int main()
{
    int N;
    cin >> N;

    vector <int> A(N);
    vector <int> B(N);

    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }


    for(int i=0;i<N;i++)
    {
        cin >> B[i];
    }

    cout << solution(A,B,N+1) << endl;

    return 0;
}

/* 
Sample Test Case

4
2 3 3 4
1 1 0 0

*/