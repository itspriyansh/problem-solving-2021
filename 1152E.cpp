#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define i64 long long
#define ld long double
#define F first
#define S second
#define MOD 1000000007
#define pairii pair<int, int>
#define pb push_back
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
#define matrix vector<vector<int> >
#define vi vector<int>
#define vi64 vector<i64>
#define uset unordered_set
#define umap unordered_map
#define mpr make_pair
#define ALL(x) x.begin(), x.end()
#define RALL(data) data.rbegin(),data.rend()
#define TYPEMAX(type) std::numeric_limits<type>::max()
#define TYPEMIN(type) std::numeric_limits<type>::min()
using namespace std;

#ifdef ONLINE_JUDGE
class NullBuffer : public std::streambuf {
public:
    int overflow(int c) {
        return c;
    }
};
ostream logger(new NullBuffer());
#endif
#ifndef ONLINE_JUDGE
ostream &logger = cout;
#endif
void insertAtStart(int a, vi &b) {
    b.pb(a);
    for(int i=b.size()-1;i>0;i--) {
        b[i] = b[i-1];
    }
    b[0] = a;
}

void dfs(int u, bool vs[], vi adj[], pairii ar[], vi &path, vi &kp) {
    stack<int> state;
    state.push(u);
    while(!state.empty()) {
        auto u = state.top();
        state.pop();
        bool comp = 1;
        while(!adj[u].empty()) {
            int e = adj[u].back();
            adj[u].pop_back();
            if(vs[e]) {
                continue;
            }
            vs[e] = 1;
            int v = ar[e].F+ar[e].S-u;
            state.push(u);
            state.push(v);
            comp = 0;
            break;
        }
        if(comp) {
            path.pb(kp[u]);
        }
    }
}

void solveMain() {
    int n;
    cin>>n;
    int l = 0;
    umap<int, int> mp;
    vi kp;
    pairii ar[n-1];

    for(int i=0;i<n-1;i++) {
        cin>>ar[i].F;
        if(!mp.count(ar[i].F)) {
            mp[ar[i].F] = l++;
            kp.pb(ar[i].F);
        }
    }
    for(int i=0;i<n-1;i++) {
        cin>>ar[i].S;
        if(ar[i].S < ar[i].F) {
            cout<<-1;
            return;
        }
        if(!mp.count(ar[i].S)) {
            mp[ar[i].S] = l++;
            kp.pb(ar[i].S);
        }
    }
    vi adj[l];
    bool vs[n-1];
    for(int i=0;i<n-1;i++) {
        int u = mp[ar[i].F], v = mp[ar[i].S];
        ar[i] = {u,v};
        adj[u].pb(i);
        adj[v].pb(i);
        vs[i] = 0;
    }
    vi path;
    path.reserve(n);
    int s = -1, ends = 0;

    for(int i=0;i<l;i++) {
        if(adj[i].size()&1) {
            s = s == -1 ? i : s;
            ends++;
        }
    }
    logger<<"Total nodes: "<<l<<endl;
    if(ends > 3) {
        cout<<-1;
        return;
    }
    s = s == -1 ? 0 : s;

    dfs(s, vs, adj, ar, path, kp);
    if(path.size() < n) {
        logger<<"Incomplete"<<endl;
        cout<<-1;
        return;
    }
    for(auto &a: path) {
        cout<<a<<" ";
    }
}

void setup() {

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    #ifdef ONLINE_JUDGE
    fastio
    #endif
    setup();
    int t=1;
    // cin>>t;
    while(t--) {
        solveMain();
    }
    return 0;
}
