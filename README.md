# String Analysis and Manipulation Project

This C++ project implements various string analysis and manipulation algorithms, focusing on substring relationships, permutations, and combinations. The project provides functionality to analyze relationships between strings and find valid subsets and permutations based on specific criteria.

## Core Functionality

The project implements several key features:
- Checking if one string is a subset of another
- Verifying substring relationships
- Finding valid substring combinations
- Generating and validating string permutations
- Removing duplicate characters from strings

## Project Structure

### Main Components

- **main.cpp**
  - Contains the program entry point
  - Demonstrates usage of core functionalities
  - Handles test cases with example strings (S1, S2, S_prime)

### String Analysis Modules

#### Subset Operations
- **isSubset.h/cpp**
  - Implements subset checking functionality
  - Verifies if all characters from one string exist in another
  - Uses duplicate removal for accurate comparison

#### Substring Operations
- **isSubstring.h/cpp**
  - Provides substring verification functionality
  - Implements efficient substring checking with bounds validation
  - Helper function `checkSecondString` for detailed comparison

#### String Manipulation
- **removeDuplicates.h/cpp**
  - Removes duplicate characters from strings
  - In-place algorithm for memory efficiency
  - Preserves original character order

#### Advanced String Operations
- **SubsetCombination.h/cpp**
  - Finds all valid subsets meeting specific criteria
  - Checks for both substring and required character conditions
  - Provides count of valid combinations

- **SubsetPermutations.h/cpp**
  - Generates all possible permutations of input strings
  - Validates permutations against specific conditions
  - Provides detailed output of valid permutations

## Usage Example

```cpp
string S1 = "abcab";     // Main string
string S2 = "abc";       // Substring to find
string S_prime = "ab";   // Required symbols

// Check if S2 contains all required symbols
if(isSubset(S2, S_prime)) {
    // Check if S1 contains S2
    if(isSubstring(S1, S2)) {
        // Find valid combinations and permutations
        SubsetCombination(S1, S2, S_prime);
        SubsetPermutations(S1, S2, S_prime);
    }
}
```

## Requirements

- C++ compiler with C++11 support or later
- Standard Template Library (STL)

## Implementation Details

### Key Algorithms

1. **Subset Checking**
   - Uses character-by-character comparison
   - Removes duplicates before comparison
   - O(n*m) time complexity where n and m are string lengths

2. **Substring Verification**
   - Implements efficient substring searching
   - Includes bounds checking for safety
   - O(n*m) time complexity for worst case

3. **Duplicate Removal**
   - In-place algorithm
   - Preserves original character order
   - O(n) time complexity

4. **Permutation Generation**
   - Recursive implementation
   - Generates all possible arrangements
   - Validates against substring and subset conditions

### Error Handling

The program includes various error checks:
- Validation of string lengths
- Verification of required character presence
- Bounds checking in substring operations

## Build and Run

Compile all source files together:
```bash
g++ *.cpp -o string_analysis
./string_analysis
```