#include <iostream>

using namespace std;

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string str; int N;
  cin>>str>>N;
  int ans=0;
  for(int i=0; i<str.size(); i++){
    ans*=N;
    if(str[i]>='0'&&str[i]<='9')ans+=str[i]-'0';
    else ans+=str[i]-'A'+10;
  }
  cout<<ans;
}
