/**
 * @author: Anjali Agrawal
 * @link: http://codeforces.com/problemset/problem/776/C
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
#define matrix vector<vector<int> >
#define vi vector<int>
#define vi64 vector<i64>
#define uset unordered_set
#define umap unordered_map
#define mpr make_pair
using namespace std;

i64 modExp(i64 a, int ex);

void solveMain() {
	int n, k;
	cin>>n>>k;
	int ar[n];
	i64 sum[n+1];
	sum[0] = 0;
	map<i64, int> cnt;
	cnt[0]++;
	for(int i=0;i<n;i++) {
		cin>>ar[i];
		sum[i+1] = sum[i]+ar[i];
	}
	i64 lim = 1e14, ans = 0;
	for(int i=1;i<=n;i++) {
		for(i64 p=1;p<=lim;) {
			if(cnt.count(sum[i]-p)) {
				ans += cnt[sum[i]-p];
			}
			p *= k;
			if(p==1) break;
		}
		cnt[sum[i]]++;
	}
	cout<<ans;
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

i64 modExp(i64 a, int ex) {
	if(!ex) return 1;
	i64 b = modExp(a, ex>>1);
	b = (b*b)%MOD;
	if(ex&1) return (b*a)%MOD;
	return b;
}
