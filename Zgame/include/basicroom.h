#ifndef BASICROOM_H
#define BASICROOM_H

#include "room.h"
#include "item.h"
#include "gameengine.h"
#include "itemContainer.h"
#include "describable.h"
#include <vector>
#include <utility>

namespace Game {

    class BasicRoom : public Room, public Describable {
        ItemContainer<Item> itemContainer;
    public:
        BasicRoom(const std::string& name, const std::string& description);

        void detailedDescription() const override;
        void describe() const override;
        void addItem(const Item& item);
        Item removeItem(const std::string& itemName);
        void addConnectedRoom(Direction direction, BasicRoom* room);
        [[nodiscard]] BasicRoom* getConnectedRoom(Direction direction) const;
        void clearItems();
        const std::vector<Item>& getItems() const override;

    private:
        std::vector<std::pair<Direction, BasicRoom*>> connectedRooms;
    };

} // namespace Game

#endif // BASICROOM_H
