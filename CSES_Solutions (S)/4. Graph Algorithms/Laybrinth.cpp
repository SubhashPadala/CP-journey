/*
 *     User: eu_18 
 *     Problem: Laybrinth
 */

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6+7;
void solve();
#define ll long long
void BFS(ll source, ll destination);
char get_direction(ll source, ll destination);
#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)


ll n, m;
bool visited[MAX_N];
vector<ll> adj[MAX_N];
vector<char> path;

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

void BFS(ll source, ll destination)
{
    queue<vector<char>> paths;
    queue<ll> q;
    vector<char> curr_path;
    curr_path.push_back('X');
    paths.push(curr_path);
    q.push(source);
    visited[source]=true;
    while(q.size())
    {
        curr_path = paths.front();
        paths.pop();
        int last = q.front();
        q.pop();
        if(last==destination)
        {
            string s(++curr_path.begin(), curr_path.end());
            cout<<"YES\n"<<s.length()<<"\n"<<s;
            cout<<endl;
            return;
        }
        for(auto i : adj[last])
        {
            if(!visited[i])
            {
                vector<char> newpath(curr_path);
                char direction = get_direction(last, i);
                newpath.push_back(direction);
                paths.push(newpath);
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
    /*FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            cout<<endl;
            cout<<i*m+j<<" : ";
            for(auto k : adj[i*m+j])cout<<k<<", ";
            cout<<endl;
        }
    }*/
    if(get_direction(source, destination)!='0')
    {
        cout<<"YES\n1\n"<<get_direction(source, destination);
        return;
    }
    //cout<<source<<destination<<endl;
    BFS(source, destination);
    return;
}

