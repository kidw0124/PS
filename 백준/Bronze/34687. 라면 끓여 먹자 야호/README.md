# [Bronze III] 라면 끓여 먹자 야호 - 34687 

[문제 링크](https://www.acmicpc.net/problem/34687) 

### 성능 요약

메모리: 2084 KB, 시간: 0 ms

### 분류

수학, 구현, 사칙연산

### 제출 일자

2025년 11월 23일 21:48:16

### 문제 설명

<p>대전과학고등학교의 기숙사에 사는 코이는 야식을 너무 먹고 싶어서 컵라면을 끓이기로 결심했다. 하지만 코이의 전기 포트는 너무 작아서 컵라면에 적힌 권장 물양을 모두 채울 수가 없는 경우가 많았다.</p>

<p>수많은 실험 끝에 코이는 한 가지 중요한 사실을 알아냈다. 컵라면을 성공적으로 끓이기 위해서는 전기 포트에 담긴 물의 양이 권장 물양의 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c38"></mjx-c><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mi class="mjx-n"><mjx-c class="mjx-c25"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>81</mn><mi mathvariant="normal">%</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$81\%$</span></mjx-container> 이상이기만 해도 한다는 것이다. 만약 물의 양이 이 기준에 미치지 못하면 물이 제대로 끓지 않아 컵라면을 버려야 한다.</p>

<p>컵라면의 권장 물양과 코이가 전기 포트에 넣은 물의 양이 주어졌을 때, 코이가 컵라면을 성공적으로 끓여 먹을 수 있는지 판별해 보자.</p>

### 입력 

 <p>첫째 줄에 컵라면의 권장 물양을 나타내는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 코이가 포트에 실제로 넣은 물의 양을 나타내는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>이 공백으로 구분되어 주어진다. 모든 물의 양은 mL(밀리리터) 단위로 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>,</mo><mi>M</mi><mo>≤</mo><mn>1</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(1 \le N, M \le 1\,000)$</span> </mjx-container></p>

### 출력 

 <p>코이가 라면을 성공적으로 끓여 먹을 수 있다면 <span style="color:#e74c3c;"><code>yaho</code></span>를, 그렇지 않다면 <span style="color:#e74c3c;"><code>no</code></span>를 출력한다.</p>

