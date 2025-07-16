#pragma once
#include <memory>
#include <string>
#include "GiftSuggester.h"
#include "GiftPreferences.h"

/**
 * Responsible for:
 *    1. Collecting console input.
 *    2. Delegating to GiftSuggester.
 *    3. Printing formatted results.
 *
 * Keeps user-facing logic separate from the recommendation engine,
 * simplifying unit tests and potential future GUI integration.
 */

class GiftManager {
private:
    /* Helper stages split for clarity and testability */
    void collectUserInput();
    void displaySuggestions() const;

    //Member data
    std::unique_ptr<GiftSuggester> suggester_;   //Owned recommendation engine
    std::string occasion_;                       //Parsed occasion
    GiftPreferences prefs_;                      //Parsed interests
    double budget_{};                            //Spending cap (0 ⇒ unlimited)

public:
    GiftManager();
    /**Entry point that drives full prompt -->-- suggest -->-- display.*/
    void run();
};
