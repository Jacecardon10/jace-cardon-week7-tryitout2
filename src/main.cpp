#include <iostream>
#include <cmath> // for abs()
using namespace std;

class Polynomial {
public:
    int a = 0;
    int b = 0;
    int c = 0;
    
    Polynomial operator+(Polynomial other) {
        other.a += a;
        other.b += b;
        other.c += c;

        return *this;
    }

    Polynomial operator-(Polynomial other) {
        a -= other.a;
        b -= other.b;
        c -= other.c;

        return *this;
	}
    
    friend ostream& operator <<(ostream& os, Polynomial& p) {

        os << p.a << "x^2 " << "+ " << p.b << "x " << "+ " << p.c << endl;
        return os;
    }

    friend istream& operator >> (istream& is, Polynomial& p){
       
        cout << "Enter coefficient a (for x^2): ";
        is >> p.a;
        cout << "Enter coefficient b (for x): ";
        is >> p.b;
        cout << "Enter coefficient c (constant term): ";
        is >> p.c;

		return is;
	}
};


int main() {
    Polynomial p1, p2;

    cout << "Polynomial 1:\n";
    cin >> p1;

    cout << "\nPolynomial 2:\n";
    cin >> p2;

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;

    cout << "\nP1 = " << p1 << endl;
    cout << "P2 = " << p2 << endl;

    cout << "\nP1 + P2 = " << sum << endl;
    cout << "P1 - P2 = " << diff << endl;

    return 0;
}