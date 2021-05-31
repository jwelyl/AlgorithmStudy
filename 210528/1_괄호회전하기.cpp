#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {  // 1000 * 1000 = 1000000
    int ans = 0;

    for (char ch : s) {
        stack<char> st;
        for (char ch : s) {
            if (st.empty() || ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else if (st.top() == '(' && ch == ')')
                st.pop();
            else if (st.top() == '{' && ch == '}')
                st.pop();
            else if (st.top() == '[' && ch == ']')
                st.pop();
            else
                break;
        }

        if (st.empty()) ans++;
        rotate(s.begin(), s.begin() + 1, s.end());
    }

    return ans;
}