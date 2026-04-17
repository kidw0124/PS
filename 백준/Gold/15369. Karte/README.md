# [Gold I] Karte - 15369 

[문제 링크](https://www.acmicpc.net/problem/15369) 

### 성능 요약

메모리: 6360 KB, 시간: 124 ms

### 분류

해 구성하기, 그리디 알고리즘, 정렬

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>… Take these cards, I tell ya, my cousin from Sweden sent them when the hunger for war was at its peak, and we stayed playing rummy in the trenches.</p>

<blockquote>
<p>Daniel: “Are we playin’ rummy, eh?”</p>

<p>Domagoj: “Well ok then.”</p>

<p>Daniel: “Watch this now. You have a deck of N cards, where the i th card has a claim written on it in the form of ‘At least a<sub>i</sub> cards beneath this one contain a false claim.’ You have to shuffle them so that exactly K cards contain a false claim.”</p>

<p>Domagoj: “You destroy me in this game every time, where did you get these cards, son?!”</p>

<p>Daniel: “Ah, my old man organizes card tournaments, so each day he gives me free cards, ten bucks per deck.”</p>
</blockquote>

<p>Your task is to help Domagoj solve Daniel’s task. Output the order in which Domagoj must place the cards. It is also possible that this is a bad joke on Daniel’s part, and that there is no possible order to place the cards in. In that case, output -1.</p>

### 입력 

 <p>The first line contains integers N and K (1 ≤ N ≤ 5·10<sup>5</sup>, 0 ≤ K ≤ N).</p>

<p>The ith of the following N lines contains an integer a<sub>i</sub> (0 ≤ a<sub>i</sub> ≤ 5·10<sup>5</sup>).</p>

### 출력 

 <p>If the required order does not exist, output -1.</p>

<p>Otherwise, in a single line, output N integers separated by spaces, the numbers on the cards in the order from the top to the bottom​ of the deck. If there are multiple solutions, output any.</p>

