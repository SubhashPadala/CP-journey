/*
 *     User: eu18
 *     Problem: Concert Tickets.cpp
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define FOR(i,a,b) for(long long i = a; i < b; ++i)
#define RFOR(i,a,b) for(long long i = a; i >= b; --i)
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
    ll n, m, curr, ticket;
    cin>> n >> m;
    multiset<ll, greater<ll>> tickets;
    while(n--)
    {
        cin>>ticket;
        tickets.insert(ticket);
    }
    while(m--)
    {
        cin>>curr;
        auto it = tickets.lower_bound(curr);
        if(it == tickets.end())
        {
            cout << -1 << endl;
        }
        else
        {
            cout<< *it << endl;
            tickets.erase(it);
        }
        
    }
    return;
}