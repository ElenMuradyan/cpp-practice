#include <iostream>
using namespace std;

class ComplexNumber {
    private:
        double real;
        double img;
    public:
        ComplexNumber(double r, double i): real(r), img(i) {}

        ComplexNumber operator+ (const ComplexNumber &num) const {
            return ComplexNumber(real + num.real, img + num.img);
        }
        
        ComplexNumber operator- (const ComplexNumber &num) const {
            return ComplexNumber(real - num.real, img - num.img);
        }

        ComplexNumber operator* (const ComplexNumber &num) const {
            return ComplexNumber(
                real * num.real - img * num.img,
                real * num.img + img * num.real
            );
        }

        friend ostream& operator << (ostream& out, const ComplexNumber& c){
            if(c.img >= 0){
                out << c.real << " + " << c.img << "i";
            }else{
                out << c.real << " - " << -c.img << "i";
            }
            return out;
        }
};