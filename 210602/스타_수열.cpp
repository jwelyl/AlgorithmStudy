#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 500001;
int ans[MAX],lastIdx[MAX];

int solution(std::vector<int> a) {
    int answer = 0;
    fill(lastIdx,lastIdx+MAX,-1);
    
    for(int i=0; i<a.size(); i++){
        if(i-1>=0&&a[i-1]!=a[i]&&lastIdx[a[i]]<i-1){
                ans[a[i]]++;
        }
        else if(i+1<a.size()&&a[i+1]!=a[i]){
            lastIdx[a[i]]=i+1;
            ans[a[i]]++;
        }
    }
    for(int i=0; i<MAX; i++)answer=max(answer,ans[i]*2);
    return answer;
}