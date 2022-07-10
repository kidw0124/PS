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
//#define sizeof(wchar_t) 3
class string_kor
{
public:
    string_kor(const string&str):str(str){}
    string_kor(const wstring&str){
        this->str="";
        for(int i=0;i<str.size()*sizeof(wchar_t);i++){
            cout<<dec<<(*str.data())%256<<' ';
            this->str+=str[i];
        }
        cout<<this->str.size();
    }
    string_kor(){string_kor("");}
    ~string_kor(){};

    void operator=(const string&str){
        this->str=str;
    }
    void operator=(const wstring&str){
        this->str=string(str.begin(),str.end());
    }
    bool operator==(const string_kor&str){
        return str.str==this->str;
    }

    string_kor operator[](const ll&x){
        return str.substr(sizeof(wchar_t)*x,sizeof(wchar_t));
    }
    string_kor substr(ll st, ll len){
        return str.substr(sizeof(wchar_t)*st,len*sizeof(wchar_t));
    }
    size_t size(){
        return str.size()/sizeof(wchar_t);
    }
    istream& input(istream&is){
        return is>>str;
    }
    ostream& print(ostream&os){
        return os<<str;
    }
protected:
private:
    string str;
};

istream&operator>>(istream&is,string_kor&str){
    return str.input(is);
}
ostream&operator<<(ostream&os,string_kor&str){
    return str.print(os);
}

template <typename T>
string toUTF8(const basic_string<T, char_traits<T>, allocator<T>>& source)
{
    string result;

    wstring_convert<codecvt_utf8<T>, T> convertor;
    result = convertor.to_bytes(source);

    return result;
}

template <typename T>
void fromUTF8(const string& source, basic_string<T, char_traits<T>, allocator<T>>& result)
{
    wstring_convert<codecvt_utf8_utf16<T>, T> convertor;
    result = convertor.from_bytes(source);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>i;
    wstring ustr(1,i-1+0xAC00);
    string str=toUTF8(ustr);
    cout<<str;


    return 0;
}
