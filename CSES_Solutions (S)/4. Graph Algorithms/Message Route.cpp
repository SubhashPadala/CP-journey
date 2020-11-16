/*
 *     User: eu_18 
 *     Problem: Message Route
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define FOR(i,a,b) for(ll i = a; i < b; ++i)
#define RFOR(i,a,b) for(ll i = a; i >= b; --i)
#define ll long long
#define max_n int(1e6)

int n, m;
int BFS(vector<int> adj[], int parent[]);

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

int BFS(vector<int> adj[], int parent[])
{
    bool visited[n+1]={0};
    queue<int>  wait_list;
    visited[1]=true;
    wait_list.push(1);
    while(!wait_list.empty())
    {
        int s = wait_list.front();
        wait_list.pop();
        for(auto i : adj[s])
        {
            if(!visited[i])
            {
                parent[i]=s;
                if(i==n)
                {
                    return 1;
                }
                wait_list.push(i);
                visited[i]=true;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}

void solve()
{
    int x, y;
    cin>>n; cin>>m;
    int parent[n+1];
    vector<int> adj[n+1];
    stack<ll> route;
    FOR(i, 0, m)
    {
        cin>>x>>y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    if (BFS(adj, parent))
    {
        ll k = 0, i = n;
        while(i!=1)
        {
            route.push(i);
            i = parent[i];
            k++;
        }
        cout<<k+1<<endl<<"1 ";
        while(!route.empty()){cout<<route.top()<<" ";route.pop();}
    }
    return;
}
