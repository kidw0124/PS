#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    while(n--){int x,y;cin>>x>>y;
               if(!y)arr.push_back(x);
               }
    if(arr.size())cout<<ranges::min(arr);
    else cout<<-1;
    }