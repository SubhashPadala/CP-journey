/*
 *     User: eu18
 *     Problem: Distinct Numbers
 */

#include <bits/stdc++.h>
using namespace std;
void solve();

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)
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
    ll n, m, k;
    cin>>n>>m>>k;
    map<ll, ll> req;
    ll req_size[n];
    ll avail_size[n];
    FOR(i, 0, n)cin>>req_size[i];
    FOR(i, 0, m)cin>>avail_size[i];
    sort(req_size, req_size+n);
    sort(avail_size, avail_size+m);
    ll j=0, count=0;
    FOR(i, 0, n){
        FOR(j, 0, m){
            if(req_size[i]-k<=avail_size[j] && req_size[i]+k>=avail_size[j]){
                count++;
                break;
            }
        }
    }
    return;
}