# [Platinum V] Excavation - 23095 

[문제 링크](https://www.acmicpc.net/problem/23095) 

### 성능 요약

메모리: 45560 KB, 시간: 200 ms

### 분류

구현, 그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>The police investigation revealed the gangsters deployed several radioactive stones under the city to poison underground waters. The exact positions of radioactive stones were found, but due to nature of radioactivity, it is a difficult task to remove the stones safely. The government of the city thus decided to use shielded excavators to retrieve stones from the ground.</p>

<p>The city shape is a square grid. City services have several excavator types available – Reepadlo, Qrtech, Bugger, Namakatschenko, and Kopatsch. Each of them has different specifications and movement pattern. Excavators may move either as a Rook, a Queen, a Bishop, a kNight, or as a King in the game of chess, respectively (see images for movement illustration). Due to compatibility issues only a single type of excavators can be deployed.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 499px; height: 304px;"></p>

<p style="text-align: center;">Figure 1: Illustration of specific excavator movement patterns.</p>

<p>There is at most one radioactive stone on each tile of the grid. At the beginning of the excavation, there is one excavator at the position of each radioactive stone and it immediately retrieves the stone from the ground. The next steps of the operation are executed to follow strict radiation handling safety protocol. At each step only one excavator can execute a single move and it can execute it only if the move brings the excavator to a position of another excavator. Excavators of types Reepadlo, Qrtech, Bugger may skip over other excavators during a move over multiple grid tiles, i.e. they do not have to end the move on the position of the first encountered excavator. After excavator A arrives to the position of excavator B, B takes its load and A is removed from the operation to be cleaned of radiation.</p>

<p>The operation finishes succesfully if in the end there is a single excavator remaining. It is possible the operation can not be successfuly finished.</p>

<p>Your task is to determine whether the operation can be finished succesfully. If it can, print also the excavators’ moves leading to the solution.</p>

### 입력 

 <p>The first line of input contains an integer N (1 ≤ N ≤ 100), determining the size of the city, and a single character determining the excavator type to be deployed (“<code>R</code>” – Reepadlo, “<code>Q</code>” – Qrtech, “<code>B</code>” – Bugger, “<code>N</code>” – Namakatschenko, “<code>K</code>” – Kopatsch).</p>

<p>After that follow N lines describing the initial positions of the excavators in the city. Each line contains N characters, where each character is either the excavator type or “<code>.</code>” for empty field. There is always at least one excavator deployed in the city.</p>

### 출력 

 <p>On the first line print either “<code>YES</code>”, if the operation for the given configuration can be finished successfully, and “<code>NO</code>” otherwise. If the operation can be finished successfully, print also lines describing moves of excavators in the same order they were executed during the excavation, if there were any. i-th such line describes a single step and contains four space separated integers X, Y, W, Z (1 ≤ X, Y, W, Z ≤ N), indicating an excavator moves from position (X, Y) to position (W, Z) in step i. A position (X, Y) describes the position on row X (numbered from top to bottom) and in column Y (numbered from left to right).</p>

