//
// Created by Carlos R. Arias on 4/4/22.
//

#ifndef VECTOR_S22_VECTOR_H
#define VECTOR_S22_VECTOR_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class Vector {
private:
    size_t _size;
    double* _data;
public:
    Vector(size_t size);
    Vector(double* data, size_t size);
    Vector(const Vector& other);
    ~Vector();
    const Vector& operator=(const Vector& rhs);

    const Vector Sum(const Vector& rhs)const;
    const Vector Sub(const Vector& rhs)const;
    bool Equals(const Vector& rhs)const;
    double Distance(const Vector& rhs)const;

    string ToString()const;
    ostream& Write(ostream& output)const;
    istream& Read(istream& input);

    size_t GetDimension()const;
    bool IsValid()const;

    double& operator[](size_t index);
    const double& operator[](size_t index)const;
};


#endif //VECTOR_S22_VECTOR_H
