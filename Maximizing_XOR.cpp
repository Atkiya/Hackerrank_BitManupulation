//Time Complexity: O(Nlog(M))
//https://www.hackerrank.com/challenges/maximizing-xor/problem?isFullScreen=true
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maximizingXor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int maximizingXor(int l, int r) {
    int mx=0,mask=0;
  
    set<int>s;
  
    for(int i=30;i>=0;i--){

        mask|=(1<<i);
        
        for(int j=l;j<=r;j++)s.insert(j&mask);
        
        int nmx=mx|(1<<i);
        
        for(int y:s){
            
            if(s.count(nmx^y)){
                mx=nmx;
                break;
            }
        }
        s.clear();
    }
    return mx;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string r_temp;
    getline(cin, r_temp);

    int r = stoi(ltrim(rtrim(r_temp)));

    int result = maximizingXor(l, r);

    fout << result << "\n";

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
