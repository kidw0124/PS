# [Platinum III] 등수 - 31095 

[문제 링크](https://www.acmicpc.net/problem/31095) 

### 성능 요약

메모리: 589224 KB, 시간: 1192 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 제출 일자

2024년 9월 20일 07:15:54

### 문제 설명

<blockquote>
<p>소프트웨어에 진심인 LG전자는 개발자들이 문제 해결 능력을 겨루고 지적 즐거움을 누릴 수 있도록 2012년부터 매년 LG Code Jam을 개최하고 있다.</p>

<p>LG Code Jam에서 우수한 성적을 거둔 개발자는 코딩 전문가로 선발되어 비즈니스 문제 해결 및 개발자 교육과 같은 다양한 분야에 기여하고 있다.</p>

<p>특히, 신입 개발자라도 뛰어난 실력을 갖추면 전문가 타이틀을 획득할 수 있다.</p>

<p>이와 함께 LG전자는 2024년 LG 대학생 프로그래밍 경진대회를 개최하여 실력 있는 학생들에게도 지적 즐거움을 제공할 예정이다.</p>
</blockquote>

<p>운 좋은 금성이는 2024년 LG 대학생 프로그래밍 경진대회에 참가하여 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>등을 기록하는 꿈을 꾸고 있다. 이번 LG 대학생 프로그래밍 경진대회에는 총 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>명이 참가할 것이다.</p>

<p>금성이는 자신이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>등을 기록했을 때 나올 수 있는 서로 다른 대회 결과의 경우의 수를 구하고 싶다. 두 대회의 결과가 서로 다르다는 것은 두 대회에서의 등수가 다른 참가자가 1명 이상 존재한다는 뜻이다.</p>

<p>단, 동점을 기록한 사람들은 같은 등수가 된다. 예를 들어, 공동 2등이 3명일 수 있고, 이 경우 다음 등수는 5등이 된다.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>가 주어진다.</p>

<p>다음 줄부터 각 테스트 케이스마다 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>의 값이 한 줄에 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>각 테스트 케이스에 대해 문제의 정답을 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>9</mn></msup><mo>+</mo><mn>7</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^9+7$</span></mjx-container>로 나눈 나머지를 한 줄에 출력한다.</p>

