#include "SubsetCombination.h"
#include <unordered_map>

using namespace std;

long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

long long SubsetCombination(const std::string& s1, const std::string& s2) {
    std::unordered_map<char, int> char_count;
    
    // Count occurrences of each character in s1
    for (char c : s1) {
        if (s2.find(c) != std::string::npos) {  // Only count if char is in s2
            char_count[c]++;
        }
    }
    
    int total_chars = 0;
    long long denominator = 1;
    
    // Calculate total characters and denominator for repeated characters
    for (const auto& pair : char_count) {
        total_chars += pair.second;
        denominator *= factorial(pair.second);
    }
    
    // Calculate permutations
    return factorial(total_chars) / denominator;
}