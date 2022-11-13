// Application.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;
struct Pstr {
    int low, high, sum;
    Pstr(int x, int y, int z) {
        low = x; high = y; sum = z;
    }
};
void PrintS(Pstr* s) {
    cout << s->low << "\t" << s->high << "\t" << s->sum << "\n";
}
Pstr* MaxMid(int* arr,int low,int high) {
    int mid = floor((high + low) / 2), sum = 0, Lsum = -100000, Rsum = Lsum, Nlow, Nhigh;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > Lsum) {
            Lsum = sum;
            Nlow = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > Rsum) {
            Rsum = sum;
            Nhigh= i;
        }
    }
    Pstr* ret = new Pstr(Nlow, Nhigh, Lsum + Rsum);
    return ret;
}
Pstr* FindMaxStr(int* arr, int low,int high) {
    Pstr* ret = new Pstr(0, 0, 0);
    if (low == high) {
        ret->low = ret->high = low;
        ret->sum = arr[low];
        return ret;
    }
    int mid = floor((high + low) / 2);
    Pstr* Lret = FindMaxStr(arr,  low,  mid);
    Pstr* Rret = FindMaxStr(arr, mid + 1, high);
    Pstr* Sret = MaxMid(arr, low, high);
    if ((Lret->sum >= Rret->sum) && (Lret->sum >= Sret->sum))return Lret;
    else if ((Rret->sum >= Lret->sum) && (Rret->sum >= Sret->sum))return Rret;
    else return Sret;

}
int main()
{
    int arr[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
    int* m = arr;
    PrintS(FindMaxStr(m, 0, 15));
}

