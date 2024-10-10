#include "isSubstring.h"
#include <string>
using namespace std;

bool checkSecondString(const string &s1, const string &s2, int index) {
    for (int i = 0; i < s2.length(); i++) {
        if (s1[i + index] != s2[i]) {
            return false;
        }
    }
    return true;
}

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