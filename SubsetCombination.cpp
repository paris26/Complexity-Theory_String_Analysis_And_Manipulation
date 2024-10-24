// builtin libraries
#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

// include my libraries 
#include "SubsetCombination.h"
#include "isSubset.h"
#include "isSubstring.h"

void SubsetCombination(const string& S1, const string& S2, const string& S3 ){
    // counter to store number of valid strings
    int counter = 0;
    // length of S1 to iterate over
    int n = S1.length();

    // create a set to store all the characters of S3
    // for faster lookup times
    unordered_set<char> required(S3.begin(), S3.end());

    // in this function we search for subsets
    cout << "Correct Subsets are: " << endl;

    //first for loop will go over all the elements of S1
    for( int end=0; end <= n; end++){
        // this is because we got look (n-index) length substrings
        // because there are only n-index available 
        for( int start=0; start<=n-end; start++){
            // we take in each iteration a smaller substring
            // of S1 and check if it is a subset of S2
            string subToCheck = S1.substr(start, end);

            // Check two conditions:
            // 1. subToCheck contains S2 as a substring
            // 2. subToCheck contains all characters from s_prime
            if(isSubstring(subToCheck, S2) && isSubset(subToCheck, S3)) {
                cout << subToCheck << endl;
                counter++;  
        }
    }

    cout << "Number of correct subsets: " << counter << endl;

}
}
