#include <iostream>
using namespace std;

int main() {

    for (int a = 1; a <= 9; a++)   // 三
    for (int b = 0; b <= 9; b++)  // 羊
    for (int c = 1; c <= 9; c++)  // 献
    for (int d = 0; d <= 9; d++)  // 瑞
    for (int e = 1; e <= 9; e++)  // 祥
    for (int f = 0; f <= 9; f++)  // 生
    for (int g = 0; g <= 9; g++)  // 辉
    for (int h = 0; h <= 9; h++)  // 气
    {
        if (a==b||a==c||a==d||a==e||a==f||a==g||a==h) continue;
        if (b==c||b==d||b==e||b==f||b==g||b==h) continue;
        if (c==d||c==e||c==f||c==g||c==h) continue;
        if (d==e||d==f||d==g||d==h) continue;
        if (e==f||e==g||e==h) continue;
        if (f==g||f==h) continue;
        if (g==h) continue;

        int x = e * 1000 + d * 100 + f * 10 + g;
        int y = a * 1000 + b * 100 + c * 10 + d;
        int z = a * 10000 + b * 1000 + f * 100 + d * 10 + h;

        if (x + y == z) {
            cout << "      " << e << " " << d << " " << f << " " << g << endl;
            cout << "  +   " << a << " " << b << " " << c << " " << d << endl;
            cout << "----------------" << endl;
            cout << "    " << a << " " << b << " " << f << " " << d << " " << h << endl;  
            return 0;
        }
    }
    return 0;
}