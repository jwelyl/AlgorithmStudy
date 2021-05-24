#include <string>
#include <vector>

using namespace std;
vector<int> v[16];
void recur(int idx, int step, const vector<int>& weak,const vector<int>& dist,int& answer){
    if(idx==weak.size()){
        int check=0;
        for(int i=0; i<step; i++){
            if(v[step].size()==1){
                for(int j=0; j<dist.size(); j++)if(!(check&1<<j)){check|=1<<j;break;}
            }
            else{
                int n=0;
                for(int j=0; j<v[i].size()-1; j++)n+=v[i][j+1]-v[i][j];
                for(int j=0; j<dist.size(); j++){
                    if(!(check&1<<j)&&n<=dist[j]){
                        check|=1<<j;break;
                    }
                    if(j==dist.size()-1)return;
                }
            }
        }
        int ans=0;
        for(;check;check>>=1)if(check&1)ans++;
        if(ans==0)return;
        answer=min(answer,ans);return;
        return;
    }
    
    for(int i=idx; i<weak.size(); i++){
        v[step].push_back(weak[i]);
        recur(i+1,step+1,weak,dist,answer);
    }
    for(int i=idx; i<weak.size(); i++)v[step].pop_back();
}


int solution(int n, vector<int> weak, vector<int> dist) {
    int answer=10, nn=weak.size();
    for(int i=0; i<nn; i++){
        int temp=weak[0];
        weak.erase(weak.begin());
        weak.push_back(n+temp);
        recur(0,0,weak,dist,answer);
    }
    
    if(answer==10)answer=-1;
    return answer;
}