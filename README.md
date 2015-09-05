**Program**: Different algorithms, data structures implemented as part of the DSA course

**Author**: Anirudh Ravi

**About**:

**Sorting Algorithms - SortingAlgorithms.c**

Implemented the following comparison-based sorting algorithms as functions in a single C file: Bubblesort, Insertion sort, Quick sort, Merge sort

For N (size of input given below), every sorting function is called from main() & the function displays sorting time, where N=100, 1000, 5000, 10000, 25000, 50000, 100000, 500000.

An Excel sheet ("Sorting Algorithms Time Complexity.ods") displays run time of all algorithms as function of N in a single graph.

Dynamically created random arrays of integers are used in the program. For random numbers rand() & srand() are used. All sorting functions get the same array of unsorted numbers as input.

**Sparse Matrix - SparseMatrix.c**

Storing sparse matrix contained in sparsematrix.txt as a linked list and then printing the spare matrix onto the terminal.

**Heap Sort - HeapSort.c**

Implemented Heap sort algorithm using an array to sort 10 & 100 randomly generated integers. 

**Rat in a Maze - RatInAMaze.c**

An NxN maze is in the form of a matrix. This maze has some cells as open and some cells will be closed (obstacles). 

A Rat can move one cell at a time in one of the four directions with following priority: 

First it tries to move to one cell right, if it can’t move right because of obstacle or matrix bound, it tries to go Down, if it can’t move Down also, it tries to move Left, lastly if it can’t move in any of the other directions it tries to move Up. The rat tries to exhaust all these possibilities before backtracking to a path it has come from. So the priority of directional movement is:
```
Right > Down > Left > Up
```

Initially, the Rat is at the top left position i.e. at matrix[0][0]. There’s a way out at the bottom right which the Rat has to reach i.e. position matrix[N-1][N-1]. The rat starts to move one cell at a time from the beginning and its goal is to reach the bottom right position. If the rat finds a dead-end while trying to move and it has exhausted all its movement possibilities, it tries to backtrack upto the last position where it has some options open to move according to its priority order.

This program for the two different 10x10 matrices prints the complete movement of the rat in reaching the exit at bottom right, or prints “No path exists to exit” and shows its movements in the matrix after trying all the movements. If there is a path, the program prints how many times the rat has moved in a cell during the journey. In the matrix, elements with 1 show path open and elements 0 mean it is closed. The output also is in the form of a matrix that shows all the paths the rat has tried. If a cell is in the path taken by the rat, an increment is done by one for each time the rat steps onto the cell.

**Median of Medians - MedianOfMedians.c**

In a list of words, the largest word is defined as the word that comes last if you sort them alphabetically (in dictionary order), 2nd largest word is the word that comes 2nd from the last in the sorted list, and so on. The 2 files involved are random.txt and fruits.txt.

Example: If the Input is guava apple orange papaya mango. The largest word is papaya, the second largest is orange, and so on.

This program implements O(n) median of medians (MoM) algorithm to find the k-th largest word (name) from a list of unsorted words(names). This assumes that the words consist only of small letters. In a loop, it keeps asking the user for the value of 'k' and prints the k-th largest word using the above MoM algorithm, until user wants to exit. 

**Spell Checker using Hashing - SpellChecker.c**

In this program hashing is used to write a simple spell-checker/corrector. The file spell.txt contains N lines with each line of the file containing a pair of a misspelled word and its correct spelling. A hash table of all words from this file is created. Sum of ASCII values of characters of the word modulo 100 is used as the hash function. Each node of the hash table (if not null) contains a pair of the misspelled word and its correct spelling. In case of collisions, chaining is used to create a linked list with each node containing a pair of misspelled word and its correct spelling. 

This program that uses the following method to perform spell check/correction:

1.	Creates the hash-table of spell.txt and displays it on the screen.
2.	Takes inputfile to check/correct as command-line input
3.	Asks the user if he/she wants auto-spell check/correction:
    - If yes, then from the beginning of the input file, reads each word, computes its hash and finds if it is present in the hash table of spell.txt. Corrects the spelling if the word is in spell.txt 
    - Else [the user doesn’t want auto spell-correction]: Reads each word from the input file; 
      -	Compute its hash and find if it is present in the hash table; if there is no match, reads the next word if present and repeat this step
      - If there is a match, then displays the misspelled and correct word pair and asks the user if he/she wants to correct the word; if user says yes, then modifies the word; else leaves the word as it is. Reads next word if present and goes to previous step

**Red Black Tree - RedBlackTree.c**

This program is used to construct a red-black tree from these numbers: 7, 3, 18, 10, 8, 11, 22, 26.

**Closest Pair in a given 2D space using Divide & Conquer - ClosestPair.c**

In a 2D space a set of points (x and y values, assume all integers) are given. Among all the possible pair of points, this program finds the pair with minimum (Euclidian) distance between them in O(n log n) time using Divide & Conquer approach.

**Huffman Coding - HuffmanCoding.c**

This program converts a sentence into Huffman code and then prints the code. It then gets back the original sentence by decoding the Huffman code.
