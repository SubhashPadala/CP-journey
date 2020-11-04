/*
 *     User: eu_18 
 *     Problem: Subordinates
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; ++i)
#define RFOR(i,a,b) for(ll i = a; i >= b; --i)
#define max_n int(1e6)

void dfs(ll source, ll end, ll subordinates, vector<ll> adj_list[]);

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    //#ifndef ONLINE_JUDGE
    //freopen("inputf.txt", "r", stdin);
    //freopen("outputf.txt", "w", stdout);
    //#endif

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

void dfs(ll source, ll end, ll subordinates[], vector<ll> adj_list[])
{
    subordinates[source]=1;
    for(auto u : adj_list[source])
    {
        if(u==end)continue;
        dfs(u, source, subordinates, adj_list);
        subordinates[source]+=subordinates[u];
    }
    return;
}

void solve()
{
    ll n, k;
    cin>>n;
    vector<ll> adj_list[n+1];
    ll subordinates[n+1];
    FOR(i, 2, n+1)
    {
        cin>>k;
        adj_list[k].push_back(i);
    }
    dfs(1, 0, subordinates, adj_list);
    FOR(i, 1, n+1)
    {
        cout<<subordinates[i]-1<<" ";
    }
    cout<<endl;
    return;
}
