#include "isSubstring.h"
#include <string>
using namespace std;

// CHANGED: Added bounds checking for s1
bool checkSecondString(const string &s1, const string &s2, int index) {
    // TODO : Check if there's enough room in s1 to contain s2 starting at index
    if (index + s2.length() > s1.length()) {
        return false;
    }
    
    for (int i = 0; i < s2.length(); i++) {
        if (s1[i + index] != s2[i]) {
            return false;
        }
    }
    return true;
}

bool isSubstring(const string &s1, const string &s2) {
    // if s2 is longer than s1, it cannnot be a substring
    if (s2.length() > s1.length()) return false;
    
    // check for each character in s1 if it is the start of s2
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == s2[0]) {
            if (checkSecondString(s1, s2, i)) return true;
        }
    }
    return false;
}