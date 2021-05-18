#include <string>
#include <vector>

using namespace std;
const int MAX=1000000000;
string lowerCase(const string &str){
    char dest[21];
    for(int i=0; i<str.size(); i++)if(str[i]>='A'&&str[i]<='Z')dest[i]=str[i]+32;
    else dest[i]=str[i];
    dest[str.size()]='\0';
    return (string)dest;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> qry;
    if(cacheSize<=0)return 5*cities.size();
    for(auto str : cities)qry.emplace_back(lowerCase(str));
    
    vector<pair<string,int>> dq;
    for(int i=0; i<qry.size(); i++){
        int num=-1, idx=-1, val=MAX;
        
        for(int j=0; j<dq.size(); j++){
            if(dq[j].first==qry[i]){
                num=j;break;
            }
            if(val>dq[j].second){
                idx=j;val=dq[j].second;
            }
        }
        
        if(num!=-1){
            answer+=1;
            dq[num].second=i+1;
        }
        else{
            answer+=5;
            if(dq.size()<cacheSize)dq.emplace_back(qry[i],i+1);
             else{
                 dq[idx]=pair<string,int>(qry[i],i+1);
             }
        }
    }
    
    return answer;
}