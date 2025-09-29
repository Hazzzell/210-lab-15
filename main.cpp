// COMSC-210 | Lab 15 | Keng C Chan
// IDE used: Visual Studio Code (VS Code)
#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <fstream>
using namespace std;

const int W15 = 15, SIZE = 4;

class Movie {
private:
    string title;
    int yearReleased;
    string screenWriter;

public:
    // getters and setters
    string getTitle()                   { return title; }
    void setTitle(string t)             { title= t; }
    int getYearReleased()               { return yearReleased; }
    void setYearReleased(int y)         { yearReleased = y; }
    string getScreenWriter()            { return screenWriter; }
    void setScreenWriter(string n)      { screenWriter = s; }

    // other methods
    void print() {
        cout << setw(W15) << "GPA: " << GPA << endl;
        cout << setw(W15) << "Name: " << name << endl;
        cout << setw(W15) << "Course load: " << courseLoad << endl;
    }
};

int main() {
    // declarations
    cout << fixed << setprecision(2);
    vector<Student> students_v;
    array<Student, SIZE> students_a;
    ifstream fin ("input.txt");
    double g;  // holds temporary GPA
    int l;     // holds temporary load
    string n;  // holds temporary name
    int i = 0; // temporary index

    if (fin.good()) {
        while (fin >> g) {
            fin.ignore();
            getline(fin, n);
            fin >> l; 
            Student tmp;
            tmp.setGPA(g);
            tmp.setName(n);
            tmp.setCourseLoad(l);
            students_v.push_back(tmp);
            students_a[i] = tmp;
            i++;
        }
        fin.close();
    }
    else
        cout << "Input file not found.\n";

    // output vector
    for (auto val : students_v) {
        cout << val.getGPA() << " " << val.getName() 
        << " " << val.getCourseLoad() << endl;
    }
    cout << endl;

    // output array
    for (auto val : students_a) {
        cout << val.getGPA() << " " << val.getName() 
        << " " << val.getCourseLoad() << endl;
    }
    
    return 0;
}