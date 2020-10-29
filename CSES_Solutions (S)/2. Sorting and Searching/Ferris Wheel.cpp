/*
 *     User: eu18
 *     Problem: Ferris Wheel.cpp
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
    ll n, x;
    cin>>n>>x;
    ll weights[n];
    for(ll i=0; i<n; i++)cin>>weights[i];
    sort(weights, weights+n);
    ll count, visited, i;
    i=count=visited=0;
    ll j=n-1;
    while(i<j){
        if(weights[i]+weights[j]<=x){
            count++;
            visited+=2;
            i++;
            j--;
        }
        else{
            count++;
            visited+=1;
            j--;
        }
    }
    if(i==j)count++;
    cout<<count;
    return;
}