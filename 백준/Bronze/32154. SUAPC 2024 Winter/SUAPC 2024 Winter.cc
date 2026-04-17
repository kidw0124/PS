#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr({
        0,
        11,9,9,9,8,8,
        8,8,8,8,8
    });
    vector<string>brr({
        "",
        "A B C D E F G H J L M",
        "A C E F G H I L M",
        "A C E F G H I L M",
        "A B C E F G H L M",
        "A C E F G H L M",
        "A C E F G H L M",
        "A C E F G H L M",
        "A C E F G H L M",
        "A C E F G H L M",
        "A B C F G H L M"
    });
    int n;
    cin>>n;
    cout<<arr[n]<<' '<<brr[n];
}