# [Platinum I] Milk Visits - 18263 

[문제 링크](https://www.acmicpc.net/problem/18263) 

### 성능 요약

메모리: 29152 KB, 시간: 272 ms

### 분류

자료 구조(data_structures), Heavy-light 분할(hld), 오프라인 쿼리(offline_queries), 세그먼트 트리(segtree), 트리(trees)

### 문제 설명

<p>Farmer John is planning to build $N$ ($1 \leq N \leq 10^5$) farms that will be connected by $N-1$ roads, forming a tree (i.e., all farms are reachable from each-other, and there are no cycles). Each farm contains a cow with an integer type $T_i$ between $1$ and $N$ inclusive.</p>

<p>Farmer John's $M$ friends ($1 \leq M \leq 10^5$) often come to visit him. During a visit with friend $i$, Farmer John will walk with his friend along the unique path of roads from farm $A_i$ to farm $B_i$ (it may be the case that $A_i = B_i$). Additionally, they can try some milk from any cow along the path they walk. Since most of Farmer John's friends are also farmers, they have very strong preferences regarding milk. Each of his friends will only drink milk from a certain type of cow. Any of Farmer John's friends will only be happy if they can drink their preferred type of milk during their visit.</p>

<p>Please determine whether each friend will be happy after visiting.</p>

### 입력 

 <p>The first line contains two integer $N$ and $M$.</p>

<p>The second line contains $N$ space-separated integers $T_1,T_2,\ldots, T_N.$ The type of the cow in the $i$-th farm is denoted by $T_i.$</p>

<p>The next $N-1$ lines each contain two distinct integers $X$ and $Y$ ($1 \leq X, Y \leq N$), indicating that there is an edge between farms $X$ and $Y$.</p>

<p>The next $M$ lines contain integers $A_i$, $B_i$, and $C_i$. $A_i$ and $B_i$ represent the endpoints of the path walked during friend $i$'s visit, while $C_i$ ($1\le C_i\le N$) indicates the type of cow whose milk the friend enjoys drinking.</p>

### 출력 

 <p>Print a binary string of length $M.$ The $i$th character of the string should be '1' if the $i$th friend will be happy, or '0' otherwise.</p>

