#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int W, H;
int Maze[300][300];
struct point_type{
    int i;
    int j;
};
void Write_Maze(char line[], int i)
{
    for (int j = 0; line[j]; ++j) {
        int ii = i * 3, jj = j * 3;
        for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 3; ++y)
                Maze[ii+x][jj+y] = 0;
        if (line[j] == '\\') {
            Maze[ii][jj] = 1;
            Maze[ii+1][jj+1] = 1;
            Maze[ii+2][jj+2] = 1;
        }
        else {
            Maze[ii][jj+2] = 1;
            Maze[ii+1][jj+1] = 1;
            Maze[ii+2][jj] = 1;
        }
    }
}
const int direction[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool Run_Maze(int i, int j, int &longest)
{
    queue<point_type> Q;
    Q.push({i,j});
    int length = 1;
    bool isCycle = 1;
    point_type cur, nxt;
    while (!Q.empty()) {
        length++;
        cur = Q.front();
        Q.pop();

        for (int x = 0; x < 4; ++x) {
            nxt.i = cur.i + direction[x][0];
            nxt.j = cur.j + direction[x][1];
            if (nxt.i < 0 || nxt.j < 0 || nxt.i >= H || nxt.j >= W) {
                isCycle = 0;
                continue;
            }
            if (Maze[nxt.i][nxt.j] == 0) {
                Maze[nxt.i][nxt.j] = 1;
                Q.push(nxt);
            }
        }
    }
    if (isCycle == 0) return 0;
    length /= 3;
    if (longest < length) longest = length;
    return 1;
}
int main()
{
 //   freopen("input.txt","rt",stdin);
    int Case = 1;
    char line[100];
    while (scanf("%d %d", &W, &H) && (W || H)) {
        for (int i = 0; i < H; ++i){
            scanf("%s", line);
            Write_Maze(line, i);
        }
        H *= 3;
        W *= 3;
        int numOfCycles = 0;
        int longest = 0;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (Maze[i][j] == 0)
                    if (Run_Maze(i, j, longest))
                        numOfCycles++;
        printf("Maze #%d:\n", Case++);
        if (numOfCycles)
            printf("%d Cycles; the longest has length %d.\n\n", numOfCycles, longest);
        else printf("There are no cycles.\n\n");
    }
}

/*
6 4
\//\\/
\///\/
//\\/\
\/\///
3 3
///
\//
\\\
2 2
/\
\/
0 0
*/