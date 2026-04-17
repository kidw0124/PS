#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using LL = __int128;
using ld = long double;
using pll = pair<LL, LL>;
using tlll = tuple<ll, ll, ll>;

#define debug if constexpr (xdebug) cout << "[DEBUG] "

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
template<typename T>
struct LinkedList{
    struct Node{
        T data;
        Node *nextNode, *prevNode;
        Node(){
//            (*this).data=0;
            this->data=0;
            this->nextNode=nullptr;
            prevNode=nullptr;
        }
        ~Node(){
            // 이 변수가 삭제될 때 실행할 함수
        }
        Node(T data):data(data),nextNode(nullptr),prevNode(nullptr){}
        Node* insert_next(T x){
            // 현재 노드 뒤에 x노드 삽입
            Node* tmp = new Node(x);
            tmp->nextNode=this->nextNode;
            tmp->prevNode=this;
            if(this->nextNode)this->nextNode->prevNode=tmp;
            this->nextNode=tmp;
            return tmp;
        }
        Node* insert_front(T x){
            // 현재 노드 뒤에 x노드 삽입
            Node* tmp = new Node(x);
            tmp->nextNode=this;
            tmp->prevNode=this->prevNode;
            if(this->prevNode)this->prevNode->nextNode=tmp;
            this->prevNode=tmp;
            return tmp;
        }
        void erase(){
            Node* pr=this->prevNode,*nx=this->nextNode;
            pr->nextNode=nx,nx->prevNode=pr;
            delete this;
        }
    };
    Node *root = NULL;
    Node* find(T x){
        Node* now=root;
        while(now){
            if(now->data==x)return now;
            else now=now->nextNode;
        }
        return now;
    }
    Node* front(){
        return root;
    }
    Node* back(){
        if(!root)return NULL;
        else{
            Node* now=root;
//            now->root;
//            (*now).root;
            while(now->nextNode)now=now->nextNode;
            return now;
        }
    }
    bool empty(){
        return !root;
    }
    Node* push_back(T x){
        // data : x / prev,nex : null
        if(this->empty()){
            Node* tmp(x);
            return root=tmp;
        }
        else {
//            tmp->prevNode = this->back();
//            this->back()->nextNode = tmp;
            return this->back()->insert_next(x);
        }
    }
    Node* push_front(T x){
        if(this->empty()){
            Node* tmp(x);
            return root=tmp;
        }
        else{
//            tmp->nextNode = this->front();
//            this->front()->prevNode = tmp;
//            root=tmp;
            return root=front()->insert_front(x);
        }
    }
};

void solve(ll testcase){
    ll i,j;
    forward_list<char>flt; //singly linked  : prev 없음
    list<char>lst; // doubly linked : next, prev 다 있음
    string str;
    list<char>::iterator cursor;
    cin>>str;
    for(auto k:str){
        lst.push_back(k); // amt O(1)
    }
    cursor=lst.end();
    // bg=begin
    // bg   bg+1   bg+2    bg+3   bg+4=end
    //   [0]    [1]     [2]    [3]
    ll n;
    cin>>n;
    while(n--){
        char op,x;
        cin>>op;
        if(op=='P')cin>>x;
        switch (op) {
            case 'L':
                if(cursor==lst.begin())break;
                cursor--;
//                cursor=prev(cursor);
                break;
            case 'D':
                if(cursor==lst.end())continue;
//                cursor++;
                cursor = next(cursor);
                break;
            case 'B':
                if(cursor==lst.begin())continue;
                cursor--;
                cursor=lst.erase(cursor);
                // O(1) : vector, deque이랑(O(len)) 다름
                break;
            case 'P':
                lst.insert(cursor, x);
                // O(1) : vector, deque이랑(O(len)) 다름
                break;
        }
    }
    for(auto x:lst)cout<<x;
}

int main(){

#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t st = clock();
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int t = 1;
//    cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    clock_t ed = clock();
#ifdef kidw0124
    clock_t en = clock();
    cout << "Time: " << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}
