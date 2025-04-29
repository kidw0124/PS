# [Gold V] Goofy Converter - 22689 

[문제 링크](https://www.acmicpc.net/problem/22689) 

### 성능 요약

메모리: 2764 KB, 시간: 4 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2025년 4월 30일 04:30:08

### 문제 설명

<p>Nathan O. Davis is a student at the department of integrated systems. He is now taking a class in in- tegrated curcuits. He is an idiot. One day, he got an assignment as follows: design a logic circuit that takes a sequence of positive integers as input, and that outputs a sequence of 1-bit integers from which the original input sequence can be restored uniquely.</p>

<p>Nathan has no idea. So he searched for hints on the Internet, and found several pages that describe the 1-bit DAC. This is a type of digital-analog converter which takes a sequence of positive integers as input, and outputs a sequence of 1-bit integers.</p>

<p>Seeing how 1-bit DAC works on these pages, Nathan came up with a new idea for the desired converter. His converter takes a sequence L of positive integers, and a positive integer <i>M</i> aside from the sequence, and outputs a sequence <i>K</i> of 1-bit integers such that:</p>

<p><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D457 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-munderover space="4"><mjx-over style="padding-bottom: 0.111em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D457 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-over><mjx-box><mjx-munder><mjx-row><mjx-base style="padding-left: 0.522em;"><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2211 TEX-S2"></mjx-c></mjx-mo></mjx-base></mjx-row><mjx-row><mjx-under style="padding-top: 0.167em; padding-left: 0.701em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D457 TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-under></mjx-row></mjx-munder></mjx-box></mjx-munderover><mjx-texatom space="2" texclass="ORD"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em; margin-left: -0.04em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub></mjx-texatom><mjx-mtext class="mjx-n"><mjx-c class="mjx-c2E"></mjx-c></mjx-mtext></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><msub><mi>L</mi><mi>j</mi></msub><mo>=</mo><munderover><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mi>i</mi><mo>=</mo><mi>j</mi></mrow><mrow data-mjx-texclass="ORD"><mi>j</mi><mo>+</mo><mi>M</mi><mo>−</mo><mn>1</mn></mrow></munderover><mrow data-mjx-texclass="ORD"><msub><mi>K</mi><mi>i</mi></msub></mrow><mtext>.</mtext></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$$L_j = \sum_{i=j}^{j+M-1}{K_i}\text{.}$$</span> </mjx-container></p>

<p>He is not so smart, however. It is clear that his converter does not work for some sequences. Your task is to write a program in order to show the new converter cannot satisfy the requirements of his assignment, even though it would make Nathan in despair.</p>

### 입력 

 <p>The input consists of a series of data sets. Each data set is given in the following format:</p>

<pre><i>N M</i>
<i>L</i><sub>0</sub> <i>L</i><sub>1</sub> . . . <i>L</i><sub><i>N</i>-1</sub>
</pre>

<p><i>N</i> is the length of the sequence <i>L</i>. <i>M</i> and <i>L</i> are the input to Nathan’s converter as described above. You may assume the followings: 1 ≤ <i>N</i> ≤ 1000, 1 ≤ <i>M</i> ≤ 12, and 0 ≤ <i>L<sub>j</sub></i> ≤ <i>M</i> for <i>j</i> = 0, . . . , <i>N</i> - 1.</p>

<p>The input is terminated by <i>N</i> = <i>M</i> = 0.</p>

### 출력 

 <p>For each data set, output a binary sequence <i>K</i> of the length (<i>N</i> + <i>M</i> - 1) if there exists a sequence which holds the equation mentioned above, or “Goofy” (without quotes) otherwise. If more than one sequence is possible, output any one of them.</p>

