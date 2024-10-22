#include "removeDuplicates.h"
#include <string>
#include <unordered_set>
using namespace std;

void removeDuplicates(string& str) {
    if (str.length() < 2) return;
    
    int writePos = 1;
    for (int i = 1; i < str.length(); i++) {
        // Check if current char exists in string[0..writePos-1]
        int j;
        for (j = 0; j < writePos; j++) {
            if (str[i] == str[j])
                break;
        }
        
        // If not found, add it to next position
        if (j == writePos) {
            str[writePos] = str[i];
            writePos++;
        }
    }
    // cut the string up to that position 
    str.resize(writePos);  
}