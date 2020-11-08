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
    cin >> t;
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
    ll y, x;
    cin>>y>>x;
    ll k = max(x, y);
    if(k%2==0 && y==k)
    {
        cout<<k*k-x+1;
    }
    else if(k%2==0 && x==k)
    {
        cout<<(k-1)*(k-1)+y;
    }
    else if(y==k)
    {
        cout<<(k-1)*(k-1)+x;
    }
    else if(x==k)
    {
        cout<<k*k-y+1;
    }
    return;
}
