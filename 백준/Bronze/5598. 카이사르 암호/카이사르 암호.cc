#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    cout<<[](string&str){
        for(char&a:str)a=((a-'A')+23)%26+'A';
        return str;
    }(str);
}