#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <optional>
#include "GiftCategories.h"
#include "GiftPreferences.h"

/**
 * Translates occasions and user preferences into gift ideas.
 *
 * Internally maintains two tables:
 *   1. Occasion -> gift list.
 *   2. Interest -> gift list.
 *
 * Suggestions are combined, shuffled, and optionally budget-filtered.
 */

class GiftSuggester {
private:
    void loadDefaultGifts();

    std::unordered_map<std::string, std::vector<std::string>> occasion_gift_map;
    std::unordered_map<std::string, std::vector<std::string>> interest_gift_map;

public:
    GiftSuggester();                                                       // Loads default catalogues.

    /**
     * Occasion: Plain-text occasion (e.g., "Valentine's Day").
     * Prefs:    User’s stored interests.
     * Budget :   Optional spending cap; simple demo filter for now.
     * return:  Curated list of gift ideas.
     */

    std::vector<std::string> suggest(const std::string& occasion,
                                     const GiftPreferences& prefs,
                                     std::optional<double> budget = std::nullopt) const;
};
