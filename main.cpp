#include <iostream>
#include <string>
#include <algorithm>
#include "isSubset.h"
#include "isSubstring.h"
#include "SubsetCombination.h"
#include "removeDuplicates.h"
#include "SubsetPermutations.h"

using namespace std;

int main() {
    string S1, S2, S_prime;
    
    // Test values
    S1 = "abcab";     // Short main string
    S2 = "abc";       // Short substring to find
    S_prime = "ab";   // Just two required symbols             // Required symbols
    
    // Print initial values
    cout << "Initial strings:" << endl;
    cout << "S1: " << S1 << endl;
    cout << "S2: " << S2 << endl;
    cout << "S': " << S_prime << endl;

    // First check if S2 contains all symbols from S_prime
    if(!isSubset(S2, S_prime)) {
        cout << "Error: S2 doesn't contain all required symbols from S'" << endl;
        return 1;
    }

    // Then check if S1 contains S2
    if(!isSubstring(S1, S2)) {
        cout << "Error: S2 is not a substring of S1" << endl;
        return 1;
    }

    // If both conditions are met, find all valid substrings
    cout << "\nFinding all valid substrings..." << endl;
    SubsetCombination(S1, S2, S_prime);

    // Now find all valid permutations
    cout << "\nFinding all valid permutations..." << endl;
    SubsetPermutations(S1, S2, S_prime);

    return 0;
}