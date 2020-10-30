/*
 *     User: Rudr Tiwari (HumbleDynamics18 / dkodar)
 *     Problem: Counting Rooms
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)
#define gcx getchar_unlocked
#define pcx putchar_unlocked
#define ll long long

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

bool visited[1000001];
vector<int> adj[1000001];

void dfs(int x)
{
    visited[x]=true;
    for(auto& i : adj[x])
        if(visited[i]==false)
            dfs(i);
}

void solve()
{
	int n, m;
	cin >> n; cin >> m;

	string input[n];
    set<int> dots;

	FOR(i, 0, n)
		cin >> input[i];

	FOR(i, 0, n)
		FOR(j, 0, m-1)
            if (input[i][j] == input[i][j+1] and input[i][j] == '.'){
                adj[i*m+j].push_back(i*m+j+1);
                adj[i*m+j+1].push_back(i*m+j);
            }

    FOR(i, 0, n-1)
        FOR(j, 0, m)
            if (input[i][j] == input[i+1][j] and input[i][j] == '.'){
                adj[i*m+j].push_back((i+1)*m+j);
                adj[(i+1)*m+j].push_back(i*m+j);
            }

    FOR(i, 0, n)
        FOR(j, 0, m)
            if (input[i][j] == '.')
                dots.insert(i*m+j);

    int ans = 0;
    for (int i : dots)
        if (!visited[i]){
            dfs(i);
            ans ++;
        }

    cout << ans;
}
