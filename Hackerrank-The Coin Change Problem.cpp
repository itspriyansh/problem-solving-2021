/**
* @author: Sabyasachi Behera
* @problem: https://www.hackerrank.com/challenges/coin-change/problem
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */
 

long recursol (long ** dp, int n, vector<long> c, int ind) {

    if (n == 0) {
        return dp[0][ind] = 1;
    }
    if (dp[n][ind] != 0)
        return dp[n][ind];
    
    long tot = 0, curval;
    
    for (int i = ind; i < c.size (); ++i) {
        if (c[i] <= n) {
            if ((curval = recursol (dp, n - c[i], c, i)) > 0) {
                tot += curval;
            }
        }
    }
    return dp[n][ind] = tot;
}

long getWays(int n, vector<long> c) {
    
    long ** dp = new long* [n+1];
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = new long [c.size ()];
        memset (dp[i], 0, c.size () * sizeof (long));
    }
    
    long ans = recursol (dp, n, c, 0);
    
    for (int i = 0; i <= n; ++i)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    sort (c.begin (), c.end ());
    long ways = getWays(n, c);

    fout << ways << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
