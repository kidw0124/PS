# [Diamond II] 수열과 쿼리 14 - 13927 

[문제 링크](https://www.acmicpc.net/problem/13927) 

### 성능 요약

메모리: 5844 KB, 시간: 784 ms

### 분류

자료 구조, 세그먼트 트리, 이분 탐색, 퍼시스턴트 세그먼트 트리, 다차원 세그먼트 트리

### 제출 일자

2025년 10월 16일 18:32:09

### 문제 설명

<p>길이가 N인 수열 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.</p>

<ul>
	<li><code>l r k</code>: S를 A의 l번째 수부터 r번째 수까지 수로 이루어진 오름차순으로 정렬된 집합(중복을 허용하지 않음)이라고 했을 때, k번째 수를 출력한다. 만약, k번째 수가 존재하지 않으면 -1을 출력한다.</li>
</ul>

<p>수열의 인덱스는 1부터 시작한다.</p>

### 입력 

 <p>첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 100,000)</p>

<p>둘째 줄에는 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. (1 ≤ A<sub>i</sub> ≤ 10<sup>9</sup>)</p>

<p>셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 100,000)</p>

<p>넷째 줄부터 M개의 줄에는 쿼리를 만드는 정보인 a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>, d<sub>i</sub>, k<sub>i</sub>가 한 줄에 하나씩 주어진다. (0 ≤ a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>, d<sub>i</sub> ≤ N, 1 ≤ k<sub>i</sub> ≤ N)</p>

<p>각각의 쿼리 l<sub>i</sub>, r<sub>i</sub>는 다음과 같이 만든다.</p>

<p>먼저, i-1번째 쿼리의 정답을 ans<sub>i-1</sub>이라고 한다. (0번째 쿼리의 정답 ans<sub>0</sub> = 0)</p>

<ul>
	<li>l<sub>i</sub> = (a<sub>i</sub> x max(ans<sub>i-1</sub>, 0) + b<sub>i</sub>) mod N + 1</li>
	<li>r<sub>i</sub> = (c<sub>i</sub> x max(ans<sub>i-1</sub>, 0) + d<sub>i</sub>) mod N + 1</li>
</ul>

<p>만약, l<sub>i</sub> > r<sub>i</sub> 이면 l<sub>i</sub>와 r<sub>i</sub>를 바꾼다.</p>

### 출력 

 <p>각각의 쿼리에 대해서 정답을 한 줄에 하나씩 순서대로 출력한다.</p>

