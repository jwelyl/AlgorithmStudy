#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 1;
    vector<pair<int,int>> v;
    for(int i=0; i<a.size(); i++)v.emplace_back(a[i],i);
    sort(v.begin(),v.end());
    int begin = v[0].second;
    int r=begin,l=begin;
    
    for(auto n : v){
        int t = n.second;
        if(t>begin&&t>r){
            r=t;answer++;
        }
        else if(t<begin&&t<l){
            l=t;answer++;
        }
    }
    return answer;
}