#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
const int MAX=200001;
int arr[MAX];
vector<int> temp;
unordered_map<int,int> hm;
priority_queue<int, vector<int>> pq;
int N;
int solution(vector<int> stones, int k) {
    int answer = 0;
    
    for(auto i : stones)temp.push_back(i);
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    for(int i : temp)hm[i]=N++;
    
    for(int i=0; i<k; i++){
        arr[hm[stones[i]]]++;
        pq.push(stones[i]);
    }
    answer=pq.top();
    
    for(int i=0, j=k; j<stones.size(); i++,j++){
        arr[hm[stones[i]]]--;
        while(!pq.empty()&&arr[hm[pq.top()]]==0)pq.pop();
        arr[hm[stones[j]]]++;
        pq.push(stones[j]);
        answer=min(answer,pq.top());
    }
    
    return answer;
}