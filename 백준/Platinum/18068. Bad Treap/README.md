# [Platinum IV] Bad Treap - 18068 

[문제 링크](https://www.acmicpc.net/problem/18068) 

### 성능 요약

메모리: 2920 KB, 시간: 4 ms

### 분류

해 구성하기, 수학, 런타임 전의 전처리

### 제출 일자

2024년 9월 1일 20:31:55

### 문제 설명

<p>A <em>treap</em>, also known as <em>Cartesian tree</em>, is a data structure that stores a set of keys in a binary search tree.</p>

<p>Each node of this tree is characterized by a pair (x, y).</p>

<p>The x values of the nodes are the stored keys. They obey “the binary search tree rule”: all x values in the left subtree of the node are smaller than its x value, and all x values in the right subtree of the node are larger than its x value.</p>

<p>The y values of the nodes obey “the heap rule”: y value of a node is less than or equal to the y value of its parent.</p>

<p>The y value for each created node is usually selected randomly according to some distribution. This results in nice average time complexity of many operations.</p>

<p>Since this data structure unites some properties of a binary search tree and a heap, its name is a “portmanteau” term made of two words: TRee + hEAP = TREAP.</p>

<table class="table table-bordered" style="width:100%;">
	<tbody>
		<tr>
			<td style="width: 50%; text-align: center;"><img alt="" src="" style="width: 333px; height: 135px;"></td>
			<td style="width: 50%; text-align: center;"><img alt="" src="" style="width: 228px; height: 135px;"></td>
		</tr>
		<tr>
			<td style="width: 50%; text-align: center;">A treap with 7 nodes; its height is 4</td>
			<td style="width: 50%; text-align: center;">A treap for the sample test below</td>
		</tr>
	</tbody>
</table>

<p>Benjamin decided that nondeterminism in y value selection procedure is bad, as it makes execution time differ from one run to another. He decided to calculate y for each node deterministically based on its x. He selected the rule y = sin(x). He is especially glad that distinct integer x’s will always have distinct y’s.</p>

<p>Barbara understands that while the nondeterministic treap shows its worst performance when provided “bad” random sequence, the deterministic treap shows its worst performance when provided “bad” set of keys. She wants to explain it to Benjamin by showing him n integer keys, which, being stored in his data structure, will form a treap of height n — the “most unbalanced” possible situation.</p>

<p>Help Barbara by providing n such keys. All these keys should fit into the 32-bit signed integer type.</p>

### 입력 

 <p>The input consists of a single integer n (1 ≤ n ≤ 50 000).</p>

### 출력 

 <p>Output n lines containing distinct integer keys. All keys must be between −2<sup>31</sup> and 2<sup>31</sup> − 1, inclusive.</p>

<p>A treap built on these keys with the rule y = sin(x) must have height n.</p>

