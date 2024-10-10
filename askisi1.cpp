#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include "isSubset.h"
#include "isSubstring.h"
#include "SubsetCombination.h"

using namespace std;

void readStrings(string &s1, string &s2, string &s3) {
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    cout << "Enter the third string: ";
    cin >> s3;
}

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

// Function to merge two halves
void merge(string &s, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L = s.substr(left, n1);
    string R = s.substr(mid + 1, n2);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            s[k] = L[i];
            i++;
        } else {
            s[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        s[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        s[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform mergesort on a string
void mergesort(string &s, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(s, left, mid);
        mergesort(s, mid + 1, right);
        merge(s, left, mid, right);
    }
}

void CompareFunMergesort(string s1, string s2) {
    // Create temporary copies of the strings
    string temp1 = s1;
    string temp2 = s2;

    // Remove duplicates
    temp1 = removeDuplicates(temp1);
    temp2 = removeDuplicates(temp2);

    // Sort the strings
    mergesort(temp1, 0, temp1.length() - 1);
    mergesort(temp2, 0, temp2.length() - 1);

    // Compare if all symbols of one string exist in the other
    bool allExist = includes(temp1.begin(), temp1.end(), temp2.begin(), temp2.end()) ||
                    includes(temp2.begin(), temp2.end(), temp1.begin(), temp1.end());

    if (allExist) {
        cout << "All symbols of one string exist in the other" << endl;
    } else {
        cout << "Not all symbols of one string exist in the other" << endl;
    }
}

void printStrings(const string &s1, const string &s2, const string &s3) {
    cout << "First string: " << s1 << endl;
    cout << "Second string: " << s2 << endl;
    cout << "Third string: " << s3 << endl;
}

int main() {
    // Create 3 strings
    string S1, S2, S3;

    // Assuming readStrings is a function that reads the strings
    readStrings(S1, S2, S3);

    // Compare S1 and S2
    // CompareFunMergesort(S1, S2);

    // printStrings(S1, S2, S3);

    // cout << "Is S1 a subset of S2? " << (isSubset(S1, S2) ? "Yes" : "No") << endl;
    // cout << "Is S1 a subset of S3? " << (isSubset(S1, S3) ? "Yes" : "No") << endl;

    // cout << "Is S2 a substring of S1? " << (isSubstring(S1, S2) ? "Yes" : "No") << endl;

     cout << "Number of subset combinations: " << SubsetCombination(S1, S2) << endl;


    return 0;
}