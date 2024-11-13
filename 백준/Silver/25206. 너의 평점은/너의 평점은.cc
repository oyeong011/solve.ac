#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    map<string, double> gradePoints = {
        {"A+", 4.5}, {"A0", 4.0},
        {"B+", 3.5}, {"B0", 3.0},
        {"C+", 2.5}, {"C0", 2.0},
        {"D+", 1.5}, {"D0", 1.0},
        {"F", 0.0}
    };

    double totalGradePoints = 0.0;  
    double totalCredits = 0.0;      

    for (int i = 0; i < 20; i++) {
        string subject, grade;
        double credit;
        
        cin >> subject >> credit >> grade;

        if (grade != "P") {
            totalGradePoints += credit * gradePoints[grade];
            totalCredits += credit;
        }
    }

    cout << fixed << setprecision(6);
    cout << (totalCredits > 0 ? totalGradePoints / totalCredits : 0.0) << endl;

    return 0;
}