#include<bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx,avx2,fma")

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pll;

typedef long double ld;

#ifdef ONLINE_JUDGE

constexpr bool XDEBUG = false;

#else

constexpr bool XDEBUG = true;

#endif

void setup(){

    if(XDEBUG){

        freopen("input.txt","r",stdin);

        freopen("output.txt","w",stdout);

    }

    else{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cout.tie(0);

    }

}

void preprocess(){

    ll i,j,k;

}

void solve(ll testcase){

    ll i,j,k;

    ll n,m;

    cin>>n>>m;

    vector<string>str(n);

    vector<vector<bool>>chk(n,vector<bool>(m));

    vector<string>arr;

    for(i=0;i<n;i++){

        cin>>str[i];

    }

    for(i=0;i<n;i++){

        for(j=0;j<m;j++){

            switch (str[i][j]) {

                case 'G':str[i][j]='3';break;

                case 'Z':str[i][j]='4';break;

                case 'D':str[i][j]='1';break;

                case 'P':str[i][j]='2';break;

                default: str[i][j]=0;

            }

        }

    }

    for(i=n-1;i>=0;i--){

        for(j=0;j<m;j++){

            if(chk[i][j]||!str[i][j])continue;

            queue<pll>que;

            string now="";

            que.push({i,j});

            chk[i][j]=1;

            while(!que.empty()){

                auto [x,y]=que.front();

                que.pop();

                now+=str[x][y];

                ll nx=x,ny=y;

                if(str[x][y]=='3'||str[x][y]=='1'){

                    ny++;

                }

                else if(str[x][y]=='2'||str[x][y]=='4'){

                    nx--;

                }

                else{

                    continue;

                }

                if(nx<0||ny<0||nx>=n||ny>=m||!str[nx][ny] || !((str[nx][ny]^str[x][y])&1))continue;

                else{

                    que.push({nx,ny});

                    chk[nx][ny]=1;

                }

            }

            arr.push_back(now);

        }

    }

    ll p=0;

    for(auto nows:arr){

        reverse(nows.begin(),nows.end());

        while(nows.size()>2){

            if(nows.back()=='1'||nows.back()=='4')nows.pop_back();

            else{

                string a="";

                a+=nows[nows.size()-1];

                a+=nows[nows.size()-2];

                a+=nows[nows.size()-3];

                if(a=="212"){

                    p++;

                    nows.pop_back();

                    nows[nows.size()-1]='3';

                }

                else if(a=="214"){

                    nows.pop_back();

                    nows.pop_back();

                    nows[nows.size()-1]='2';

                }

                else if(a=="232"){

                    nows.pop_back();

                    nows.pop_back();

                }

                else if(a=="234"){

                    nows.pop_back();

                    nows[nows.size()-2]='2';

                }

                else if(a=="343"){

                    p--;

                    nows.pop_back();

                    nows[nows.size()-1]='2';

                }

                else if(a=="341"){

                    nows.pop_back();

                    nows.pop_back();

                    nows[nows.size()-1]='3';

                }

                else if(a=="323"){

                    nows.pop_back();

                    nows.pop_back();

                }

                else if(a=="321"){

                    nows.pop_back();

                    nows[nows.size()-2]='3';

                }

            }

        }

        if(nows=="12")p++;

        else if(nows=="43")p--;

    }

    if(p>=0){

        cout<<"Aubergine";

    }

    else cout<<"Scallion";

//    cout<<'\n'<<n;

}

int main(){

    setup();

    preprocess();

    ll t=1;

//    cin>>t;

    for(ll i=0;i<t;i++){

        solve(i+1);

    }

}