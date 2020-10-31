/*
 *     User: eu_18 
 *     Problem: Laybrinth
 */

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6+7;
void solve();
#define ll long long
#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)

void BFS(ll source, ll destination);
char get_direction(ll source, ll destination);
void get_pathnlen(ll source, ll destination);

ll n, m;
bool visited[MAX_N];
vector<ll> adj[MAX_N];
ll parent[MAX_N];

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

char get_direction(ll source, ll destination)
{
    int val = destination - source;
    if(val==m)
    {
        return 'D';
    }
    else if(val==-m)
    {
        return 'U';
    }
    else if(val == -1)
    {
        return 'L';
    }
    else if(val == 1)
    {
        return 'R';
    }
    return '0';
}

void get_pathnlen(ll source, ll destination)
{
    string path;
    ll i = destination;
    //FOR(i, 0, destination+1)cout<<parent[i];
    //cout<<get_direction(parent[destination], destination);
    //return;
    while(1)
    {
        path.push_back(get_direction(parent[i], i));
        //cout<<'acd';
        if(parent[i]==source)
        {
            cout<<"YES\n"<<path.size()<<"\n";
            RFOR(i, path.size()-1, 0)cout<<path[i];
            return;
        }
        i=parent[i];
    }
    return;
}


void BFS(ll source, ll destination)
{
    queue<ll> q;
    q.push(source);
    visited[source]=true;
    while(q.size())
    {
        int last = q.front();
        q.pop();
        if(last==destination)
        {
            //cout<<"YES"<<endl;
            get_pathnlen(source, destination);
            return;
        }
        for(auto i : adj[last])
        {
            if(!visited[i])
            {
                parent[i]=last;
                q.push(i);
                visited[i]=true;
            }
        }
    }
    cout<<"NO";
    return;
}

void solve()
{
    cin>>n>>m;
    ll source, destination;
    source=destination=0;
    string input[n];
    FOR(i,0, n)cin>>input[i];
    FOR(i, 0, n)
    {
        FOR(j, 0, m-1)
        {
            if(input[i][j]==input[i][j+1] && input[i][j]=='.')
            {
                adj[i*m+j].push_back(i*m+j+1);
                adj[i*m+j+1].push_back(i*m+j);
            }
        }
    }
    FOR(i, 0, n-1)
    {
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
            if(input[i][j]=='A')
            {
                source = i*m+j;
                if(j<m-1 && input[i][j+1]=='.')
                {
                    adj[i*m+j].push_back(i*m+j+1);
                    adj[i*m+j+1].push_back(i*m+j);
                }
                if(j>0 && input[i][j-1]=='.')
                {
                    adj[i*m+j].push_back(i*m+j-1);
                    adj[i*m+j-1].push_back(i*m+j);
                }
                if(i<n-1 && input[i+1][j]=='.')
                {
                    adj[i*m+j].push_back((i+1)*m+j);
                    adj[(i+1)*m+j].push_back((i)*m+j);
                }
                if(i>0 && input[i-1][j]=='.')
                {
                    adj[i*m+j].push_back((i-1)*m+j);
                    adj[(i-1)*m+j].push_back((i)*m+j);
                }
            }
            if(input[i][j]=='B')
            {
                destination = i*m+j;
                if(j<m-1 && input[i][j+1]=='.')
                {
                    adj[i*m+j+1].push_back(i*m+j);
                    adj[i*m+j].push_back(i*m+j+1);
                }
                if(j>0 && input[i][j-1]=='.')
                {
                    adj[i*m+j-1].push_back(i*m+j);
                    adj[i*m+j].push_back(i*m+j-1);
                }
                if(i<n-1 && input[i+1][j]=='.')
                {
                    adj[(i+1)*m+j].push_back(i*m+j);
                    adj[(i)*m+j].push_back((i+1)*m+j);
                }
                if(i>0 && input[i-1][j]=='.')
                {
                    adj[(i-1)*m+j].push_back(i*m+j);
                    adj[(i)*m+j].push_back((i-1)*m+j);
                }
            }
        }
    }
    if(get_direction(source, destination)!='0')
    {
        cout<<"YES\n1\n"<<get_direction(source, destination);
        return;
    }
    BFS(source, destination);
    return;
}

