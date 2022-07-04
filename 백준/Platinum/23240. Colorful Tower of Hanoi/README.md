# [Platinum II] Colorful Tower of Hanoi - 23240 

[문제 링크](https://www.acmicpc.net/problem/23240) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

많은 조건 분기(case_work), 다이나믹 프로그래밍(dp), 수학(math)

### 문제 설명

<p>이 문제는 잘 알려진 하노이 탑 문제의 변형이다.</p>

<p>하노이 탑 문제는 다음과 같다. 세 개의 막대기, 즉 막대기-1, 막대기-2, 막대기-3 이 있고, 막대기1 에 크기가 다른 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> 개의 디스크가 내림차순으로 쌓여 있다. 즉, 가장 작은 디스크가 가장 위에, 가장 큰 디스크가 가장 아래에 놓여 있다. 문제의 목표는 막대기-1 에 쌓여 있는 모든 디스크를 막대기-3 으로 옮기는 것이다. 단, 옮기는 과정에서, 한 번에 하나의 디스크만 옮길 수 있으며, 어떤 경우에도 큰 디스크가 작은 디스크 위에 놓여서는 안 된다.</p>

<p>원래의 하노이 탑 문제가 아래와 같이 변형된다.</p>

<ol>
	<li>동일한 크기의 디스크가 허용된다. 따라서 디스크를 이동하는 과정에서 어떤 디스크는 크기가 동일하거나 또는 더 큰 디스크 위에 놓을 수 있다.</li>
	<li>각 디스크는 빨간색(<code>R</code>), 녹색(<code>G</code>) 또는 파란색(<code>B</code>)의 세 가지 색상 중 하나로 칠해져 있다. 하지만, 동일한 크기의 디스크는 동일한 색상을 가진다.</li>
	<li>동일한 크기의 디스크가 둘 이상일 경우, 디스크를 옮긴 후 이들 간의 상대적 순서가 유지될 수도 있고, 반대로 될 수 있는데, 이를 디스크 색이 결정한다. 즉, 디스크 색이 빨간색이면 모든 디스크를 최종적으로 이동한 후 동일한 크기의 디스크의 상대적인 순서가 반대로 되어야 한다. 디스크의 색이 파란색이면 모든 디스크의 이동이 완료된 후의 상대적인 순서가 처음의 순서와 동일해야 한다. 그리고 색이 녹색이면 이동 후의 상대적인 순서가 중요하지 않다. 다만, 디스크를 이동시키는 중간 과정에서는 상대적인 순서에 대한 조건을 만족할 필요는 없다.</li>
	<li>디스크 이동의 총 횟수를 최소화해야 한다.</li>
</ol>

<p>그림 C.1 은 디스크를 모두 옮긴 후, 크기가 같은 디스크의 색상에 따른 상대적 순서의 조건을 만족시키는 예를 보여준다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 400px; height: 197px;"></p>

<p style="text-align: center;">그림 C.1</p>

### 입력 

 <p>입력은 표준입력을 사용한다. 첫 번째 줄에는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>m</mi><mo>≤</mo><mn>25</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le m \le 25$</span></mjx-container>)이 주어진다. 여기서, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m$</span></mjx-container>은 가장 큰 디스크의 지름을 나타낸다. 이어지는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m$</span></mjx-container> 줄에서, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$i$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>i</mi><mo>≤</mo><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le i \le m$</span></mjx-container>) 번째 줄에는 하나의 영어 대문자와 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>𝑘</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$𝑘$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2265"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>≥</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\ge 1$</span></mjx-container>)가 주어지는데, 이는 지름의 크기가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>i</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$i$</span></mjx-container> 인 디스크에 관한 정보를 나타낸다. 즉, 영어 대문자는 디스크의 색을, 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D458 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>k</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$k$</span></mjx-container>는 동일한 크기의 디스크 개수를 나타낸다. 문자 ‘<code>R</code>’은 빨간색, ‘<code>G</code>’는 녹색, ‘<code>B</code>’는 파란색을 각각 의미한다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m$</span></mjx-container>까지의 디스크 지름 각각에 대해서, 그 지름을 가진 디스크가 적어도 하나 이상 존재한다.</p>

<p>참고로, 쌓여 있는 디스크의 총 개수는 50 을 넘지 않는다.</p>

### 출력 

 <p>출력은 표준출력을 사용한다. 결과를 한 줄에 출력하되, 디스크의 색에 따른 상대적인 순서의 조건을 만족시키면서 막대기-1 에 쌓여 있는 모든 디스크를 막대기-3 으로 이동하기 위한 최소 이동 횟수를 출력한다.</p>

