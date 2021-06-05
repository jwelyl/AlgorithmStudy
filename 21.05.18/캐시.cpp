#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    if(cacheSize == 0) {
        answer = cities.size() * 5;
        return answer;
    }
    
    for(int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        vector<string> ::iterator iter = find(cache.begin(), cache.end(), cities[i]);
        
        if(iter != cache.end()) {
            // 있다면
            string city = *iter;
            cache.erase(iter);
            cache.push_back(city);
            answer++;
        }
        else {
            // 없다면
            if(cache.size() < cacheSize) cache.push_back(cities[i]);
            else {
                cache.erase(cache.begin());
                cache.push_back(cities[i]);
            }
            answer += 5;
        }
    }
    
    return answer;
}