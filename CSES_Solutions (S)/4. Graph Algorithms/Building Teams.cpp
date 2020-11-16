/*
 *     User: eu_18 
 *     Problem: Building Teams
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)
#define ll long long
#define max_n int(1e6)

bool BuildTeams(vector<int> adj[], int teamof[], int n);

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif

    int t=1;
    //cin >> t;
    while(t--)
    {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}

void solve()
{
    int n, m, x, y;
    cin>>n; cin>>m;
    vector<int> adj[n+1];
    int teamof[n+1]={0};
    FOR(i, 0, m)
    {
        cin>>x;                 cin>>y;
        adj[x].push_back(y);    adj[y].push_back(x);
    }
    if(BuildTeams(adj, teamof, n))
    {
        FOR(i, 1, n+1)
        {
            cout<<teamof[i]<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
}

bool BuildTeams(vector<int> adj[], int teamof[], int n)
{
    bool visited[n+1] = {0};
    FOR(i, 1, n+1)
    {
        if(visited[i])continue;
        queue<int> waitlist;
        int source = i;
        waitlist.push(i);
        visited[i]=true;
        teamof[i]=1;
        while(!waitlist.empty())
        {
            int u = waitlist.front();
            waitlist.pop();
            for(auto v : adj[u])
            {
                if(teamof[u]==teamof[v])return false;
                else if(!visited[v])
                {
                    visited[v]=true;
                    waitlist.push(v);
                    teamof[v]=(teamof[u]==1)?2:1;
                }
            }

        }
    }
    return true;
}
