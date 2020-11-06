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
    ll n, k, q;
    cin>>n>>q;
    ll sum[n+1]={0};
    FOR(i, 1, n+1)
    {
        cin>>k;
        sum[i]=k+sum[i-1];
    }
    FOR(i, 0, q)
    {
        ll a, b;
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<"\n";
    }
    return;
}
