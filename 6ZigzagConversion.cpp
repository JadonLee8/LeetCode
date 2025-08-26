class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }
        string zigzag = "";
        for (int i = 0; i < s.length(); i+= (numRows - 1) * 2){
            zigzag += s[i];
        }
        for (int row = 2; row < numRows; row++){
            bool toggle = true;
            for (int i = row - 1; i < s.length(); i += (toggle ? (numRows - row) * 2 : (row - 1) * 2)){
                zigzag += s[i];
                if (i != row - 1) toggle = !toggle;
            }
        }
        for (int i = numRows - 1; i < s.length(); i += (numRows - 1) * 2){ 
            zigzag += s[i];
        }
        return zigzag;
    }
    // NOTES after looking at optimal solution
    /*
    - algo looks good, but they used string.reserve to pre reserve the space for the string instead of dynamically allocate it
    -  
    */
};
