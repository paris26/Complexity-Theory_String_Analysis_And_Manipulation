#include <unordered_set>
#include "isSubset.h"
using namespace std;

bool isSubset(const string &s1, const string &s2) {
    unordered_set<char> set1(s1.begin(), s1.end());

    for (char ch : s2) {
        if (set1.find(ch) == set1.end()) {
            return false;
        }
    }

    return true;
}