#include <bits/stdc++.h>
using namespace std;

class Box {
public:
    int a, b;
    double c;
    Box add(const Box& t) const {
        Box d;
        d.a = a + t.a;  d.b = b + t.b;  d.c = c + t.c;
        return d;
    }
    Box operator+(const Box& t) const {
        Box d;
        d.a = a + t.a;  d.b = b + t.b;  d.c = c + t.c;
        return d;
    }
    friend ostream & operator << (ostream & os, const Box & box) {
        os << box.a << " " << box.b << " " << box.c << endl;
        return os;
    }
private:
    int d;
};

namespace env {
    int add(int a, int b) {
        return a + b;
    }
    namespace odd {
        int sub(int a, int b) {
            return a - b;
        }
    }
};

template <class T>
inline T Max(T const &a, T const& b) {
    return a < b? b : a;
}


int main() {
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;
    cout << env::odd::sub(a, b) << endl;
    std::cout << env::add(a, b) << std::endl;
    std::cout << Max(a, b) << std::endl;
    Box P;
    P.a = 1;    P.b = 2;    P.c = 4.4;
    std::cout << P << endl;
    return 0;
}
