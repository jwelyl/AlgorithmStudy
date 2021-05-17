#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int limit;
set<int> s;
int recur(int step, int idx, int check, const vector<vector<string>>& rel){
    if(idx>=limit&&step>0)return 0;
    if(step==0){
        for(auto i : s)
            if(s.find(i&check)!=s.end())return 0;
        
        vector<string> v;
        for(int i=0; i<rel.size(); i++){
            string temp="";
            for(int j=0,n=0;j<limit;j++,n++)if(check&(1<<j)){
                temp+=rel[i][n];
            }
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        if(v.size()==rel.size()){
            s.insert(check);
            return 1;
        }
        return 0;
    }
    int res=0;
    for(int i=idx; i<limit; i++){
        res+=recur(step-1,i+1,check|(1<<i),rel);
    }
    return res;
}

int solution(vector<vector<string>> rel) {
    int answer = 0,n=1; 
    limit=rel[0].size();
    do{
        answer+=recur(n,0,0,rel);
        n++;
    }while(n<=limit);
    return answer;
}