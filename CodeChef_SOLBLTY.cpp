#include<iostream>
using namespace std;

int main(){

    int t, X,A,B;
    cin >> t;
    while(t--){
        cin >> X >> A >> B;
        int sum = A+(100-X)*B;
        cout << sum*10 << endl;
    }
    return 0;
}
