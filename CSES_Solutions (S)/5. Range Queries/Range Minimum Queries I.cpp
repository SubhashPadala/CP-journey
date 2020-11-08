/*
 *     User: eu_18 
 *     Problem: 
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define ll long long
#define FOR(i,a,b) for(ll i = a; i < b; ++i)
#define RFOR(i,a,b) for(ll i = a; i >= b; --i)
#define max_n int(1e6)


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


void solve()
{
    ll n, q;
    cin>>n>>q;
    ll logs[n+1]={0};
    FOR(i, 2, n+1)
    {
        logs[i] = logs[i/2]+1;
    }
    ll table[logs[n]+1][n+1]={0};
    ll p = logs[n]+1;
    ll curr_len, end_;
    FOR(i, 0, p)
    {
        curr_len = (1<<i);
        end_=n-curr_len+2;
        FOR(j, 1, end_)
        {
            if(curr_len==1)cin>>table[i][j];
            else table[i][j]=min(table[i-1][j], table[i-1][j+curr_len/2]);
        }
    }
    ll a, b, p_curr, start2;
    FOR(i, 0, q)
    {
        cin>>a>>b;
        p_curr = logs[b-a+1];
        start2 = b-(1<<p_curr)+1;
        cout<<min(table[p_curr][a], table[p_curr][start2])<<"\n";
    }
    return;
}
