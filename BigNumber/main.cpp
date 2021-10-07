#include <iostream>

int getLength(const int& x) {
    int count = 0;
    int number = x;
    while(number > 0) {
        number = number / 10;
        count += 1;
    }

    return count;
}

int pow(const int& x, const int& y) {
    int number = x;

    for(int i = 0; i < y - 1; i++) {
        number = number * x;
    }
    return number;
}


int prod(int u, int v) {
    if (u == 0 || v == 0) return 0;
    int length_u = getLength(u);
    int length_v = getLength(v);
    int n = length_u > length_v ? length_u : length_v;
    int m = int((float(n) / 2));

    if(m < 2) {
        return u * v;
    }

    int x = u / pow(10, m);
    int y = u % pow(10, m);
    int w = v / pow(10, m);
    int z = v % pow(10, m);

    int r = prod(x + y, w + z);
    int p = prod(x, w);
    int q = prod(y, z);

    return (p * pow(10, 2 * m)) + ((r - p - q) * pow(10, m)) + q;
}


int main() {
    // int overflow 방지는 안되용..ㅠㅠ
    std::cout << (prod(78829, 142356)) << '\n';
    return 0;
}
