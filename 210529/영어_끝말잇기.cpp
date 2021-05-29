#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string,int>hm;
    int nn=0;
    bool flag=true;
    char lastchar;
    
    for(int i=0; i<words.size(); i++){
        string str = words[i];
        if(i>0&&str[0]!=lastchar){
            nn=(i+1);break;
        }
        lastchar=str[str.size()-1];
        
        if(hm[str]>0){
            nn=i+1;break;
        }
        hm[str]++;
    }
    int divid=0,temp=nn;
    while(temp>0){
        temp-=n;
        divid++;
    }
    int mod=nn-n*(divid==0?0:divid-1);
    answer={mod,divid};
    return answer;
}