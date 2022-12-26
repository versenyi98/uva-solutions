| ID | UVa Online Judge | External | Link to solution |
|:---|:---|:---|:---:|
| 12720 | [Algorithm of Phil](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=823&page=show_problem&problem=4572) | [PDF](https://onlinejudge.org/external/127/12720.pdf) | [Solution](https://github.com/versenyi98/uva-solutions/tree/main/solutions/12720%20-%20Algorithm%20of%20Phil)|
Erase from the middle of the string causes TLE. Indexing the end of the first bit and the start of the second bit is faster. String is: [0..index_of_end][deleted part][index_of_start..n-1]
