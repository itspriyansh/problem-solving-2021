/**
 * @author: Anjali Agrawal
 * @link: http://codeforces.com/problemset/problem/812/C
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define i64 long long
#define F first
#define S second
#define MOD 1000000007
#define pair pair<int, int>
#define pb push_back
#define endl '\n'
#define matrix vector<vector<int>>
using namespace std;

void solveMain() {
	int n;
	i64 S;
	cin>>n>>S;
	i64 ar[n], trial[n];
	for(int i=0;i<n;i++) {
		cin>>ar[i];
	}
	int ans = 0, l = 0, r = n;
	i64 mx = 0;
	while(l <= r) {
		int k = (l+r)/2, idx = 0;
		for(int i=0;i<n;i++) {
			trial[idx++] = ar[i] + (i64)k*(i+1);
		}
		sort(trial, trial+n);
		i64 total = 0;
		for(int i=0;i<k && total <= S;i++) {
			total += trial[i];
		}
		if(total <= S) {
			ans = k;
			mx = total;
			l = k+1;
		} else {
			r = k-1;
		}
	}
	cout<<ans<<' '<<mx;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	fastio
	int t=1;
	// cin>>t;
	while(t--) {
		solveMain();
	}
	return 0;
}
