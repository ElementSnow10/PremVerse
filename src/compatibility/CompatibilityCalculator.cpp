#include "Compatibility.h"
#include <fstream>
#include <sstream>

// Definition of static members
std::vector<std::string> Compatibility::emotional_q;
std::vector<std::string> Compatibility::intellectual_q;
std::vector<std::string> Compatibility::physical_q;
std::vector<std::string> Compatibility::lifegoals_q;
std::vector<std::string> Compatibility::lifestyle_q;
std::vector<std::string> Compatibility::social_q;
std::vector<std::string> Compatibility::spiritual_q;

// Constructor
Compatibility::Compatibility(const User& u_1, const User& u_2)
    : user_1(u_1), user_2(u_2), intimacy_(false), intimacy_score_(0)
{}

// Helper function for loading questions from a file
static void load_questions_from_file(std::vector<std::string>& vec, const std::string& filename) {
    vec.clear();
    std::ifstream infile(filename);
    std::string line;
    while (std::getline(infile, line)) {
        if (!line.empty())
            vec.push_back(line);
    }
    infile.close();
}

// Static functions to load question categories
void Compatibility::loadQuestionsEmotional(const std::string& filename) {
    load_questions_from_file(emotional_q, filename);
}
void Compatibility::loadQuestionsSocial(const std::string& filename) {
    load_questions_from_file(social_q, filename);
}
void Compatibility::loadQuestionsSpiritual(const std::string& filename) {
    load_questions_from_file(spiritual_q, filename);
}
void Compatibility::loadQuestionsLifestyle(const std::string& filename) {
    load_questions_from_file(lifestyle_q, filename);
}
void Compatibility::loadQuestionsLifegoals(const std::string& filename) {
    load_questions_from_file(lifegoals_q, filename);
}
void Compatibility::loadQuestionsPhysical(const std::string& filename) {
    load_questions_from_file(physical_q, filename);
}
void Compatibility::loadQuestionsIntellectual(const std::string& filename) {
    load_questions_from_file(intellectual_q, filename);
}

void Compatibility::checkIntimacy() {
    std:: cout << "If you and your partner are having a romantic relation please enter 1 or enter 0" << "\n";
    int answer;
    std:: cin >> answer;
    if(answer) Compatibility::INTIMACY = true;
}
float score_emotional = 0.0;
float score_social = 0.0;
float score_physical = 0.0;
float score_intellectual = 0.0;
float score_lifestyle = 0.0;
float score_lifegoals = 0.0;
float score_spiritual = 0.0;

void Compatibility::questionsForCompatibilityCheck() {
    int answer;
    std:: cout << "Please answer in the format, 1 means strongly disagree and 5 means strongly agree" << "\n";
    for(size_t i = 0;i < emotional_q.size();i++){
        std:: cout << emotional_q[i] << "\n";
        std:: cin >> answer;
        score_emotional += answer;
    }
    for(size_t i = 0;i < social_q.size();i++){
        std:: cout << social_q[i] << "\n";
        std:: cin >> answer;
        score_social += answer;
    }
    for(size_t i = 0;i < physical_q.size();i++){
        std:: cout << physical_q[i] << "\n";
        std:: cin >> answer;
        score_physical += answer;
    }
    for(size_t i = 0;i < intellectual_q.size();i++){
        std:: cout << intellectual_q[i] << "\n";
        std:: cin >> answer;
        score_intellectual += answer;
    }
    for(size_t i = 0;i < spiritual_q.size();i++){
        std:: cout << spiritual_q[i] << "\n";
        std:: cin >> answer;
        score_spiritual += answer;
    }
    for(size_t i = 0;i < lifestyle_q.size();i++){
        std:: cout << lifestyle_q[i] << "\n";
        std:: cin >> answer;
        score_lifestyle += answer;
    }
    for(size_t i = 0;i < lifegoals_q.size();i++){
        std:: cout << lifegoals_q[i] << "\n";
        std:: cin >> answer;
        score_lifegoals += answer;
    }

}
