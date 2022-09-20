#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<string.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unordered_set<int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.insert(x);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(a.find(x)!=a.end()){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
    }
}