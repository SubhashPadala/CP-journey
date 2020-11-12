/*
 *     User: eu18
 *     Problem: Restaurant Customers
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define FOR(i,a,b) for(ll i = a; i < b; ++i)
#define RFOR(i,a,b) for(ll i = a; i >= b; --i)
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

void solve()
{
    ll n, curr_count=0, max=0;
    cin>>n;
    ll arrival[n];  ll depature[n];
    FOR(i, 0, n)cin>>arrival[i]>>depature[i];
    ll j = 0;
    sort(arrival, arrival+n);   sort(depature, depature+n);
    FOR(i, 0, n)
    {
        curr_count++;
        max = (max>curr_count)?max:curr_count;
        if(i==n-1)
        {
            cout<<max;
            return;
        }
        while(arrival[i+1]>depature[j])
        {
            j++;
            curr_count--;
        }
    }
    return;
}