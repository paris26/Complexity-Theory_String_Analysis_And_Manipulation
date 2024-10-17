#include <unordered_set>
#include "isSubset.h"
#include "removeDuplicates.h"
using namespace std;


// in this function we want to check if all the elements of s2 are in s1
// 1) do not care about the order they are in
// 2) do not care about the number of times they appear
bool isSubset(const string &s1, const string &s2) {
    // Remove duplicates from the strings
    string s1_no_duplicates = removeDuplicates(s1);
    string s2_no_duplicates = removeDuplicates(s2);

    // iterate over each character of s2
    for (char c2 : s2_no_duplicates) {
        // create boolean value to store if the character is found
        bool found = false;
        //loop over elements in s1
        for (char c1 : s1_no_duplicates) {
            if (c2 == c1) {
                found = true;
                break;
            }
        }
        // if found is false then return false
        if (!found) {
            return false;
        }
    }
    return true;
}