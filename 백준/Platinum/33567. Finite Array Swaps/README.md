# [Platinum II] Finite Array Swaps - 33567 

[문제 링크](https://www.acmicpc.net/problem/33567) 

### 성능 요약

메모리: 51416 KB, 시간: 412 ms

### 분류

애드 혹, 비트 집합, 많은 조건 분기, 자료 구조, 그리디 알고리즘, 해시를 사용한 집합과 맵, 구현, 시뮬레이션, 트리를 사용한 집합과 맵

### 제출 일자

2025년 3월 4일 04:42:04

### 문제 설명

<blockquote>
<p><strong>이 문제는 <a href="/problem/33559" target="_blank">Infinite Array Swaps</a>와 굵은 글씨로 적힌 부분과 입출력만 다릅니다.</strong></p>
</blockquote>

<p>동우는 길이가 $N$인 두 배열 $A=\left[ A_1,A_2,\cdots ,A_N \right]$과 $B=\left[ B_1,B_2,\cdots ,B_N \right]$을 가지고 있다.</p>

<p>동우는 두 배열에 다음 두 시행을 <strong>합쳐서 최대 $K$번</strong> 할 수 있다. 교환하는 두 원소의 인덱스는 달라야 한다.</p>

<ul>
	<li>배열 $A$에서 두 원소를 골라 교환한다.</li>
	<li>배열 $B$에서 두 원소를 골라 교환한다.</li>
</ul>

<p>이 연산을 통해 얻은 최종 상태에서의 두 배열을 $A^\prime=\left[ A_1^\prime,A_2^\prime,\cdots ,A_N^\prime \right]$과 $B^\prime=\left[ B_1^\prime,B_2^\prime,\cdots ,B_N^\prime \right]$이라 할 때, 동우는 $A_i^\prime=B_i^\prime$를 만족하는 쌍의 개수를 최대화하려고 한다. 두 배열이 주어질 때, 이를 최대로 하는 교환을 찾아보자.</p>

### 입력 

 <p>첫 번째 줄에 두 배열의 길이 $N(1\le N\le 10^5)$과 총 시행의 최대 횟수 $K(0\le K\le 2)$가 공백으로 구분되어 주어진다.</p>

<p>두 번째 줄에 배열 $A$의 원소 $A_1,A_2,\cdots ,A_N(1\le A_i\le 10^9)$이 공백으로 구분되어 주어진다.</p>

<p>세 번째 줄에 배열 $B$의 원소 $B_1,B_2,\cdots ,B_N(1\le B_i\le 10^9)$이 공백으로 구분되어 주어진다.</p>

<p>주어지는 입력은 모두 정수이다.</p>

### 출력 

 <p>첫 번째 줄에 $A_i^\prime=B_i^\prime$를 만족하는 쌍의 개수의 최댓값을 출력한다.</p>

<p>두 번째 줄에 최종 상태에서의 배열 $A^\prime$의 원소 $A_1^\prime,A_2^\prime,\cdots ,A_N^\prime$을 공백으로 구분하여 출력한다.</p>

<p>세 번째 줄에 최종 상태에서의 배열 $B^\prime$의 원소 $B_1^\prime,B_2^\prime,\cdots ,B_N^\prime$을 공백으로 구분하여 출력한다.</p>

<p>네 번째 줄에 시행의 총 횟수 $T(0\le T\le K)$를 출력한다.</p>

<p>다음 줄부터 $T$줄에 걸쳐 한 줄에 한 번의 시행을 출력한다. 시행은 일어나는 순서대로 출력해야 하며, 시행에 따라 아래 둘 중 하나를 출력한다. 배열 $A$와 $B$에 출력한 시행을 순서대로 적용했을 때 $A^\prime$과 $B^\prime$이 되어야 한다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>A</code></span> $i$ $j$: $A_i$와 $A_j$를 교환한다. $(i\ne j)$</li>
	<li><span style="color:#e74c3c;"><code>B</code></span> $i$ $j$: $B_i$와 $B_j$를 교환한다. $(i\ne j)$</li>
</ul>

<p>가능한 정답이 여러 개라면 아무거나 하나 출력한다.</p>

