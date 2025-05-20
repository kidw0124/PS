# [Platinum IV] Optimization for UltraNet - 20263 

[문제 링크](https://www.acmicpc.net/problem/20263) 

### 성능 요약

메모리: 40800 KB, 시간: 360 ms

### 분류

자료 구조, 분리 집합, 그래프 이론, 그리디 알고리즘, 최소 스패닝 트리, 트리

### 제출 일자

2025년 5월 21일 05:27:17

### 문제 설명

<p>The UltraNet company provides network connectivity for all cities in a country. For a pair of cities, they are either directly connected or indirectly connected. A city i and another city j are directly connected if a cable with a symmetrical bandwidth of b<sub>i,j</sub> = b<sub>j,i</sub> is wired between them. For two cities that are not directly connected, at least one path between the two cities exists. In the current UltraNet, more than one path is possibly available for a city pair.</p>

<p>The current UltraNet is perfectly working, while the maintenance fee of each cable is costly. Energy conservation is another concern. The energy consumption of a cable is proportional to its bandwidth. Therefore, the company has an optimization plan to reorganize the network with the policies in the following order:</p>

<ol>
	<li>The number of cables should be minimized without sacrificing the connectivity of the whole UltraNet. In other words, exactly one path between every city pair should be satisfied.</li>
	<li>If there is more than one way to minimize the number of cables, the bottleneck of the whole network should be maximized. The bottleneck of a network is determined by the city pair with the narrowest bandwidth, and the bandwidth of a city pair (i, j), b'<sub>i,j</sub>, is determined by the cable with the narrowest bandwidth on the only path from i to j.</li>
	<li>If there is still more than one way to meet the above two points, the total energy consumption of the network should be minimized. In other words, the sum of bandwidths of the remaining cables should be minimized.</li>
</ol>

<p>Your task is to help UltraNet optimize the network and then output the sum of the bandwidths among all city pairs in the optimized network. For optimizing the following example, the three cables in dotted will be discarded. In the resulting network, the bottleneck is 3, the sum of bandwidths of the remaining four cables is 6 + 3 + 8 + 4 = 21, and the sum of the bandwidths among all city pairs is <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-munder limits="false"><mjx-mo class="mjx-sop"><mjx-c class="mjx-c2211 TEX-S1"></mjx-c></mjx-mo><mjx-script style="vertical-align: -0.285em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-munder><mjx-texatom space="2" texclass="ORD"><mjx-msup><mjx-mi class="mjx-n"></mjx-mi><mjx-script style="vertical-align: 0.363em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom><mjx-munderover space="2" limits="false"><mjx-mo class="mjx-sop"><mjx-c class="mjx-c2211 TEX-S1"></mjx-c></mjx-mo><mjx-script style="vertical-align: -0.285em; margin-left: 0px;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-texatom><mjx-spacer style="margin-top: 0.284em;"></mjx-spacer><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D457 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-munderover></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><munder><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mi>i</mi><mo>=</mo><mn>1</mn></mrow></munder><mrow data-mjx-texclass="ORD"><msup><mi></mi><mi>n</mi></msup><mo>−</mo><mn>1</mn></mrow><munderover><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mi>j</mi><mo>=</mo><mi>i</mi><mo>+</mo><mn>1</mn></mrow><mrow data-mjx-texclass="ORD"><mi>n</mi></mrow></munderover></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\sum_{i=1}{^n-1}\sum_{j=i+1}^{n}\)</span></mjx-container>b'<sub>i,j</sub> = 6 + 4 + 6 + 3 + 4 + 8 + 3 + 4 + 3 + 3 = 44.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/7abd5e46-6793-40e9-b3cd-3aa3c9702227/-/preview/" style="width: 212px; height: 183px;"></p>

### 입력 

 <p>Each test case begins with two integers n and m, denoting numbers of cities and cables, respectively. Then, m lines will follow for specifying the m cables. Each of the m lines contains three positive integers, i, j, and b<sub>i,j</sub>, denoting that a cable with a bandwidth of b<sub>i,j</sub> directly connects the city pair (i, j), where the cities are numbered from 1 to n, and i < j since b<sub>i,j</sub> = b<sub>j,i</sub>. No more than one cable will be available between every city pair in the current network. In addition, the bandwidths of all cables are distinct; no two cables have the same bandwidth rating.</p>

### 출력 

 <p>The output is a single integer that is the sum of the bandwidths of all city pairs in the optimized network.</p>

