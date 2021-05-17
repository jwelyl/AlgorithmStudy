#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// 균형잡힌 괄호 => 올바른 문자열로 변환한 결과 리턴
bool isCorrect(string& s, int* pos) {
    bool ret = true;

    int left = 0, right = 0;
    stack<char> st;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push('(');
            left++;
        } else {
            right++;
            if (st.empty())
                ret = false;
            else
                st.pop();
        }

        if (left == right) {
            *pos = i + 1;
            break;
        }
    }

    return ret;
}

string solution(string p) {
    if (p.empty()) return p;

    int pos = 0;
    bool correct = isCorrect(p, &pos);

    string u = p.substr(0, pos);
    string v = p.substr(pos);

    if (correct) return u + solution(v);

    string ans = '(' + solution(v) + ')';
    for (int i = 1; i < u.length() - 1; ++i) {
        if (u[i] == '(')
            ans += ')';
        else
            ans += '(';
    }

    return ans;
}
