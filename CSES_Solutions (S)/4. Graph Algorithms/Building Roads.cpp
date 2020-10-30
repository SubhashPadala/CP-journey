/*
 *     User: eu_18 
 *     Problem: Building Roads
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
vector<ll> new_roads;

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
void dfs(int x, vector<ll> adj[])
{
    visited[x]=true;
    for(auto i : adj[x])
    {
        if(visited[i]==false)
            dfs(i, adj);
    }
}
void solve()
{
    cin>>n>>m;
    vector<ll> adj[n];
    ll x, y;
    while(m--)
    {
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    ll need = 0;
    FOR(i, 0, n)
    {
        if(!visited[i])
        {
            new_roads.push_back(i);
            dfs(i, adj);
            need++;
        }
    }
    cout<<need-1;
    ll i=new_roads.size()-1;
    while(new_roads.size()!=1)
    {
        cout<<endl;
        cout<<new_roads[i]+1<<" "<<new_roads[i-1]+1;
        new_roads.pop_back();
        i--;
    }
}

