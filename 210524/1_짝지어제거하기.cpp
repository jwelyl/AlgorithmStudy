#include <stack>
#include <string>

using namespace std;

int solution(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c)
            st.pop();
        else
            st.push(c);
    }

    return st.empty();
}

// 예시에서 글자 제거 과정을 보여줘서 바로 스택 이용하라는걸 파악함