# [Platinum I] 순열 - 13180 

[문제 링크](https://www.acmicpc.net/problem/13180) 

### 성능 요약

메모리: 17720 KB, 시간: 28 ms

### 분류

조합론, 수학

### 제출 일자

2025년 6월 3일 02:11:41

### 문제 설명

<p>길이가 N 인 순열이란, 1 이상 N 이하의 자연수 N 개로 이루어진, 같은 수가 두 번 이상 등장하지 않는 수열을 의미한다. 길이가 N 인 순열의 종류는 총 N!개가 있다.</p>

<p>이 순열에서 K-minsum이라는 것을 정의할 것이다. 순열 A 가 있고, 각 원소를 순서대로 나열하면 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>일 때, 순열 A 의 K-minsum은</p>

<p><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-mtext class="mjx-n"><mjx-c class="mjx-c4B"></mjx-c><mjx-c class="mjx-c2D"></mjx-c><mjx-c class="mjx-c6D"></mjx-c><mjx-c class="mjx-c69"></mjx-c><mjx-c class="mjx-c6E"></mjx-c><mjx-c class="mjx-c73"></mjx-c><mjx-c class="mjx-c75"></mjx-c><mjx-c class="mjx-c6D"></mjx-c></mjx-mtext><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-munderover space="4"><mjx-over style="padding-bottom: 0.2em; padding-left: 0.408em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-over><mjx-box><mjx-munder><mjx-row><mjx-base><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2211 TEX-S2"></mjx-c></mjx-mo></mjx-base></mjx-row><mjx-row><mjx-under style="padding-top: 0.167em; padding-left: 0.148em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-under></mjx-row></mjx-munder></mjx-box></mjx-munderover><mjx-texatom space="2" texclass="ORD"><mjx-munderover><mjx-over style="padding-bottom: 0.2em; padding-left: 0.818em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-over><mjx-box><mjx-munder><mjx-row><mjx-base style="padding-left: 0.41em;"><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2211 TEX-S2"></mjx-c></mjx-mo></mjx-base></mjx-row><mjx-row><mjx-under style="padding-top: 0.167em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D457 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-under></mjx-row></mjx-munder></mjx-box></mjx-munderover><mjx-texatom space="2" texclass="ORD"><mjx-mtext class="mjx-n"><mjx-c class="mjx-c6D"></mjx-c><mjx-c class="mjx-c69"></mjx-c><mjx-c class="mjx-c6E"></mjx-c></mjx-mtext><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-msub space="2"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c22EF"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-msub space="2"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D457 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-msub space="2"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D457 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-texatom></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mtext>K-minsum</mtext><mo stretchy="false">(</mo><mi>A</mi><mo stretchy="false">)</mo><mo>=</mo><munderover><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mi>i</mi><mo>=</mo><mn>1</mn></mrow><mrow data-mjx-texclass="ORD"><mi>N</mi></mrow></munderover><mrow data-mjx-texclass="ORD"><munderover><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mi>j</mi><mo>=</mo><mi>i</mi><mo>+</mo><mi>K</mi></mrow><mrow data-mjx-texclass="ORD"><mi>N</mi></mrow></munderover><mrow data-mjx-texclass="ORD"><mtext>min</mtext><mo stretchy="false">(</mo><msub><mi>A</mi><mi>i</mi></msub><mo>,</mo><msub><mi>A</mi><mrow data-mjx-texclass="ORD"><mi>i</mi><mo>+</mo><mn>1</mn></mrow></msub><mo>,</mo><mo>⋯</mo><mo>,</mo><msub><mi>A</mi><mrow data-mjx-texclass="ORD"><mi>j</mi><mo>−</mo><mn>1</mn></mrow></msub><mo>,</mo><msub><mi>A</mi><mi>j</mi></msub><mo stretchy="false">)</mo></mrow></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[\text{K-minsum}(A) = \sum_{i=1}^{N}{\sum_{j=i+K}^{N}{\text{min}(A_i, A_{i+1}, \cdots, A_{j-1}, A_j)}}\]</span> </mjx-container></p>

<p>이다. min은 인자로 나열된 수 중의 최솟값을 구하는 함수이다. K 가 주어질 때, 길이가 N인 모든 N!개의 순열에 대해 K-minsum을 구해 그 합을 출력하는 프로그램을 작성하라.</p>

### 입력 

 <p>첫 번째 줄에는 순열의 길이를 나타내는 자연수 N 과 정수 K(0 ≤ K ≤ N)가 주어진다. (1 ≤ N ≤ 10<sup>6</sup>)</p>

### 출력 

 <p>길이가 N 인 모든 N!개의 순열에 대해 K-minsum을 구해 그 합을 출력한다. 합이 매우 커질 수 있으므로 1,000,000,007로 나눈 나머지를 출력해야 한다.</p>

