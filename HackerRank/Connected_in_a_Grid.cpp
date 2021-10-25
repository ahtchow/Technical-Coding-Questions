#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxRegion' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY grid as parameter.
 */

    /**
    
    Runtime: O(wxh) - must travcerse entire matrix
    Space: O(wxh) - up to wxh DFS recursive calls 
    
    **/
    
struct Coordinate{
    int row;
    int col;
};

int getSizeOfRegion(vector<vector<int>>& grid, const Coordinate location){
    
    /* Boundary Check */
    if (location.row < 0 || location.row >= grid.size() ||
        location.col < 0 || location.col >= grid[0].size() || grid[location.row][location.col] <= 0){
            return 0;
        }
    
    grid[location.row][location.col] = -1;
    int size = 1; 
    
    /* Search 8 Spots, DFS */
    for(int r = location.row-1; r <= location.row+1; r++){
        for(int c = location.col-1; c <= location.col+1; c++){
            if(c == location.col && r == location.row){
                continue;
            }
            size += getSizeOfRegion(grid, Coordinate{r,c});;
        }
    }

    return size;
}


int maxRegion(vector<vector<int>> grid) {

    int max_region_size = 0;
    for(int row = 0; row < grid.size(); row++){
        for(int col = 0; col < grid[0].size(); col++){
            if(grid[row][col] == 1){
                int region_size = getSizeOfRegion(grid, Coordinate{row, col});
                max_region_size = region_size > max_region_size ? region_size : max_region_size;
            }
        
        }
    }
    
    return max_region_size;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> grid(n);

    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
