#include <iostream>
#include <string>
using namespace std;

string shortestPalindrome(string s) {
    int n = s.length();
    if (n <= 1) return s;
    
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    string combined = s + "#" + rev;
    int len = combined.length();
    
    vector<int> lps(len, 0);
    
    for (int i = 1, j = 0; i < len; ) {
        if (combined[i] == combined[j]) {
            lps[i] = j + 1;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    int prefixLen = lps[len - 1];
    string prefix = s.substr(prefixLen);
    reverse(prefix.begin(), prefix.end());
    
    return prefix + s;
}

int main() {
    string s = "abcd";
    string result = shortestPalindrome(s);
    cout << "Shortest Palindrome: " << result << endl;
    return 0;
}
