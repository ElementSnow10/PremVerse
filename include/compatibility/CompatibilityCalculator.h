#pragma once
#include <iostream> 
#include <string>
#include<vector>

class Compatibility {
private :  
    const User & user_1;
    const User & user_2;
    bool INTIMACY = false;
    int INTIMACY_score;
    static std::vector<std::string> emotional_q,intellectual_q,physical_q,lifegoals_q,lifestyle_q,social_q,spiritual_q;
public :
    void check_intimacy();
    void questions_for_compatibility_check();
    Compatibility(const User & u_1 , const User &u_2);


    static void load_questions_emotional(const std::string & filename);
    static void load_questions_social(const std::string & filename);
    static void load_questions_spiritual(const std::string & filename);
    static void load_questions_lifestyle(const std::string & filename);
    static void load_questions_lifegoals(const std::string & filename);
    static void load_questions_physical(const std::string & filename);
    static void load_questions_intellectual(const std::string & filename);
};
