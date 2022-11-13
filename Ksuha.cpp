// Ksuha.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct coup {
    int f;
    int s;
    coup(int x, int y);
    coup();
};
coup::coup() {}
coup::coup (int x, int y) {
    f = x; s=y;
}


coup* R(int* mass,int sz){
    coup* Ret = new coup[];
    for (int i = 0; i < sz; i++) {
        for (int j = 0;j < sz; j++) {
            if (mass[i] % mass[j] == 0) {
                coup X(mass[i], mass[j]);
            }
        }
    }
}
int main()
{
    int* mass = new int[];
}

