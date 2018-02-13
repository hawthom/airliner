#ifndef MATRIX10F10_HPP
#define MATRIX10F10_HPP

#include "cfe.h"
#include "Vector10F.hpp"

#define M_DEG_TO_RAD_F		(0.01745329251994329576f)

namespace math
{

class Matrix10F10
{
public:

private:
	static const int SIZE = 10;
	Vector10F data[SIZE];
	Vector10F nan;

public:
	Matrix10F10(Vector10F m0, Vector10F m1, Vector10F m2, Vector10F m3, Vector10F m4, Vector10F m5, Vector10F m6, Vector10F m7, Vector10F m8, Vector10F m9);
	~Matrix10F10();
	Vector10F& operator [] (uint32 i);
	Vector10F operator [] (uint32 i) const;
	Matrix10F10();
	Matrix10F10 Transpose(void);
	static Matrix10F10 Identity(void);
	Vector10F operator*(const Vector10F &vecIn);
	Vector10F operator+(const Vector10F &vecIn);
	void operator+=(const Matrix10F10 &mat);
	Matrix10F10 operator*(const Matrix10F10 &matIn);
	Matrix10F10 operator*(const float &scalar);
	void Zero(void);
    Matrix10F10 operator+(const Matrix10F10 &matIn) const;
    void Print();

protected:

};

}

#endif
