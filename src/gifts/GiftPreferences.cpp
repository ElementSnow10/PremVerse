#include "GiftPreferences.h"
#include <algorithm>
#include <iterator>

void GiftPreferences::addInterest(std::string interest) {
    // Normalise to lower case
    std::transform(interest.begin(), interest.end(), interest.begin(), [](unsigned char c){
        return std::tolower(c);
    });

    if (std::find(interests_.begin(), interests_.end(), interest) == interests_.end())
        interests_.push_back(std::move(interest));
}

const std::vector<std::string>& GiftPreferences::interests() const noexcept {
    return interests_;
}

void GiftPreferences::clear() noexcept {
    interests_.clear();
}
