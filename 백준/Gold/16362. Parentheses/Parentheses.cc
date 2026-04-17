//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//
//bool isoperand(char x){
//    return ('A'<=x&&x<='Z')||('a'<=x&&x<='z');
//}
//bool isoperator(char x){
//    return x=='+'||x=='-'||x=='*'||x=='/'||x=='%';
//}
//
//bool iserr(string str){
//    int type;
//    int i=0;
//    int a=0;
//    type=isoperand(str[i])?1:isoperator(str[i])?2:str[i]=='('?3:str[i]==')'?4:5;
//    if(type==4||type==2)return false;
//    for(i=1;i<str.size();i++){
//        int type2=isoperand(str[i])?1:isoperator(str[i])?2:str[i]=='('?3:str[i]==')'?4:5;
//        if(type==1){
//            if(type2==2||type2==4||type2==5);
//            else return false;
//        }
//        if(type==2){
//            if(type2==1||type2==3||type2==5);
//            else return false;
//        }
//        if(type==3){
//            if(type2==1||type2==3||type2==4||type2==5);
//            else return false;
//            a++;
//        }
//        if(type==4){
//            if(type2==2||type2==4||type2==5);
//            else return false;
//            if(a==0)return false;
//            else a--;
//        }
//
//        if(type2!=5)type=type2;
//    }
//    if(type==4)a--;
//    if(a==0&&(type==1||type==4))return true;
//    else return false;
//}
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    ll i,j;
//    string str;
//    getline(cin,str);
//    i=0;
//    ll x=0;
//    while(str[x]==' ')x++;
//    str='('+str.substr(x)+')';
//    if(str.size()!=0&&!iserr(str)){
//        cout<<"error";
//        return 0;
//    }
//    ll ppp=0,papa=0;
//    for(i=0;i<str.size();i++){
//        if(isoperand(str[i]))ppp++;
//        if(str[i]=='(')papa++;
//    }
//    if(ppp==1&&papa==1){
//        cout<<"proper";
//        return 0;
//    }
//    stack<char>stk;
//    bool iserr=0,isimp=0;
//    for(i=0;i<str.size();i++){
//        switch(str[i]){
//        case ' ':
//            break;
//        case '(':
//            stk.push('(');
//            break;
//        case ')':
//            if(stk.size()<4){
//                cout<<"improper";
//                return 0;
//            }
//            else{
//                if(!isoperand(stk.top())){
//                    cout<<"improper";
//                    return 0;
//                }
//                else{
//                    stk.pop();
//                    if(!isoperator(stk.top())){
//                        cout<<"improper";
//                        return 0;
//                    }
//                    else{
//                        stk.pop();
//                        if(!isoperand(stk.top())){
//                            cout<<"improper";
//                            return 0;
//                        }
//                        else{
//                            stk.pop();
//                            if(stk.top()!='('){
//                                cout<<"improper";
//                                return 0;
//                            }
//                            else{
//                                stk.pop();
//                                stk.push('a');
//                            }
//                        }
//                    }
//                }
//            }
//            break;
//        default:
//            stk.push(str[i]);
//        }
//    }
//    if(stk.size()==1)cout<<"proper";
//    else{
//        cout<<"improper";
//    }
//    return 0;
//}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

bool iscorrect(string str){
    for(int i=0;i<(int)str.size()-2;i++){
        if(str[i]=='('&&str[i+1]=='a'&&str[i+2]==')')return iscorrect((i?str.substr(0,i):"")+"a"+(i==str.size()-3?"":str.substr(i+3)));
        if(str[i]=='a'&&str[i+1]=='+'&&str[i+2]=='a')return iscorrect((i?str.substr(0,i):"")+"a"+(i==str.size()-3?"":str.substr(i+3)));
    }
    return str=="a";
}
bool isproper(string str){
    for(int i=0;i<(int)str.size()-4;i++){
        if(str[i]=='('&&str[i+1]=='a'&&str[i+2]=='+'&&str[i+3]=='a'&&str[i+4]==')')return isproper((i?str.substr(0,i):"")+"a"+(i==str.size()-5?"":str.substr(i+5)));
    }
    return str=="a+a";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string str;
    getline(cin,str);
    string newstr="";
    for(i=0;i<str.size();i++){
        if(str[i]<='z'&&str[i]>='a')newstr+="a";
        else if(str[i]<='Z'&&str[i]>='A')newstr+="a";
        else if(str[i]=='('||str[i]==')')newstr+=str[i];
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='%')newstr+="+";
    }

    if(iscorrect(newstr)){
        if(newstr=="a"||isproper(newstr)){
            cout<<"proper";
        }
        else{
            cout<<"improper";
        }
    }
    else{
        cout<<"error";
    }

    return 0;
}
