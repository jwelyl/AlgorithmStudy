#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct SII{
    string head;
    int number,idx;
    SII(const string& str, int n, int i):head(str),number(n),idx(i){}
    bool operator <(const SII& d)const{
        if(head==d.head && number==d.number) return idx<d.idx;
        else if(head==d.head)return number<d.number;
        else return head<d.head;
    }
};

int Stoi(const string& str){
    int ret=0;
    for(int i=0; i<str.size(); i++){
        ret*=10;
        ret+=str[i]-'0';
    }
    return ret;
}
string lowerCase(const string& str){
    char ret[str.size()+1];
    for(int i=0; i<str.size(); i++){
        if(str[i]>='A'&&str[i]<='Z')ret[i]=str[i]+32;
        else ret[i]=str[i];
    }
    ret[str.size()]='\0';
    return (string)ret;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<SII> fileSet;
    int n=0;
    for(auto str : files){
        str=lowerCase(str);
        string head;
        int i=0,j=0,number;
        while(j<str.size() && !(str[j]>='0'&&str[j]<='9'))j++;
        head=str.substr(i,j);
        i=j;
        while(j<str.size()&&j<i+5&&(str[j]>='0'&&str[j]<='9'))j++;
        number=Stoi(str.substr(i,j-i));
        fileSet.emplace_back(head,number,n++);
    }
    sort(fileSet.begin(),fileSet.end());
    for(auto sii : fileSet){
        answer.push_back(files[sii.idx]);
    }
    return answer;
}