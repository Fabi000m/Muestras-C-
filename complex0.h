#include <iostream>
#ifndef _COMPLEX_00_
#define _COMPLEX_00_

class Complex
{
private:
	double m_real;
	double m_imaginary;
public:
	Complex(double, double);
	Complex();
	Complex operator~() const;
	Complex operator+(Complex) const;
	Complex operator-(Complex) const;
	Complex operator*(Complex) const;
	Complex operator*(double) const;
	friend std::ostream & operator<<(std::ostream &, Complex &);
	friend std::istream & operator>>(std::istream &, Complex &);
	friend Complex operator*(double, Complex);
};
#endif