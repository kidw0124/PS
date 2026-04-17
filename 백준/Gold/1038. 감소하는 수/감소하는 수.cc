#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin>>n;
    vector<ll>vct;
    for(int i=1;i<1024;i++){
        string str;
        for(int j=9;j>=0;j--){
            if(i&(1<<j)){
                str+=to_string(j);
            }
        }
        vct.push_back(stoll(str));
    }
    sort(vct.begin(),vct.end());
    if(n>=vct.size())cout<<-1;
    else cout<<vct[n];
}