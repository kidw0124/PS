#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int base;
    int number=0;
    cin>>str>>base;
    int len = str.size();
    for(int i=0;i<len;i++){
        if(isdigit(str[i])){
            number+=(str[i]-'0')*pow(base,len-i-1);
        }
        else{
            number+=(str[i]-'A'+10)*pow(base,len-i-1);
        }
    }
    cout<<number;

    return 0;
}
