#include "removeDuplicates.h"
#include <string>
#include <unordered_set>
using namespace std;

// Function to remove duplicates from a string
string removeDuplicates(const string &str) {
    unordered_set<char> seen;
    string result;
    for (char ch : str) {
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            result += ch;
        }
    }
    return result;
}