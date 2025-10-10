# [Diamond IV] 이항 계수 6 - 14854 

[문제 링크](https://www.acmicpc.net/problem/14854) 

### 성능 요약

메모리: 2228 KB, 시간: 604 ms

### 분류

수학, 정수론, 조합론, 중국인의 나머지 정리, 뤼카 정리

### 제출 일자

2025년 10월 11일 02:49:32

### 문제 설명

<p>자연수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(N\)</span></mjx-container>과 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(K\)</span></mjx-container>가 주어졌을 때 이항 계수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-texatom texclass="OPEN"><mjx-mo class="mjx-sop"><mjx-c class="mjx-c28 TEX-S1"></mjx-c></mjx-mo></mjx-texatom><mjx-mfrac><mjx-frac atop="true" delims="true" style="vertical-align: -0.345em;"><mjx-num style="padding-bottom: 0.306em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-num><mjx-den><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-den></mjx-frac></mjx-mfrac><mjx-texatom texclass="CLOSE"><mjx-mo class="mjx-sop"><mjx-c class="mjx-c29 TEX-S1"></mjx-c></mjx-mo></mjx-texatom></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="ORD"><mrow data-mjx-texclass="OPEN"><mo minsize="1.2em" maxsize="1.2em">(</mo></mrow><mfrac linethickness="0"><mi>N</mi><mi>K</mi></mfrac><mrow data-mjx-texclass="CLOSE"><mo minsize="1.2em" maxsize="1.2em">)</mo></mrow></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\binom{N}{K}\)</span></mjx-container>를 142857으로 나눈 나머지를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수 T (1 ≤ T ≤ 10<sup>5</sup>)가 주어진다.</p>

<p>각 테스트 케이스는 한 줄로 이루어져 있으며, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(N\)</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(K\)</span></mjx-container>가 주어진다. (1 ≤ <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(N\)</span></mjx-container> ≤ 10<sup>9</sup>, 0 ≤ <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(K\)</span></mjx-container> ≤ <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(N\)</span></mjx-container>)</p>

### 출력 

 <p>각 테스트 케이스 마다 한 줄에 하나씩 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-texatom texclass="OPEN"><mjx-mo class="mjx-sop"><mjx-c class="mjx-c28 TEX-S1"></mjx-c></mjx-mo></mjx-texatom><mjx-mfrac><mjx-frac atop="true" delims="true" style="vertical-align: -0.345em;"><mjx-num style="padding-bottom: 0.306em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-num><mjx-den><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-den></mjx-frac></mjx-mfrac><mjx-texatom texclass="CLOSE"><mjx-mo class="mjx-sop"><mjx-c class="mjx-c29 TEX-S1"></mjx-c></mjx-mo></mjx-texatom></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="ORD"><mrow data-mjx-texclass="OPEN"><mo minsize="1.2em" maxsize="1.2em">(</mo></mrow><mfrac linethickness="0"><mi>N</mi><mi>K</mi></mfrac><mrow data-mjx-texclass="CLOSE"><mo minsize="1.2em" maxsize="1.2em">)</mo></mrow></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\binom{N}{K}\)</span></mjx-container>를 142857으로 나눈 나머지를 출력한다.</p>

