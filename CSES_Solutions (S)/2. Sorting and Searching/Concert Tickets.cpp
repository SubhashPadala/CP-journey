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
    ll n, m, p=0, j =0;
    cin>>n>>m;

    ll price[n];
    ll max_aff[m];
    FOR(i, 0, n)cin>>price[i];
    FOR(i, 0, m)cin>>max_aff[i];
    sort(price, price+n);
    sort(max_aff, max_aff+m);
    FOR(i, 0, m)
    {
        p = 0;
        while(true)
        {   
            if(max_aff[i]>=price[j])
            {
                p = price[j];
                j++;
                if(price[j-1]==max_aff[i])
                {
                    cout<<p<<endl;
                    break;
                }
                continue;
            }
            else if(p)
            {
                cout<<p<<endl;
                break;
            }
            else if(!p)
            {
                cout<<-1<<endl;
                break;
            }
        }
    }
    return;
}