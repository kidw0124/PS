# [Gold II] Ooorrraaannngggeee Game - 34165 

[문제 링크](https://www.acmicpc.net/problem/34165) 

### 성능 요약

메모리: 146752 KB, 시간: 192 ms

### 분류

다이나믹 프로그래밍, 역추적

### 제출 일자

2025년 9월 3일 05:29:33

### 문제 설명

<blockquote>
<p><strong>가영이가~~~ 좋아하는~~~ 랜덤~~~ 게임!!</strong></p>
</blockquote>

<p>코로나로 인해 3학년 만에 처음으로 MT를 간 20학번 가영이는 동기들과 함께 술게임을 즐기고 있다. 여러 술게임들 중 가영이가 제일 약한 게임은 바로 오렌지 게임이다! 오렌지 게임을 할 때마다 계속 걸린 가영이는 더 이상 술을 먹지 않기 위해 술게임의 신 건희에게 비법을 알려달라고 부탁했다. 하지만 비법을 쉽게 알려주기 싫었던 건희는 가영이에게 다음과 같은 게임을 제안했다.</p>

<ol>
	<li>건희가 알파벳으로 이루어진 문자열을 하나 제시한다.</li>
	<li>가영이는 건희가 제시한 문자열에서 순서를 유지한 채 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>개 이상의 글자를 지워 만들 수 있는 문자열들 중 가장 긴 오렌지 문자열을 찾아 그 길이를 말한다. 오렌지 문자열이란 <span style="color:#e74c3c;"><code>orange</code></span>의 순서는 유지한 채로 각 문자가 1개 이상 연속하여 존재하고, 그 사이에 다른 문자가 존재하지 않는 문자열을 말한다. 예를 들어, <span style="color:#e74c3c;"><code>ooorraannnngeeeee</code></span>는 오렌지 문자열이지만, <span style="color:#e74c3c;"><code>ooraang</code></span>나 <span style="color:#e74c3c;"><code>oorrooaanngge</code></span>는 오렌지 문자열이 아니다.</li>
	<li>가영이가 말한 답이 정답이면 가영이의 승리, 오답이면 건희의 승리로 게임은 끝이 난다.</li>
</ol>

<p>가영이가 게임에서 이겨 건희에게 오렌지 게임의 비법을 받을 수 있도록 가영이를 도와 가장 긴 오렌지 문자열의 길이를 찾아주자.</p>

### 입력 

 <p>첫 번째 줄에 건희가 제시한 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><msup><mn>10</mn><mn>6</mn></msup><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N(1\le N\le 10^6)$</span></mjx-container>의 알파벳 소문자로만 이루어진 문자열이 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 건희가 제시한 문자열에서 찾을 수 있는 가장 긴 오렌지 문자열의 길이를 출력한다. 만약 오렌지 문자열을 찾을 수 없다면 대신 <span style="color:#e74c3c;"><code>0</code></span>을 출력한다.</p>

<p>제시한 문자열에서 오렌지 문자열을 찾을 수 있다면, 두 번째 줄에 가능한 가장 긴 오렌지 문자열을 하나 출력한다. 정답이 여러 개면 아무거나 하나 출력한다.</p>

