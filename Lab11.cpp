// COMSC-210 | Lab  11| Tianyi Cao
#include <iostream>
#include <string>

using namespace std;

//first create a struct include a dynamic array
struct Athlete {
    string name;
    int number;
    double *times;

    //When the Athlete object is deleted, this frees the internal times array.
    ~Athlete() {
        if(times != nullptr) {
            delete[] times;
            times = nullptr;
        }
    }
};