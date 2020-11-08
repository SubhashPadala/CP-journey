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
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}


void solve()
{
    ll n, count = 0;
    cin>>n;
    if(n==2 || n==3)cout<<"NO SOLUTION";
    else if(n==1)cout<<n;
    else
    {
        FOR(i, 1, n+1)
            if(!(i&1))
                cout<<i<<" ";
        FOR(i, 1, n+1)
            if(i&1)
                cout<<i<<" ";
    }
    
    return;
}
