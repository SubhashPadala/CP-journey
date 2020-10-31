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

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif

    int t=1;
    /*is Single Test case?*/cin >> t;
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
	int N = 0;
	cin >> N;

	//ll product = 1;
	int arr[N];
	FOR(i, 0, N){

		cin >> arr[i];
		//product *= arr[i];
	}

	int l = 1;
	if (__gcd(arr[0], arr[1]) != 1)
		l = 2;

	for (int i = 2; i < N; i++){

		for (int j = 0; j < l; j++)
			if (__gcd(arr[i], arr[j]) != 1){
				l = i+1;
				break;
			}
	}

	cout << l;

}