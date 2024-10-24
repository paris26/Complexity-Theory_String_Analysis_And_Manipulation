#include <string>
#include <iostream>
#include <vector>
#include "SubsetPermutations.h"
#include "isSubset.h"
#include "isSubstring.h"

using namespace std;

void permuteAndCheck(string &S1, const string &S2, const string& S3, int l, int r, 
                     vector<string>& correct, int& totalPermutations);

void SubsetPermutations(string &S1, string &S2, string& S3) {
    int len = S1.length();
    // create a vector to store the permutations
    vector<string> correctPermutations;
    int totalPermutations = 0;

    // Check condition1
    if(!isSubstring(S1, S2)) {
        cout << "Error : S2 not a substring of S1" << endl;
        return;
    }
    // check for condition 2
    if(!isSubset(S1, S3)) {
        cout << "Error : S1 does not contain all characters from S3" << endl;
        return;
    }

    cout << "Starting Permutations: " << endl;
    permuteAndCheck(S1, S2, S3, 0, len-1, correctPermutations, totalPermutations);  

    cout << "\n=== Summary ===\n";
    cout << "Total permutations generated: " << totalPermutations << endl;
    cout << "Number of valid permutations: " << correctPermutations.size() << endl;
   
    if (!correctPermutations.empty()) {
        cout << "\nValid permutations that contain '" << S2 << "' and all characters from '"
             << S3 << "':\n" << endl;
             
        for (size_t i = 0; i < correctPermutations.size(); i++) {
            cout << i + 1 << ". " << correctPermutations[i] << endl;
        }
    }
}

void permuteAndCheck(string &S1, const string &S2, const string& S3, int l, int r, 
                     vector<string>& correct, int& totalPermutations) {
    if(l == r) {
        totalPermutations++;
        cout << "Generated permutation " << totalPermutations << ": " << S1 << endl;
       
        // Check if this permutation contains S2 as substring and all chars from S3
        if (isSubstring(S1, S2) && isSubset(S1, S3)) {
            correct.push_back(S1);
        }
    }
    else {
        // from the position you are
        // till the end of the string
        // swap the characters and permute
        for(int i = l; i <= r; i++) {
            swap(S1[l], S1[i]);
           
            // move to the next index
            permuteAndCheck(S1, S2, S3, l+1, r, correct, totalPermutations);  // Fixed: Added missing parameters
            swap(S1[l], S1[i]);
        }
    }
}