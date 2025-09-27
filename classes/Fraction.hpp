#include <iostream>
#include <string>
#include <vector>
#include <numbers>
#include <algorithm>

using namespace std;

int gcd (int a, int b){
    if(b == 0){
        return a;
    }

    return gcd(b, a % b);
}

class Fraction{
    private:
        int numerator;
        int denominator;
        void normalize() {
            const int gcdNum = gcd(numerator, denominator);
            numerator /= gcdNum;
            denominator /= gcdNum;
        }
    public:
        Fraction(int num, int denom){
            if (denom == 0) {
                throw invalid_argument("Denominator cannot be zero.");
            }
            numerator = num;
            denominator = denom;
            normalize();
        }

        Fraction operator+ (const Fraction &otherNum) {
            return Fraction(numerator * otherNum.denominator + denominator * otherNum.numerator, denominator * otherNum.denominator);
        }

        Fraction operator- (const Fraction &otherNum) {
            return Fraction(numerator * otherNum.denominator - denominator * otherNum.numerator, denominator * otherNum.denominator);
        }

        Fraction operator* (const Fraction &otherNum) {
            return Fraction(numerator * otherNum.numerator, denominator * otherNum.denominator);
        }

        Fraction operator/ (const Fraction &otherNum) {
            return Fraction(numerator * otherNum.denominator, denominator * otherNum.numerator);
        }

        friend ostream &operator<<(ostream &out, const Fraction &num){
            int numer = num.numerator;
            int denom = num.denominator;

            out << numer << " / " << denom << endl;
            return out;
        }
};