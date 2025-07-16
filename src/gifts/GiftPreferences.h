#pragma once
#include <string>
#include <vector>

/**
 * Lightweight value object that tracks a user’s interests for personalised gift suggestions.
 */

class GiftPreferences {
private:
    std::vector<std::string> interests_;

public:
    // Mutators/accessers
    void addInterest(std::string interest);           //Adds a single interest (case-insensitive, de-duplicated)
    const std::vector<std::string>& interests() const noexcept;            //Immutable view
    void clear() noexcept;                            //Resets stored interests
};
