#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<string,int> hm;

int strint(string s){
    int ns=0;
    for(int i=0; i<s.size(); i++){
        ns*=10;
        ns+=s[i]-'0';
    }
    return ns;
}
bool compare(const string& src, const string& dest){
    if(src.size()!=dest.size())return false;
    for(int i=0; i<src.size(); i++)
        if(src[i]!=dest[i])return false;
    return true;
}
vector<string> tockens(const string &str){
    vector<string> res;
    for(int i=0, j=0; i<str.size(); i++){
        while(j<str.size()&&str[j]!=' ')j++;
        string temp=str.substr(i,j-i);
        if(!compare(temp,"and"))
            res.emplace_back(temp);
        i=j++;
    }
    
    return res;
}
vector<int> v[110];
int n=1;
void recur(const vector<string>& vv, int idx, string temp){
    if(idx==4){
        if(hm[temp]==0)
            hm[temp]=n++;
        v[hm[temp]].push_back(strint(vv[idx]));
        return;
    }
    recur(vv,idx+1,temp+vv[idx]);
    recur(vv,idx+1,temp+"-");
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> user;
    vector<vector<string>>qry;
    for(string str : info)user.push_back(tockens(str));
    for(string str : query)qry.push_back(tockens(str));
    
    for(auto s:user) recur(s,0,"");
    for(int i=0; i<110; i++)sort(v[i].begin(),v[i].end());
    for(auto s:qry){
        int num=strint(s[4]);
        string temp=s[0]+s[1]+s[2]+s[3];
        int i =lower_bound(v[hm[temp]].begin(),v[hm[temp]].end(),num)-v[hm[temp]].begin();
        
        answer.push_back(v[hm[temp]].size()-i);
    }
    return answer;
}