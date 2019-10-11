//Дано число N. Определите, сколькими способами можно расставить на доске N×N N ферзей, не бьющих друг друга.
//
//Формат входных данных
//        Задано единственное число N. (N ≤ 10)
//
//Формат выходных данных
//        Выведите ответ на задачу.
//Подсказка
//        Напишите рекурсивную функцию, которая пытается поставить ферзя в очередной столбец. 
// Если на эту клетку ставить ферзя нельзя (он бьет предыдущих), 
// то такой вариант даже не стоит рассматривать. 
// Когда вы успешно поставили ферзя в последний столбец - увеличивайте счетчик.
//Sample Input:
//
//8
//Sample Output:
//
//92

#include <iostream>
#include <vector>

using namespace std;
int queen(int, int, int, int [10][10]);

int queen(int c, int s, int n, int a[10][10]) {
    if (c == -1) {
        return s;
    }
    if (c < n) {
        for (int l = 0; l < n; l++) {
            for (int i = 0; i < c; i++) {
                int j = 0;
                while (a[i][j] != 1) {
                    j++;
                }
                int dx = l - j;
                int dy = c - i;
                if (dx * dx == dy * dy | l == j) {
                    a[c][l] = 2;
                }
            }
        }
        int l = 0;
        while (a[c][l] != 0 && l < n) {
            l++;
        }
        if (a[c][l] == 0) {
            a[c][l] = 1;
            c++;
            queen(c, s, n, a);
        } else {
            for (int l = 0; l < n; l++)
                a[c][l] = 0;
            c--;
            int j = 0;
            while (a[c][j] != 1 && j < n) {
                j++;
            }
            if (a[c][j] == 1) {
                a[c][j] = 2;
                queen(c, s, n, a);
            } else
                return s;
        }
    } else {
        s++;
        c--;
        int j = 0;
        while (a[c][j] != 1) {
            j++;
        }
        a[c][j] = 2;
        queen(c, s, n, a);
    }
}

int t08_queen() {
    int c = 0;
    int s = 0;
    int n;
    int a[10][10] = {{3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                     {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                     {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                     {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                     {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                     {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                     {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                     {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                     {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                     {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}};
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    cout << queen(c, s, n, a);
    return 0;
}