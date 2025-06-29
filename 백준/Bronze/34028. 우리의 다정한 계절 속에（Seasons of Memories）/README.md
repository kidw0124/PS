# [Bronze I] 우리의 다정한 계절 속에(Seasons of Memories) - 34028 

[문제 링크](https://www.acmicpc.net/problem/34028) 

### 성능 요약

메모리: 2084 KB, 시간: 0 ms

### 분류

수학, 구현, 애드 혹, 사칙연산

### 제출 일자

2025년 6월 30일 01:43:14

### 문제 설명

<p>여자친구는 2015년 1월 16일에 데뷔한 6인조 걸그룹으로, 2025년 1월 6일 신곡 “우리의 다정한 계절 속에”를 발매했다.</p>

<p>지금은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>A</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A$</span></mjx-container>년 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container>월 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>C</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$C$</span></mjx-container>일이다. 여자친구가 데뷔한 후로 우리는 여자친구와 몇 개의 계절을 함께했는지 구하자.</p>

<p>계절은 날짜에 따라 다음과 같이 구분한다.</p>

<ul>
	<li>12월 1일 -- 2월 29일: 겨울</li>
	<li>3월 1일 -- 5월 31일: 봄</li>
	<li>6월 1일 -- 8월 31일: 여름</li>
	<li>9월 1일 -- 11월 30일: 가을</li>
</ul>

<p>일부만 함께한 계절도 함께한 계절로 포함된다. 즉, 여자친구가 데뷔한 겨울인 2015년 1월 16일 -- 2월 28일도 겨울을 한 번 함께한 것으로 취급힌다.</p>

### 입력 

 <p>첫째 줄에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>A</mi><mo>,</mo><mi>B</mi><mo>,</mo><mi>C</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A,B,C$</span></mjx-container>가 공백을 사이에 주고 주어진다.</p>

### 출력 

 <p>첫째 줄에 여자친구와 함께한 계절의 수를 출력한다.</p>

