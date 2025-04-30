#include<bits/stdc++.h>

using namespace std;

int main(){
      string identifier;
      cin>>identifier;

      if(isValidIdentifier(identifier)){
        cout<<identifier<<" is valid"<<endl;
      else{
        cout<<identifier<<" is not valid"<<endl;
        }
       return 0;
}
 


bool isKeyword(const string& str){
    vector<string> keywords = {"int","float","double,""if","else","for","while","return","switch","case","break","continue","class","public","private",
"void","static","const","char","struct","do","while","auto"};

for(const string& keyword : keywords){
 if(str == keyword){
 return true;
  }
} 
 return false;
}


bool isValidIdentifier(const string &str) {
   if(str.empty())  return false;
if(isKeyword(str)) return false;
  
 switch(str[0]){
  case '_':
    break;
default:
if(!isalpha(str[0])) return false;
}

for(int i=1;i<str.length();i++){
    switch(str[i]){
  case '_':
    break;
  default:
    if(!isalnum(str[i])) return false;
 } 
}  



return true;
}

 
}