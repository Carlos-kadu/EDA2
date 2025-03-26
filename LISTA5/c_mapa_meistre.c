
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char str[101][101];
int dis[101][101];
int x;

void dfs(int i, int j, int dir) {
    if (i == n || i == -1 || j == m || j == -1) {
        printf("!\n");
        exit(0);
    }
    if (dis[i][j]) {
        printf("!\n");
        exit(0);
    }
    dis[i][j] = 1;

    if (str[i][j] == '*') {
        printf("*\n");
        exit(0);
    }
    if (str[i][j] == '.') {
        if (dir == 1) {
            dfs(i + 1, j, 1);
        }
        if (dir == 3) {
            dfs(i - 1, j, 3);
        }
        if (dir == 2) {
            dfs(i, j + 1, 2);
        }
        if (dir == 4) {
            dfs(i, j - 1, 4);
        }
    }
    if (str[i][j] == '>') {
        dfs(i, j + 1, 2);
    }
    if (str[i][j] == '<') {
        dfs(i, j - 1, 4);
    }
    if (str[i][j] == 'v') {
        dfs(i + 1, j, 1);
    }
    if (str[i][j] == '^') {
        dfs(i - 1, j, 3);
    }
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    if (str[0][0] == '.') {
        printf("!\n");
        return 0;
    }
    if (str[0][0] == '*') {
        printf("*\n");
        return 0;
    }
    if (str[0][0] == '>') {
        x = 2;
    }
    if (str[0][0] == '<') {
        x = 4;
    }
    if (str[0][0] == 'v') {
        x = 1;
    }
    if (str[0][0] == '^') {
        x = 3;
    }

    dfs(0, 0, x);

    printf("!\n");

    return 0;
}
