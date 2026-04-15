# [Silver V] Dialling Digits - 32540 

[문제 링크](https://www.acmicpc.net/problem/32540) 

### 성능 요약

메모리: 19348 KB, 시간: 100 ms

### 분류

구현

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>Disaster struck at the Billboards And Phone-numbers Company!  % Deliberately using hyphen in Phone-numbers for the backronym Due to a bug in their database system, they lost the corresponding mnemonic phrases for each of the registered phone numbers. These mnemonic phrases are typically used on billboards, to make a phone number for an advertisement easier to remember by people who read them. To dial the phone number from a mnemonic phrase, you simply have to press the number keys corresponding to each letter, as shown in Figure D.1. For example, the phone number "<code>1-800-BAPC</code>" would be dialled as "<code>1-800-2272</code>".</p>

<p>Using this information and a given list of valid words, reconstruct the possible mnemonic phrases for each registered phone number. Each mnemonic phrase consists of exactly one word from the word list. In the input, you will only receive the part of the phone number that should be exactly linked to possible mnemonic phrases, so it does not include the "<code>1-800-</code>" prefix (or any other prefix).</p>

<p style="text-align: center;"><img alt="" src="" style="width: 247px; height: 200px;"></p>

<p style="text-align: center;">Figure D.1: The keypad of a telephone, where some numbers are assigned several letters.</p>

<p style="text-align: center;"><small>Public Domain by Sakurambo on <a href="https://commons.wikimedia.org/wiki/File:Telephone-keypad2.svg">Wikimedia Commons</a>, modified</small></p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ and $m$ ($1 \leq n, m \leq 10^5$, $n \cdot m \leq 10^5$), the number of words and the number of phone numbers.</li>
	<li>$n$ lines, each with a word $w$ ($1 \leq |w| \leq 10$), consisting only of English lowercase letters (<code>a-z</code>). The words are unique and given in alphabetical order.</li>
	<li>$m$ lines, each with a phone number $p$ ($1 \leq |p| \leq 10$), consisting only of digits that correspond to letters in a mnemonic phrase (<code>2-9</code>).</li>
</ul>

### 출력 

 <p>For each phone number, output the number of words that are a valid mnemonic phrase for this phone number, followed by these words in alphabetical order.</p>

