#include "isSubstring.h"
#include <string>
using namespace std;

// checks all the remaining elements
// so that the 2 strings are equal
bool checkSecondString(const string &s1, const string &s2, int index) {
    for (int i = 0; i < s2.length(); i++) {
        if (s1[i + index] != s2[i]) {
            return false;
        }
    }
    return true;
}

// we use a function to check for the first element 
// of the second string in the first string
// if we find it we loop for all the next elements in both
bool isSubstring(const string &s1, const string &s2) {
    // we know that if s2 is bigger than s1 to immediately return false
    if (s2.length() > s1.length()) return false;
    

    for (int i = 0; i <= s1.length(); i++) {
        if (s1[i] == s2[0]) {
            if (checkSecondString(s1, s2, i)) return true;
        }
    }
    return false;
}