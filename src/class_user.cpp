#include "user.h"
#include <fstream>
#include <iostream>

std::vector<std::string> User::hobbies;

void User::load_hobbies(const std::string &filename) {
    hobbies.clear();
    std::ifstream infile(filename);
    if(!infile) {
        std::cerr << "Error opening the file: " << filename << "\n";
        return ;
    }
    std::string line;
    while (!getline(infile,line)) {
        if(!line.empty())
            hobbies.push_back(line);
    }
    infile.close();
}
void User::get_info(){
    std::cout << "Enter your name" << "\n";
    std::getline(std::cin, name);

    std::cout << "Enter your age" << "\n";
    std::cin >> age;

    std::cin.ignore(); // Clear newline

    std::cout << "Enter your birth-date,birth-month,birth-year 
                in dd mm yyyy format (please leave space after
                entering date and month)" << "\n";
    std::cin >> birth_date >> birth_month >> birth_year;

    std::cin.ignore(); // Clear newline

    std::cout << "Please enter the character corresponding to your gender " << "\n";
    std::cout << "M:Male" << "\n" << "F:Femlae" << "\n" 
              << "B:Bisexual" << "\n" << "L:Lesbian" << "\n"
              << "G:Gay" << "\n";
    std::cin >> GENDER;

    std::cin.ignore(); // Clear newline

    std::cout << "Please enter your profession" << "\n";
    std::getline(std::cin ,profession);

    std::cout << "Please enter your address" <<"\n";
    std::getline(std::cin ,Location);

    std::cout << "From the following list of hobbies enter the
                  indexes of those that you relate with once you
                  are done enter -1" << "\n";
    for(size_t i = 0;i < hobbies.size();i++){
        std::cout << i+1 <<" " << hobbies[i] << "\n"; 
    }
    int index;
    while (std::cin >> index && index != -1) {
        if (index >= 0 && index < Hobbies.size()) {
            matched_hobbies.push_back(index);
        } else {
            std::cout << "Invalid index, try again.\n";
        }
    }
    std::cin.ignore(); // flush newline
}
