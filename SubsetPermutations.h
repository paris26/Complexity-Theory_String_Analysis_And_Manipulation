// SubsetPermutations.h
#ifndef SUBSET_PERMUTATIONS_H
#define SUBSET_PERMUTATIONS_H

#include <string>
#include <vector>
using namespace std;

void SubsetPermutations(string &S1, string &S2, string& S3);
void permuteAndCheck(string &S1, const string &S2, const string& S3, int l, int r, 
                     vector<string>& correct, int& totalPermutations);

#endif