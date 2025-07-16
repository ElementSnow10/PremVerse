#pragma once
#include <string>
#include <string_view>

/**
 *  Centralised catalogue of supported gift-related categories (both occasions and interests).
 *  Provides bidirectional conversion. (toString() and fromString())
 *  Utilities and string constants used as map keys.
 */

struct GiftCategories {

    enum class Category {
        kValentines,
        kAnniversary,
        kBirthday,
        kBooks,
        kGadgets,
        kFashion,
        kOutdoors
    };

    //Utility converters.
    static std::string  toString(Category cat);
    static Category     fromString(const std::string& str);

    //String literals used across the code base.
    inline static constexpr std::string_view kValentines { "Valentine's Day" };
    inline static constexpr std::string_view kAnniversary{ "Anniversary"     };
    inline static constexpr std::string_view kBirthday   { "Birthday"        };
    inline static constexpr std::string_view kBooks      { "books"           };
    inline static constexpr std::string_view kGadgets    { "gadgets"         };
    inline static constexpr std::string_view kFashion    { "fashion"         };
    inline static constexpr std::string_view kOutdoors   { "outdoors"        };
};
