#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr;
    int n;
    while(cin>>n)arr.push_back(n);
    cout<<2*arr.back()-*(arr.rbegin()+1);
}