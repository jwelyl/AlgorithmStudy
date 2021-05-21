#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (!cacheSize) return cities.size() * 5;

    int ans = 0;
    vector<string> v;

    for (string& city : cities) {
        bool hit = false;

        transform(city.begin(), city.end(), city.begin(), ::tolower);
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == city) {
                hit = true;
                ans += 1;
                v.erase(v.begin() + i);
                v.push_back(city);
                break;
            }
        }
        if (!hit) {
            ans += 5;
            if (v.size() >= cacheSize) v.erase(v.begin());
            v.push_back(city);
        }
    }

    return ans;
}
