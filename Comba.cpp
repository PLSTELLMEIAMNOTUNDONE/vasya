
#include <iostream>
using namespace std; //n- элеметы m- позиции
struct set {
    int n; int m; int** SET;
    set(int x, int y) {
        n = x; m = y;
        SET = new int* [pow(n,m)];
        
        for (int j = 0; j < pow(n, m); j++) {
            SET[j] = new int[m];
            for (int i = 0; i < m; i++) {
                SET[j][i] = 0;
            }
        }
        for (int j = 0; j <  m; j++) for (int i = 0; i < pow(n,m)+1; i++) {
            SET[i][m-1-j] = i%n;
        }
    }
    void Print() {
        for (int i = 0; i < pow(n,m); i++) {
            for (int j = 0; j < m; j++)
                cout << SET[i][j] << "\t";
            cout <<  "\n";
        }
    }
};


int main()
{
    set s(3,2);
    s.Print();
}

