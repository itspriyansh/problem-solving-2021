/**
 * @author: Anjali Agrawal
 * @link: http://codeforces.com/problemset/problem/832/C
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define i64 long long
#define ld long double
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
#define all(x) x.begin(), x.end()
using namespace std;

i64 modExp(i64 a, int ex);

struct Triplet {
	double x;
	int y,z;
	
	Triplet(double x, int y, int z): x(x), y(y), z(z) {}

	static bool compare(Triplet &a, Triplet &b) {
		return a.x < b.x || (a.x == b.x && a.y > b.y);
	}
};

void solveMain() {
	int n,s,x,y,z;
	cin>>n>>s;
	vector<pair > people[2];
	for(int i=0;i<n;i++) {
		cin>>x>>y>>z;
		people[z-1].pb(mpr(x,y));
		if(z == 2) {
			people[z-1].back().F = 1e6 - people[z-1].back().F;
		}
	}
	// int debug = 0;
	double low = 0, high = 1e6, ans = 1e6;
	for(int t=0;t<100;t++) {
		double mid = (low+high) / 2.0;
		// if(t==debug) {
		// 	cout<<"Time: "<<mid<<endl;
		// }
		int cnt[] = {0, 0};
		bool ok = false;
		vector<Triplet > results;
		results.reserve(2*n);
		
		for(int i=0;i<2;i++) {
			for(int j=0;j<people[i].size();j++) {
				pair &p = people[i][j];
				if(p.F <= mid*p.S) {
					results.pb(Triplet(0, 1, i));
					results.pb(Triplet(1e6, -1, i));
					continue;
				} else if(p.F > mid*(s+p.S)) {
					continue;
				}
				double k = min(1e6, ((mid*(s+p.S)-p.F)*(1.0*s-p.S))/(1.0*s) + 1.0*p.F);
				if(!i) {
					results.pb(Triplet(p.F, 1, i));
					results.pb(Triplet(floor(k), -1, i));
				} else {
					results.pb(Triplet(1e6-floor(k), 1, i));
					results.pb(Triplet(1e6-p.F, -1, i));
				}
			}
		}
		sort(all(results), Triplet::compare);
		for(auto &r: results) {
			// if(t==debug) {
			// 	cout<<r.x<<" -> "<<r.y<<" -> "<<r.z<<endl;
			// }
			cnt[r.z] += r.y;
			if(cnt[0]>0 && cnt[1]>0) {
				ok = true;
				break;
			}
		}
		if(ok) {
			ans = mid;
			high = mid;
		} else {
			low = mid;
		}
	}
	cout<<fixed<<setprecision(30)<<ans;
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
