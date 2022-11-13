// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<string.h>
using namespace std;

void print(char** m) {
	for (int i = 0; i < 3; i++) 
		cout << m[i]<<",";
	cout << "\n";
}
int xar(char* x, char* y) {
	int i = 0; while (1) {
		if (!x[i])return 1;
		if (!y[i])return 0;
		i++;
	}
}
int main()
{
	char* m[5];
	for (int i = 0; i < 4; i++) { m[i] = new char[5 - i]; cin >> m[i]; m[4 - i] = 0; }
	print(m);
	
	if(xar(m[0],m[1]))print(m);
	for (int i = 0; i < 2; i++) {
		int Min = i;
		for (int j = i + 1; j < 3; j++) {
			if (m[j] < m[Min]) {
				cout << j<<"\n"; Min = j;
			}
		}
		char* tmp = m[i]; m[i] = m[Min]; m[Min] = tmp;
	}
	
	print(m);
}

