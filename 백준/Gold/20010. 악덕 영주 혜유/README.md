# [Gold II] 악덕 영주 혜유 - 20010 

[문제 링크](https://www.acmicpc.net/problem/20010) 

### 성능 요약

메모리: 18772 KB, 시간: 140 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 최소 스패닝 트리

### 문제 설명

<p>FT온라인 게임에서 치열한 경쟁을 통해 영주가 된 혜유는 퀘스트를 받았다. 퀘스트의 내용은 자신이 관리하고 있는 마을 사이에 교역로를 건설하여 마을 간 교류를 활성화시키는 것이다. 이때, 교역로는 양 방향으로 이동할 수 있으며, 서로 도달이 불가능한 마을이 없도록 교역로를 건설하여야 한다.</p>

<p>마음이 괘씸한 혜유는 돈을 최대한 적게 쓰면서 퀘스트를 달성하려고 한다. 혜유를 도와서 모든 마을과 마을을 최소한의 비용으로 연결하고 그 비용을 구해보자. 또한 혜유는 이때 마을과 마을을 이동하는 가장 최악의 비용이 얼마인지에 관심이 많다. 임의의 두 마을을 이동하는 최단 경로 중 비용이 가장 큰 경로의 비용도 구해보자.</p>

### 입력 

 <p>첫 번째 줄에는 마을의 수 N(1 ≤ N ≤ 1,000)과 설치 가능한 교역로의 수 K(1 ≤ K ≤ 1,000,000)가 주어진다.</p>

<p>두 번째 줄부터 K + 1줄에는 서로 다른 두 마을의 번호 a, b (a ≠ b)와 두 마을을 연결하는 비용 c가 주어진다. (1 ≤ c ≤ 1,000,000)</p>

<p>항상 모든 마을을 연결할 수 있는 경우만 입력으로 주어진다, 또한 최소 비용으로 연결하는 방법은 유일하다.</p>

<p>서로 다른 두 마을 사이에 건설할 수 있는 교역로는 최대 하나뿐이다.</p>

<p>마을은 0부터 N - 1 사이의 번호를 갖는다.</p>

<div id="dicLayer" style="display: none; color: rgb(0, 0, 0); font-size: 12px; font-family: Arial; background: -webkit-linear-gradient(bottom, rgb(255, 235, 0), rgb(255, 220, 0)); width: 400px; height: 150px;">
<div id="dicLayerContents"> </div>

<div id="dicLayerSub"> </div>
</div>

<div id="dicRawData" style="display: none;"> </div>

### 출력 

 <p>첫 번째 줄에는 모든 마을을 연결하는 최소 비용을 출력한다. </p>

<p>두 번째 줄에는 마을과 마을을 이동하는 비용이 가장 큰 경로의 비용을 출력한다.</p>

<div id="dicLayer" style="display: none; color: rgb(0, 0, 0); font-size: 12px; font-family: Arial; background: -webkit-linear-gradient(bottom, rgb(255, 235, 0), rgb(255, 220, 0)); width: 400px; height: 150px;">
<div id="dicLayerContents"> </div>

<div id="dicLayerSub"> </div>
</div>

<div id="dicRawData" style="display: none;"> </div>

