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
    unordered_map<string,int>mp;
    vector<string> arr;
    int n;
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr.push_back(s);
        mp[s]=i+1;
    }
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        if(isdigit(s[0])){
            cout<<arr[stoi(s)-1]<<'\n';
        }
        else{
            cout<<mp[s]<<'\n';
        }
    }
}