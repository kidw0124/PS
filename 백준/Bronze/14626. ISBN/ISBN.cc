#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int idx=str.find('*');
    str[idx]='0';
    int chs=0;
    for(int i=0;i<str.size();i++){
        chs+=(str[i]-'0')*(i%2*2+1);
    }
    if(idx%2){
        cout<<(10-chs%10)*7%10;
    }
    else{
        cout<<(10-chs%10)%10;
    }
}