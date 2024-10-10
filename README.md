# Complexity Theory

This project contains a set of C++ programs and functions related to string manipulation and comparison. The main functionalities include reading strings, removing duplicates, sorting strings using merge sort, comparing strings, and checking if one string is a subset of another.

## Files

### `askisi1.cpp`

This file contains the main logic of the program, including the following functions:

- **`readStrings`**: Reads three strings from the user.
- **`removeDuplicates`**: Removes duplicate characters from a string.
- **`merge`**: Merges two halves of a string during the merge sort process.
- **`mergesort`**: Sorts a string using the merge sort algorithm.
- **`CompareFunMergesort`**: Compares two strings after removing duplicates and sorting them.
- **`printStrings`**: Prints three strings.
- **`main`**: The main function that orchestrates the reading, processing, and comparison of strings.

### `isSubset.h`

This header file declares the `isSubset` function, which checks if one string is a subset of another.

### `isSubset.cpp`

This file contains the implementation of the `isSubset` function, which uses an unordered set to determine if all characters of one string are present in another string.

### `isSubstring.h`

This header file is included in `askisi1.cpp` but is not detailed in the provided context. It likely declares a function related to substring operations.

## Functions

### `readStrings`

```cpp
void readStrings(string &s1, string &s2, string &s3);