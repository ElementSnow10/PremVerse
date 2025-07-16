
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
class Compatibility{
private : 
    const User & user_1;
    const User & user_2;
    bool INTIMACY = false;
    int compatibility_emotional[4],compatibility_physical[2],compatibility_intellectual[4],compatibility_lifegoals[4],compatibility_lifestyle[4],compatibility_social[4],compatibility_spiritual[4];
    int INTIMACY_score[4];
    static std::vector<std::string> emotional_q,intellectual_q,physical_q,lifegoals_q,lifestyle_q,social_q,spiritual_q;
public : 
    static void load_questions(const std::string & filename1,const std::string & filename2,const std::string & filename3,const std::string & filename4,const std::string & filename5,const std::string & filename6,const std::string & filename7 ){
        std::ifstream input_file_emotional(filename1);
        std::ifstream input_file_social(filename2);
        std::ifstream input_file_spiritual(filename3);
        std::ifstream input_file_physical(filename4);
        std::ifstream input_file_intellectual(filename5);
        std::ifstream input_file_lifestyle(filename6);
        std::ifstream input_file_lifegoals(filename7);
        std::string question;
        while (std::getline(input_file_emotional,question)) {
            if (!question.empty()){
                emotional_q.push_back(question);
            }
        }
        while (std::getline(input_file_social,question)) {
            if (!question.empty()){
                social_q.push_back(question);
            }
        }
        while (std::getline(input_file_spiritual,question)) {
            if (!question.empty()){
                spiritual_q.push_back(question);
            }
        }
        while (std::getline(input_file_physical,question)) {
            if (!question.empty()){
                physical_q.push_back(question);
            }
        }
        while (std::getline(input_file_intellectual,question)) {
            if (!question.empty()){
                intellectual_q.push_back(question);
            }
        }
        while (std::getline(input_file_lifestyle,question)) {
            if (!question.empty()){
                lifestyle_q.push_back(question);
            }
        }
        while (std::getline(input_file_lifegoals,question)) {
            if (!question.empty()){
                lifegoals_q.push_back(question);
            }
        }
    }
    Compatibility(const User & u1,const User &u2) : user_1(u1) , user_2(u2) {}
    void check_intimacy() {
        std:: cout << "If you have been sexually active please enter 1 else enter 0" << "\n";
        int check;
        std:: cin >> check;
        if(check) INTIMACY = true;
    }
    void questions_for_compatibility_check(){
        std:: cout << "Please mention the number according to the following terminilogy" << "\n" << "1 - stringly disagree " << "\n";
        std:: cout << "5 - strongly agree" << "\n";
    }
};  
int main (){    
    Compatibility::load_questions("emotional.txt" , "social.txt" , "spiritual.txt" , "physical.txt" ,"intellectual.txt" ,"lifestyle.txt" , "lifegoal.txt");
    return 0;
}
