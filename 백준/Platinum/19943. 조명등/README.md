# [Platinum II] 조명등 - 19943 

[문제 링크](https://www.acmicpc.net/problem/19943) 

### 성능 요약

메모리: 5892 KB, 시간: 256 ms

### 분류

볼록 껍질을 이용한 최적화(cht), 다이나믹 프로그래밍(dp)

### 문제 설명

<p>관광지로 유명한 아르미 도시에서는 아래 <그림 1>에서 보는 것처럼 일직선으로 된 길을 따라 자그만 조각품을 장대 끝에 달아 두었다. 장대의 높이와 장대의 간격은 설치자의 예술 감각에 따라 다양하다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/0638c87a-be3f-47b7-998a-405f796f144e/-/preview/" style="width: 640px; height: 117px;"><br>
 </p>

<p style="text-align: center;"><그림 1> 5개의 조각품이 설치된 모습</p>

<p>장대 끝에 달린 조각품이 야간에도 모두 다 잘 보일 수 있도록 하기 위해 조명등을 설치하려고 한다. 조명등 역시 장대 끝에 설치하는데, 조명등 위에 있는 갓 때문에 아래 방향 좌우 45° 범위 내에 있는 공간만 밝게 비춘다. 조명등은 필요한 곳에 새로운 장대를 세워 그 끝에 설치하는데, 이미 조각품이 설치된 곳에도 조명등을 설치할 수 있다. 아래 <그림 2>는 <그림 1>에서 보인 5개의 조각품을 비추기 위해 3개의 조명등을 설치한 예를 보여준다. 처음 두 조명등은 새로운 위치에 막대를 세워 그 끝에 조명등을 설치하였고, 세 번째 조명등은 설치된 조각 위치와 동일한 곳에 설치되었다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 640px; height: 144px;"></p>

<p style="text-align: center;"><그림 2> 조명등이 설치된 예</p>

<p><그림 3>은 조명등을 1개만 설치하여 전체 조각품을 비추는 예를 보여준다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 640px; height: 318px;"></p>

<p>조명등을 높이 달수록 더 많은 면적을 밝게 할 수 있지만, 그에 비례하여 더 비싼 등을 달아야 한다. 즉, 각 조명등의 설치 비용은 그 조명등이 밝히는 삼각형 모양의 면적이다.</p>

<p>설치된 모든 조각품을 비추기 위해 최소 비용으로 조명등을 설치하려고 한다.</p>

### 입력 

 <p>첫 줄에 테스트 케이스의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>가 주어진다. 각 테스트 케이스의 첫 줄에는 조각품의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. 다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에는 각 조각품의 위치 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x$</span></mjx-container> 좌표 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>x</mi><mi>i</mi></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x_i$</span></mjx-container>와 높이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c210E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>h</mi><mi>i</mi></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$h_i$</span></mjx-container>가 주어진다. 조각품은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x$</span></mjx-container> 좌표가 증가하는 순서로 주어진다.</p>

### 출력 

 <p>각 테스트 케이스에 대해서 한 줄에 최소 비용을 소수점 아래 둘째 자리까지 정확하게 출력한다.</p>

