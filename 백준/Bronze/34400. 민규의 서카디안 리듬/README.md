# [Bronze IV] 민규의 서카디안 리듬 - 34400 

[문제 링크](https://www.acmicpc.net/problem/34400) 

### 성능 요약

메모리: 2084 KB, 시간: 0 ms

### 분류

수학, 사칙연산

### 제출 일자

2025년 9월 22일 05:01:27

### 문제 설명

<p>서카디안 리듬은 낮과 밤의 변화에 따라 24시간 주기로 반복되는 인간의 몸에서 일어나는 변화를 의미한다. 민규는 서카디안 리듬을 유지하며 규칙적인 삶을 산다. 따라서, 하루 24시간 중 16시간 동안 연속해서 깨어있고, 8시간 동안 연속해서 잠을 잔다. 어느 날, 윤수는 민규에게 사실 인간의 생체 리듬은 25시간이라는 정보를 알려주었다. 따라서, 민규는 생체리듬에 맞는 삶을 살기 위해 17시간 동안 연속해서 깨어있고, 8시간 동안 연속해서 잠을 자는 생활 패턴을 반복한다. 민규가 잠을 자기 시작하는 시각은 낮과 밤의 변화와 관계없이 본인의 리듬에 맞게 진행된다.</p>

<p>평범한 삶을 사는 윤수는 민규에게 연락하기 위해 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>t</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$t$</span></mjx-container>시간 30분 후에 민규가 깨어있을지 자고 있을지 판단하는 프로그램을 만들어보자. 현시간 0시에 민규는 수면을 끝내고 깨어 있는 상태를 시작한다.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>가 주어진다.</p>

<p>두 번째 줄부터 다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>개의 줄에 걸쳐 각 테스트 케이스 마다 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>t</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$t$</span></mjx-container>가 주어진다.</p>

### 출력 

 <p>각 테스트 케이스마다 민규가 깨어있으면 <span style="color:#e74c3c;"><code>ONLINE</code></span>, 자고 있으면 <span style="color:#e74c3c;"><code>OFFLINE</code></span>을 출력한다.</p>

