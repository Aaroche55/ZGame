#ifndef ITEM_H
#define ITEM_H

#include <string>

namespace Game {

    class Item {
        friend std::string getItemDetails(const Item& item); // Grant friendship

    public:
        Item(const std::string& name, const std::string& description); // Constructor accepting name and description

        std::string getName() const;
        std::string getDescription() const;

        // Operator overloading for equality and inequality
        bool operator==(const Item& other) const;
        bool operator!=(const Item& other) const;

    private:
        std::string name;
        std::string description;
    };

    // Declaration of getItemDetails function
    std::string getItemDetails(const Item& item);

} // namespace Game

#endif // ITEM_H
