#include <bits/stdc++.h>
using namespace std;
int main() {
    int i,j,k;
    string str;
    cin>>str;
    int n=str.size();
    stack<pair<int,int>>stk;
    vector<int>pp(n);
    stk.push({1,0});
    for(i=0;i<n;i++){
        if(str[i]=='('){
            stk.top().second--;
            stk.push({str[i-1]-'0',0});
        }
        else if(str[i]==')'){
            auto [a,b]=stk.top();
            stk.pop();
            stk.top().second
                +=a*b;
        }
        else {
            stk.top().second++;
        }
    }
    cout<<stk.top().second;
}