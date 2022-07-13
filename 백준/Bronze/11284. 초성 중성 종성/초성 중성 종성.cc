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
#define KOR_LEN 3
vector<string> cho({"ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ", "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"});
vector<string> joong({"ㅏ", "ㅐ", "ㅑ", "ㅒ", "ㅓ", "ㅔ", "ㅕ", "ㅖ", "ㅗ", "ㅘ", "ㅙ", "ㅚ", "ㅛ", "ㅜ", "ㅝ", "ㅞ", "ㅟ", "ㅠ", "ㅡ", "ㅢ", "ㅣ"});
vector<string> jong({"","ㄱ", "ㄲ", "ㄳ", "ㄴ", "ㄵ", "ㄶ", "ㄷ", "ㄹ", "ㄺ", "ㄻ", "ㄼ", "ㄽ", "ㄾ", "ㄿ", "ㅀ", "ㅁ", "ㅂ", "ㅄ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"});

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

class string_kor
{
public:
    string_kor(const string&str):str(str){}
    string_kor(){string_kor("");}
    ~string_kor(){};

    void operator=(const string&str){
        this->str=str;
    }
    void operator=(const string_kor&str){
        this->str=str.str;
    }
    void operator=(const wstring&str){
        this->str=string(str.begin(),str.end());
    }
    bool operator==(const string_kor&str){
        return str.str==this->str;
    }


    string_kor operator[](const ll&x){
        return str.substr(KOR_LEN*x,KOR_LEN);
    }
    string_kor substr(ll st, ll len){
        return str.substr(KOR_LEN*st,len*KOR_LEN);
    }
    size_t size(){
        return str.size()/KOR_LEN;
    }
    string to_string(){
        return str;
    }

    string_kor cho_sung(){
        string ret="";
        ret.clear();
        for(int i=0;i<str.size();i+=3){
            string_kor ss=(*this)[i/3];
            wstring ustr;
            fromUTF8(ss.to_string(),ustr);
            ret+=cho[(ustr[0]-0xAC00)/(21*28)];
        }
        return string_kor(ret);

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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string str;
    cin>>str;
    wstring ustr;
    fromUTF8(str,ustr);
    ll t=ustr[0]-0xAC00;
    cout<<cho[t/21/28]<<'\n';
    cout<<joong[t/28%21]<<'\n';
    cout<<jong[t%28]<<'\n';

    return 0;
}
