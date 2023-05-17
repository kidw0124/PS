#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int x=0;
    for(int i=0;i<5;i++){
        cin>>s;
        if(s.find("FBI")!=string::npos){
            cout<<i+1<<' ';
            x=1;
        }
    }
    if(!x)cout<<"HE GOT AWAY!";
}