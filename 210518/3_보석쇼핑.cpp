#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);

    unordered_set<string> uset;
    for (string& s : gems) {
        uset.insert(s);
    }

    unordered_map<string, int> umap;
    int range = 100000;
    int start = 0, end = 0;
    int i;
    while (true) {
        for (i = end; i < gems.size(); ++i) {
            umap[gems[i]]++;
            if (umap.size() == uset.size()) {
                end = i;
                break;
            }
        }
        if (i == gems.size()) break;

        for (i = start; i < gems.size(); ++i) {
            if (umap[gems[i]] == 1) {
                start = i;
                break;
            } else
                umap[gems[i]]--;
        }

        if (end - start < range) {
            answer = {start + 1, end + 1};
            range = end - start;
        }

        umap.erase(gems[start]);
        start++;
        end++;
    }

    return answer;
}
