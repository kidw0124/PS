# [Diamond IV] 점 세게 돌리기 - 35158 

[문제 링크](https://www.acmicpc.net/problem/35158) 

### 성능 요약

메모리: 85976 KB, 시간: 712 ms

### 분류

구현, 자료 구조, 세그먼트 트리, 비트마스킹, 분할 정복, 오프라인 쿼리

### 제출 일자

2026년 4월 21일 03:43:49

### 문제 설명

<p>$3$차원 공간에 한 개의 점 $\left(x_0,y_0,z_0\right)$가 있다.</p>

<p>이 점에 대해 다음 연산들을 적용할 수 있다.</p>

<ul>
<li>$x$축 회전(<span style="color:#e74c3c;"><code>X</code></span>) : $\left( x,y,z \right)\mapsto\left( x,-z,y \right)$</li>
<li>$y$축 회전(<span style="color:#e74c3c;"><code>Y</code></span>) : $\left( x,y,z \right)\mapsto\left( z,y,-x \right)$</li>
<li>$z$축 회전(<span style="color:#e74c3c;"><code>Z</code></span>) : $\left( x,y,z \right)\mapsto\left( -y,x,z \right)$</li>
<li>$x$축 대칭(<span style="color:#e74c3c;"><code>XX</code></span>) : $\left( x,y,z \right)\mapsto\left( x,-y,-z \right)$</li>
<li>$y$축 대칭(<span style="color:#e74c3c;"><code>YY</code></span>) : $\left( x,y,z \right)\mapsto\left( -x,y,-z \right)$</li>
<li>$z$축 대칭(<span style="color:#e74c3c;"><code>ZZ</code></span>) : $\left( x,y,z \right)\mapsto\left( -x,-y,z \right)$</li>
<li>$xy$평면 대칭(<span style="color:#e74c3c;"><code>XY</code></span> 혹은 <span style="color:#e74c3c;"><code>YX</code></span>) : $\left( x,y,z \right)\mapsto\left( x,y,-z \right)$</li>
<li>$yz$평면 대칭(<span style="color:#e74c3c;"><code>YZ</code></span> 혹은 <span style="color:#e74c3c;"><code>ZY</code></span>) : $\left( x,y,z \right)\mapsto\left( -x,y,z \right)$</li>
<li>$xz$평면 대칭(<span style="color:#e74c3c;"><code>ZX</code></span> 혹은 <span style="color:#e74c3c;"><code>XZ</code></span>) : $\left( x,y,z \right)\mapsto\left( x,-y,z \right)$</li>
</ul>

<p>서현이는 <span style="color:#e74c3c;"><code>X</code></span>, <span style="color:#e74c3c;"><code>Y</code></span>, <span style="color:#e74c3c;"><code>Z</code></span>로 이루어진 문자열 $S$를 가지고 있다. 서현이는 이 문자열의 $l$번째 문자부터 $r$번째 문자로 이루어진 부분 문자열 $S\left[ l\ldots r \right]$을 연속적인 연산들로 해석하려 한다. 이때 문자 하나를 연산 하나로 보거나, 이웃한 문자 두 개를 연산 하나로 볼 수 있다. 연산을 해석할 수 있는 경우의 수가 피보나치 수라는 사실은 서현이에게 너무나도 자명하다. 그렇다면 해석한 연산들을 주어진 점 $\left( x_0,y_0,z_0 \right)$에 대해 왼쪽부터 차례로 적용할 때, 최종적으로 점이 위치할 수 있는 서로 다른 좌표의 개수를 구하고 싶다.</p>

<p>구체적으로 다음과 같은 쿼리 $Q$개를 독립적으로 처리해 보자. 즉, 모든 쿼리에 대해 점의 초기 위치는 $\left( x_0,y_0,z_0 \right)$에서 시작한다.</p>

<ul>
<li>$l$ $r$: $S\left[ l\ldots r \right]$을 연속적인 연산들로 해석할 때, $\left( x_0,y_0,z_0 \right)$가 최종적으로 위치할 수 있는 서로 다른 좌표의 개수를 출력한다.</li>
</ul>

### 입력 

 <p>첫 번째 줄에 점의 초기 좌표를 의미하는 세 정수 $x_0,y_0,z_0(-3\le x_0,y_0,z_0\le 3)$가 공백으로 구분되어 주어진다.</p>

<p>두 번째 줄에 <span style="color:#e74c3c;"><code>X</code></span>, <span style="color:#e74c3c;"><code>Y</code></span>, <span style="color:#e74c3c;"><code>Z</code></span>로만 이루어진 문자열 $S(1\le\lvert S\rvert\le 100\, 000)$가 주어진다.</p>

<p>세 번째 줄에 쿼리의 개수 $Q(1\le Q\le 100\, 000)$가 주어진다.</p>

<p>네 번째 줄부터 $Q$줄에 걸쳐 $i$번째 쿼리를 의미하는 정수 $l_i,r_i(1\le l_i\le r_i\le\lvert S\rvert)$가 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>첫 번째 줄부터 $Q$줄에 걸쳐 각 쿼리에 대한 답을 출력한다.</p>

