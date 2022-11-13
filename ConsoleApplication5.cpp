
//Пользователь вводит коэфиценты полинома, его порядок, точность и границы интервала
//прога выводит промежуточые значение x(j) f(j) и ответ
using namespace std;
#include <iostream>
void printer(double* m, int rank) { // да, rank через k :)

    for (int i = 0; i < rank; i++) cout << "(" << m[i] << "x^" << rank - i << ")" << "+";
    cout << m[rank] << endl;
}

double* koefCreator(int rank) {
    double* koef = new double[rank + 1];
    for (int i = 0; i < rank + 1; i++) {
        cout << "enter  " << i << "  koef\n"; // коэфиценты создаются и храняться в массиве в порядке справа-налево
        // т.е. koef[0]=a0;koef[1]=a1 для полинома вида a0 * x^n +a1 *x^n-1... и так далее
        double x;
        cin >> x;
        koef[i] = x;
    }
    printer(koef, rank);
    return koef;
}

double  funCounter(double* m, int rank, double  x) {
    double  ans = 0;
    for (int i = 0; i < rank + 1; ++i) ans += m[i] * pow(x, rank - i);
    return ans;
}
double* ProdKoefCreator(double* m, int rank) {
    double* ProdKoef = new double[rank];
    for (int i = 0; i < rank; i++) {
        ProdKoef[i] = m[i] * (rank - i);
    }

    return ProdKoef;
}
double ChekRoot(int rank, double edgeNegativ, double edgePositiv, double* kf)
{
    for (;;)
    {
        double x = 0.5 * (edgeNegativ + edgePositiv);
        if (x == edgeNegativ || x == edgePositiv)return x; // простой бинарный поиск корня на отрезке
        if (funCounter(kf, rank, x) < 0)edgeNegativ = x; //работает корректно так как мы не обязаны искать все корни
        else edgePositiv = x;
    }
}
double Approx(double* m, double a, double b, double acc, int rank) {

    if ((funCounter(m, rank, a) * funCounter(m, rank, b)) > 0) { cout << "mod error\n"; return 0; }
    double x, * m1 = ProdKoefCreator(m, rank), * m2 = ProdKoefCreator(m1, rank - 1);
    cout << "pr1:  "; printer(m1, rank - 1);
    cout << "pr2:  "; printer(m2, rank - 2);
    double pr1Root = ChekRoot(rank - 1, a, b, m1); double pr2Root = ChekRoot(rank - 2, a, b, m2);
    if (pr1Root != a && pr1Root != b && pr2Root != a && pr2Root != b) { cout << "prRoot error\n"; return 0; }
    //фукция ChekRoot устроена таким образом что, если на промежутке корней нет, то она вернет одну из краевых точек

    int j = 0;


    if ((funCounter(m1, rank - 1, a) * funCounter(m2, rank - 2, a)) > 0)x = b;
    else x = a;
    while (abs(funCounter(m, rank, x)) >= acc) {
        cout << "x(" << j << ")=" << x << "\t" << "f(x(" << j << "))=" << funCounter(m, rank, x) << "\n";
        x = x - (funCounter(m, rank, x) / funCounter(m1, rank - 1, x));
        j++;
    }
    cout << "x(" << j << ")=" << x << "\t" << "f(x(" << j << "))=" << funCounter(m, rank, x) << "\n";
    return x;
}



int main()
{
    int rank;
    double acc=0.0001, a, b;
    cout << "polinomilial rank?\n"; cin >> rank;
    //cout << "Accuracy lvl?\n"; cin >> acc;
    cout << "left edge?\n"; cin >> a;
    cout << "right edge?\n"; cin >> b;
    double* task = koefCreator(rank);
    cout << "answer=" << Approx(task, a, b, acc, rank) << endl;
    cin >> a;
}

