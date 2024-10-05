#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring s[low..high] is a palindrome
bool checkPal(const string &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

// This function prints the longest palindrome substring
// It also returns the length of the longest palindrome
string longestPalSubstr(string& s) {
  
    // Get length of input string
    int n = s.size();

    // All substrings of length 1 are palindromes
    int maxLen = 1, start = 0;

    // Nested loop to mark start and end index
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          
            // Check if the current substring is 
            // a palindrome
            if (checkPal(s, i, j) && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }

    return s.substr(start, maxLen);
}

// Driver Code
int main() {
    string s = "forgeeksskeegfor";
    cout << longestPalSubstr(s) << endl;
    return 0;
}
