#include <iostream>
#include <stack>
#include <string>

using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    int maxLen = 0;
    int start = -1; // The index where the current valid substring starts

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (st.empty()) {
                start = i; // Update the starting index of the current substring
            } else {
                st.pop();
                if (st.empty()) {
                    maxLen = max(maxLen, i - start); // No open parentheses left, update max length
                } else {
                    maxLen = max(maxLen, i - st.top()); // Update max length with the current valid substring
                }
            }
        }
    }

    return maxLen;
}

int main() {
    string s = "(()())";
    int result = longestValidParentheses(s);
    cout << "The longest valid parentheses substring length is: " << result << endl;
    return 0;
}
