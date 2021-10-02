/**
* @author: Priyansh Bhardwaj
* @link: https://www.codechef.com/LTIME100A/problems/SUBLCS
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define i64 long long
#define ld long double
#define F first
#define S second
#define MOD 1000000007
#define pairii pair<int, int>
#define pb push_back
#define endl '\n'
#define matrix vector<vector<int> >
#define vi vector<int>
#define vi64 vector<i64>
#define uset unordered_set
#define umap unordered_map
#define mpr make_pair
#define all(x) x.begin(), x.end()
using namespace std;

i64 modExp(i64 a, int ex);

void getSeries(int ar[], pairii series[], int n, bool decreasing, bool rev) {
	if(decreasing) {
		for(int i=0;i<n;i++) {
			ar[i] = -ar[i];
		}
	}
	if(rev) {
		reverse(ar, ar+n);
	}

	int dp[n];
	fill(dp, dp+n, INT32_MAX);
	umap<int, int> last;
	for(int i=0;i<n;i++) {
		int x = upper_bound(dp, dp+n, ar[i]) - dp;
		series[i] = mpr(x+1, last.count(ar[i]) && series[last[ar[i]]].F == x ? series[last[ar[i]]].S+1 : 1);
		dp[x] = ar[i];
		last[ar[i]] = i;
 	}

	if(decreasing) {
		for(int i=0;i<n;i++) {
			ar[i] = -ar[i];
		}	
	}
	if(rev) {
		reverse(ar, ar+n);
		reverse(series, series+n);
	}
}

void solveMain() {
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++) {
		cin>>ar[i];
	}
	pairii series[4][n];
	getSeries(ar, series[0], n, false, false);
	getSeries(ar, series[1], n, true, true);
	getSeries(ar, series[2], n, true, false);
	getSeries(ar, series[3], n, false, true);

	int lis = 0, lds = 0;
	for(int i=0;i<n;i++) {
		// cout<<series[0][i].F<<" "<<series[1][i].F<<" -> "<<series[2][i].F<<" "<<series[3][i].F<<" => ";
		// cout<<series[0][i].S<<" "<<series[1][i].S<<" -> "<<series[2][i].S<<" "<<series[3][i].S<<endl;
		lis = max(lis, series[0][i].F+series[1][i].F-1);
		lds = max(lds, series[2][i].F+series[3][i].F-1);
	}
	int ans = 0;
	umap<int, int> dp[2];
	for(int i=0;i<n;i++) {
		if(lis == series[0][i].F+series[1][i].F-1) {
			dp[0][ar[i]] = max(dp[0][ar[i]], series[0][i].S + series[1][i].S - 1);
		}
		if(lds == series[2][i].F+series[3][i].F-1) {
			dp[1][ar[i]] = max(dp[1][ar[i]], series[2][i].S + series[3][i].S - 1);
		}
	}
	for(int i=0;i<2;i++) {
		for(auto &it: dp[i]) {
			ans = max(ans, min(it.S, dp[1-i][it.F]));
		}
	}
	cout<<ans<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	fastio
	int t=1;
	cin>>t;
	while(t--) {
		solveMain();
	}
	return 0;
}

i64 modExp(i64 a, int ex) {
	if(!ex) return 1;
	i64 b = modExp(a, ex>>1);
	b = (b*b)%MOD;
	if(ex&1) return (b*a)%MOD;
	return b;
}
