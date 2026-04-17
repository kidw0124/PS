# [Gold II] 동전 옮기기 - 20047 

[문제 링크](https://www.acmicpc.net/problem/20047) 

### 성능 요약

메모리: 2828 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>100 원짜리 동전과 10 원짜리 동전이 임의의 순서로 한 선 위에 나열되어 있다고 하자. 이제 여기서 ‘<strong>두 손가락 이동</strong>’ 을 아래와 같이 정의하자.</p>

<ul>
	<li>단계 1: 임의의 두 동전을 선택한다.</li>
	<li>단계 2: 단계 1 에서 선택한 두 동전을 둘의 순서를 유지한 채 임의의 위치로 이동한다. (두 동전 모두 제자리에 있거나 두 동전의 순서를 유지한다면 하나만 이동해도 된다.)</li>
</ul>

<p>‘두 손가락 이동’ 후에도 다른 동전들 간의 순서는 그대로 유지된다. 예를 들어 100 원을 <code>o</code>, 10 원을 <code>x</code> 라 했을 때, 초기에 동전이 <code>oxox<strong>ox</strong>xxoo</code> 와 같이 나열되어 있다 하자. 이제 이들 중 굵게 표시된 두 동전을 선택하여 두 손가락 이동을 한번 한 경우, 나올 수 있는 여러 결과들 중에서 네 가지 결과만 아래에 표시했다 (아래 예시에 없는 다른 결과들 또한 나올 수 있음에 유의하자).</p>

<ul>
	<li><code><strong>ox</strong>oxoxxxoo</code></li>
	<li><code>ox<strong>o</strong>oxxx<strong>x</strong>oo</code></li>
	<li><code>oxox<strong>o</strong>xxo<strong>x</strong>o</code></li>
	<li><code>oxox<strong>ox</strong>xxoo</code></li>
</ul>

<p><em>n</em> 개의 동전이 나열되어 있는 두 상태 <em>S</em>, <em>T</em>와 함께 두 손가락 이동을 위해 선택할 두 동전의 위치가 주어졌을 때, 한번의 두 손가락 이동을 통해 <em>S</em>에서 <em>T</em>로의 변환이 가능한지 결정하는 프로그램을 작성하시오.</p>

### 입력 

 <p>입력은 표준입력을 사용한다. 첫 번째 줄에 나열된 동전 개수를 나타낸 양의 정수 <em>n</em> (3 ≤ <em>n</em> ≤ 10,000)이 주어진다. 다음 두 줄에 <em>n</em> 개의 동전이 나열된 상태인 <em>S</em> 와 <em>T</em> 가 각각 주어지며, 이 때 <em>S</em>와 <em>T</em> 는 <code>o</code> 와 <code>x</code> 로 이루어진 길이가 <em>n</em> 인 문자열로 표현된다 (<code>o</code> 와 <code>x</code> 는 모두 소문자이다). 동전의 위치는 왼쪽에서 오른쪽으로 0부터 <em>n</em> − 1까지 차례대로 번호를 매겨 구분한다. 마지막 줄에는 두 손가락 이동을 위해 선택할 두 동전의 위치 <em>i</em>와 <em>j</em>가 주어지며, <em>i</em>는 <em>j</em> 보다 작다 (0 ≤ <em>i</em> < <em>j</em> ≤ <em>n</em> − 1).</p>

### 출력 

 <p>출력은 표준출력을 사용한다. 한번의 두 손가락 이동을 통해 <em>S</em> 에서 <em>T</em>로의 변환이 가능한 경우 <code>YES</code> 를, 그렇지 않은 경우 <code>NO</code> 을 출력한다.</p>

