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

//add two functions to get data and show data
void getData (Athlete *a, int num);
void showData (Athlete *a, int num);

int main(){
    //define the number of athletes and times
    int AthleteNum;
    int TimeNum;
    cout << "Enter the number of athletes: ";
    cin >> AthleteNum;
    cout << "Enter the number of times for each athlete: ";
    cin >> TimeNum;
}

void getData (Athlete *a, int num) {
    cout << "Enter name: ";
    getline(cin, a->name);
    cout << "Enter athlete number: ";
    cin >> a->number;
}
    
void showData (Athlete *a, int num) {
    cout << "Name: " << a->name << endl;
    cout << "Athlete number: " << a->number << endl;
}