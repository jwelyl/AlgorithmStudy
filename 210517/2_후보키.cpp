#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isUniq(vector<vector<string>>& relation, int r, int c, int bit) {
    for (int i = 0; i < r - 1; ++i) {  // 모든 튜플에 대해 유일하게 식별
        for (int j = i + 1; j < r; ++j) {
            bool isSame = true;
            for (int k = 0; k < c; ++k) {
                if ((bit & 1 << k) == 0) continue;  // 1, 10, 100, 1000
                if (relation[i][k] != relation[j][k]) {
                    isSame = false;
                    break;
                }
            }

            if (isSame) return false;
        }
    }

    return true;
}

int countBit(int bit) {
    int cnt = 0;
    while (bit) {
        if (bit & 1) ++cnt;
        bit = bit >> 1;
    }

    return cnt;
}

// 모든 필드의 멱집합 만들고, 유일성, 최소성 체크
int solution(vector<vector<string>> relation) {
    int ans = 0;
    int r = relation.size();
    int c = relation[0].size();

    vector<int> candidate;
    for (int i = 1; i < 1 << c; ++i) {                          // 0001~1111
        if (isUniq(relation, r, c, i)) candidate.push_back(i);  // 유일성 만족
    }

    sort(candidate.begin(), candidate.end(), [](int bit1, int bit2) {
        return countBit(bit1) > countBit(bit2);
    });

    while (!candidate.empty()) {
        int n = candidate.back();  // 최소성 만족
        candidate.pop_back();
        ++ans;

        for (auto it = candidate.begin(); it != candidate.end();) {
            if ((n & *it) == n)
                it = candidate.erase(it);
            else
                ++it;
        }
    }

    return ans;
}
