#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

int N;

char home[40];

int main(){
    int i,j;
    //freopen
    cin>>N;
    for(i=0;i<N;i++){
        int score=0,l=0;
        int tui=0,tot=0;
        scanf(" %s",home);
        l=strlen(home);
        for(j=0;j<l;j++){
            if('0'<=home[j]&&home[j]<='9'){
                score+=home[j]-'0';
            }
            else{
                score+=home[j]-'A'+10;
            }
            if(score/10==4){
                cout<<tot<<"(weapon)"<<endl;
                tui=score/10;
                break;
            }
            else if(score/10>4){
                cout<<tot<<"(09)"<<endl;
                tui=score/10;
                break;
            }
            else if(tui!=score/10){
                tui=score/10;
                tot+=tui;
            }
            else{
                tui=score/10;
            }

        }
        if(tui<4){
            cout<<tot<<endl;
        }
    }


    return 0;
}
