# [Gold IV] 장작 넣기 - 24884 

[문제 링크](https://www.acmicpc.net/problem/24884) 

### 성능 요약

메모리: 2024 KB, 시간: 4 ms

### 분류

구현, 브루트포스 알고리즘, 시뮬레이션, 백트래킹

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>숭고한은 캠핑장을 운영하는데 저녁이 되면 $T$시간 동안 모닥불 놀이를 하려고 한다. 모닥불 놀이가 종료되기 전까지 최소 $K$개의 모닥불을 유지하고 싶다. 숭고한은 아르바이트생 SKH에게 모닥불에 장작을 넣도록 지시했다.</p>

<ul>
	<li>모닥불은 일렬로 놓인다. </li>
	<li>모닥불의 시작 화력은 $0$ 이상의 정수로 주어진다.</li>
	<li>모닥불의 화력이 $0$ 이하이면 꺼진 것이다.</li>
	<li>모닥불이 $1$번이라도 꺼지면 다시 불이 붙지 않는다.</li>
	<li>모닥불의 화력은 인접한 모닥불이 $0$개 켜져 있으면 $1$시간마다 $3$ 감소한다.</li>
	<li>모닥불의 화력은 인접한 모닥불이 $1$개 켜져 있으면 $1$시간마다 $2$ 감소한다.</li>
	<li>모닥불의 화력은 인접한 모닥불이 $2$개 켜져 있으면 $1$시간마다 $1$ 감소한다.</li>
	<li>SKH의 시작 위치는 입력으로 주어진다.</li>
	<li>SKH는 반드시 $1$시간마다 현 위치에 있는 모닥불에 장작을 넣거나, 인접한 모닥불로 이동해 장작을 넣는다.</li>
	<li>SKH는 꺼진 모닥불에도 장작을 넣을 수 있다.</li>
	<li>SKH는 $T$시각에 이동하지 않고 장작도 넣지 않는다. </li>
	<li>SKH가 장작을 넣은 모닥불은 $1$시간 동안 화력이 감소하지 않는다.</li>
	<li>$1$시간마다 모닥불의 화력은 SKH가 장작을 넣기 전에 감소한다.</li>
</ul>

<p>예를 들어 $3$시간 동안 모닥불 놀이를 할 때의 타임라인은 아래와 같다.</p>

<table border="1" cellpadding="1" cellspacing="1" class="table table-bordered" style="width: 800px;">
	<tbody>
		<tr>
			<td style="text-align: center;"><strong>시각</strong></td>
			<td style="text-align: center;"><strong>0</strong></td>
			<td style="text-align: center;"><strong>1</strong></td>
			<td style="text-align: center;"><strong>2</strong></td>
			<td style="text-align: center;"><strong>3</strong></td>
		</tr>
		<tr>
			<td style="text-align: center;"><strong>순서</strong></td>
			<td style="text-align: center;"> </td>
			<td style="text-align: center;">화력 감소 → 장작 넣기</td>
			<td style="text-align: center;">화력 감소 → 장작 넣기</td>
			<td style="text-align: center;">화력 감소 → 놀이 종료</td>
		</tr>
	</tbody>
</table>

<p>모닥불 놀이가 종료되기 전까지 최소 $K$개의 모닥불이 유지되도록 SKH가 모닥불에 장작을 넣는 경우의 수를 구하라.</p>

### 입력 

 <p>첫째 줄에 모닥불의 개수 $N$, SKH의 시작 모닥불 번호 $W$, 모닥불 놀이 시간 $T$, 유지해야 하는 최소 모닥불의 개수 $K$가 공백을 사이에 두고 주어진다. ($1 \le N \le 6$, $0 \le W < N$, $1 \le T \le 11$, $1 \le K \le N$)</p>

<p>다음 줄에 모닥불의 화력 $F_i$ ($0 \le i < N$, $0 \le F_i \le 50$)가 왼쪽 모닥불부터 차례대로 공백으로 구분되어 주어진다.</p>

<p>입력으로 주어지는 모든 수는 정수이다.</p>

### 출력 

 <p>모닥불 놀이가 종료되기 전까지 최소 $K$개의 모닥불이 유지되도록 모닥불에 장작을 넣는 경우의 수를 출력한다.</p>

