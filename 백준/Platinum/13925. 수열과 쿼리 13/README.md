# [Platinum I] 수열과 쿼리 13 - 13925 

[문제 링크](https://www.acmicpc.net/problem/13925) 

### 성능 요약

메모리: 52768 KB, 시간: 212 ms

### 분류

자료 구조, 세그먼트 트리, 느리게 갱신되는 세그먼트 트리

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>길이가 N인 수열 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오. </p>

<ul>
	<li><code>1 x y v</code>: A<sub>i</sub> = (A<sub>i</sub> + v) % MOD를 수행한다. (x ≤ i ≤ y)</li>
	<li><code>2 x y v</code>: A<sub>i</sub> = (A<sub>i</sub> × v) % MOD를 수행한다. (x ≤ i ≤ y)</li>
	<li><code>3 x y v</code>: A<sub>i</sub> = v를 수행한다. (x ≤ i ≤ y)</li>
	<li><code>4 x y</code>: (ΣA<sub>i</sub>) % MOD를 출력한다. (x ≤ i ≤ y)</li>
</ul>

<p>여기서 MOD는 항상 10<sup>9</sup>+7이며, %는 나머지 연산을 의미한다.</p>

### 입력 

 <p>첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 100,000)</p>

<p>둘째 줄에는 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. (1 ≤ A<sub>i</sub> ≤ 10<sup>9</sup>)</p>

<p>셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 100,000)</p>

<p>넷째 줄부터 M개의 줄에는 쿼리가 한 줄에 하나씩 주어진다. (1 ≤ x ≤ y ≤ N, 1 ≤ v ≤ 10<sup>9</sup>)</p>

### 출력 

 <p>4번 쿼리에 대해서 정답을 한 줄에 하나씩 순서대로 출력한다.</p>

