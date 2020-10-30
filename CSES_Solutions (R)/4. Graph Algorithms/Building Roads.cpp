/*
 *     User: Rudr Tiwari (HumbleDynamics18 / dkodar)
 *     Problem: Building Roads
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)
#define gcx getchar_unlocked
#define pcx putchar_unlocked
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

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
        //cout << "\n";
    }

    cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}

// Remember to change size according to question.
bool visited[MAX_N];
vector<int> adj_list[MAX_N];

void dfs(int x)
{
    visited[x]=true;

    for(auto& i : adj_list[x])
        if(visited[i]==false)
            dfs(i);
}

void solve()
{
    int n, m;
    cin >> n; cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int num = 0;
    vector<int> required_connections;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        	required_connections.push_back(i);
            num++;
        }
    }
    cout << num-1 << "\n"; // number of connected components
    FOR(i, 0, num-1)
    	cout << required_connections[i] << " " << required_connections[i+1] << "\n";
}