### Binary Search

https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/

Pseudocode:
The following is the way how I write a binary search. It is easy to memorize, and the base case is simple to check.

```
binary_search(low, high, p):
    // A more general approach of binary search:
    // Given: 
    //  - Function p(x) which tells that if condition at index x is true
    //  - Range (low, high)
    // Output:
    //  - Smallest index i such that p(i) is true. (p(i-1) is false)

    // p(i) could be as simple as whether a number at index i is equal to X, or a complicated one.

    1. Make sure p(hi) is true. If you're not sure, choose hi big enough depending on the problem.
    2. Make sure p(low) is false.
    3. Make sure low < high
    // It is useful to think of the pointers low and high as follows:
    // p(x) is false for x <= low, and p(x) is true for x >= high.
    while low + 1 < high:
        mid = low + (high-low)/2
        if p(mid) == true:
            high = mid
        else:
            low = mid
    return lo         // lo is the least x for which p(x) is true

    // At the end of the loop, low + 1 = high. 
```

### Binomial Coefficients
Understand binomial coefficients, what they are, and how to compute them. 
http://www.csl.mtu.edu/cs4321/www/Lectures/Lecture%2015%20-%20Dynamic%20Programming%20Binomial%20Coefficients.htm

To evaluate n choose k, they use C[i, j] = C[i-1, j-1] + C[i-1, j] identity.
Understand how does the Algorithm Binomial(n,k) works.

### Basic Probability and Expected Value.

You can read this until NestedRandomness problem:
https://www.topcoder.com/community/data-science/data-science-tutorials/understanding-probabilities/

### Number Theory.

1. Know about greatest common divisor. The following is a pseudocode for computing gcd of two numbers using Eucledian algorithm.
```
int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
}
```

2. Know about Sieve of Eratosthenes. Useful algorithm to know.
http://www.geeksforgeeks.org/sieve-of-eratosthenes/

3. (Optional) Having templates for Chinese Remainder Theorem, Extended Eucledian Algorithm, and Multiplicative inverse could be useful.

### Fast Exponentiation.

Refer to http://web.stanford.edu/class/cs97si/02-mathematics.pdf

Recursive version:
```
double pow(double a, int n) {
    if(n == 0) return 1;
    if(n == 1) return a;
    double t = pow(a, n/2);
    return t * t * pow(a, n%2);
}
```

Iterative version:
```
double pow(double a, int n) {
    double ret = 1;
    while(n) {
        if(n%2 == 1) ret *= a;
        a *= a; n /= 2;
    }
    return ret;
}
```
Intuition: Say, n = 11 = 2^3 + 2^1 + 2^0. Then, a^n = a^(2^3) * a^(2^1) * a^(2^0).
The line n%2 == 1 is checking the last bit of the binary representation of n. n /= 2 basically cuts of the last bit.

### Divide and Conquer:
Familiarize yourself with the basic idea of Divide and Conquer:
http://www.geeksforgeeks.org/divide-and-conquer-introduction/
