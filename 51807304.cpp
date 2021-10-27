//https://www.codechef.com/START14C/problems/FIXFIX
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const ll MOD = 1e9 + 7;
void printArr(int arr[], int n,string s="\n"){
	if(s==" "){
		for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;	
	}
	else{
		for(int i=0;i<n;i++){
		cout<<arr[i]<<'\n';
	}
	}
	}
void inputArr(int arr[],int n){
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
}
void inputVector(vector<int>v,int n){
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
}

int min(int a, int b){
	if(a>b)
		return b;
	return a;
}
int max(int a, int b){
	if(a>b)
		return a;
	return b;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
	
		 if(n-k==1){
			cout<<-1<<endl;
		}
		else if((n-k)%2==0){
			
			for(int i =1;i<k+1;i++){
				cout<<i<<" ";
				
			}

			for(int i=n;i>k;i--){
				
				cout<<i<<" ";
			}
			cout<<endl;
		}
		else{
			
			for(int i =1;i<=k;i++){
				cout<<i<<" ";
			}
			cout<<n<<" ";
			for(int i = k+1;i<n;i++){
				cout<<i<<" ";
			}
			cout<<endl;

		}
		}
	return 0;
}
