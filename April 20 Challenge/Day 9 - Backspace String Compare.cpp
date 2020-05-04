/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. 
# means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int lenS = S.length()-1, lenT = T.length()-1;
        int i, j, toDel = 0;        
        
        /* Travel backwards in both the strings */
        for((i = lenS, j = lenT) ; (i >= 0 || j >= 0) ; i--,j--){        
            /* String S, travel backwards till ###.. */ 
            for(toDel = 0; i >= 0 && (toDel > 0 || S[i] == '#'); i--)
                (S[i] == '#') ? toDel++ : toDel--;

            /* String T, travel backwards till ###.. */ 
            for(toDel = 0; j >= 0 && (toDel > 0 || T[j] == '#'); j--)
                (T[j] == '#') ? toDel++ : toDel--;
            
            if(i < 0 || j < 0)
                return i==j;
            
            if(S[i] != T[j])
                return false;
        }
        return true;
    }
};