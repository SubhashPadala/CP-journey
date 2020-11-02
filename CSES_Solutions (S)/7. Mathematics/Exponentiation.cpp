/*
 *     User: eu_18 
 *     Problem: Exponentiation
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define ll unsigned long long
#define FOR(i,a,b) for(ll i = a; i < b; ++i)
#define RFOR(i,a,b) for(ll i = a; i >= b; --i)
#define gcx getchar_unlocked
#define pcx putchar_unlocked
const int m = 1e9+7;

ll exp_(ll a, ll b, ll mod);
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
        //cout << "\n";
    }

    cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}

ll exp_(ll a, ll b, ll mod)
{
    if(b==0)
    {
        return 1;
    }
    else if(b%2==0)
    {
        ll y = exp_(a, b/2, mod);
        return ((y*y)%mod);
    }
    else
    {
        return ((a%mod)*(exp_(a, b-1, mod)))%mod;
    }
}
void solve()
{
    ll a, b, e;
    cin>>a>>b;
    e = exp_(a, b, m);
    cout<<e<<"\n";
}
