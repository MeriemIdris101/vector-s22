#include "vector.h"

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::left;
using std::setw;

void Test(bool condition, const char* message, unsigned int& passedTests);


int main() {
    double w[] = {1, 4}, x[] = {9, -1}, y[] = {1, 1, 2};

    Vector a(w, 2), b(x, 2), c(y, 3);

    unsigned int passedTests = 0;
    Test(a.ToString() == "[1, 4]", "ToString 1 Passed", passedTests);
    Test(b.ToString() == "[9, -1]", "ToString 2 Passed", passedTests);
    Test(c.ToString() == "[1, 1, 2]", "ToString 3 Passed", passedTests);

    Vector d(0);
    Test(d.IsValid() == false, "IsValid is Working", passedTests);
    d = a;
    Test(d.ToString() == "[1, 4]", "Assignment Result correct", passedTests);
    Test(a.Equals(d) == true, "Equals works 1", passedTests);
    Test(a.Equals(a) == true, "Equals works 2", passedTests);
    Test(a.Equals(b) == false, "Equals works 3", passedTests);
    d = a.Sum(b);
    Test(d.ToString() == "[10, 3]", "Sum worked 1", passedTests);
    d = a.Sum(c);
    Test(!d.IsValid(), "Sum different size vector worked", passedTests);

    return 0;
}

void Test(bool condition, const char* message, unsigned int& passedTests){
    if (condition){
        cout << "TEST PASSED (" << left << setw(40) << message << ") Total Passed: " << ++passedTests << endl;
    }else{
        cout << "TEST FAILED (" << message << ")" << endl;
    }
}