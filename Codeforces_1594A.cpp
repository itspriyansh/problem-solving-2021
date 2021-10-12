/* Codeforces Problem Link : https://codeforces.com/contest/1594/problem/A */
/* A very direct and simple approach to the problem. The problem has been rated for 800
   and below, someone may overcomplicate the problem in order to determine the numbers
   but we need to note that it says to print only one pair if multiple pairs lead to the
   given number lets visualize this using the number line :
   ..........-4,-3,-2,-1,0,1,2,3,4.................. we can see that when we move one no.
   to the right we add 1 and if we move same value in left side both of the numbers cancel
   each other -1+1=0, this is the trick. No matter which number we want as the sum we can
   always add 1 extra to the current sum to get the number for example we want 5 then we sum
   -4 + -3 + -2 + -1 + 0 + 1 + 2 + 3 + 4 + 5 = 5, there may be other pairs but we need to 
    only one and (-n+1, n) will always satisfy the condition */
#include <iostream>
using namespace std;
int main()
{
    long long int t {},n {};
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << -n+1 << " " << n << endl;
        n = 0;
    }
    return 0;
}
