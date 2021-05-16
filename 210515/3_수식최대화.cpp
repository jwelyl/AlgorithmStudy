#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<char> order{'*', '+', '-'};
vector<long long> num;
vector<char> op;

long long calc() {
    vector<long long> tmpNum = num;
    vector<char> tmpOp = op;

    for (int i = 0; i < 3; ++i) {  // order 순서대로 연산
        for (int j = 0; j < tmpOp.size(); ++j) {
            if (tmpOp[j] == order[i]) {
                if (tmpOp[j] == '+')
                    tmpNum[j] += tmpNum[j + 1];
                else if (tmpOp[j] == '-')
                    tmpNum[j] -= tmpNum[j + 1];
                else
                    tmpNum[j] *= tmpNum[j + 1];

                tmpNum.erase(tmpNum.begin() + j + 1);
                tmpOp.erase(tmpOp.begin() + j);
                j--;  // 벡터 사이즈 줄었으니까 빠꾸
            }
        }
    }

    return abs(tmpNum[0]);
}

long long solution(string expression) {
    long long answer = 0;

    char myStr[100];
    strcpy(myStr, expression.c_str());
    char* p = strtok(myStr, "+-*");
    while (p != NULL) {
        num.push_back(stoll(p));
        p = strtok(NULL, "+-*");
    }
    for (char ch : expression) {
        if (ch == '+' || ch == '-' || ch == '*') {
            op.push_back(ch);
        }
    }  // 연산자, 피연산자 분리

    do {
        answer = max(answer, calc());
    } while (next_permutation(order.begin(), order.end()));

    return answer;
}
