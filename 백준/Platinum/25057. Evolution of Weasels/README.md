# [Platinum IV] Evolution of Weasels - 25057 

[문제 링크](https://www.acmicpc.net/problem/25057) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

애드 혹

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>A wild basilisk just appeared at your doorstep. You are not entirely sure what a basilisk is and you wonder whether it evolved from your favorite animal, the weasel.</p>

<p>How can you find out whether basilisks evolved from weasels? Certainly, a good first step is to sequence both of their DNAs. Then you can try to check whether there is a sequence of possible mutations from the DNA of the weasel to the DNA of the basilisk.</p>

<p>Your friend Ron is a talented alchemist and has studied DNA sequences in many of his experiments. He has found out that DNA strings consist of the letters <code>A</code>, <code>B</code> and <code>C</code> and that single mutations can only remove or add substrings (a substring is a contiguous sequence of characters). The substrings that can be removed or added by a mutation are <code>AA</code>, <code>BB</code>, <code>CC</code>, <code>ABAB</code> or <code>BCBC</code>. During a sequence of mutations a DNA string may even become empty.</p>

<p>Ron has agreed to sequence the DNA of the weasel and the basilisk for you, but finding out whether there is a sequence of possible mutations that leads from one to the other is too difficult for him, so you have to do it on your own.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains an integer $t$ ($1 ≤ t ≤ 100$) — the number of test cases. The descriptions of the $t$ test cases follow.</p>

<p>The first line of each test case contains a string $u$ ($1 ≤ |u| ≤ 200$) — the DNA of the weasel.</p>

<p>The second line of each test case contains a string $v$ ($1 ≤ |v| ≤ 200$) — the DNA of the basilisk.</p>

<p>The values $|u|$, $|v|$ denote the lengths of the strings $u$ and $v$. It is guaranteed that both strings $u$ and $v$ consist of the letters <code>A</code>, <code>B</code> and <code>C</code>.</p>

### 출력 

 <p>For each test case, print <code>YES</code> if there is a sequence of mutations to get from $u$ to $v$ and <code>NO</code> otherwise.</p>

