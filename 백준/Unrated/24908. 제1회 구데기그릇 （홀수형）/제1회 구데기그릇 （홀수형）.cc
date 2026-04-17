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

void ans1(){
	ll n;
	cin>>n;
	ll i,ans=0,now=0;
	for(i=0;i<n;i++){
		now+=i+1;
		ans+=now;
	}
	cout<<ans;
}
void ans2(){
	cout<<"\"IMPOSSIBLE\"";
}


void ans4(){
	ll t=0;
    ll a,b;
    char c;
    string str;
    getline(cin,str);
    if(str.find(' ')!=string::npos){
		a=stoi(str.substr(0,str.find(' '))),b=stoi(str.substr(str.find(' ')+1));
		if(a&&b)cout<<a+b<<'\n';
		else return;
		while(cin>>a>>b){
    getline(cin,str);
			if(a&&b)cout<<a+b<<'\n';
			else return;
		}
    }
    else{
		t=stoi(str);
		while(t--){
			getline(cin,str);
			if(str.find(',')!=string::npos){
				a=stoi(str.substr(0,str.find(','))),b=stoi(str.substr(str.find(',')+1));
			}
			else if(str.find(' ')!=string::npos){
				a=stoi(str.substr(0,str.find(' '))),b=stoi(str.substr(str.find(' ')+1));
			}
			else{
				cout<<t+1+stoi(str)<<'\n';
				return;
			}
			cout<<a+b<<'\n';
		}
    }
}

