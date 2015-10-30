class Solution {
public:
    int get_sum(vector<vector<int> >& board, int x, int y) {
        int s = 0;
        for (int i = x-1; i <= x+1; i++) {
            for (int j = y-1; j <= y+1; j++) {
                s += board[i][j];
            }
        }
        return s;
    }
    void copyOfArray(vector<vector<int> >& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        if (n == 0) {
            return;
        }
        vector<vector<int> > board_t(m + 2, vector<int>(n + 2, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                board_t[i][j] = board[i-1][j-1];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int sum = get_sum(board_t, i, j);
                if (board[i-1][j-1] == 1 && (sum <= 2 || sum >=5)) {
                    board[i-1][j-1] = 0;
                } else if (board[i-1][j-1] == 0 && sum == 3) {
                    board[i-1][j-1] = 1;
                }
            }
        }
    }
    int get_sum(vector<vector<int> > &last, int cur_line, int last_line, vector<vector<int> >& board, int x, int y) {
        int sum = 0;
        for (int j = y-1 ; j <= y+1; j++) {
            if (j >= 0 && j < board[0].size()) {
                sum += last[last_line][j];
            }
        }
        if (y - 1 >= 0) {
            sum += last[cur_line][y - 1];
        }
        if (y + 1 < board[0].size()) {
            sum += board[x][y + 1];
        }
        if (x + 1 < board.size()) {
            for (int j = y-1 ; j <= y+1; j++) {
                if (j >= 0 && j < board[0].size()) {
                    sum += board[x + 1][j];
                }
            }
        }
        return sum + board[x][y];
    }
    void twoHArray(vector<vector<int> >& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        if (n == 0) {
            return;
        }
        vector<vector<int> > last_two(2, vector<int>(n, 0));
        int cur_line = 0, last_line = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = get_sum(last_two, cur_line, last_line, board, i, j);
                last_two[cur_line][j] = board[i][j];
                if (board[i][j] == 1 && (sum <= 2 || sum >=5)) {
                    board[i][j] = 0;
                } else if (board[i][j] == 0 && sum == 3) {
                    board[i][j] = 1;
                }
            }
            swap(cur_line, last_line);
        }
    }
    void noExtraSpace(vector<vector<int> > &board) {
        //set 0->1 with value 2
        //set 1->0 with value 3
        /* Excellent job by @StefanPochmann !! very neat!!! */
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int count = 0;
                for (int I=max(i-1, 0); I<min(i+2, m); ++I) {
                    for (int J=max(j-1, 0); J<min(j+2, n); ++J) {
                        count += board[I][J] & 1;
                    }
                }
                if (count == 3 || count - board[i][j] == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                board[i][j] >>= 1;
    }
    void gameOfLife(vector<vector<int> >& board) {
        /* first method */
        //copyOfArray(board);
        /* second method */
        //twoHArray(board);
        /* third method */
        //O(1) space, just use the board to store the real value using other values
        //at last turn it to be right value
        noExtraSpace(board);
    }
};