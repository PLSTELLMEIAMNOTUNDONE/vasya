#include "iostream"
#include<fstream>
#include"string"
const int lnum = 20;
const int lreis = 5;
const int ltype = 4;
struct aero {
	char num[lnum + 1]; char reis[lreis + 1]; char type[ltype + 1];
private:

};
int comp(const void* arg1, const void* arg2) {
	aero* x1 = (aero*)arg1; aero* x2 = (aero*)arg2;
	int i = 0;
	while (1) {
		char y = x1->num[i]; char z = x2->num[i];
		if (y < z) { return -1; }
		if (y > z) { return 1; }
		i++;
	}
}
int main()
{
	using namespace std;
	const int d = 7;
	aero based[d];
	const int lbuf = 29;
	char buf[lbuf];
	ifstream fin("aero.txt");
	if (!fin) { cout<<"eror"; system(" pause"); }


	for (int k = 0; k < d; k++) {
		for (int j = 0; j < lnum; j++) {
			based[k].num[j] = 0;
		}
	}
	int i = 0;
	while (1) {
		fin.getline(buf, lbuf + 1);
		if (!(*buf)) { break; };
		strncpy_s(based[i].num, buf, lnum);
		based[i].num[lnum] = 0;
		strncpy_s(based[i].type, &buf[lnum + lreis], ltype);
		based[i].type[ltype] = 0;
		strncpy_s(based[i].reis, &buf[lnum], lreis);
		based[i].reis[lreis] = 0;
		++i;

	}
	qsort(based, d, sizeof(aero), comp);
	cout << "!\n";
	for (int k = 0; k < d; k++) {
		cout << based[k].num << "\n";
	}

	char zapros[5];
	cout << "type of plane?\n";
	cin >> zapros;
	int f = 1;
	for (int k = 0; k < d; k++) {
		if (strcmp(zapros, based[k].type) == 0) {
			cout << "punkt:" << based[k].num << "\t"
				<< "reis:" << based[k].reis << "\n";
			f = 0;
		}
	}
	if (f) { cout << "takih ne nashos((\n"; }
	system("pause");
	return 0;
}