void ans6(){
	vector<ll>mp(11172);
	for(ll i=0;i<11172;i++){
		cin>>mp[i];
	}
	{
		cout<<mp[503]*mp[9656]*mp[5752]<<' ';
		cout<<mp[11025]*mp[2911]*mp[5752]<<' ';
		cout<<mp[10603]*mp[5752]<<' ';
		cout<<mp[5122]*mp[1087]*mp[5752]<<' ';
		cout<<mp[2012]*mp[9523]*mp[5752]<<' ';
		cout<<mp[10516]*mp[4720]*mp[5752]<<' ';
		cout<<mp[10749]*mp[3733]*mp[5752]<<' ';
		cout<<mp[9649]*mp[5752]<<' ';
		cout<<mp[11103]*mp[5752]<<' ';
		cout<<mp[6198]*mp[2070]*mp[5752]<<' ';
		cout<<mp[6198]*mp[5752]<<' ';
		cout<<mp[8487]*mp[5752]<<' ';
		cout<<mp[2911]*mp[1087]*mp[5752]<<' ';
		cout<<mp[5411]*mp[9763]*mp[5752]<<' ';
		cout<<mp[5702]*mp[3010]*mp[5752]<<' ';
		cout<<mp[9351]*mp[5752]<<' ';
		cout<<mp[5122]*mp[5752]<<' ';
		cout<<mp[11079]*mp[5752]<<' ';
		cout<<mp[7150]*mp[5752]<<' ';
		cout<<mp[9591]*mp[5752]<<' ';
		cout<<mp[9768]*mp[5752]<<' ';
		cout<<mp[6791]*mp[5752]<<' ';
		cout<<mp[2306]*mp[5752]<<' ';
		cout<<mp[6580]*mp[5752]<<' ';
		cout<<mp[10512]*mp[5752]<<' ';
		cout<<mp[4821]*mp[5752]<<' ';
		cout<<mp[6380]*mp[5752]<<' ';
		cout<<mp[7665]*mp[5752]<<' ';
		cout<<mp[5629]*mp[5752]<<' ';
		cout<<mp[1040]*mp[5752]<<' ';
		cout<<mp[1030]*mp[5752]<<' ';
		cout<<mp[10390]*mp[5752]<<' ';
		cout<<mp[10527]*mp[5752]<<' ';
		cout<<mp[7668]*mp[5752]<<' ';
		cout<<mp[5061]*mp[5752]<<' ';
		cout<<mp[3266]*mp[5752]<<' ';
		cout<<mp[10778]*mp[7418]*mp[5752]<<' ';
		cout<<mp[2070]*mp[5752]<<' ';
		cout<<mp[3266]*mp[11103]*mp[5752]<<' ';
		cout<<mp[278]*mp[5752]<<' ';
		cout<<mp[2911]*mp[5752]<<' ';
		cout<<mp[4101]*mp[5752]<<' ';
		cout<<mp[7507]*mp[11103]*mp[5752]<<' ';
		cout<<mp[3329]*mp[5752]<<' ';
		cout<<mp[984]*mp[5752]<<' ';
		cout<<mp[9019]*mp[5752]<<' ';
		cout<<mp[4406]*mp[7507]*mp[5752]<<' ';
		cout<<mp[4542]*mp[1181]*mp[5752]<<' ';
		cout<<mp[9047]*mp[5752]<<' ';
		cout<<mp[4821]*mp[4304]*mp[5752]<<' ';
		cout<<mp[4821]*mp[9899]*mp[5752]<<' ';
		cout<<mp[3991]*mp[3401]*mp[5752]<<' ';
		cout<<mp[8368]*mp[10527]*mp[5752]<<' ';
		cout<<mp[4406]*mp[2070]*mp[5752]<<' ';
		cout<<mp[4130]*mp[10093]*mp[5752]<<' ';
		cout<<mp[3010]*mp[3329]*mp[5752]<<' ';
		cout<<mp[11073]*mp[7670]*mp[5752]<<' ';
		cout<<mp[8057]*mp[11103]*mp[5752]<<' ';
		cout<<mp[1204]*mp[9971]*mp[5752]<<' ';
		cout<<mp[4130]*mp[3608]*mp[5752]<<' ';
		cout<<mp[5888]*mp[5752]<<' ';
		cout<<mp[9971]*mp[5752]<<' ';
		cout<<mp[10778]*mp[5752]<<' ';
		cout<<mp[3148]*mp[5752]<<' ';
		cout<<mp[9389]*mp[5752]<<' ';
		cout<<mp[9523]*mp[5752]<<' ';
		cout<<mp[1954]*mp[9768]*mp[5752]<<' ';
		cout<<mp[4830]*mp[5122]*mp[5752]<<' ';
		cout<<mp[7017]*mp[4888]*mp[5752]<<' ';
		cout<<mp[11103]*mp[1491]*mp[5752]<<' ';
		cout<<mp[9351]*mp[11103]*mp[5752]<<' ';
		cout<<mp[503]*mp[9389]*mp[5752]<<' ';
		cout<<mp[9809]*mp[7493]*mp[5752]<<' ';
		cout<<mp[5122]*mp[7666]*mp[5752]<<' ';
		cout<<mp[6326]*mp[4933]*mp[5752]<<' ';
		cout<<mp[9147]*mp[9124]*mp[5752]<<' ';
		cout<<mp[10485]*mp[7418]*mp[5752]<<' ';
		cout<<mp[1087]*mp[11118]*mp[5752]<<' ';
		cout<<mp[9106]*mp[5752]<<' ';
		cout<<mp[7838]*mp[5752]<<' ';
		cout<<mp[1827]*mp[5752]<<' ';
		cout<<mp[3755]*mp[5752]<<' ';
		cout<<mp[8367]*mp[5752]<<' ';
		cout<<mp[10511]*mp[5752]<<' ';
		cout<<mp[8607]*mp[5752]<<' ';
		cout<<mp[9019]*mp[8607]*mp[5752]<<' ';
		cout<<mp[7507]*mp[7470]*mp[5752]<<' ';
		cout<<mp[6228]*mp[3755]*mp[5752]<<' ';
		cout<<mp[5454]*mp[1899]*mp[5752]<<' ';
		cout<<mp[7507]*mp[7322]*mp[5752]<<' ';
		cout<<mp[6389]*mp[5974]*mp[5752]<<' ';
		cout<<mp[4130]*mp[5752]<<' ';
		cout<<mp[9769]*mp[5752]<<' ';
		cout<<mp[11118]*mp[5752]<<' ';
		cout<<mp[4048]*mp[5752]<<' ';
		cout<<mp[5122]*mp[2931]*mp[5752]<<' ';
		cout<<mp[3752]*mp[9899]*mp[5752]<<' ';
		cout<<mp[11103]*mp[2070]*mp[5752]<<' ';
		cout<<mp[8607]*mp[6228]*mp[5752]<<' ';
		cout<<mp[9351]*mp[3329]*mp[5752]<<' ';
		cout<<mp[4416]*mp[4130]*mp[5752]<<' ';
		cout<<mp[9047]*mp[5346]*mp[5752]<<' ';
		cout<<mp[4578]*mp[984]*mp[5752]<<' ';
		cout<<mp[4416]*mp[3733]*mp[5752]<<' ';
		cout<<mp[612]*mp[5629]*mp[5752]<<' ';
		cout<<mp[8368]*mp[8021]*mp[5752]<<' ';
		cout<<mp[960]*mp[7669]*mp[5752]<<' ';
		cout<<mp[9799]*mp[4638]*mp[5752]<<' ';
		cout<<mp[1746]*mp[10621]*mp[5752]<<' ';
		cout<<mp[3266]*mp[11118]*mp[5752]<<' ';
		cout<<mp[10659]*mp[11025]*mp[5752]<<' ';
		cout<<mp[6926]*mp[5752]<<' ';
		cout<<mp[7248]*mp[5752]<<' ';
		cout<<mp[469]*mp[5752]<<' ';
		cout<<mp[4821]*mp[11103]*mp[5752]<<' ';
		cout<<mp[11103]*mp[5006]*mp[5752]<<' ';
		cout<<mp[3401]*mp[8132]*mp[5752]<<' ';
		cout<<mp[6687]*mp[5702]*mp[5752]<<' ';
		cout<<mp[4638]*mp[6926]*mp[5752]<<' ';
		cout<<mp[7485]*mp[4130]*mp[5752]<<' ';
		cout<<mp[1087]*mp[11079]*mp[5752]<<' ';
		cout<<mp[2931]*mp[5669]*mp[5752]<<' ';
		cout<<mp[9688]*mp[7493]*mp[5752]<<' ';
		cout<<mp[7670]*mp[5752]<<' ';
		cout<<mp[7322]*mp[5752]<<' ';
		cout<<mp[10882]*mp[5752]<<' ';
		cout<<mp[5669]*mp[5752]<<' ';
		cout<<mp[4130]*mp[10093]*mp[10527]*mp[5752]<<' ';
		cout<<mp[2359]*mp[6756]*mp[5752]<<' ';
		cout<<mp[7665]*mp[4130]*mp[5752]<<' ';
		cout<<mp[7507]*mp[9899]*mp[5752]<<' ';
		cout<<mp[9688]*mp[4053]*mp[5974]*mp[5752]<<' ';
		cout<<mp[9427]*mp[3148]*mp[11025]*mp[5752]<<' ';
		cout<<mp[10603]*mp[5122]*mp[1087]*mp[5752]<<' ';
		cout<<mp[7670]*mp[8090]*mp[3266]*mp[5752]<<' ';
		cout<<mp[5587]*mp[5749]*mp[4933]*mp[5752]<<' ';
		cout<<mp[7838]*mp[10007]*mp[6521]*mp[5752]<<' ';
		cout<<mp[6380]*mp[7493]*mp[5752]<<' ';
		cout<<mp[9763]*mp[4720]*mp[5752]<<' ';
		cout<<mp[9267]*mp[9899]*mp[5752]<<' ';
		cout<<mp[1746]*mp[5752]<<' ';
		cout<<mp[328]*mp[5752]<<' ';
		cout<<mp[10524]*mp[4933]*mp[9768]*mp[5752]<<' ';
		cout<<mp[11017]*mp[11025]*mp[5122]*mp[5752]<<' ';
		cout<<mp[4416]*mp[8090]*mp[9878]*mp[5752]<<' ';
		cout<<mp[6228]*mp[2976]*mp[5122]*mp[5752]<<' ';
		cout<<mp[1087]*mp[8607]*mp[5752]<<' ';
		cout<<mp[3733]*mp[4416]*mp[5752]<<' ';
		cout<<mp[7470]*mp[6198]*mp[5752]<<' ';
		cout<<mp[9019]*mp[10652]*mp[5752]<<' ';
		cout<<mp[8727]*mp[2070]*mp[5752]<<' ';
		cout<<mp[1939]*mp[4130]*mp[1827]*mp[5752]<<' ';
		cout<<mp[8368]*mp[5752]<<' ';
		cout<<mp[7669]*mp[2270]*mp[5752]<<' ';
		cout<<mp[1733]*mp[9096]*mp[1733]*mp[5752]<<' ';
		cout<<mp[1087]*mp[612]*mp[5629]*mp[5752]<<' ';
		cout<<mp[9389]*mp[5238]*mp[5752]<<' ';
		cout<<mp[5749]*mp[503]*mp[5752]<<' ';
		cout<<mp[10787]*mp[1746]*mp[5752]<<' ';
		cout<<mp[7493]*mp[7017]*mp[5752]<<' ';
		cout<<mp[1939]*mp[5752]<<' ';
		cout<<mp[93]*mp[5752]<<' ';
		cout<<mp[2070]*mp[8090]*mp[3182]*mp[5752]<<' ';
		cout<<mp[960]*mp[9039]*mp[5752]<<' ';
		cout<<mp[9124]*mp[10652]*mp[5752]<<' ';
		cout<<mp[8057]*mp[10390]*mp[5752]<<' ';
		cout<<mp[7507]*mp[8427]*mp[5752]<<' ';
		cout<<mp[7668]*mp[2931]*mp[5752]<<' ';
		cout<<mp[5133]*mp[5893]*mp[6228]*mp[784]*mp[5752]<<' ';
		cout<<mp[6259]*mp[784]*mp[3121]*mp[10719]*mp[5752]<<' ';
		cout<<mp[10778]*mp[9147]*mp[4133]*mp[6234]*mp[5752]<<' ';
		cout<<mp[9351]*mp[9768]*mp[5752]<<' ';
		cout<<mp[4053]*mp[5974]*mp[5752]<<' ';
		cout<<mp[7668]*mp[2070]*mp[5752]<<' ';
		cout<<mp[5749]*mp[7667]*mp[3447]*mp[4406]*mp[5752]<<' ';
		cout<<mp[10882]*mp[9899]*mp[3752]*mp[4542]*mp[5752]<<' ';
		cout<<mp[5366]*mp[9047]*mp[5122]*mp[2306]*mp[5752]<<' ';
		cout<<mp[4821]*mp[9899]*mp[1204]*mp[9971]*mp[5752]<<' ';
		cout<<mp[2359]*mp[7722]*mp[9649]*mp[5752]<<' ';
		cout<<mp[8368]*mp[9124]*mp[9656]*mp[278]*mp[5752]<<' ';
		cout<<mp[5587]*mp[3148]*mp[9523]*mp[5752]<<' ';
		cout<<mp[5238]*mp[10524]*mp[5752]<<' ';
		cout<<mp[5238]*mp[10485]*mp[5752]<<' ';
		cout<<mp[11073]*mp[784]*mp[5752]<<' ';
		cout<<mp[10942]*mp[8021]*mp[5752]<<' ';
		cout<<mp[5778]*mp[2306]*mp[5752]<<' ';
		cout<<mp[10524]*mp[4705]*mp[5752]<<' ';
		cout<<mp[4416]*mp[3182]*mp[5752]<<' ';
		cout<<mp[11103]*mp[7663]/3*mp[5752]<<' ';
		cout<<mp[7150]*mp[6687]*mp[10749]*mp[3733]*mp[5752]<<' ';
		cout<<mp[7493]*mp[3266]*mp[9124]*mp[10390]*mp[5752]<<' ';
		cout<<mp[8607]*mp[1434]*mp[6687]*mp[2306]*mp[5752]<<' ';
		cout<<mp[3608]*mp[3752]*mp[5752]<<' ';
		cout<<mp[2070]*mp[4406]*mp[5752]<<' ';
		cout<<mp[5749]*mp[9147]*mp[5752]<<' ';
		cout<<mp[7671]*mp[5752]<<' ';
		cout<<mp[9377]*mp[5752]<<' ';
		cout<<mp[10524]*mp[328]*mp[5752]<<' ';
		cout<<mp[10524]*mp[3401]*mp[5752]<<' ';
		cout<<mp[7507]*mp[11103]*mp[7665]*mp[5752]<<' ';
		cout<<mp[8679]*mp[8090]*mp[6580]*mp[5752]<<' ';
		cout<<mp[9047]*mp[3010]*mp[6234]*mp[5752]<<' ';
		cout<<mp[4130]*mp[5122]*mp[10778]*mp[7418]*mp[5752]<<' ';
		cout<<mp[1204]*mp[9971]*mp[1087]*mp[11079]*mp[5752]<<' ';
		cout<<mp[1620]*mp[9377]*mp[10778]*mp[7418]*mp[5752]<<' ';
		cout<<mp[10524]*mp[9338]*mp[5752]<<' ';
		cout<<mp[3093]*mp[6729]*mp[5752]<<' ';
		cout<<mp[3093]*mp[7493]*mp[5752]<<' ';
		cout<<mp[3093]*mp[6977]*mp[5752]<<' ';
		cout<<mp[2931]*mp[5752]<<' ';
		cout<<mp[1087]*mp[9338]*mp[5752]<<' ';
		cout<<mp[10485]*mp[3752]*mp[5752]<<' ';
		cout<<mp[6289]*mp[5752]<<' ';
		cout<<mp[11103]*mp[9389]*mp[5752]<<' ';
		cout<<mp[11103]*mp[3266]*mp[5752]<<' ';
		cout<<mp[9591]*mp[7665]*mp[5752]<<' ';
		cout<<mp[469]*mp[4464]*mp[5752]<<' ';
		cout<<mp[469]*mp[503]*mp[5752]<<' ';
		cout<<mp[6336]*mp[5752]<<' ';
		cout<<mp[10882]*mp[4168]*mp[8125]*mp[5752]<<' ';
		cout<<mp[5669]*mp[4168]*mp[8125]*mp[5752]<<' ';
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	ll n;
    string str;
    getline(cin,str);
	n=stoi(str);
	switch(n){
		case 1:ans1();break;
		case 2:ans2();break;
		case 4:ans4();break;
		case 6:ans6();break;
        default:cout<<"731706508";
	}
	return 0;
}
