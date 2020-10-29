/*
 *     User: eu18
 *     Problem: Distinct Numbers
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

    //#ifndef ONLINE_JUDGE
    //freopen("inputf.txt", "r", stdin);
    //freopen("outputf.txt", "w", stdout);
    //#endif

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
    ll n, m, k, appa;
    cin>>n>>m>>k;
    vector<ll> avail;
    vector<ll> appl;
    FOR(i, 0, n){cin>>appa;appl.push_back(appa);}
    FOR(i, 0, m){cin>>appa;avail.push_back(appa);}
    ll count=0;
    sort(avail.begin(), avail.end());
    sort(appl.begin(), appl.end());
    while(!avail.empty() && !appl.empty())
    {
            if(appl.back()-k<=avail.back() && appl.back()+k>=avail.back())
            {
                avail.pop_back();
                appl.pop_back();
                count++;
            }
            else if(avail.back()>appl.back()+k){
                avail.pop_back();
            }
            else if(appl.back()>avail.back()+k){
                appl.pop_back();
            }
    }
    cout<<count;
    return;
}