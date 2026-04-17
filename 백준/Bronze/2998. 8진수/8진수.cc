#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    stack<int>stk;
    cin>>s;
    for(int i=s.size()-1;i>=0;i-=3){
        string k=s.substr(max(0,i-2),min(3,i+1));
        bitset<4>bts(k);
        int j=bts.to_ulong();
        stk.push(j);
    }
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
}