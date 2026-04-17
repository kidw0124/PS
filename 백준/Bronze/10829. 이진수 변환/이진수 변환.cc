#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,n;
    cin>>n;
    bitset<64>arr(n);
    string s=arr.to_string();
    cout<<s.substr(s.find('1'));
}