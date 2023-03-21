# [Platinum I] Numbers - 12925 

[문제 링크](https://www.acmicpc.net/problem/12925) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

수학, 분할 정복을 이용한 거듭제곱

### 문제 설명

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-msqrt space="3"><mjx-sqrt><mjx-surd><mjx-mo class="mjx-n"><mjx-c class="mjx-c221A"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.163em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-box></mjx-sqrt></mjx-msqrt><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.363em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>3</mn><mo>+</mo><msqrt><mn>5</mn></msqrt><msup><mo stretchy="false">)</mo><mi>n</mi></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\( (3+\sqrt5)^n \)</span></mjx-container>의 정수부의 마지막 3자리를 구하시오.</p>

<p>예를 들어, n = 5인 경우, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-msqrt space="3"><mjx-sqrt><mjx-surd><mjx-mo class="mjx-n"><mjx-c class="mjx-c221A"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.163em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-box></mjx-sqrt></mjx-msqrt><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.363em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c39"></mjx-c><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c2E"></mjx-c><mjx-c class="mjx-c37"></mjx-c><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c39"></mjx-c><mjx-c class="mjx-c38"></mjx-c><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2E"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2E"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2E"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>3</mn><mo>+</mo><msqrt><mn>5</mn></msqrt><msup><mo stretchy="false">)</mo><mn>5</mn></msup><mo>=</mo><mn>3935.73982</mn><mo>.</mo><mo>.</mo><mo>.</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\( (3+\sqrt5)^5 = 3935.73982... \)</span></mjx-container> 이므로, 답은 935이다.</p>

<p>만약 자릿수가 3자리 이하이라면 leading zero를 붙여 출력한다.</p>

<p>예를 들어, n = 2인 경우, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-msqrt space="3"><mjx-sqrt><mjx-surd><mjx-mo class="mjx-n"><mjx-c class="mjx-c221A"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.163em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-box></mjx-sqrt></mjx-msqrt><mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-script style="vertical-align: 0.363em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c37"></mjx-c><mjx-c class="mjx-c2E"></mjx-c><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c36"></mjx-c><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c37"></mjx-c><mjx-c class="mjx-c39"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2E"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2E"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2E"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>3</mn><mo>+</mo><msqrt><mn>5</mn></msqrt><msup><mo stretchy="false">)</mo><mn>2</mn></msup><mo>=</mo><mn>27.4164079</mn><mo>.</mo><mo>.</mo><mo>.</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\( (3+\sqrt5)^2 = 27.4164079... \)</span></mjx-container> 이므로, 답은 027이다.</p>

### 입력 

 <p>첫 번째 줄에는 Test Case의 개수 T (1 ≤ T ≤ 100)이 입력으로 주어진다.</p>

<p>각 Test Case에는 자연수 n이 하나 주어진다. (2 ≤ n ≤ 2×10<sup>9</sup>)</p>

### 출력 

 <p>각 Test case에 대해, “Case #c: x”의 형식으로 각 줄에 정답을 출력한다. c는 Test Case의 번호이다. (1부터 매겨진다.) x는 해당 Test Case의 정답이다.</p>

