# [Gold IV] 가희와 btd5 - 22238 

[문제 링크](https://www.acmicpc.net/problem/22238) 

### 성능 요약

메모리: 5240 KB, 시간: 192 ms

### 분류

이분 탐색, 유클리드 호제법, 기하학, 구현, 수학, 정수론, 시뮬레이션, 정렬

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>btd5에는 Darting Gun Tower가 있습니다. Darting Gun Tower는 아래의 알고리즘으로 풍선을 공격합니다.</p>

<ul>
	<li>공격하고자 하는 목표물의 방향으로 공격 방향을 바꿉니다.</li>
	<li>공격 방향에 있는 풍선들의 체력을 <i>d</i>씩 낮춥니다.</li>
</ul>

<p><strong>Darting Gun Tower</strong>는 좌표 (0, 0)에 하나 있습니다.<br>
Darting Gun Tower가 공격을 하게 되면, <strong>공격하는 방향에 놓인 모든 풍선들은 동일한 수치의 피해</strong>를 입히게 됩니다.<br>
초기에 풍선은 <em>N</em>개 있고, Darting Gun Tower는 공격을 <em>M</em>번 하였습니다. 공격을 끝낼 때 마다, 남은 풍선의 수를 세어 주세요.<br>
초기 상태에 Darting Gun Tower가 특정 방향으로 데미지가 10<sup>9</sup> 이상의 공격을 했을 때, <strong>모든 풍선을 제거할 수 있는 방법이 존재합니다.</strong></p>

### 입력 

 <p>첫 번째 줄에 <em>N</em>, <em>M</em>이 주어집니다.</p>

<p>2번째 줄부터 <em>N</em>+1번째 줄까지 풍선이 있는 <em>x</em>좌표, <em>y</em>좌표, 체력이 주어집니다.</p>

<p><em>N</em>+2번째 줄부터 <em>N</em>+<em>M</em>+1번째 줄까지 Darting Gun Tower의 공격 방향 (<em>x</em>, <em>y</em>)와, Darting Gun Tower가 준 데미지 <em>d</em>가 주어집니다.</p>

### 출력 

 <p><em>x</em>번째 줄에 <em>x</em>번째 공격이 끝났을 때 남은 풍선의 개수를 출력해 주세요.</p>

