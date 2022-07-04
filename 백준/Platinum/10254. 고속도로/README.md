# [Platinum II] 고속도로 - 10254 

[문제 링크](https://www.acmicpc.net/problem/10254) 

### 성능 요약

메모리: 8116 KB, 시간: 516 ms

### 분류

볼록 껍질(convex_hull), 기하학(geometry), 회전하는 캘리퍼스(rotating_calipers)

### 문제 설명

<p>n개의 도시를 가진 나라가 있다. 이 나라에서는 도시들 중 가장 먼 두 도시 사이에 직행 고속도로를 놓으려 한다.</p>

<p>고속도로는 시작점과 끝점이 아닌 다른 나라를 통과해도 된다. 즉, n개의 도시 중 유클리드 거리가 가장 먼 두 도시를 찾으려 한다. 모든 도시는 한 평면 위에 있다.</p>

<p><img src="https://www.acmicpc.net/upload/images2/highway(1).png"></p>

<p>위의 예제에서는 (12,0)의 도시와 (-6,3)의 도시가 가장 먼 유클리드 거리를 갖는다.</p>

<p>도시 n개의 좌표가 주어지면 모든 두 도시 쌍의 거리 중 가장 먼 두 도시를 찾아라.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 수 T가 주어진다. </p>

<p><span style="line-height:1.6em">각 테스트 케이스의 첫 줄엔 도시의 개수 n이 주어진다. (</span><span style="line-height:1.6em">2 ≤ n ≤ 200,000</span><span style="line-height:1.6em">) </span><span style="line-height:1.6em">그 후 n줄에 걸쳐 각 도시의 x좌표와 y좌표가 주어진다. (-10,000,000 ≤ x, y ≤ 10,000,000) </span><span style="line-height:1.6em">x, y는 항상 정수이며, 어떤 두 도시가 같은 점 위에 있는 경우는 없다.</span></p>

### 출력 

 <p>테스트 케이스마다 가장 먼 두 점의 좌표를 출력한다.</p>

<p>만일 그 두 점의 좌표가 각각 (x1, y1), (x2, y2)이라면 x1 y1 x2 y2를 출력하면 된다.</p>

<p>가장 먼 거리를 갖는 두 점의 쌍이 여러 개라면 그 중 아무 것이나 출력해도 상관없다.</p>

