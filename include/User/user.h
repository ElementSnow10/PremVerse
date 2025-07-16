#pragma once
#include <iostream>
#include <vector>
#include <string>

class User{
private :
    std:: string name;
    int age,birth_date,birth_month,birth_year;
    char GENDER;
    std:: string profession,Location;
    static std:: vector<std:: string> hobbies;
    static std:: vector<std::string > matched_hobbies;
public :
    static void load_hobbies(const std::string &filename);
    void get_info();
};
