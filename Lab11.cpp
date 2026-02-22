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

    cin.ignore();
    //create an array of Athlete objects
    Athlete *roster = new Athlete[AthleteNum];
    //for each athlete, create a dynamic array for times and get data
    for (int i = 0; i < AthleteNum; i++) {
        getData(&roster[i], TimeNum);
    }
    //show data for each athlete
    for (int i = 0; i < AthleteNum; i++) {
        showData(&roster[i], TimeNum);
    }
    cin.ignore();
    //delete the roster array, which will also call the destructor for each Athlete
    delete[] roster;
    return 0;
}

void getData (Athlete *a, int num) {
    static int nrStu = 1;
    cout << "Input data for athlete #" << nrStu << ":\n";
    cout << "Enter name: ";
    getline(cin, a->name);
    cout << "Enter athlete number: ";
    cin >> a->number;
    for (int i = 0; i < num; i++) {
        cout << "Enter time " << i + 1 << ": ";
        cin >> a->times[i];      
    }
    cin.ignore();
    cout << endl << endl;
    nrStu++;
}
    
void showData (Athlete *a, int num) {
    cout << "Name: " << a->name << endl;
    cout << "Athlete number: " << a->number << endl;
    for (int i = 0; i < num; i++) {
        cout << "Time " << i + 1 << ": " << a->times[i] << endl;
        cout << endl << endl;
    }
    
}