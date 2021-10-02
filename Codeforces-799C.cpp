/**
 * @author: Anjali Agrawal
 * @link: http://codeforces.com/problemset/problem/799/C
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
#define uset unordered_set
#define umap unordered_map
#define mpr make_pair
#define INF INT32_MAX
using namespace std;

i64 modExp(i64 a, int ex) {
	if(!ex) return 1;
	i64 b = modExp(a, ex>>1);
	b = (b*b)%MOD;
	if(ex&1) return (b*a)%MOD;
	return b;
}

struct Sparse {
	matrix dp;
	int m, n;

	Sparse(vector<pair > &ar) {
		m = ar.size();
		n = log2(m) + 1;
		dp.resize(m);
		for(int i=0;i<m;i++) {
			dp[i].resize(n);
		}
		for(int j=0;j<n;j++) {
			for(int i=0;i-1+(1<<j)<m;i++) {
				if(!j) {
					dp[i][j] = ar[i].S;
					continue;
				}
				dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
			}
		}
	}

	int query(int l, int r) {
		int len = log2(r-l+1);
		return max(dp[l][len], dp[r-(1<<len)+1][len]);
	}
};

struct Segment {
	vi tree;
	int n, l;

	Segment(vector<pair > &ar) {
		n = ar.size();
		if(!n) return;
		l = 4*n+1;
		tree.resize(l);
		build(0, n-1, ar);
	}

	void build(int l, int r, vector<pair > &ar, int i=0) {
		if(l == r) {
			tree[i] = ar[l].S;
			return;
		}
		int m = (l+r)/2;
		build(l, m, ar, 2*i+1);
		build(m+1, r, ar, 2*i+2);
		tree[i] = max(tree[2*i+1], tree[2*i+2]);
	}

	int query(int a, int b) {
		return query(a, b, 0, n-1);
	}

	int query(int a, int b, int l, int r, int i=0) {
		if(r<a || l>b) {
			return 0;
		}
		if(a<=l && b>=r) {
			return tree[i];
		}
		int m = (l+r)/2;
		return max(query(a,b,l,m,2*i+1), query(a,b,m+1,r,2*i+2));
	}
};

void solveMain() {
	int n,c,d;
	cin>>n>>c>>d;
	vector<pair > ar[2];
	ar[0].reserve(n);
	ar[1].reserve(n);
	int a,b;
	char C;
	for(int i=0;i<n;i++) {
		cin>>a>>b>>C;
		ar[C-'C'].pb(make_pair(b, a));
	}
	sort(ar[0].begin(), ar[0].end());
	sort(ar[1].begin(), ar[1].end());
	Sparse sp[] = { Sparse(ar[0]), Sparse(ar[1]) };
	// Segment sp[] = { Segment(ar[0]), Segment(ar[1]) };
	int cnt = 0;
	i64 ans = 0;
	int it = upper_bound(ar[0].begin(), ar[0].end(), make_pair(c, INF)) - ar[0].begin() - 1;
	// cout<<it<<endl;
	if(it >= 0) {
		ans += sp[0].query(0, it);
		cnt++;
	}
	it = upper_bound(ar[1].begin(), ar[1].end(), make_pair(d, INF)) - ar[1].begin() - 1;
	// cout<<it<<endl;
	if(it >= 0) {
		ans += sp[1].query(0, it);
		cnt++;
	}
	if(cnt < 2) {
		ans = -INF;
	}
	int money[] = {c, d};
	for(int i=0;i<2;i++) {
		for(int j=0;j<ar[i].size();j++) {
			auto &a = ar[i][j];
			if(a.F >= money[i]) break;
			it = upper_bound(ar[i].begin(), ar[i].end(), make_pair(money[i]-a.F, INF)) - ar[i].begin() - 1;
			// cout<<i<<", "<<j<<", "<<it<<endl;
			if(it <= j) break;
			ans = max(ans, 1ll*a.S+sp[i].query(j+1, it));
		}
	}
	cout<<(ans == -INF ? 0 : ans);
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
