# 大数计算

- 涉及题目
    - OJ0015.A+B Problem.cpp
    - OJ0016 A-B Problem Plus.cpp
    - OJ0017 AxB Problem.cpp
    - OJ0019 N! Plus.cpp
    
- 题目要求
    - OJ0015-OJ0017输入要求：A、B正整数，数字长度小于1000，即0<=A,B<10^1000
    - OJ0019输入要求：N正整数、数字小于10000，即0<=N<10000
    
- 题干

    **15. A+B Problem Plus**

    **题目描述**

    I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.

    **解答要求**

    时间限制：1000ms, 内存限制：100MB

    **输入**

    The first line of the input contains an integer T(1≤T≤20) which means the number of test cases.
    Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large,that means you should not process them by using 32-bit integer.You may assume the length of each integer will not exceed 1000.

    **输出**

    For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B.Note there are some spaces int the equation. Output a blank line between two test cases.

    **样例**

    输入样例 1

    ```
    2
    1 2
    112233445566778899 998877665544332211
    ```
    
    输出样例 1
    
    ```
    Case 1: 
    1 + 2 = 3 
    
    Case 2: 
    112233445566778899 + 998877665544332211 = 1111111111111111110
    ```

    **16. A-B Problem Plus**

    **题目描述**

    I have a very simple problem for you again. Given two integers A and B, your job is to calculate the result of A - B.

    **解答要求**

    时间限制：1000ms, 内存限制：100MB

    **输入**

    The first line of the input contains an integer T(1<=T<=20) which means the number of test cases.
    Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large,that means you should not process them by using 32-bit integer.
    You may assume the length of each integer will not exceed 1000.

    **输出**

    For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A - B = ?", ? means the result of A - B.Note there are some spaces int the equation. Output a blank line between two test cases.

    **样例**

    输入样例 1

    ```
    3
    9 8
    12 8
    123456789 987654321
    ```
    
    输出样例 1
    
    ```
    Case 1:
    9 - 8 = 1
    Case 2:
    12 - 8 = 4
    Case 3:
    123456789 - 987654321 = -864197532
    ```
    
    **17. A×B Problem**
    
    **题目描述**
    
    I have a very simple problem for you. Given two integers A and B, your job is to multiply the product is of A × B.
    
    **解答要求**
    
    时间限制：1000ms, 内存限制：100MB
    
    **输入**
    
    Each line will contain two integers A and B. Process to end of file.Notice that the integers are very large,that means you should not process them by using 32-bit integer.
    You may assume the **length** of each integer will not exceed 1000.
    
    **输出**
    
    For each case, output the product is of A × B in one line.
    
    **样例**
    
    输入样例 1
    
    ```
    1 2
    3 11
    14512451451245124512 15125125124512451245
    ```
    
    输出样例 1
    
    ```
    2
    33
    219502644063494817653152060344354417440
    ```
    
    **19. N! Plus**
    
    **题目描述**
    
    Given an integer N(0 ≤ N ≤ 10000), your task is to calculate N!.
    
    **解答要求**
    
    时间限制：5000ms, 内存限制：100MB
    
    **输入**
    
    One N in one line.
    
    **输出**
    
    For each N, output N! in one line.
    
    **样例**
    
    输入样例 1
    
    ```
    3
    ```
    
    输出样例 1
    
    ```
    6
    ```
    
    