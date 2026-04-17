# [Bronze IV] 2033년 밈 투표 - 29731 

[문제 링크](https://www.acmicpc.net/problem/29731) 

### 성능 요약

메모리: 2040 KB, 시간: 0 ms

### 분류

구현, 문자열, 집합과 맵

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>2033년, 하루나라에서 밈 1위를 결정하고자 하는 투표가 예정되어 있어 1위를 다투고 있는 후보들은 자신들의 독특한 공약을 내세우고 있다. 여론조사에 따르면, 'Rick Astley'는 유권자에게 다음과 같은 공약을 내세워 현재 1위라고 한다. </p>

<ul>
	<li><span style="color:#e74c3c;"><code>Never gonna give you up</code></span></li>
	<li><span style="color:#e74c3c;"><code>Never gonna let you down</code></span></li>
	<li><span style="color:#e74c3c;"><code>Never gonna run around and desert you</code></span></li>
	<li><span style="color:#e74c3c;"><code>Never gonna make you cry</code></span></li>
	<li><span style="color:#e74c3c;"><code>Never gonna say goodbye</code></span></li>
	<li><span style="color:#e74c3c;"><code>Never gonna tell a lie and hurt you</code></span></li>
	<li><span style="color:#e74c3c;"><code>Never gonna stop</code></span></li>
</ul>

<p>하지만 해킹 기술이 너무 발달한 나머지, Rick Astley의 공약을 싫어하는 해커가 그의 공약을 몰래 바꾸고 있다. haru_101은 해커가 Rick Astley의 공약을 바꿨는지 알고 싶다. 주어진 문장 중 하나라도 기존 공약에 속하지 않으면 공약이 바뀐 것으로 본다. 단, 대소문자를 구분한다. 여러분이 haru_101을 도와주자.</p>

### 입력 

 <p>첫 번째 줄에 정수 $N$이 주어진다. $(1 \leq N \leq 100)$</p>

<p>두 번째 줄부터 $N+1$ 번째 줄까지 영문 대소문자 및 공백으로 이루어진 공약 $S_i$ 가 주어진다. 이때, $S_i$는 공백으로 시작하거나 공백으로 끝나지 않는다. $(1 \leq |S_i| \leq 50)$</p>

### 출력 

 <p>모든 문장이 Rick Astley가 만든 공약에 속한다면 <span style="color:#e74c3c;"><code>No</code></span>를, 하나라도 속하지 않는다면 <span style="color:#e74c3c;"><code>Yes</code></span>를 출력한다.</p>

