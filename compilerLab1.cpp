#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
    if((s[0]=='/') && (s[1]=='/'))
    {
      cout<<"Yes"<<endl;
    }
    else if((s[0] =='/') && (s[1]=='*') && (s[s.size()-2]=='*') && (s[s.size()-1]=='/'))
      cout<<"Commentting"<<endl;

    else cout<<"No"<<endl;
}
