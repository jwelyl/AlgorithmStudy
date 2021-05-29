#include <string>
#include <vector>
#include <stack>

using namespace std;
bool compare(string src, string dest){
    if(src.size()!=dest.size())return false;
    for(int i=0; i<src.size(); i++)if(src[i]!=dest[i])return false;
    return true;
}
vector<int> solution(string s) {
    vector<int> answer;
    int delZero=0,cnt=0,size=s.size();
    stack<char> st;
    while(size>1){
        cnt++;
        int temp=0;
        for(int i=0; i<s.size(); i++)if(s[i]=='1')temp++;
        delZero+=(s.size()-temp);
    
        while(temp){
            st.push(temp%2+'0');
            temp/=2;
        }
        s="";
        while(!st.empty()){s+=st.top();st.pop();}
        size=s.size();
   }
    
    answer={cnt,delZero};
    return answer;
}