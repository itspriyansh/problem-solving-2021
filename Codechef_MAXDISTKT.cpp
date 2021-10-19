//https://www.codechef.com/SNCKQL21/problems/MAXDISTKT/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
    
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	vector<pair<int,int>> arr;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    arr.push_back({x,i});
	}
	sort(arr.begin(),arr.end());
	int k=0;
	for(int i=0;i<n;i++){
	    if(arr[i].first>k){
	        arr[i].first=k;
	        k++;
	    }
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<n;i++){
	    cout << arr[i].first<<" ";
	}
	cout<<endl;
	}
	return 0;
}
