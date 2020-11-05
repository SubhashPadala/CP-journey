/*
 *     User: Rudr Tiwari (HumbleDynamics18 / dkodar)
 *     Problem: 
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)
#define gcx getchar_unlocked
#define pcx putchar_unlocked
#define ll long long

const int MAX_N = 2e5 + 1;
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
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}

// Remember to change size according to question.
bool visited[MAX_N] = {false};
bool visited2[MAX_N] = {false};
vector<int> adj_list[MAX_N];
int _count=0;

void dfs(int x)
{
    visited[x]=true;

    for(auto& i : adj_list[x]){
        if(visited[i]==false){
            dfs(i);
            if (visited2[x]==false and visited2[i] == false){
            	_count++;
            	visited2[x] = true; visited2[i] = true;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1);
    cout << _count;
}