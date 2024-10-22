#include <string>
#include <iostream>
using namespace std;

//This function prints recursively all possible combinations of characters in a string
void printCombinations(const string& chars, string current = "", int index = 0) {
    if (index == chars.length()) {
        if (!current.empty()) {
            cout << current << endl;
        }
        return;
    }
    
    // Include current character
    printCombinations(chars, current + chars[index], index + 1);
    // Exclude current character
    printCombinations(chars, current, index + 1);
}

// Helper function to remove duplicates from a string
string removal(const string& str) {
    string result;
    for (char c : str) {
        bool found = false;
        for (char existing : result) {
            if (c == existing) {
                found = true;
                break;
            }
        }
        if (!found) {
            result += c;
        }
    }
    return result;
}

// Main function that prints combinations and returns count
long long SubsetCombination(const string& s1, const string& s2) {
    // Get common characters between s1 and s2
    string common_chars;
    for (char c : s1) {
        bool found = false;
        for (char s2_char : s2) {
            if (c == s2_char) {
                found = true;
                break;
            }
        }
        if (found) {
            common_chars += c;
        }
    }
    
    // Remove duplicates from common characters
    common_chars = removal(common_chars);
    
    // Print all combinations
    cout << "Combinations:" << endl;
    printCombinations(common_chars);
    
    // Calculate count using bit shifting (2^n - 1)
    return (1LL << common_chars.length()) - 1;
}