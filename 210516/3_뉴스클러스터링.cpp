#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int solution(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), [](char c) { return tolower(c); });
    transform(str2.begin(), str2.end(), str2.begin(), [](char c) { return tolower(c); });

    vector<string> v1, v2, unionSet, interSet;
    for (int i = 1; i < str1.length(); ++i) {
        if (isalpha(str1[i - 1]) && isalpha(str1[i])) {
            string element;
            element += str1[i - 1];
            element += str1[i];
            v1.push_back(element);
        }
    }
    for (int i = 1; i < str2.length(); ++i) {
        if (isalpha(str2[i - 1]) && isalpha(str2[i])) {
            string element;
            element += str2[i - 1];
            element += str2[i];
            v2.push_back(element);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(unionSet));
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(interSet));

    if (interSet.empty() && unionSet.empty()) return 65536;
    return 65536 * interSet.size() / unionSet.size();
}
