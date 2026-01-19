# [Gold V] KCPC 스티커 만들기 - 35162 

[문제 링크](https://www.acmicpc.net/problem/35162) 

### 성능 요약

메모리: 2084 KB, 시간: 4 ms

### 분류

애드 혹, 기하학, 해 구성하기, 많은 조건 분기

### 제출 일자

2026년 1월 20일 05:35:49

### 문제 설명

<p>동우는 이번 KCPC를 맞이하여 <strong>KCPC 스티커</strong>를 만들고자 한다.</p>

<p><strong>KCPC 스티커</strong>를 만들기 위해 동우는 아래 사진처럼 생긴 <code>K</code>, <code>C</code>, <code>P</code> 글자 스티커가 필요하다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ff322731-ec66-4c3e-a50f-7f96059df3b4/-/preview/" style="width: 300px; max-width: 100%;"></p>

<p>그동안 동우는 ◯CPC에 상당히 많이 참여했기 때문에 <code>C</code>, <code>P</code> 글자 스티커는 많지만, 동우가 참여하거나 운영한 KCPC는 2022년부터 2024년 총 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3$</span></mjx-container>번 뿐이므로 <code>K</code> 글자 스티커는 몇 개 없다.</p>

<p>동우는 본인이 가진 스티커를 모두 평면에 잘 배치하여 <strong>KCPC 스티커</strong>를 만들고자 한다. <strong>KCPC 스티커</strong>의 각 문자는 서로 겹치면 안 되며, 스티커 내에서 문자를 이루는 모든 선분의 끝점은 다른 선분과 닿아 있어야 한다. 즉, 구체적으로 다음 조건을 만족해야 한다.</p>

<ul>
<li>서로 다른 선분은 교차해서는 안 된다. 단, 끝점이 닿아 있는 경우 교차하지 않은 것으로 생각한다.</li>
<li>두 개의 문자가 한 선분을 공유해서는 안 된다.</li>
<li>아래 사진의 파란 점은 다른 스티커의 선분에 닿아 있어야 한다.
	<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ddf64ed3-2a9a-4fad-a6ef-17a1411e47e1/-/preview/" style="width: 300px; max-width: 100%;"></p>
</li>
<li>문자를 회전이나 뒤집는 행위는 자유롭게 허용된다.</li>
</ul>

<p>아래 그림은 가능한 예시들이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/798875db-47de-4fe8-bc9f-ddeee6b21c03/-/preview/" style="width: 300px; max-width: 100%;"></p>

<p>아래 그림은 불가능한 예시들이다. 첫 번째의 경우 두 개의 문자가 한 선분을 공유하고, 두 번째의 경우 다른 선분과 닿지 않은 끝점이 있으며, 세 번째의 경우 선분이 교차한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/244ef04c-c4a2-4959-abc0-6ed7a3902f82/-/preview/" style="width: 300px; max-width: 100%;"></p>

<p>동우가 가진 <code>K</code>, <code>C</code>, <code>P</code> 글자 스티커의 개수가 주어질 때, 조건을 만족하는 <strong>KCPC 스티커</strong>를 만들 수 있는지 판단해 보자.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c38"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>T</mi><mo>≤</mo><mn>40</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>803</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T(1\le T\le 40\, 803)$</span></mjx-container>가 주어진다.</p>

<p>두 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>줄에 걸쳐 각 테스트 케이스 별로 한 줄에 동우가 가진 <code>K</code>, <code>C</code>, <code>P</code> 글자 스티커의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi><mo>,</mo><mi>C</mi><mo>,</mo><mi>P</mi><mo stretchy="false">(</mo><mn>0</mn><mo>≤</mo><mi>K</mi><mo>≤</mo><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K,C,P(0\le K\le 3$</span></mjx-container>; <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn><mo>≤</mo><mi>C</mi><mo>,</mo><mi>P</mi><mo>≤</mo><mn>100</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0\le C,P\le 100$</span></mjx-container>; <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>K</mi><mo>+</mo><mi>C</mi><mo>+</mo><mi>P</mi><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\le K+C+P)$</span></mjx-container>가 공백으로 구분되어 주어진다.</p>

<p>같은 테스트 케이스가 여러 번 주어지지는 않는다.</p>

### 출력 

 <p>첫 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>줄에 걸쳐 각 테스트 케이스 별로 가능하면 <span style="color:#e74c3c;"><code>Y</code></span>, 불가능하면 <span style="color:#e74c3c;"><code>N</code></span>을 출력한다.</p>

