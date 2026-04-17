#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    cout<<s.size()+count(s.begin(),s.end(),':')+count(s.begin(),s.end(),'_')*5;
}