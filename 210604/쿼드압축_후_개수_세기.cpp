#include <string>
#include <vector>
using namespace std;
typedef pair<int,int> p;
p divCon(int r, int c, int size, const vector<vector<int>> &map){
    p ret={0,0};
    if(size<1)return ret;
    
    int zero=0,one=0;
    for(int i=r; i<r+size; i++)for(int j=c; j<c+size; j++){
        if(map[i][j]==0)zero++;
        else one++;
    }
    if(zero==0){return ret={0,1};}
    else if(one==0){return ret={1,0};}
    
    int dr[4]={0,0,1,1}, dc[4]={0,1,0,1};
    int nsize=size/2;
    for(int i=0; i<4; i++){
        p d = divCon(r+dr[i]*nsize,c+dc[i]*nsize,nsize,map);
        ret.first+=d.first;
        ret.second+=d.second;
    }
    return ret;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int numZero, numOne;
    p d = divCon(0,0,arr.size(),arr);
    numZero=d.first;
    numOne=d.second;
    
    answer.push_back(numZero);
    answer.push_back(numOne);
    return answer;
}