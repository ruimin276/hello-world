#include <bits/stdc++.h>
using namespace std;

int a[10][10]=
{
    {},
    {0,1,0,0,6,0,0,0,0},
    {0,0,0,0,4,0,0,2,0},
    {0,4,0,0,0,0,3,1,0},
    {0,0,5,0,0,0,6,0,0},
    {0,0,0,4,8,0,0,0,3},
    {0,0,0,0,0,5,0,0,0},
    {0,0,6,0,3,1,0,0,0},
    {0,0,0,0,0,8,5,0,2},
};

bool availability(int x, int y, int n)
{
    for(int i = 1; i <= 8; i++)
    {
        if(a[x][i] == n || a[i][y] == n)
            return 0;
    }
    if(x == y)
    {
        for(int i = 1; i <= 8; i++)
        {
            if(a[i][i] == n)
                return 0;
        }
    }
    if(x == 9 - y)
    {
        for(int i = 1; i <= 8; i++)
        {
            if(a[i][9 - i] == n)
                return 0;
        }
    }
    return 1;
}

void dosudoku(int x, int y);

void donext(int x, int y)
{
    if(x == 8 && y == 8)
    {
        for(int i = 1; i <= 8; i++)
        {
            for(int j = 1; j <= 8; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
        return;
    }
    if(y == 8)
        dosudoku(x + 1, 1);
    else
        dosudoku(x, y + 1);
}

void dosudoku(int x, int y)
{
    if(a[x][y] == 0)
    {
        for(int n = 1; n <= 8; n++)
        {
            if(availability(x, y, n))
            {
                a[x][y] = n;
                donext(x, y);
                a[x][y] = 0;
            }
        }
    }
    else
    {
        donext(x, y);
    }
}

int main()
{
    dosudoku(1, 1);
}
