// isSubset.cpp
#include <unordered_set>
#include "isSubset.h"
#include "removeDuplicates.h"
#include <iostream>
using namespace std;

// CHANGED: Fixed the logical error in isSubset implementation
// Now correctly checks if s1 contains all elements of s2
bool isSubset(const string &s1, const string &s2) {
    
    //store the 2 strings in copies
    string s1_no_duplicates = s1;
    string s2_no_duplicates = s2;

    // Remove duplicates from the strings    
    removeDuplicates(s1_no_duplicates);
    removeDuplicates(s2_no_duplicates);

    // TODO: Revers the loop to check fot s1 contains all elements of s2
    for (char c2 : s2_no_duplicates) {
        bool found = false;
        // when you find the character in s1, set found to true
        // and break
        for (char c1 : s1_no_duplicates) {
            if (c2 == c1) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}