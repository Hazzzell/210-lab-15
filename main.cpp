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
    void setScreenWriter(string s)      { screenWriter = s; }

    // other methods
    void print() {
        cout << setw(W15) << "Movie: " << screenWriter << endl;
        cout << setw(W15) << "Year Released: " << yearReleased << endl;
        cout << setw(W15) << "Screenwriter: " << title << endl;
    }
};

int main() {
    // declarations
    cout << fixed << setprecision(2);
    vector<Movie> movies_v;
    array<Movie, SIZE> movies_a;
    ifstream fin ("input.txt");
    string t;  // holds temporary title
    int y;     // holds temporary year
    string s;  // holds temporary screenwriter
    int i = 0; // temporary index

    if (fin.good()) {
        while (fin >> t) {
            fin.ignore();
            getline(fin, s);
            fin >> y; 
            Movie tmp;
            tmp.setTitle(t);
            tmp.setYearReleased(y);
            tmp.setScreenWriter(s);
            movies_v.push_back(tmp);
            movies_a[i] = tmp;
            i++;
        }
        fin.close();
    }
    else
        cout << "Input file not found.\n";

    // output vector
    for (auto val : movies_v) {
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
