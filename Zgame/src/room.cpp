// room.cpp
#include "room.h"

namespace Game {

    Room::Room(const std::string& name, const std::string& description)
            : name(name), description(description) {}

    std::string Room::getName() const {
        return name;
    }

    std::string Room::getDescription() const {
        return description;
    }

} // namespace Game
