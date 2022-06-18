#include <bits/stdc++.h>
using namespace std;

using row_t = vector<bool>;
using grid_t = vector<row_t>;

bool is_ok(const grid_t &grid, int p, int q) {
  for(int i = p-1, j = q-1; i >= 0 && j >= 0; --i, --j) {
    if(grid[i][j]) {
      return false;
    }
  }

  for(int i = p+1, j = q+1;  
      i < grid.size() && j < grid[i].size(); ++i, ++j) {
    if(grid[i][j]) {
      return false;
    }
  }

  for(int i = p-1, j = q+1; i >= 0 && j < grid[i].size();
      --i, ++j) {
    if(grid[i][j]) {
      return false;
    }
  }

  for(int i = p+1, j = q+1; 
      i < grid.size() && j < grid[i].size(); ++i, ++j) {
    if(grid[i][j]) {
      return false;
    }
  }
  return true;
}

void dfs(int p, int q, int k, 
         grid_t &grid, int &cnt, 
         int &total_cnt) {
  if(q == grid.size()) {
    q = 0;
    ++p;
  }

  for(int i = p; i < grid.size(); ++i) {
    for(int j = q; j < grid[i].size(); ++j) {
      grid[i][j] = true;
      if(is_ok(grid, i, j)) {
        ++cnt;
        if(cnt == k) {
          ++total_cnt;
        } else {
          dfs(i, j+1, k, grid, cnt, total_cnt);
        }
        --cnt;        
      }
      grid[i][j] = false;
    }
    q = 0;
  }
}

int main() {
  while(true) {
    int n, k;
    cin >> n >> k;
    if(n == 0 && k == 0) {
      break;
    }

    grid_t grid(n, row_t(n, false));
    int cnt = 0;
    int total_cnt = 0;
    dfs(0,0, k, grid, cnt, total_cnt);
    cout << total_cnt << "\n";
  }
  return 0;
}