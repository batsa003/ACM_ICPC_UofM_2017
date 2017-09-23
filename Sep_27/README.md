### Binary Search

Reading: https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/

Pseudocode:
The following is the way how I write a binary search. It is easy to memorize, and the base case is simple to check.

```
binary_search(low, high, p):
    // A more general approach of binary search:
    // Given a function p(x) which tells that if condition at index x is true and a range (low, high)
    // We are trying to find the smallest index i such that p(i) is true. (p(i-1) is false)
    // p(i) could be as simple as whether a number at index i is equal to X, or a complicated one.
    1. Make sure p(hi) is true. If you're not sure, choose hi big enough depending on the problem.
    2. Make sure p(low) is false.
    3. Make sure low < high

    while low + 1 < high:
        mid = low + (high-low)/2
        if p(mid) == true:
            high = mid
        else:
            low = mid
    return lo         // lo is the least x for which p(x) is true
    // At the end of the loop, low + 1 = high. 
    // It is useful to think of the pointers low and high as follows:
    // p(x) is false for x <= low, and p(x) is true for x >= high.
```
