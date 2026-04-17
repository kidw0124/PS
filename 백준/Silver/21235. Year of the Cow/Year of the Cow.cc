#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

map<string,int> ffff;
vector<tuple<string, string, string, bool> > v;

set<string> name;
queue<string>temp;
int n;

map<string,int> year;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ffff["Ox"]=0;
    ffff["Tiger"]=1;
    ffff["Rabbit"]=2;
    ffff["Dragon"]=3;
    ffff["Snake"]=4;
    ffff["Horse"]=5;
    ffff["Goat"]=6;
    ffff["Monkey"]=7;
    ffff["Rooster"]=8;
    ffff["Dog"]=9;
    ffff["Pig"]=10;
    ffff["Rat"]=11;
    cin>>n;
    for(i=0;i<n;i++){
        string a,b,n,t,s;
        cin>>a>>t>>t>>n>>s>>t>>t>>b;
        name.insert(a);
        name.insert(b);
        if(n=="previous"){
            v.push_back(make_tuple(a,b,s,false));
        }else{
            v.push_back(make_tuple(a,b,s,true));
        }
    }
    temp.push("Bessie");
    year["Bessie"]=2520;
    name.erase("Bessie");
    while(!name.empty()){
        for(auto k : v){
            if(get<0>(k)==temp.front()){
                if(name.find(get<1>(k))==name.end())continue;
                int x=year[temp.front()];
                if(get<3>(k)==true){
                    x++;
                    while(x%12!=ffff[get<2>(k)]){
                        x++;
                    }
                    year[get<1>(k)]=x;
                    temp.push(get<1>(k));
                }
                else{
                    x--;
                    while(x%12!=ffff[get<2>(k)]){
                        x--;
                    }
                    year[get<1>(k)]=x;
                    temp.push(get<1>(k));
                }
                name.erase(get<1>(k));
            }
            if(get<1>(k)==temp.front()){
                if(name.find(get<0>(k))==name.end())continue;
                int x=year[temp.front()];
                if(get<3>(k)==true){
                    x++;
                    while(x%12!=ffff[get<2>(k)]){
                        x++;
                    }
                    year[get<0>(k)]=x;
                    temp.push(get<0>(k));
                }
                else{
                    x--;
                    while(x%12!=ffff[get<2>(k)]){
                        x--;
                    }
                    year[get<0>(k)]=x;
                    temp.push(get<0>(k));
                }
                name.erase(get<0>(k));
            }
        }
        temp.pop();
    }

    cout<<abs(year["Elsie"]-2520);


    return 0;
}