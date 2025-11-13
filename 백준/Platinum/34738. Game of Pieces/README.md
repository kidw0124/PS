# [Platinum III] Game of Pieces - 34738 

[문제 링크](https://www.acmicpc.net/problem/34738) 

### 성능 요약

메모리: 92160 KB, 시간: 420 ms

### 분류

자료 구조, 세그먼트 트리, 느리게 갱신되는 세그먼트 트리, 값 / 좌표 압축

### 제출 일자

2025년 11월 14일 01:38:38

### 문제 설명

<p>If you’ve ever played Tetris for long enough, you might have experienced the <em>Tetris effect</em> – seeing falling blocks even after you have stopped playing. To stay focused on solving problems and avoid such distractions, we will consider a simplified version of the game.</p>

<p>The game is played on a board composed of square cells arranged in a grid. Columns of the grid are numbered sequentially from left to right. The board is infinite to the right and to the top. Each cell is either empty or filled, and initially, all cells are empty.</p>

<p>A sequence of N rectangular pieces is given, and the pieces are dropped onto the board one at a time. Pieces have different sizes. A piece of size $L$ is either vertical ($L \times 1$ cells) or horizontal ($1 \times L$ cells). When a piece is dropped at a specified column, it starts at a location above all the currently filled cells and falls straight down until it either reaches the bottom of the board or lands on top of an already filled cell. Once a piece lands, it fills its final set of cells.</p>

<p>Each time a piece lands, the game is considered <em>safe</em> if no empty cell has a filled cell above it; otherwise the game is <em>unsafe</em>, the offending piece is removed from the board, and the game continues with the next piece as if it had never been dropped.</p>

<p>In the example below, corresponding to the first sample input, the game becomes unsafe once the second piece lands, hence the piece is removed and the next pieces keep the game safe.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 415px; height: 100px;"></p>

<p>Given the sequence of pieces and their drop positions, your task is to determine, for each piece, whether it makes the board unsafe after landing.</p>

### 입력 

 <p>The first line contains an integer $N$ ($1 ≤ N ≤ 2 \cdot 10^5$), indicating the number of pieces.</p>

<p>Each of the next $N$ lines describes a piece with a character $C$ and two integers $L$ and $P$ ($1 ≤ L ≤ 10^9$ and $1 ≤ P ≤ 10^{18}$), representing respectively the type of the piece, its length, and the position where it is dropped. For a vertical piece, $C$ is the character “<code>|</code>” (pipe), the piece has $L \times 1$ cells, and it is dropped at column $P$. For a horizontal piece, $C$ is the character “<code>-</code>” (hyphen), the piece has $1 \times L$ cells, and it is dropped spanning columns $P, P + 1, \dots , P + L − 1$.</p>

### 출력 

 <p>Output a single line with a string of length $N$. The $i$-th character of the string must be the uppercase letter “<code>U</code>” if the game becomes unsafe immediately after the $i$-th piece lands on the board, and the uppercase letter “<code>S</code>” otherwise.</p>

