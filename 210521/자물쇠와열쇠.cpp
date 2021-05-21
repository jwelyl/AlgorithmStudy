#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> p;
vector<p>keys[4];
int temp[21][21];
void rot(vector<vector<int>>& key, int n){
    int size=key.size();
    bool first=false;
    int fx,fy;
    for(int i=0; i<size; i++)for(int j=0; j<size; j++)
        temp[j][size-1-i]=key[i][j];
    for(int i=0; i<size; i++)for(int j=0; j<size; j++){
        key[i][j]=temp[i][j];
        if(key[i][j]==1){
            if(!first){
                fy=i;fx=j;first=true;
            }
            keys[n].emplace_back(i-fy,j-fx);
        }
    }
}
bool solving(const vector<vector<int>>& lock, int n, int need){
    bool ret=false;
    int size=lock.size();
    int get=0;
    for(int i=-size; i<size; i++)for(int j=-size; j<size*2; j++)if(!ret){
        if(i>=0&&j>=0&&j<size&&lock[i][j])continue;
        get=0;
        for(auto key : keys[n]){
            int y=key.first+i, x=key.second+j;
            if(y<0||x<0||y>=size||x>=size)continue;
            if(lock[y][x])break;
            get++;
        }
        if(get==need)ret=true;
    }
    return ret;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int need=0,size=lock.size();
    for(int i=0;i<size;i++)for(int j=0;j<size;j++)
        if(lock[i][j]==0)need++;
    for(int i=0; i<4; i++)rot(key,i);
    
    for(int i=0; i<4; i++)if(!answer)answer=solving(lock,i,need);
    
    return answer;
}