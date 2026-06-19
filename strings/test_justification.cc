#include <bits/stdc++.h>
using namespace std;

//Leetcode 68 : Test Justification

// STEPS:
// 1. Iterate through the elements of the "words" array with a var i.

// 2. initiate a second variable j and set it to i, iintiate a third 
// variable to track the current length of the line.

// 3. using a while loop (and the j variable), check if adding a new word to the current 
// line length alongside tye required number of spaces (1 space for each
// word for now) exceeds the maxWidth. If not, increment the length of the 
// line with the length of the next wird and keep iterating with j.

// 4. Create a string container to store each "processed" line. also create variables
// to store the number if words in each line (by getting the difference between the now 
// increaed j and i), and another to store the number of spaces (by getting the difference)
// between the maxWidth and the length of the line.

// 5. check if theres only one word in the array (i.e j == n) or if the you are at the last 
// line, in which case you should left justify by default and fill the remaining width with spaces.

// 6. else, use variables to store the number of spaces there should be after each word
// (except the last), and another to store the number of extraspaces (which would come
// after each word till it is exhausted).

// 7. Use a for loop to add the current word to the line, and add the number of required spaces
// after it, if there's an extraspace, add it after the word (usually the first word).

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    
    for (int i = 0; i < n; i++) {
        int j = i;
        int currLen = 0;
        
        while (j < n && currLen + words[j].size() + (j-i) <= maxWidth) {
            currLen += words[j].size();
            j++;
        }

        string line = "";
        int num_words = j - i;
        int num_spaces = maxWidth - currLen;

        if (j == n || num_words == 1) {
            for (int k = i; k < j; k++) {
                line += words[k];
                if (k < j - 1) line += " ";
            }
            line += string(maxWidth - line.size(), ' ');
        } else {
            int base_spaces = num_spaces / (num_words - 1);
            int extra_spaces = num_spaces % (num_words - 1);

            for (int k = i; k < j; k++) {
                line += words[k];
                if (k < j - 1) {
                    line += string(base_spaces, ' ');
                    
                    if (extra_spaces > 0) {
                        line += " ";
                        extra_spaces--;
                    }
                }
            }
        }
        result.push_back(line);
        i = j - 1;
    }
    return result;
}

int main() {
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth = 2;

    vector<string> answer = fullJustify(words, maxWidth);
    for (auto val : answer) cout << val << "\n";
    cout << endl;

    return 0;
}