#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    while(getline(cin,str),str!="#")
        cout<<count_if(str.begin(),
                       str.end(),
                       [](auto x){
                           switch(tolower(x)){
                               case 'a':case'e':case'i':case'o':case'u':return true;
                               default:return false;
                           }
                           }
                       )<<endl;
    }
