#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string,char> hm;
char a='H';
vector<int> failure(const string& str){
    vector<int> f(str.size(),0);
    for(int i=1,j=0; i<str.size(); i++){
        while(str[i]!=str[j]&&j>0)j=f[j-1];
        if(str[i]==str[j])f[i]=++j;
    }
    return f;
}
vector<string> tockens(const string str){
    vector<string> res;
    int n=str.size();
    for(int i=0,j=0; i<n; i++,j++){
        while(j<n&&str[j]!=',')j++;
        res.emplace_back(str.substr(i,j-i));
        i=j;
    }
    return res;
}
int tt(const string& str1){
    int h=0,m=0;
    string hh=str1.substr(0,2);
    string mm=str1.substr(3,2);
    
    for(int i=0; i<2; i++){
        h*=10;m*=10;
        h+=hh[i]-'0';m+=mm[i]-'0';
    }
    
    return h*60+m;
}
string change(const string& str){
    char ret[1500];
    int j=0;
    string t="";
    for(int i=0; i<str.size(); i++){
        if(i+1<str.size()&&str[i]!='#'&&str[i+1]=='#'){
            t=str.substr(i,2);
            if(hm[t]==0)hm[t]=a++;
            ret[j]=hm[t];
            j++;
        }
        else if(str[i]!='#'){
            ret[j]=str[i];
            j++;
        }
    }
    ret[j]='\0';
    return (string)ret;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    m=change(m);
    int time=0;
    vector<int> fail=failure(m);
    for(auto str : musicinfos){
        vector<string> tmp=tockens(str);
        int size=tt(tmp[1])-tt(tmp[0]);
        string temp=change(tmp[3]);
        bool flag=false;
        for(int i=0,j=0,l=0; l<size; l++,i++){
            if(i==temp.size())i=0;
            
            while(temp[i]!=m[j]&&j>0)j=fail[j-1];
            if(temp[i]==m[j]){
                j++;
                if(j==m.size()){
                    flag=true;
                    break;
                }
            }
        }
        if(flag&&time<size){
            answer=tmp[2];  
            time=size;
        }
    }
    answer=answer.size()==0?"(None)":answer;
    return answer;
}