#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*The flippingBits function takes an unsigned integer n as input.
It uses the XOR (^) operator to flip all the bits. XORing with 1 toggles each bit (0 to 1 and 1 to 0).
The constant 0xFFFFFFFF is a 32-bit integer with all bits set to 1, representing the binary number 11111111111111111111111111111111.
The main function reads the number of queries (q) and then processes each query by calling the flippingBits function and printing the result.
 0xFFFFFFFF=4294967295=2^32-1*/

/*
 * Complete the 'flippingBits' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long flippingBits(long n) {
    return n^0xFFFFFFFF;
  // other ways
  //  return n^4294967295;
  // return n^((1ull<<32ull)-1ull);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        long result = flippingBits(n);

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
