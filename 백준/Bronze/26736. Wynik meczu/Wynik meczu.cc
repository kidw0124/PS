#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;cin>>str;
    cout<<ranges::count(str,'A')<<" : "
        <<ranges::count(str,'B');
}