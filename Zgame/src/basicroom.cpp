#include "basicroom.h"
#include "game_exception.h"
#include <iostream>
#include <algorithm>

namespace Game {

    BasicRoom::BasicRoom(const std::string& name, const std::string& description)
            : Room(name, description) {}

    void BasicRoom::detailedDescription() const {
        std::cout << "Detailed description of " << name << ": " << description << std::endl;
    }

    void BasicRoom::describe() const {
        std::cout << "You are in " << name << ": " << description << std::endl;
        if (!itemContainer.getItems().empty()) {
            std::cout << "You see the following items:" << std::endl;
            for (const auto& item : itemContainer.getItems()) {
                std::cout << "- " << item.getName() << std::endl;
            }
        } else {
            std::cout << "There are no items in this room." << std::endl;
        }
    }

    void BasicRoom::addItem(const Item& item) {
        itemContainer.addItem(item);
    }

    const std::vector<Item>& BasicRoom::getItems() const {
        return itemContainer.getItems();
    }

    void BasicRoom::clearItems() {
        itemContainer.clearItems();
    }

    void BasicRoom::addConnectedRoom(Direction direction, BasicRoom* room) {
        connectedRooms.emplace_back(direction, room);
    }

    BasicRoom* BasicRoom::getConnectedRoom(Direction direction) const {
        auto it = std::find_if(connectedRooms.begin(), connectedRooms.end(), [&direction](const auto& pair) {
            return pair.first == direction;
        });
        if (it != connectedRooms.end()) {
            return it->second;
        }
        return nullptr;
    }

    Item BasicRoom::removeItem(const std::string& itemName) {
        try {
            return itemContainer.removeItem(itemName);
        } catch (const std::runtime_error& e) {
            throw GameException("Item '" + itemName + "' not found in the room.");
        }
    }

} // namespace Game
