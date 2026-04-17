#include<bits/stdc++.h>

using namespace std;

int main(){

    string str;

    cin>>str;

    int ans=0;

    for(auto k:str){

        if(k=="KOREA"[ans%5])ans++;

    }

    cout<<ans;

}

