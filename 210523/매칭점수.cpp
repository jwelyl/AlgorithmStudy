#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string,int> hm;
vector<pair<int,int>> con(23);
vector<string> link[23];
int num=1;
bool compare(const string& src, const string& dest){
    if(src.size()!=dest.size())return false;
    for(int i=0; i<src.size(); i++)if(src[i]!=dest[i])return false;
    return true;
}
string lowerCase(const string& str){
    char temp[str.size()+1];
    for(int i=0; i<str.size(); i++){
        if(str[i]>='A'&&str[i]<='Z')temp[i]=str[i]+32;
        else temp[i]=str[i];
    }
    temp[str.size()]='\0';
    return (string)temp;
}
vector<string> tockens2(const string& str){
    vector<string> v;
    for(int i=0,j=0; i<str.size(); i++,j++){
        while(j<str.size()&&str[j]!=' ')j++;
        string temp = str.substr(i,j-i);
         i=j;
        v.push_back(temp);
     }
    return v;
}
void tockens(vector<vector<string>>& v, const string& str){
     for(int i=0,j=0; i<str.size(); i++,j++){
         while(i<str.size()&&str[i]!='<')i++;
         j=i;
        while(j<str.size()&&str[j]!='>')j++;
        v.push_back(tockens2(str.substr(i,j-i)));
         i=j;
     }
}
void getNum(int idx, const string &src, const string& dest){
    int n=0; 
    for(int i=0,j=0; i<src.size(); i++,j++){
        while(j<src.size()&&src[j]>='a'&&src[j]<='z')j++;
        string temp = src.substr(i,j-i);
        if(compare(temp,dest))n++;
         i=j;
     }
    con[idx].first=n;
}
int solution(string word, vector<string> pages) {
    int answer = 0;
    double mp=0;
    vector<vector<string>> vp[pages.size()];
    vector<string>url;
    word=lowerCase(word);
    for(int i=0; i<pages.size(); i++) pages[i] = lowerCase(pages[i]);
    for(int i=0; i<pages.size(); i++) tockens(vp[i],pages[i]);
    for(int i=0; i<pages.size(); i++){
        string _url;
        for(int j=0; j<vp[i].size(); j++)if(compare("<meta",vp[i][j][0])&&vp[i][j].size()>2){
            _url =vp[i][j][2].substr(17);
            break;
        }
        hm[_url]=num++;
        url.push_back(_url);
    }
    for(int i=0; i<pages.size(); i++){
        getNum(i+1,pages[i],word);
        int ln=0;
        for(int j=0; j<vp[i].size(); j++)
            if(compare("<a",vp[i][j][0])){
                ln++;
                string _url=vp[i][j][1].substr(14);
                if(_url[_url.size()-1]=='"')_url+="/";
                link[hm[_url]].push_back(url[i]);
            }
        con[hm[url[i]]].second=ln;
    }
    for(int i=0; i<pages.size(); i++){
        double bp=con[i+1].first;
        double lp=0;
        for(auto str : link[i+1]){
            double lbp=con[hm[str]].first;
            double llp=con[hm[str]].second;
            lp+=(lbp/llp);
        }
        if(bp+lp>mp){
            mp=bp+lp;
            answer=i;
        }
    }
    return answer;
}