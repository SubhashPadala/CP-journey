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

const int MAX_N = 2e5 + 1;
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
    //cin >> t;
    while(t--)
    {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock()/CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}

int preprocess[MAX_N][20];

int find_power(int num){

	int j = 0;
	while (1<<j <= num)
		j++;

	return j-1;
}


void solve()
{
	int n, q;
	cin >> n; cin >> q;

	int arr[n];
	FOR(i, 0, n)
		cin >> arr[i];

	// Making of the sparse table.
	FOR(i, 0, n)
		preprocess[i][0] = arr[i];

	for (int j = 1; j <= 20; j++) {
    	for (int i = 0; i + (1 << j) <= n; i++){
			preprocess[i][j] = min(preprocess[i][j-1], preprocess[i+(1<<(j-1))][j-1]);
		}
	}

	// Preprocessing log values.
	int log[MAX_N+1];
	log[1] = 0;
	for (int i = 2; i <= MAX_N; i++)
	    log[i] = log[i/2] + 1;

	FOR(i, 0, q){

		int a, b;
		cin >> a; cin >> b;
		a--; b--;

		int j = log[b - a + 1];
		int minimum = min(preprocess[a][j], preprocess[b - (1 << j) + 1][j]);
		cout << minimum << "\n";
	}

}
