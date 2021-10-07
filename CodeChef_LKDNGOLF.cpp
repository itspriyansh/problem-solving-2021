#include<bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t,N,x,k;
	cin >> t;
	while(t--){
		cin >> N >> x >> k;
		if(x%k==0){
			cout << "YES" <<endl;
		} 
		else if((N+1)%k == x%k){
			cout << "YES" <<endl;
		}
		else{
			cout << "NO" <<endl;
		}
	}

	return 0;
}
