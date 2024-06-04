#include "item.h"

namespace Game {

    Item::Item(const std::string& name, const std::string& description)
            : name(name), description(description) {}

    std::string Item::getName() const {
        return name;
    }

    std::string Item::getDescription() const {
        return description;
    }

    // Operator overloading for equality
    bool Item::operator==(const Item& other) const {
        return name == other.name && description == other.description;
    }

    // Operator overloading for inequality
    bool Item::operator!=(const Item& other) const {
        return !(*this == other);
    }

    // Definition of getItemDetails function
    std::string getItemDetails(const Item& item) {
        return "Item: " + item.name + ", Description: " + item.description;
    }

} // namespace Game
