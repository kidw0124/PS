#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

int is_zero(char*Str){
    return (strcmp(Str,"0")==0);
}

int is_exceed(char*str){
    int len=strlen(str);
    if(len>19)return 1;
    if(len<19)return 0;
    return (strcmp(str,"9223372036854775807")>0);
}

char str1[26],str2[26];

int main(){
    int i,j;
    LL a,r,b;
    scanf(" %s %s %lld",str1,str2,&r);
    if(is_zero(str1)||is_zero(str2)){
        cout<<'0';
    }
    else if(is_exceed(str1)||is_exceed(str2)){
        cout<<"overflow";
    }
    else{
        sscanf(str1,"%lld",&a);
        sscanf(str2,"%lld",&b);
        if(a>(r/b)){
            printf("overflow");
        }
        else{
            printf("%lld\n",a*b);
        }
    }

    return 0;
}
