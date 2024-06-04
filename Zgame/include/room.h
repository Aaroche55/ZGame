// room.h
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "item.h"

namespace Game {

    class Room {
    public:
        Room(const std::string& name, const std::string& description);
        virtual ~Room() = default;

        virtual std::string getName() const;
        virtual std::string getDescription() const;
        virtual void describe() const = 0;
        virtual const std::vector<Item>& getItems() const = 0;

    protected:
        std::string name;
        std::string description;
    };

} // namespace Game

#endif // ROOM_H
