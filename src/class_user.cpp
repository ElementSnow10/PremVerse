#include <iostream>
#include <string>
#include <vector>
#include<fstream>
class User {
private:
    std::string name;
    int age;
    int birth_date, birth_month;
    char GENDER;
    static std::vector<std::string> Hobbies;
    std::vector<int> Matched_hobbies;
    std::string profession;
    std::string Location;

public:
    static void load_hobbies(const std::string & filename){
            Hobbies.clear();
        std::ifstream input_file(filename);
        std::string hobby;
        while (std::getline(input_file, hobby)) {
            if (!hobby.empty()){
                Hobbies.push_back(hobby);
            }
        }
    }
    void get_info() {
        std::cout << "Please enter your name: ";
        std::getline(std::cin, name);

        std::cout << "Please enter your age: ";
        std::cin >> age;

        std::cout << "Please enter your birth date: ";
        std::cin >> birth_date;

        std::cout << "Please enter your birth month: ";
        std::cin >> birth_month;

        std::cout << "Please enter the character according to your gender\n";
        std::cout << "M:Male\nF:Female\nL:Lesbian\nG:Gay\nB:Bisexual\n";
        std::cin >> GENDER;

        std::cin.ignore(); // flush newline

        std::cout << "Please enter your profession: ";
        std::getline(std::cin, profession);

        std::cout << "Please enter your location: ";
        std::getline(std::cin, Location);

        std::cout << "Available hobbies:\n";
        for (size_t i = 0; i < Hobbies.size(); i++) {
            std::cout << i << ": " << Hobbies[i] << "\n";
        }

        std::cout << "Mention the index numbers of the hobbies that match your hobbies (space-separated, end with -1):\n";
        int idx;
        while (std::cin >> idx && idx != -1) {
            if (idx >= 0 && idx < Hobbies.size()) {
                Matched_hobbies.push_back(idx);
            } else {
                std::cout << "Invalid index, try again.\n";
            }
        }
        std::cin.ignore(); // flush newline
    }
};
// Initialize static member
std::vector<std::string> User::Hobbies;
// as we cannot call a function in the global scope in c++ so we did it in the main function
int main (){
    User::load_hobbies("hobbies.txt");
    return 0;
}

