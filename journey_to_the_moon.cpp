// Hackerrank
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

map <long, vector <long> > mp;

/* Find size of each connected component
Using Queue and BFS here, same can be done Union-Find */
vector <long> cal_conncomp(int n)
{
    map <long, vector <long> > :: iterator it;
    vector <bool> visited(n,false);
    vector <long> result;
    long sum = 0;

    for(it = mp.begin(); it!=mp.end(); it++)
    {
        long count = 0;
        queue <long> Q;
        if(visited[it->first] == false)
        {
            Q.push(it->first);
            visited[it->first] = true;
        }
        /* skip if already visited */
        else
            continue;

        while(!Q.empty())
        {
            long val = Q.front();
            count++;
            Q.pop();

            vector <long> temp = mp[val];
            for(int i=0;i<temp.size();i++)
            {
                if(visited[temp[i]] == false)
                {
                    visited[temp[i]] = true;
                    Q.push(temp[i]);
                }
            }
        }
        /* keep track of the total number of nodes seen */
        sum += count;
        result.push_back(count);
        //cout << it->first << " --> " << count << endl;
    }

    /* Nodes which are not seen are single nodes have component size as 1 */
    for(int i=0;i<(n-sum);i++)
        result.push_back(1);

    return result;
}

int main()
{
    long n,p;
    cin >> n >> p;

    long val_1,val_2;

    for(int i=0;i<p;i++)
    {
        cin >> val_1 >> val_2;
        mp[val_1].push_back(val_2);
        mp[val_2].push_back(val_1);
    }

    vector <long> comps = cal_conncomp(n);

    /* This routine calculates the total number of ways
    we can pair astronauts from different countries */
    long prev_res = 0;
    long cur_res = 0;
    for(int i=0;i<comps.size();i++)
    {
        cur_res += prev_res * comps[i];
        prev_res = prev_res + comps[i];
    }

    cout << cur_res << endl;

    return 0;
}
