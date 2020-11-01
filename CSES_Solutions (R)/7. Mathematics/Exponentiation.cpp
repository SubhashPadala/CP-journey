/*
 *     User: Rudr Tiwari (HumbleDynamics18 / dkodar)
 *     Problem: 
 */
 
#include <bits/stdc++.h>
using namespace std;
void solve();
 
#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b; --i)
#define gcx getchar_unlocked
#define pcx putchar_unlocked
#define ll long long
 
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
 
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
	ll a, b;
	cin >> a; cin >> b;
 
	ll ans = 1;
	
	while (b > 0){
 
		if (b & 1)
			ans = (ans*a) % MOD;
 
		b = b>>1;
		a = (a*a) % MOD; 
	}
 
	cout << ans;
}