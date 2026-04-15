# [Platinum IV] Omnes Viae Yokohamam Ducunt? - 33001 

[문제 링크](https://www.acmicpc.net/problem/33001) 

### 성능 요약

메모리: 24252 KB, 시간: 168 ms

### 분류

수학, 그래프 이론, 최단 경로, 데이크스트라

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p><em>“Omnes viae Romam ducunt”</em> is an old Latin proverb meaning “all roads lead to Rome.” It is still desirable to have access to the capital from all the regions of a country.</p>

<p>The Kingdom of Kanagawa has a number of cities, including the capital city, Yokohama. The Ministry of Transport of the Kingdom is now planning to construct a highway network, connecting all those cities.</p>

<p>There are a number of candidate highway segments, each of which directly connects two cities. A highway network is a set of highway segments chosen from the candidates. The following are required for the highway network.</p>

<ul>
	<li>All the cities should be connected via highway segments in the network, directly or indirectly.</li>
	<li>To save the budget, the minimum number of segments should be chosen. In other words, the highway network should not be redundant; the path connecting any pair of cities should be unique.</li>
</ul>

<p>The highway network should be made resistant to natural disasters, with the limited budget. The emphasis is placed on accessibility to and from the capital city, Yokohama. As the network is planned to be non-redundant, when one segment becomes unavailable due to a natural disaster, some of the cities become inaccessible from Yokohama.</p>

<p>We want to minimize the <em>total risk severity</em>, defined as follows.</p>

<p>The cities in the Kingdom have different populations and economic scales, based on which, the cities are assigned certain <em>significance values</em>. Given a highway network, the <em>damage</em> suffered from a natural disaster on a single segment in the network is estimated by the sum of the significance values of such cities made inaccessible from Yokohama.</p>

<p><em>Vulnerabilities</em> to natural disasters are assessed for all the candidate segments. The <em>risk severity</em> of a segment is calculated as the product of its estimated damage and vulnerability. The total risk severity of the network is estimated as the sum of the risk severities of all the segments in the network.</p>

<p>Your task is to determine the minimum total risk severity by appropriately designing the highway network.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<blockquote>
<p>$n$ $m$</p>

<p>$p_1$ $\cdots$ $p_n$</p>

<p>$u_1$ $v_1$ $q_1$</p>

<p>$\vdots$</p>

<p>$u_m$ $v_m$ $q_m$</p>
</blockquote>

<p>The first two integers $n$ and $m$ ($2 ≤ n ≤ 10^5$, $1 ≤ m ≤ 3 \times 10^5$) describe the numbers of cities and highway segment candidates, respectively. The cities are numbered from $1$ to $n$, with Yokohama numbered $1$. The second line contains $n$ integers $p_1, \dots , p_n$, where each $p_i$ ($1 ≤ p_i ≤ 1000$) represents the significance value assigned to the city numbered $i$.</p>

<p>The following $m$ lines describe the candidate highway segments. The $j$-th line of them contains three integers $u_j$, $v_j$, and $q_j$ ($1 ≤ u_j < v_j ≤ n$, $1 ≤ q_j ≤ 10^6$), meaning that the segment candidate connecting cities numbered $u_j$ and $v_j$ has the vulnerability $q_j$. Each pair $(u_j , v_j )$ appears at most once in the input.</p>

<p>It is guaranteed that one or more highway networks that connect all the cities can be designed using some of these segments.</p>

### 출력 

 <p>Output a line containing the minimum possible total risk severity.</p>

