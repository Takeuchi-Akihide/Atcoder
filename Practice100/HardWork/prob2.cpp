#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define MAX_N   100005

int main(void) {
    double a, b, x;
    double arufa, kakudo;
    cin >> a >> b >> x;
    if (x >= a * a * b / 2) {
        arufa = atan((2 * (a * a * b - x)) / pow(a, 3));
    } else {
        arufa = atan((a * b * b) / (2 * x));
    }
    kakudo = arufa * 180 / M_PI;
    cout << fixed << std::setprecision(15) << kakudo << endl;
    return 0;
}
