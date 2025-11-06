# [Platinum II] Missing Separators - 33126 

[문제 링크](https://www.acmicpc.net/problem/33126) 

### 성능 요약

메모리: 490984 KB, 시간: 580 ms

### 분류

다이나믹 프로그래밍, 문자열, 접미사 배열과 LCP 배열

### 제출 일자

2025년 11월 6일 23:55:56

### 문제 설명

<p>You have a dictionary, which is a list of <strong>distinct</strong> words sorted in alphabetical order. Each word consists of uppercase English letters.</p>

<p>You want to print this dictionary. However, there is a bug with the printing system, and all words in the list are printed next to each other without any separators between words. Now, you ended up with a string $S$ that is a concatenation of all the words in the dictionary in the listed order.</p>

<p>Your task is to reconstruct the dictionary by splitting $S$ into one or more words. Note that the reconstructed dictionary must consist of distinct words sorted in alphabetical order. Furthermore, you want to maximize the number of words in the dictionary. If there are several possible dictionaries with the maximum number of words, you can choose any of them.</p>

### 입력 

 <p>A single line consisting of a string $S$ ($1 ≤ |S| ≤ 5000$). String $S$ consists of only uppercase English letters.</p>

### 출력 

 <p>First, output an integer in a single line representing the maximum number of the words in the reconstructed dictionary. Denote this number as $n$.</p>

<p>Then, output $n$ lines, each containing a single string representing the word. The words must be distinct, and the list must be sorted alphabetically. The concatenation of the words in the listed order must equal $S$.</p>

<p>If there are several possible dictionaries with the maximum number of words, output any of them.</p>

