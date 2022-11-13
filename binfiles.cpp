#include <iostream>
#include <cstring>
#include <cstdlib>
#include<fstream>

using namespace std;
const int lbuf = 64, model_z = 32, price_z = 6, size_z = 6, oprt_z = 4, depth_z = 3; 

struct scan {
char model[model_z+1]; // наименование модели
int price;      // цена
double x_size;  // горизонтальный размер области сканирования
double y_size;  // вертикальный размер области сканирования
int x_optr;     // оптическое разрешение по горизонтали
int y_optr;     // оптическое разрешение по вертикали
int depth;      // глубина цвета
};
int price_compar(const void* arg1, const void* arg2) { //сортирую по возрастанию цены
	scan* x1 = (scan*)arg1; scan* x2 = (scan*)arg2;
	int y = x1->price; int z = x2->price;
	if (y < z) { return -1; }
	if (y >= z) { return 1; }
}
void funce1(const char* filename, scan x[], short n) { // функция записывает n структур из массива x в бинарный файл
	ofstream outF(filename, ios::out | ios::binary);
	if (!outF) { cout << "eror";  }
	
	outF.write((char*)&n, sizeof(short));

	for (int i = 0; i < 8; i++)
		outF.write((char*)&(x[i]), sizeof(scan));	
	outF.close();
}
void funce2(const char* filename, scan x[], int f(const void*,const void*)) { //функцияя читает в массив x все структуры из бинарного файла и сортирует его
	
	ifstream inF(filename, ios::in | ios::binary);
	if (!inF) { cout << "eror"; }
	short n2;
	inF.read((char*)&n2, sizeof(short));
	
	for (int i = 0; i < n2; i++)
		inF.read((char*)&(x[i]), sizeof(scan));
	inF.close(); 
	qsort(x, n2, sizeof(scan), f);
}


int main() {
	scan based[8]; 
	char buf[lbuf];
	ifstream fin("scan.txt"); //считываем  из текстового файла  структуры в массив  
	if (!fin) { cout << "eror";  }
	int i = 0;
	while (1) {
		int x = 0;
		fin.getline(buf, lbuf + 1);
		if (!(*buf))break;
		strncpy_s(based[i].model, &buf[x], model_z);
		based[i].model[32] = 0; x += model_z;
		char bufer[100]; // сюда будем считывать файл, а в структуру записывать данные преобразованные в нужный тип
		strncpy_s(bufer, &buf[x], price_z);
		based[i].price = atoi(bufer); x += price_z;
		strncpy_s(bufer, &buf[x], size_z);
		based[i].x_size = atof(bufer); x += size_z+1; //+1 чтобы не читать х
		strncpy_s(bufer, &buf[x], size_z);
		based[i].y_size = atof(bufer); x += size_z;
		strncpy_s(bufer, &buf[x], oprt_z);
		based[i].x_optr = atoi(bufer); x += oprt_z+1;
		strncpy_s(bufer, &buf[x], oprt_z);
		based[i].y_optr = atoi(bufer); x += oprt_z;
		strncpy_s(bufer, &buf[x], depth_z);
		based[i].depth = atoi(bufer);
		cout << based[i].model<<"\t";
		cout << based[i].price << "\t"; 
		cout << based[i].x_size << "\t";
		cout << based[i].y_size << "\t";
		cout << based[i].x_optr << "\t";
		cout << based[i].y_optr << "\t";
		cout << based[i].depth << "\n"; // для наглядности просто вывожу начальные данные
		++i;
		
	}
	
	scan ans[8]; 
	short n = sizeof(based) / sizeof(scan);
	funce1("out.txt", based,n); //записали данные из массива в бинарный файл 
	
	funce2("out.txt", ans,price_compar); //считали данные в другой массив из бинарного файла и отсортировали его
	short n2 = sizeof(ans) / sizeof(scan); 
	funce1("out.txt", ans,n2);//записали отсортированные данные в файл
	cout << "------------\n";
	for (int i = 0; i < n2; i++) {
		cout << ans[i].model << "\t";
		cout << ans[i].price << "\t";
		cout << ans[i].x_size << "\t";
		cout << ans[i].y_size << "\t";
		cout << ans[i].x_optr << "\t";
		cout << ans[i].y_optr << "\t";
		cout << ans[i].depth << "\n";
	} // для наглядности вывожу записанный в конце массив
	puts("final\n");
	
	
	return 0;
}