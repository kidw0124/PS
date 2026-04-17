# [Diamond II] 페르마의 마지막 정리 - 27307 

[문제 링크](https://www.acmicpc.net/problem/27307) 

### 성능 요약

메모리: 2028 KB, 시간: 4 ms

### 분류

수학, 정수론, 분할 정복을 이용한 거듭제곱, 소인수분해, 폴라드 로, 지수승강 보조정리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>페르마의 마지막 정리는 다음과 같다.</p>

<p>$$\nexists (x, y, z) \in (\mathbb{Z\setminus}\{0\})^3 \quad s.t. \quad x^n + y^n = z^n(n \ge 3, n \in \mathbb{Z}, xyz \ne 0)$$</p>

<p style="text-align: center;"><img alt="페르마의 마지막 정리로 본 조선붕당의 이해" src="" style="width: 413px; height: 1400px;"></p>

<p style="text-align: center;">출처: 페이스북 수학 갤러리</p>

<p>유학을 꿈꾸는 창호는 위의 그림에서 서학을 믿고 있었기에, 본인이 페르마의 마지막 정리를 넘어 창호의 마지막 정리를 만들었다며 자랑한다. 우선 $2$ 이상의 정수 $k$를 소인수분해 했을 때 나오는 서로 다른 소수들의 집합을 $k$의 소수 집합이라고 정의하고 $\mathbb{p}(k)$라고 하자. 이때 $1$은 소인수분해 할 수 없으므로 $\mathbb{p}(1) = \emptyset$이라고 하자. 즉, $k = p_1^{e_1} p_2^{e_2} \cdots p_t^{e_t}(p_i$는 서로 다른 소수이고, $e_i \ge 1$인 정수$)$에 대해 $\mathbb{p}(k) = \{p_1, p_2, \cdots, p_t\}$이다. 이때, 창호의 마지막 정리는 다음과 같다.</p>

<p><strong>음이 아닌 홀수 $n$과 $0$이 아닌 정수 $x$와 $y$에 대하여, $x + y \ne 0$이라면, 어떤 1 이상의 정수 $z$가 존재해 $\mathbb{p}(z) \cap \mathbb{p}(\lvert x\rvert) = \emptyset$, $\mathbb{p}(z) \cap \mathbb{p}(\lvert y\rvert)= \emptyset$, $\mathbb{p}(z) \subseteq \mathbb{p}(\lvert x+y\rvert)$라면, 모든 음이 아닌 정수 $m$에 대하여 $\lvert x^n + y^n\rvert$는 $z^m$의 배수가 될 수 없다.</strong></p>

<p>이를 곰곰이 들여다보던 동우는 이 명제에 상당히 많은 반례가 존재함을 발견한다. $x$, $y$, $n$과 $m$이 주어졌을 때 위의 명제를 만족하지 않는 $z^m$의 개수와 합을 구해보자. 즉, $\mathbb{p}(z) \cap \mathbb{p}(\lvert x\rvert) = \emptyset$, $\mathbb{p}(z) \cap \mathbb{p}(\lvert y\rvert) = \emptyset$, $\mathbb{p}(z) \subseteq \mathbb{p}(\lvert x+y\rvert)$를 만족하면서, $\lvert x^n + y^n\rvert$는 $z^m$의 배수가 되는 $z^m$의 개수와 합을 구하면 된다.</p>

### 입력 

 <p>첫 번째 줄에 음이 아닌 홀수 $n$ ($1 \le n \le 10^{18}$, $n \equiv 1 \pmod{2}$)과 $0$이 아닌 정수 $x$와 $y$ ($1 \le \lvert x\rvert, \lvert y\rvert \le 10^{18}$, $x + y \ne 0$), 정수 $m$ ($1 \le m \le 10^{18}$)이 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>주어진 $n$,$x$, $y$, $m$에 대해 $\mathbb{p}(z) \cap \mathbb{p}(\lvert x\rvert) = \emptyset$, $\mathbb{p}(z) \cap \mathbb{p}(\lvert y\rvert) = \emptyset$, $\mathbb{p}(z) \subseteq \mathbb{p}(\lvert x+y\rvert)$를 만족하며 $\lvert x^n + y^n\rvert$가 $z^m$의 배수가 되는 $z^m$의 개수와 합을 $1\,000\,000\,007$으로 나눈 나머지를 공백으로 구분하여 출력한다.</p>

