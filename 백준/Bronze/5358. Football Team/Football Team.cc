#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    while(getline(cin,str)){
        for(auto k:str){
            if(k=='e'||k=='E')cout<<(char)(k+'i'-'e');
            else if(k=='i'||k=='I')cout<<(char)(k+'e'-'i');
            else cout<<k;
        }
        cout<<'\n';
    }
}