/*
 *     User: eu18
 *     Problem: Missing Number
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
    ll n, input;
    cin>>n;
    ll sum=n*(n+1)/2;
    n--;
    while(n--){
    
        cin>>input;
        sum-=input;
    }
    cout<<sum;
    return;
}