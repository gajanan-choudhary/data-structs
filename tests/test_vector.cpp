#include "vector.h"

using namespace std;

int main(){
    Vector u;
    Vector v(12.0, 16.0);
    Vector w;

    u.setx(3.0);
    u.sety(4.0);


    cout << "u" << u << ", ||u|| = " << u.mag() << endl;
    cout << "Testing: u.getx() = " << u.getx() << ", u.gety() = " << u.gety() << endl;

    cout << "v" << v << ", ||v|| = " << v.mag() << endl;

    cout << "u + v = " << u + v << endl;
    cout << "u - v = " << u - v << endl;

    u += v;
    cout << "u += v" << u << endl;

    u -= v;
    cout << "u -= v" << u << endl;

    cout << "5*u = " << 5*u << " u*5 = " << u*5 << endl;
    cout << "u/5 = " << u/5 << endl;

    return 0;
}
