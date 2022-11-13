// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"
#include <vector>
using namespace std;
int binSearch(int L, int R, int target,vector<int> v) {
    int i = (L + R) / 2;
    
    if (v.at(i) == target||L==R)return i;
    if (v.at(i) < target)return binSearch(i+1, R, target, v);
    else return binSearch(L, i, target, v);
}
int searchInsert(vector<int>& nums, int target) {
    int i = binSearch(0, nums.size()-1, target, nums);
    return i +(nums.at(i) < target);
    
}

int main()
{
    vector<int> v = { 1, 4, 5, 7 };
    cout << searchInsert(v, 2);
}


