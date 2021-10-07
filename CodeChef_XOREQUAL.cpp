#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,N,arr[100000];
	cin >> t; 
	for(int i=0;i<100000;i++){
		if(i==0){
			arr[0] = 1;
			continue;
		}
		arr[i]=(arr[i-1]*2)%1000000007;
	}
	while(t--){
		cin >> N;
		cout << arr[N-1] << endl;
	}
	return 0;
}
