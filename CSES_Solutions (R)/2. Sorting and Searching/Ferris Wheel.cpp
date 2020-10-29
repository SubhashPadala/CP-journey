/*
 *     User: Rudr Tiwari (HumbleDynamics18 / dkodar)
 *     Problem: Ferris Wheel
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
	int n, x;
	cin >> n; cin >> x;

	int weights[n];
	FOR(i, 0, n)
		cin >> weights[i];

	sort(weights, weights+n);

	// Just use 2 pointers.
	int i = 0, j = n-1;
	int ans = 0;
	int visited = 0;
	while (i < j){

		if (weights[i] + weights[j] <= x){
			i += 1; j -= 1;
			ans += 1; visited += 2;
		}

		else
			j -= 1;
	}

	if (i == j){
		visited += 1;
		ans += 1;
	}

	ans += (n - visited);

	cout << ans;

}