//
// Created by Carlos R. Arias on 4/4/22.
//

#include "vector.h"
//#include <vector>
#include <cmath>
#include <sstream>

using std::stringstream;

Vector::Vector(size_t size) {
    if (size == 0){
        _data = nullptr;
        _size = 0;
    }else{
        _size = size;
        _data = new double[_size];
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = 0.0;
        }
    }
}

Vector::Vector(double *data, size_t size) {
    if (size == 0){
        _data = nullptr;
        _size = 0;
    }else{
        _size = size;
        _data = new double[_size];
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = data[i];
        }
    }
}

Vector::Vector(const Vector &other) {
    if (other._size == 0){
        _data = nullptr;
        _size = 0;
    }else{
        _size = other._size;
        _data = new double[_size];
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }
}

Vector::~Vector() {
    if (_data != nullptr)
        delete[] _data;
}

const Vector &Vector::operator=(const Vector &rhs) {
    if (this == &rhs)
        return *this;
    if (rhs._size == 0){
        delete[] _data;
        _data = nullptr;
        _size = 0;
        return *this;
    }
    if (rhs._size == _size){
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = rhs._data[i];
        }
    }else{
        delete[] _data;
        _size = rhs._size;
        _data = new double[_size];
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = rhs._data[i];
        }
    }
    return *this;
}

const Vector Vector::Sum(const Vector &rhs) const {
    if (_size != rhs._size){
        return Vector(0);
    }
    Vector retVal(_size);
    for (size_t i = 0; i < _size; ++i) {
        retVal._data[i] = _data[i] + rhs._data[i];
    }
    return retVal;
}

const Vector Vector::Sub(const Vector &rhs) const {
    if (_size != rhs._size){
        return Vector(0);
    }
    Vector retVal(_size);
    for (size_t i = 0; i < _size; ++i) {
        retVal._data[i] = _data[i] - rhs._data[i];
    }
    return retVal;
}

bool Vector::Equals(const Vector &rhs) const {
    if (_size != rhs._size)
        return false;
    for (size_t i = 0; i < _size; ++i) {
        if (_data[i] != rhs._data[i])
            return false;
    }
    return true;
}

double Vector::Distance(const Vector &rhs) const {
    if (_size != rhs._size)
        return -1;
    double sum = 0;
    for (size_t i = 0; i < _size; ++i) {
        sum += pow(_data[i] - rhs._data[i], 2);
    }
    return sqrt(sum);
}

string Vector::ToString() const {
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < _size; ++i) {
        if (i != _size - 1)
            ss << _data[i] << ", ";
        else
            ss << _data[i] << "]";
    }
    return ss.str();
}

ostream &Vector::Write(ostream &output) const {
    output << _size << " ";
    for (size_t i = 0; i < _size; ++i) {
        output << _data[i] << " ";
    }
    return output;
}

istream &Vector::Read(istream &input)  {
    size_t inputSize;
    input >> inputSize;
    if (input.fail())
        return input;
    if (_size != inputSize){
        delete[] _data;
        _size = inputSize;
        _data = new double [_size];
        for (size_t i = 0; i < _size; ++i) {
            input >> _data[i];
            if (input.fail())
                return input;
        }
    }
    return input;
}



//This function multiplies each number by circling through the vector
const Vector Vector::operator-() {
    Vector subNum(_size);
    for(size_t m = 0; m < _size; ++m) {
        subNum[m] = _data[m]* - 1;
    }
    return subNum;

}

const Vector Vector::operator*(double val) const {
    Vector mulNum(_size);
    for(size_t m = 0; m < _size; ++m) {
        mulNum[m] = _data[m]* val;
    }
    return mulNum;
}









size_t Vector::GetDimension() const {
    return _size;
}

bool Vector::IsValid() const {
    return _size != 0;
}

double &Vector::operator[](size_t index) {
    return _data[index];
}

const double &Vector::operator[](size_t index) const {
    return _data[index];
}

bool Vector::operator==(const Vector &rhs) const {
    return Equals(rhs);
}

bool Vector::operator!=(const Vector &rhs) const {
    return !Equals(rhs);
}

const Vector Vector::operator+(const Vector &rhs) const {
    return Sum(rhs);
}

const Vector Vector::operator-(const Vector &rhs) const {
    return Sub(rhs);
}
