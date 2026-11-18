#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include <string>
#include <iomanip>

double cal(const double* x, int i, int n, double arbyz);
double lag(const double* x, const double* y, int n, double arbyz);
void print(const double* x, const double* y, int n, double arbyz);

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    double x[] = { 1, 2, 4, 5 };
    double y[] = { 0, 3, 15, 24 };
    int n = sizeof(x) / sizeof(x[0]);

    print(x, y, n, 3.0);

    print(x, y, n, 6.0);

    system("pause");
    return 0;
}









double cal(const double* x, int i, int n, double arbyz)
{
    double L = 1.0;

    for (int j = 0; j < n; ++j)
    {
        if (i != j)
        {
            L *= (arbyz - x[j]) / (x[i] - x[j]);
        }
    }

    std::wcout << L"L_" << i << L"(" << arbyz << L") = "
        << std::fixed << std::setprecision(4) << L << "\n";

    return L;
}

double lag(const double* x, const double* y, int n, double arbyz)
{
    double result = 0.0;

    for (int i = 0; i < n; ++i)
    {
        double L_i = cal(x, i, n, arbyz);
        result += y[i] * L_i;
    }

    return result;
}

void print(const double* x, const double* y, int n, double arbyz)
{
    std::wcout << L"Интерполяция  x = " << arbyz << L"\n";

    double result = lag(x, y, n, arbyz);

    std::wcout << L"Результат " << result << "\n";
    std::wcout << "\n";
}