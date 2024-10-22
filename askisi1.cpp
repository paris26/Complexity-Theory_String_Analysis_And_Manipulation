#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include "isSubset.h"
#include "isSubstring.h"
#include "SubsetCombination.h"
#include "removeDuplicates.h"

using namespace std;

void readStrings(string &s1, string &s2, string &s3) {
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    cout << "Enter the third string: ";
    cin >> s3;
}

void printStrings(const string &s1, const string &s2, const string &s3) {
    cout << "First string: " << s1 << endl;
    cout << "Second string: " << s2 << endl;
    cout << "Third string: " << s3 << endl;
}

int main() {
    string S1 = "abababaababab";
    string S2 = "abc";
    string S3 = "abababaa";

    bool s2subset1 = false;

    if(isSubset(S2, S1)){
        cout << "S2 is a subset of S1" << endl;
        s2subset1 = true;
    }else{
        cout << "S2 is not a subset of S1" << endl;
    }


    isSubstring(S1, S3) ? cout << "S3 is a substring of S1" << endl : cout << "S3 is not a substring of S1" << endl;

    if(s2subset1){
        cout << "The number of ways to choose S2 from S1 is: " << SubsetCombination(S1, S2) << endl;
    }else{
        cout << "The number of ways to choose S2 from S1 is: 0 [s2 is not a SUBSET]" << endl;
    }

    return 0;
}