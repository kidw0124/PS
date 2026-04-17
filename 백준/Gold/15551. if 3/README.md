# [Gold IV] if 3 - 15551 

[문제 링크](https://www.acmicpc.net/problem/15551) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기, 해싱

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>다음 프로그램을 실행시켰을 때, "<code>true</code>"를 출력하는 길이가 N인 문자열 <code>a, b</code> 를 찾는 프로그램을 작성하시오.</p>

<pre class="brush:java; toolbar:false;">import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        if (!a.equals(b) && a.hashCode() == b.hashCode()) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
    }
}</pre>

<p>실행 환경은 BOJ 채점 서버의 Java 실행 환경과 같다.</p>

### 입력 

 <p>첫째 줄에 문자열의 길이 N (2 ≤ N ≤ 100)이 주어진다.</p>

### 출력 

 <p>첫째 줄에 문자열 <code>a</code>, 둘째 줄에 문자열 <code>b</code>를 출력한다.</p>

<p>문자열 <code>a</code>와 <code>b</code>는 <code>java.util.Scanner</code>의 <code>next</code>메소드로 입력받을 수 있어야 한다.</p>

