#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

//https://www.hackerrank.com/challenges/the-great-xor/problem?isFullScreen=true
/*Some of the observations:
For a number which is one less than power of 2, the answer is 0.
The reason for this is any number less than that would flip one or more bits(from all 1s) which causes the value to decrease.
For a number which is power of 2, the answer is one less than the input.
For other numbers, we see that the answer can be obtained from its group.*/

/*
 * Complete the 'theGreatXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER x as parameter.
 */

long theGreatXor(long x) {
    return (1ull<<((long)log2(x)+1))-1-x;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string x_temp;
        getline(cin, x_temp);

        long x = stol(ltrim(rtrim(x_temp)));

        long result = theGreatXor(x);

        fout << result << "\n";
    }

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
