# [Bronze III] Append and Panic! - 33135 

[문제 링크](https://www.acmicpc.net/problem/33135) 

### 성능 요약

메모리: 2088 KB, 시간: 0 ms

### 분류

구현, 문자열, 정렬

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>Today is Gabriel’s first day at his new job, and he has been given his first task. He needs to read a string made up of uppercase letters from a file, sort the letters in the string alphabetically, filter out repeated letters, and then write the result back to the original file. For instance, sorting the string “<code>ICPC</code>” would produce “<code>CCIP</code>”, which would become “<code>CIP</code>” after removing repeated letters. Easy, right?</p>

<p>However, Gabriel made a tiny mistake. Instead of overwriting the file with the filtered string, he accidentally appended it to the file. Now, the file is corrupted, containing the original string followed by the sorted, duplicate-free version of it, and Gabriel is in a bit of a panic.</p>

<p>Given the content of the corrupted file, can you determine the length of the original string? Gabriel is confident that with this information, he will be able to complete his assigned task.</p>

### 입력 

 <p>The input consists of a single line that contains a string $S$ made up of uppercase letters ($2 ≤ |S| ≤ 2000$), which is the concatenation of the original (uncorrupted) string $t$ and the sorted, duplicate-free version of $t$.</p>

### 출력 

 <p>Output a single line with an integer indicating the length of $t$.</p>

