# [Platinum III] yo, i herd u liek ternary operators, so.. - 25321 

[문제 링크](https://www.acmicpc.net/problem/25321) 

### 성능 요약

메모리: 5532 KB, 시간: 116 ms

### 분류

조합론(combinatorics), 자료 구조(data_structures), 수학(math), 스택(stack)

### 문제 설명

<p style="margin-bottom: 15px;"><img alt="" src="https://upload.acmicpc.net/a2068ae8-c874-48c3-a2eb-4e104b3c38d5/-/preview/" style="display: block; margin-left: auto; margin-right: auto; width: 100%; max-width: 400px;"></p>

<p>진수는 삼항 연산자를 아주 좋아한다. 삼항 연산자는</p>

<p style="text-align:center;"><code>(condition) ? (value_if_true) : (value_if_false)</code></p>

<p>와 같이 생긴 연산자로, <code>condition</code>이 참일 경우 <code>value_if_true</code>로 평가되고 아닐 경우 <code>value_if_false</code>로 평가된다.</p>

<p>진수가 삼항 연산자에서 재미있다고 느끼는 점은 삼항 연산자 안에 또 삼항 연산자를 쓸 수 있다는 것이다. 다시 말해 <code>condition</code>과 <code>value</code>에도 삼항 연산자가 들어갈 수 있다.</p>

<p>진수는 삼항 연산자를 너무 좋아한 나머지, 연산자가 삼항 연산자밖에 없는 프로그래밍 언어를 개발하기로 했다. 진수가 개발하는 언어의 특징은, 만약 주어진 식이 여러 가지로 해석될 수 있다면 실행할 때마다 다른 해석을 사용해서 다른 결과를 낼 수도 있다는 것이다. 예를 들어 <code>a?b:c?d:e</code> 는</p>

<p style="text-align:center;"><code>((a)?(b):(c)) ? (d) : (e)</code>   또는   <code>(a) ? (b) : ((c)?(d):(e))</code></p>

<p>로 해석될 수 있다.</p>

<p>진수는 문득 본인이 작성한 식이 몇 가지 방법으로 해석될 수 있는지 궁금해졌다. 구체적으로 정의하자면,</p>

<p style="text-align:center;"><code><expr> ::= (<expr>)?(<expr>):(<expr>) | <variable></code><br>
<code><variable> ::= a | b | c | ... | z</code></p>

<p>위의 BNF(Backus–Naur form)에서 <code><expr></code>로 나타낼 수 있는 문자열 중에서 괄호를 제거하고 비교하였을 때 진수가 작성한 식과 같은 문자열이 되는 경우의 수가 궁금한 것이다.</p>

<p>괄호가 없는 삼항 연산자로만 구성된 식이 주어지면 가능한 해석의 수를 출력하는 프로그램을 작성하자. 해석될 수 있는 방법의 수가 너무 클 수 있으므로, 이 수를 소수인 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>007</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\, 000\, 000\, 007$</span></mjx-container><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c37"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mo>=</mo><msup><mn>10</mn><mn>9</mn></msup><mo>+</mo><mn>7</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(=10^9+7)$</span></mjx-container>로 나눈 나머지를 계산한다.</p>

### 입력 

 <p>첫 번째 줄에 알파벳 소문자와 <span style="color:#e74c3c;"><code>?</code></span>와 <span style="color:#e74c3c;"><code>:</code></span>만으로 이루어진 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mrow space="4"><mjx-mo class="mjx-n"><mjx-c class="mjx-c7C"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c7C"></mjx-c></mjx-mo></mjx-mrow><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>5</mn><mo>≤</mo><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">|</mo><mi>S</mi><mo data-mjx-texclass="CLOSE">|</mo></mrow><mo>≤</mo><mn>300</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(5\leq\left\vert S \right\vert\leq 300\, 000)$</span> </mjx-container></p>

<p>주어진 문자열은 적어도 하나 이상의 유효한 식으로 해석될 수 있다.</p>

### 출력 

 <p>문제에서 요구하는 수를 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>007</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\, 000\, 000\, 007$</span></mjx-container>로 나눈 나머지를 출력한다.</p>

