class User {
private :
    std::string name;
    int age;
    int birth_date , birth_month ;
    char GENDER;
public :
    void get_info(){
        std::cout << "Please enter your name" << std::endl;
        std::cin >> name;
        std:: cout << "Please enter your age" << std::endl;
        std::cin >> age;
        std:: cout << "Please enter your birth date" << std::endl;
        std::cin >> birth_date;
        std:: cout << "Please enter your birth month" << std::endl;
        std::cin >> birth_month;
        std :: cout << "Please enter the character according to your gender" << std:: endl;
        std:: cout << "M:Male" << "\n" << "F:Female" << "\n" << "L:Lesbian" << "\n" << "G:Gay" << "\n" << "B:Bisexual" << "\n";
        std:: cin >> GENDER;

    }
}
