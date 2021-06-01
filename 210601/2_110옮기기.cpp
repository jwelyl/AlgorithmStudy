#include <stack>
#include <string>
#include <vector>

using namespace std;

string func(string& str) {
    int cnt110 = 0;
    stack<char> st;
    for (int i = 0; i < str.length(); ++i) {  // 1. 110 갯수 카운트, 110 제거
        char target = str[i];
        if (st.size() < 2)
            st.push(target);
        else {
            char b = st.top();
            st.pop();
            char a = st.top();
            st.pop();
            if (a == '1' && b == '1' && target == '0') {
                cnt110++;
                continue;
            } else {
                st.push(a);
                st.push(b);
                st.push(target);
            }
        }
    }

    string nStr;
    while (!st.empty()) {
        nStr = st.top() + nStr;
        st.pop();
    }

    if (!cnt110) return nStr;

    string str110 = "";
    while (cnt110--) {
        str110 += "110";
    }
    // 2. 110 삽입
    if (nStr.find("111") != -1) {
        int pos = nStr.find("111");
        return nStr.substr(0, pos) + str110 + nStr.substr(pos);
    } else {
        if (nStr.find("0") != -1) {
            int pos = nStr.rfind("0");
            return nStr.substr(0, pos + 1) + str110 + nStr.substr(pos + 1);
        } else {
            return str110 + nStr;
        }
    }
}

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (string& str : s) {
        answer.push_back(func(str));
    }

    return answer;
}