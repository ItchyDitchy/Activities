#include <iostream>
#include <vector>

using namespace std;

bool hasRubble(vector<char> row) {
    for (char c : row)
        if (c == 'X')
            return true;
    return false;
}

int minLasers(vector<vector<char>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (grid[i][j] == 'X')
                if (i > 0 && grid[i - 1][j] == 'X' || j > 0 && grid[i][j-1] == 'X')
                    return -1;

    int lasers = 0;

    for (int i = 0; i < rows; i++)
        if (hasRubble(grid[i]))
            lasers++;

    for (int i = 0; i < cols; i++) {
        vector<char> col;
        for (int j = 0; j < rows; j++)
            col.push_back(grid[i][j]);
        if (hasRubble(col))
            lasers++;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int rows, cols;
        cin >> rows >> cols;

        vector<vector<char>> grid(rows, vector<char>(cols));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> grid[i][j];

        int lasers = minLasers(grid);
        cout << (lasers == -1 ? "FISSION MAILED" : to_string(lasers)) << endl;
    }
}