#include<bits/stdc++.h>
using namespace std;
#include<random>
using namespace std;

int rand_num(int m, int M)
{
	random_device rn;
	mt19937_64 rnd(rn());

	uniform_int_distribution<int> range(m, M);

	return range(rnd);
}

int main(){
    
        printf("%d",rand_num(0,2));
    
}
