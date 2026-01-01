# [Bronze III] 생수병 놓기 - 34980 

[문제 링크](https://www.acmicpc.net/problem/34980) 

### 성능 요약

메모리: 2088 KB, 시간: 0 ms

### 분류

구현, 문자열, 많은 조건 분기

### 제출 일자

2026년 1월 1일 17:55:41

### 문제 설명

<p>민호는 학교에서 텀블러 대신 생수병을 가져오는 것으로 유명하다. 민호는 책상 위에 일렬로 붙어 있는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 자리에만 생수병을 놓고, 절대 한 자리에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2$</span></mjx-container>개 이상의 생수병을 배치하지 않는 습관이 있다. 오늘도 민호는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 자리 중 일부에 생수병을 배치해 두고 수업을 들으러 갔다.</p>

<p>수업이 모두 끝난 뒤 교실로 돌아온 민호는 자신의 생수병 배치가 이상하다는 느낌을 받았다. 민호는 아침에 어떻게 생수병을 배치했는지는 정확히 기억하고 있었지만, 혹시 생수병이 사라졌거나 바뀌었을지도 모른다는 불안감에 상황을 정확히 파악하지 못했다.</p>

<p>민호의 생수병 배치는 다음 네 가지 경우 중 하나로 분류된다.</p>

<ul>
<li>생수병의 개수가 감소한 경우: <code><span style="color:#e74c3c;">Oryang</span></code></li>
<li>생수병의 개수가 같지만 배치가 달라진 경우: <code><span style="color:#e74c3c;">Its fine</span></code></li>
<li>생수병의 개수가 증가한 경우: <code><span style="color:#e74c3c;">Manners maketh man</span></code></li>
<li>생수병의 개수와 배치가 모두 동일한 경우: <code><span style="color:#e74c3c;">Good</span></code></li>
</ul>

<p>혼란스러운 민호를 위해, 생수병에 어떤 일이 일어났는지를 판별하는 프로그램을 작성하자!</p>

### 입력 

 <p>첫번째 줄에 자리의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>150</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(1 \le N \le 150)$</span> </mjx-container></p>

<p>두번째 줄에 아침에 민호가 배치한 생수병을 의미하는 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>의 문자열이 주어진다.</p>

<p>세번째 줄에 저녁에 민호가 확인한 생수병의 배치를 의미하는 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>의 문자열이 주어진다.</p>

<p>두번째 줄과 세번째 줄에 주어지는 문자열은 <code><span style="color:#e74c3c;">w</span></code>와 <span style="color:#e74c3c;"><code>.</code></span>으로 구성되어 있으며, 문자열의 <code><span style="color:#e74c3c;">w</span></code>는 생수병이 있는 자리, <code><span style="color:#e74c3c;">.</span></code>는 비어 있는 자리를 의미한다.</p>

### 출력 

 <p>첫번째 줄에 생수병에 무슨 일이 일어났는지 알려주는 문자열을 출력한다.</p>

