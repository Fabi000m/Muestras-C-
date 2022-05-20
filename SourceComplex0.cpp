#include "complex0.h"
#include <iostream>

Complex::Complex()
{
	m_real = 0.0;
	m_imaginary = 0.0;
}

//Inicializa complex definiendo la parte real y la parte imaginaria.
//El primer argumento es la parte real, mientras que el segundo
//es la parte imaginaria. 
Complex::Complex(double real, double imaginary)
{
	m_real = real;
	m_imaginary = imaginary;
}

Complex Complex::operator~() const
{
	Complex i_;
	
	i_.m_real = m_real;
	i_.m_imaginary = -m_imaginary;
	
	return i_;
}

Complex Complex::operator+(Complex i) const
{
	Complex i_;

	i_.m_real = m_real + i.m_real;
	i_.m_imaginary = m_imaginary + i.m_imaginary;
	
	return i_;
}

Complex Complex::operator-(Complex i) const
{
	Complex i_;

	i_.m_real = m_real - i.m_real;
	i_.m_imaginary = m_imaginary - i.m_imaginary;
	
	return i_;
}

Complex Complex::operator*(Complex i) const
{
	Complex i_;

	i_.m_real = m_real * i.m_real - m_imaginary * i.m_imaginary;
	i_.m_imaginary = m_real * i.m_imaginary + m_imaginary * i.m_real;
	
	return i_;
}

Complex Complex::operator*(double x) const
{
	Complex i_;

	i_.m_real = m_real * x;
	i_.m_imaginary = m_imaginary * x;

	return i_;
}

std::ostream & operator<<(std::ostream & out, Complex & i)
{
	out << "(" << i.m_real << "," << i.m_imaginary << "i)" << std::endl;
	
	return out;
}

std::istream & operator>>(std::istream & in, Complex & i)
{
	double a;
	double b;
	std::cout << "Real: ";
	in >> i.m_real;

	std::cout << "Imaginary: ";
	in >> i.m_imaginary;

	return in;
}

Complex operator*(double x, Complex i) 
{
	Complex i_;

	i_.m_real = x * i.m_real;
	i_.m_imaginary = x * i.m_imaginary;

	return i_;
}

