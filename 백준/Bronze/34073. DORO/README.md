# [Bronze IV] DORO - 34073 

[문제 링크](https://www.acmicpc.net/problem/34073) 

### 성능 요약

메모리: 2088 KB, 시간: 0 ms

### 분류

문자열

### 제출 일자

2025년 7월 29일 02:48:44

### 문제 설명

<blockquote>
<p><strong><em>DORODORO WAN!</em></strong></p>

<p>    — voice 군단, <i>DORODORA ODORO</i></p>
</blockquote>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/1dc32459-005b-482b-a883-0b2180a0017b/-/preview/" style="width: 387px; height: 400px; max-width: 100%"></p>

<p>사람 말을 하는 귀엽고 깜찍한 생물 도로롱에 대해서 아는가? 이 생물은 사람의 말을 따라 하는 기묘한 능력을 갖추고 있지만, 안타깝게도 각 단어의 끝에 DORO를 붙이지 않고서는 말을 하지 못한다! 예를 들어, 도로롱이 <strong>i love you</strong>라는 말을 하고자 한다면, 실제로는 <strong>iDORO loveDORO youDORO</strong>라고 말을 한다.</p>

<p>도로롱이 전하고자 하는 말이 주어진다. 이 말은 알파벳 소문자와 공백으로만 구성되어 있다. 이 말을 토대로 실제로 도로롱이 하는 말이 무엇일지 예측해 보자!</p>

### 입력 

 <p>첫 번째 줄에 단어의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \leq N \leq 100$</span></mjx-container>)</p>

<p>두 번째 줄에 도로롱이 전하고자 하는 말이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 단어의 형태로 주어진다. 각 단어들은 공백 한 칸으로 구분되며, 알파벳 소문자로 구성된다. 도로롱이 전하고자 하는 말은 공백으로 시작하거나 끝나지 않으며, 모든 단어의 길이와 공백의 개수를 합치면 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>100</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$100$</span></mjx-container> 이하이다.</p>

### 출력 

 <p>도로롱이 실제로 하는 말을 출력한다.</p>

