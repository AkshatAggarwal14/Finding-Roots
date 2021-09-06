#include "bits/stdc++.h"
using namespace std;

double f(double x) {  //? this is the required function
    // return cos(x) - x * exp(x);  //1 0
    return x * x * x - 2 * x - 5;  //2 3
    // return x * log10(x) - 1.2;  //2 3
}
double f_(double x) {  //? derivative of required function
    // return -sin(x) - (x + 1) * exp(x);  //1 0
    return 3 * x * x - 2;  //2 3
    // return (log(x) + 1) / log(10);  //2 3
}

const double eps = 1e-13;  //! precision you want + 1

/*
Here 'l' is the given value where f(l) < 0
'r' is given value where f(r) > 0
'iterations' is the maximum number of iterations that happen if answer is not found
*/
void Bisection_Method(double l, double r, int iterations) {
    double prev = l, next = r;
    for (int i = 1; i <= iterations; ++i) {
        double mid = (l + r) / 2;
        next = mid;

        if (abs(next - prev) < eps) {
            cout << "\nAnswer is: " << prev;
            return;
        } else {
            prev = next;
        }

        double val = f(mid);
        cout << "Iteration " << i << ": " << mid << "\n";
        if (abs(val) < eps) {
            cout << "\nAnswer is: " << mid;
            return;
        } else if (val < 0)
            l = mid;
        else
            r = mid;
    }
}

double nxt_Regula(double cur, double prev) {
    return (prev - ((cur - prev) / (f(cur) - f(prev))) * f(prev));
}

/*
Here 'l' is the given value where f(l) < 0
'r' is given value where f(r) > 0
'iterations' is the maximum number of iterations that happen if answer is not found
*/
void Regula_falsi(double l, double r, int iterations) {
    double prev = l, next = r;
    for (int i = 1; i <= iterations; ++i) {
        double n_ext = nxt_Regula(r, l);

        next = n_ext;
        if (abs(next - prev) < eps) {
            cout << "\nAnswer is: " << prev;
            return;
        } else {
            prev = next;
        }

        double val = f(n_ext);
        cout << "Iteration " << i << ": " << n_ext << "\n";
        if (abs(val) < eps) {
            cout << "\nAnswer is: " << n_ext;
            return;
        } else if (val < 0)
            l = n_ext;
        else
            r = n_ext;
    }
}

double nxt_Newton(double prev) {
    return prev - f(prev) / f_(prev);
}

/*
Here 'l' is the given value where f(l) < 0
'r' is given value where f(r) > 0
'iterations' is the maximum number of iterations that happen if answer is not found
*/
void Newton_Raphson(double l, double r, int iterations) {
    double mid = (l + r) / 2;
    double prev = mid, next = prev;
    for (int i = 1; i <= iterations; ++i) {
        cout << "Iteration " << i << ": " << prev << "\n";
        next = nxt_Newton(prev);
        if (abs(next - prev) > eps) {
            prev = next;
        } else {
            cout << "\nAnswer is: " << prev;
            return;
        }
    }
}

int main() {
    cout << fixed << setprecision(12);  //! precision you want
    Bisection_Method(2, 3, 1000);
    cout << "\n\n\n";
    Regula_falsi(2, 3, 1000);
    cout << "\n\n\n";
    Newton_Raphson(2, 3, 1000);
    return 0;
}