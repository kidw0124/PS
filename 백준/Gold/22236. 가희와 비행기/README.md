# [Gold IV] 가희와 비행기 - 22236 

[문제 링크](https://www.acmicpc.net/problem/22236) 

### 성능 요약

메모리: 6068 KB, 시간: 12 ms

### 분류

조합론(combinatorics), 다이나믹 프로그래밍(dp), 수학(math)

### 문제 설명

<p>가희는 김포 공항에서 김해 공항까지 비행기를 타고 가려고 합니다.</p>

<p>비행기가 수평 방향으로 1만큼 이동하였을 때,<strong> 비행기의 고도는 1만큼 변화합니다. (상승 또는 하강)</strong></p>

<p>비행기가 상승하거나 하강할 때에는 <strong>이동한 수평 거리 당, 고도 변화량이 동일</strong>합니다. 그림 1은 이 조건을 만족하지만, 그림 2는 그렇지 않습니다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/1a30e9c0-21aa-4c1e-b046-8aafd51282be/-/preview/">    <img alt="" src="https://upload.acmicpc.net/48501960-e0d5-4c9e-82ce-7cbc3b10cf2e/-/preview/"></p>

<p style="text-align: center;"><strong>[그림 1] 비행기가 상승할 때와 하강할 때</strong></p>

<p style="text-align: center;"> </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6b967991-2d5d-4f7c-b64e-575cb987bbc7/-/preview/"></p>

<p style="text-align: center;"><strong>[그림 2] 문제의 조건을 만족하지 않는 비행 경로 </strong></p>

<p>김포 공항에서 김해 공항까지 수평 거리는 <em>d</em>입니다. 아래 조건을 만족하는 비행기가 비행할 수 있는 가짓수를 구해 주세요.</p>

<p> </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d898742f-6e1e-4e1e-90bf-8bf44720cfb4/-/preview/"><br>
<strong>[그림 3] 김포공항에서 김해공항 방항으로 날아가는 비행기</strong></p>

<ul>
	<li>김포 공항에서 이륙하면 김해 공항에 착륙할 때 까지 <strong>다른 어떠한 지점에도 착륙하지 않습니다. 고도가 0이 되었을 때, 착륙하였다고 합니다.</strong></li>
	<li>비행기는 수평 거리 <em>d</em>만큼 이동합니다.  수평거리 <em>d</em>만큼 이동했을 때 고도가 0인 지점에 김해 공항이 있습니다.</li>
	<li>비행기는 이륙할 때부터 착륙할 때 까지 비행 방향을 바꾸지 않습니다. 즉, 김포 공항에서부터 김해 공항까지 일직선으로 날아갑니다.</li>
	<li>비행기는 지구를 한 바퀴 이상 돌지 않으며, 김해 공항이 있는 방향 반대편(북서쪽)으로 비행하지 않습니다.</li>
	<li>김포 공항과 김해 공항의 고도는 0이며, <strong>비행기가 날아가는 경로 상에는 장애물이 존재하지 않습니다.</strong></li>
</ul>

<p> </p>

### 입력 

 <p>첫 줄에 <em>d</em>와 <em>m</em>이 주어집니다.</p>

### 출력 

 <p>문제에 대한 답을 <em>m</em>으로 나눈 나머지를 출력해 주세요.</p>

