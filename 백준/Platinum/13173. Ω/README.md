# [Platinum V] Ω - 13173 

[문제 링크](https://www.acmicpc.net/problem/13173) 

### 성능 요약

메모리: 2308 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 분할 정복을 이용한 거듭제곱, 수학, 모듈로 곱셈 역원, 정수론

### 제출 일자

2024년 6월 21일 23:39:38

### 문제 설명

<p>이제 조금 더 어려운 문제를 해결해 보자. 당신은 지금 P면체 주사위를 굴리고 있다. 각 면에는 1 이상 P 이하의 자연수가 하나씩 적혀 있으며, 주사위를 굴렸을 때 각 면이 나올 확률은 모든 면에 대해 동일하다. 이제 다음과 같은 놀이를 할 것이다.</p>

<ul>
	<li>처음에는 K라는 수를 가지고 있다.</li>
	<li>가지고 있는 수가 0이거나 N이면 놀이를 끝낸다. 놀이가 끝나지 않았다면 주사위를 굴린다. 만약에 Q 이하인 수가 나오면 현재 가지고 있는 수에서 1을 빼주고, 아니라면(즉 Q 초과의 수가 나오면) 1을 더해준다. 이를 계속 반복한다.</li>
</ul>

<p>놀이가 끝났을 때 가지고 있는 수가 N일 확률을 구하는 프로그램을 작성하라.</p>

### 입력 

 <p>첫 번째 줄에는 정수 P(1 ≤ P ≤ 100)가 주어진다.</p>

<p>두 번째 줄에는 정수 Q(0 ≤ Q ≤ P)가 주어진다.</p>

<p>세 번째 줄에는 정수 N(1 ≤ N ≤ 100)이 주어진다.</p>

<p>네 번째 줄에는 정수 K(0 ≤ K ≤ N)가 주어진다.</p>

### 출력 

 <p>놀이가 끝났을 때의 숫자가 N 일 확률을 출력한다. 정확한 판별을 위해, 답을 기약분수로 나타내었을 때 a/b가 된다면, (a × b<sup>-1</sup>) mod 1,000,000,007을 대신 출력하도록 한다. b<sup>-1</sup>은 b의 모듈러 곱셈에 대한 역원이다. 이 문제에서는 가능한 모든 입력에 대해 답이 존재한다.</p>

