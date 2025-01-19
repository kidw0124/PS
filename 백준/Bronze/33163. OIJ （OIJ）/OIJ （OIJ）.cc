#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string str;
    cin>>n>>str;
    for(int i=0;i<n;i++){
        if(str[i]=='J')cout<<'O';
        if(str[i]=='O')cout<<'I';
        if(str[i]=='I')cout<<'J';
    }
}