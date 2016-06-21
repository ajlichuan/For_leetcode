C/C++ Coding Exercise – Power of Three
时间 2016-01-13 01:17:08  HelloACM
原文  https://helloacm.com/cc-coding-exercise-power-of-three-leetcode/
主题 C++
Question: Given an integer, write a function to determine if it is a power of three.

Puzzle URL: https://leetcode.com/problems/power-of-three/

Iterative

If you divide the number iteratively by 3, you will get 1 at the end.

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && (n % 3 == 0)) n /= 3;
        return n == 1;
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && (n % 3 == 0)) n /= 3;
        return n == 1;
    }
};
Alternatively, you can do it from the other direction (multiplication by three each time). But be careful of integer overflow so you have to use unsigned type or a 64-bit integer type e.g. long long .

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        unsigned int x = 1;
        while (x < n) {
            x *= 3;
        }
        return x == n;
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        unsigned int x = 1;
        while (x < n) {
            x *= 3;
        }
        return x == n;
    }
};
Recursion

In the recursion form,

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;
        if ((n == 0) || (n % 3 != 0)) return false;
        return isPowerOfThree(n / 3);
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;
        if ((n == 0) || (n % 3 != 0)) return false;
        return isPowerOfThree(n / 3);
    }
};
Cheating List

Since the input range is type of integer (32-bit signed), therefore, the valid numbers are limited and can be computed in advance. So the task is to check if the given input is in the list. You can do this using Binary Search, Linear Search, or just using hashset (e.g. unordered_set).

#include <unordered_set>
 
class Solution {
public:
    bool isPowerOfThree(int n) {
        std::unordered_set<int> list = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};        
        return list.find(n) != list.end();
    }
};
#include <unordered_set>

class Solution {
public:
    bool isPowerOfThree(int n) {
        std::unordered_set<int> list = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};        
        return list.find(n) != list.end();
    }
};
Math

From above method, we know that the biggest signed-integer (32-bit) that can be divided by 3 is 1162261467. Then we can say the any power-of-three can be divided by this number.

class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0) && (1162261467 % n == 0);
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0) && (1162261467 % n == 0);
    }
};
Log

We know:

Therefore the value of x should be integer.

class Solution {
public:
    bool isPowerOfThree(int n) {
        double x = log(n) / log(3);
        return (n > 0) && (abs(x - (int)(x + 0.5)) < 1e-10);
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
        double x = log(n) / log(3);
        return (n > 0) && (abs(x - (int)(x + 0.5)) < 1e-10);
    }
};
We add +0.5 to x to avoid rounding errors that is because log(243)/log(3) happens to be 4.999999999. Therefore, any math solutions that involve precision errors are not perfect. For example, the following works:

class Solution {
public:
    bool isPowerOfThree(int n) {
        double x = log10(n) / log10(3);
        return (n > 0) && (ceil(x) == floor(x));
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
        double x = log10(n) / log10(3);
        return (n > 0) && (ceil(x) == floor(x));
    }
};
But, if you replace log10 function with log then it will fail the tests because of precision error from the x variable.

If you useJava, you can think of ternary number system. So any valid numbers will be in the form of 1, 10, 100, 1000 etc. Java's Integer.toString can take a second parameter which specifies the number system you want to convert to, in this case, it is radix-3 format. Theregular expression * matches zero or more characters.

public boolean isPowerOfThree(int n) {
    return Integer.toString(n, 3).matches("10*");
}
public boolean isPowerOfThree(int n) {
    return Integer.toString(n, 3).matches("10*");
}
--EOF--