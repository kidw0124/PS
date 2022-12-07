#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a=0;
    cin>>n;
    string str;
    while(n--){
        cin>>str;
        str=str.substr(2);
        if(stoi(str)<=90)a++;
    }
    cout<<a;
}