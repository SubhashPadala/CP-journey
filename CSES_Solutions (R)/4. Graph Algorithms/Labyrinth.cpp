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
 
// bool visited[1000001];
int n, m;
vector<int> parent;
vector<int> adj[1000000];
 
void bfs(int source, int end){
 
	parent.assign(1000000, -1);
	queue<int> q;
	q.push(source);
	parent[source] = -2;
 
	while (q.size()){
 
		int u = q.front(); q.pop();
		if (u == end) break;
		for (int v : adj[u]) {
			if (parent[v] == -1){
				
				parent[v] = u;
				q.push(v);
			}
		}
	}
}
 
void solve()
{
    cin >> n; cin >> m;
 
    char input[n][m];
 
    int source = 0, end = 0;
    FOR(i, 0, n)
    	FOR(j, 0, m){
        cin >> input[i][j];
        if (input[i][j] == 'A'){
        	input[i][j] = '.';
        	source = i*m + j;
        }
 
        if (input[i][j] == 'B'){
        	input[i][j] = '.';
        	end = i*m +j;
        }
    }
 
 
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
 
    bfs(source, end);
    if (parent[end] == -1)
    	cout << "NO";
 
    else{
    	cout << "YES" << "\n";

    	int i = end;
    	string s = "";
    	while (parent[i] != -2){
			if (parent[i] - i == 1)
				s += "L";
			else if (parent[i] - i == -1)
				s += "R";
			else if (parent[i] - i == m)
				s += "U";
			else
				s += "D";
			i = parent[i];
    	}
    	cout << s.size() << "\n";
    	reverse(s.begin(), s.end());
    	cout << s;
    }
    
}