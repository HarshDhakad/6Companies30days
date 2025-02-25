//Back-end complete function Template for C++
class Solution {
  public:
    string st;

    // Function to print the parenthesis of matrix chain multiplication
    void printParenthesis(int i, int j, int n, vector<vector<int>> &bracket,
                          char &name) {
        // If i and j are equal, it means only one matrix is remaining
        if (i == j) {
            st += name; // add the name of matrix to the string
            name++;     // increment the name for the next matrix
            return;
        }
        st += '('; // add '(' to the string
        printParenthesis(
            i, bracket[i][j], n, bracket,
            name); // recursively print the parenthesis for the left side of the split
        printParenthesis(
            bracket[i][j] + 1, j, n, bracket,
            name); // recursively print the parenthesis for the right side of the split
        st += ')'; // add ')' to the string
    }

    // Function to calculate the minimum number of operations needed to multiply the
    // matrices
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> m(
            n, vector<int>(
                   n)); // create a 2D array to store the minimum number of operations
        vector<vector<int>> bracket(
            n, vector<int>(n)); // create a 2D array to store the split position for
                                // each matrix multiplication
        for (int i = 1; i < n; i++)
            m[i][i] = 0;              // initialize the diagonal elements to 0
        for (int L = 2; L < n; L++) { // iterate over the lengths of the sequences
            for (int i = 1; i < n - L + 1;
                 i++) {            // iterate over the starting indices of the sequences
                int j = i + L - 1; // calculate the ending index of the sequence
                m[i][j] = INT_MAX; // set the minimum number of operations to a large
                                   // value at first
                for (int k = i; k <= j - 1;
                     k++) { // iterate over possible split positions
                    int q = m[i][k] + m[k + 1][j] +
                            arr[i - 1] * arr[k] *
                                arr[j]; // calculate the number of operations needed for
                                        // this split
                    if (q < m[i][j]) {  // if this split has less operations than the
                                        // current minimum, update the values
                        m[i][j] = q;
                        bracket[i][j] = k;
                    }
                }
            }
        }
        char name = 'A'; // initialize the name of the matrices
        printParenthesis(1, n - 1, n, bracket,
                         name); // call the function to print the parenthesis
        return st;              // return the string containing the parenthesis
    }
};
