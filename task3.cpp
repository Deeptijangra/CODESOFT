#include <iostream>
#include <string>
#include <vector>

int main() {
    int numStudents;
    double totalGrade = 0.0;
    double highestGrade = 0.0;
    double lowestGrade = 100.0;  // Assuming grades are between 0 and 100

    std::vector<std::string> studentNames;
    std::vector<double> studentGrades;

    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        std::string name;
        double grade;

        std::cout << "Enter student name: ";
        std::cin.ignore();  // Clear the newline character left in the input buffer
        std::getline(std::cin, name);

        std::cout << "Enter " << name << "'s grade: ";
        std::cin >> grade;

        studentNames.push_back(name);
        studentGrades.push_back(grade);

        totalGrade += grade;

        if (grade > highestGrade) {
            highestGrade = grade;
        }
