#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    cout<<str.find_last_of(str[0])+1;
}