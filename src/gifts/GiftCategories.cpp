#include "GiftCategories.h"
#include <unordered_map>

std::string GiftCategories::toString(const Category cat) {
    static const std::unordered_map<Category, std::string> map{
        {Category::kValentines,  "Valentine's Day"},
        {Category::kAnniversary, "Anniversary"},
        {Category::kBirthday,    "Birthday"},
        {Category::kBooks,       "books"},
        {Category::kGadgets,     "gadgets"},
        {Category::kFashion,     "fashion"},
        {Category::kOutdoors,    "outdoors"}
    };
    return map.at(cat);
}

GiftCategories::Category GiftCategories::fromString(const std::string& str) {
    static const std::unordered_map<std::string, Category> map{
        {"Valentine's Day", Category::kValentines},
        {"Anniversary",     Category::kAnniversary},
        {"Birthday",        Category::kBirthday},
        {"books",           Category::kBooks},
        {"gadgets",         Category::kGadgets},
        {"fashion",         Category::kFashion},
        {"outdoors",        Category::kOutdoors}
    };
    return map.at(str);
}
