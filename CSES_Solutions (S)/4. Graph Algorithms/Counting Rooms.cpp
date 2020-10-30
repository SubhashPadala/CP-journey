/*
 *     User: eu_18 
 *     Problem: Counting Rooms
 */

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6+7;
void solve();
void dfs(int x);

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)
#define ll long long

ll n, m;

bool visited[MAX_N];
vector<ll> adj[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
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
void dfs(int x)
{
    visited[x]=true;
    for(auto& i:adj[x])
    {
        if(visited[i]==false)
            dfs(i);
    }
}
void solve()
{
    cin>>n>>m;
    string input[n];
    set<int> floors;
    FOR(i, 0, n)
        cin>>input[i];
    FOR(i, 0, n){
        FOR(j, 0, m-1)
        {
            if(input[i][j]==input[i][j+1] && input[i][j]=='.'){
                adj[i*m+j].push_back(i*m+j+1);
                adj[i*m+j+1].push_back(i*m+j);
            }
        }
    }
    FOR(i, 0, n-1){
        FOR(j, 0, m)
        {
            if(input[i][j]==input[i+1][j] && input[i][j]=='.')
            {
                adj[i*m+j].push_back((i+1)*m+j);
                adj[(i+1)*m+j].push_back(i*m+j);
            }
        }
    }
    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            if(input[i][j]=='.')
                floors.insert(i*m+j);
        }
    }
    ll nrooms = 0;
    for(int i : floors)
    {
        if(!visited[i])
        {
            dfs(i);
            nrooms++;
        }
    }
    cout<<nrooms;
}

