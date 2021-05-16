#include <string>
#include <vector>
#include <set>

using namespace std;
const int MAX=501;
vector<int> answer,tmp[MAX];
bool check[100001];

int N;

void strtoint(string &str){
    int n=0,num=0;
    vector<int> temp;
    for(int i=0; i<str.size(); i++){
        if(str[i]!=','){
            num*=10;
            num+=str[i]-'0';
        }
        else{
            temp.push_back(num);
            num=0;
        }
    }
    temp.push_back(num);
    n=temp.size();
    N=max(n,N);

    for(int i=0; i<n; i++){

        tmp[n].push_back(temp[i]);
    }

}

void distribution(string &str){
    for(int i=1; i<str.size()-1; i++){
        if(str[i]=='{'){
            int n = i+1, m=0;
            i++;
            while(str[i]!='}'){
                m++;
               i++;
            }
            string temp = str.substr(n,m);

            strtoint(temp);
        }
    }
}
void dosomething(){
    for(int i=1; i<=N; i++)
        for(auto n : tmp[i])
            if(!check[n]){
                answer.push_back(n);
                check[n]=true;
            }
}
vector<int> solution(string s) {

    distribution(s);
    dosomething();
    
    return answer;
} 
