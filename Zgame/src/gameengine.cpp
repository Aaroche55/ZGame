#include "gameengine.h"
#include "basicroom.h"

namespace Game {

    GameEngine::GameEngine()
            : currentRoomIndex(0), player("Player Name") {
        initializeRooms();
    }

    void GameEngine::start() {
        emit textOutput("Game started!");
        lookAround();
    }

    void GameEngine::movePlayer(Direction direction) {
        BasicRoom* currentRoom = dynamic_cast<BasicRoom*>(rooms[currentRoomIndex]);
        BasicRoom* nextRoom = currentRoom->getConnectedRoom(direction);

        if (nextRoom) {
            for (size_t i = 0; i < rooms.size(); ++i) {
                if (rooms[i] == nextRoom) {
                    currentRoomIndex = i;
                    break;
                }
            }
            emit textOutput(QString::fromStdString("Moved to " + nextRoom->getName()));
        } else {
            emit textOutput("You can't go that way.");
        }

        lookAround();
    }

    void GameEngine::takeItem() {
        emit textOutput("Taking all items in the current room.");

        BasicRoom* currentRoom = dynamic_cast<BasicRoom*>(rooms[currentRoomIndex]);
        if (!currentRoom) {
            emit textOutput("Error: Current room is not a BasicRoom.");
            return;
        }

        const std::vector<Item>& items = currentRoom->getItems();
        if (items.empty()) {
            emit textOutput("There are no items to take in this room.");
            return;
        }

        currentRoom->clearItems();
        emit textOutput("You took all items in the room.");
    }

    void GameEngine::lookAround() {
        BasicRoom* currentRoom = dynamic_cast<BasicRoom*>(rooms[currentRoomIndex]);
        if (!currentRoom) {
            emit textOutput("Error: Current room is not a BasicRoom.");
            return;
        }

        emit textOutput("You are in: " + QString::fromStdString(currentRoom->getName()));
        emit textOutput(QString::fromStdString(currentRoom->getDescription()));

        const auto& items = currentRoom->getItems();
        if (items.empty()) {
            emit textOutput("There are no items in this room.");
        } else {
            emit textOutput("You see the following items:");
            for (const auto& item : items) {
                emit textOutput("- " + QString::fromStdString(item.getName()));
            }
        }
    }

    void GameEngine::initializeRooms() {
        BasicRoom* Foyer = new BasicRoom("Foyer", "The door is locked behind you, find a key and escape!");
        BasicRoom* Hallway = new BasicRoom("Hallway", "A long hallway with a few doors.");
        BasicRoom* LivingRoom = new BasicRoom("Living Room", "A cozy living room lit by candles.");
        BasicRoom* Kitchen = new BasicRoom("Kitchen", "A small kitchen with a stove and a fridge.");
        BasicRoom* DiningRoom = new BasicRoom("Dining Room", "A large dining room with a long table.");
        BasicRoom* KidsRoom = new BasicRoom("Kids Room", "A colorful kids room with toys scattered around.");
        BasicRoom* MasterBedroom = new BasicRoom("Master Bedroom", "A spacious bedroom with a large bed.");
        BasicRoom* Office = new BasicRoom("Office", "A cluttered office with a desk and a computer.");
        BasicRoom* Exit = new BasicRoom("Exit", "Congratulations, you escaped!");

        rooms.push_back(Foyer);
        rooms.push_back(Hallway);
        rooms.push_back(LivingRoom);
        rooms.push_back(Kitchen);
        rooms.push_back(DiningRoom);
        rooms.push_back(KidsRoom);
        rooms.push_back(MasterBedroom);
        rooms.push_back(Office);
        rooms.push_back(Exit);

        // Add items to the rooms
        Hallway->addItem(Item("Post", "A number of unopened bills."));
        LivingRoom->addItem(Item("Candle", "A lit candle."));
        Kitchen->addItem(Item("Knife", "A sharp kitchen knife."));
        DiningRoom->addItem(Item("Wine", "A bottle of red wine."));
        KidsRoom->addItem(Item("Toy", "A small toy car."));
        MasterBedroom->addItem(Item("Book", "A book on the nightstand."));
        Office->addItem(Item("Key", "A shiny golden key."));

        // Add connected rooms
        Foyer->addConnectedRoom(Forward, Hallway);
        Foyer->addConnectedRoom(Left, LivingRoom);
        Foyer->addConnectedRoom(Right, Kitchen);
        Foyer->addConnectedRoom(Backward, Exit);

        Hallway->addConnectedRoom(Backward, Foyer);
        Hallway->addConnectedRoom(Right, DiningRoom);
        Hallway->addConnectedRoom(Forward, MasterBedroom);
        Hallway->addConnectedRoom(Left, KidsRoom);

        LivingRoom->addConnectedRoom(Right, Foyer);
        LivingRoom->addConnectedRoom(Forward, KidsRoom);

        Kitchen->addConnectedRoom(Left, Foyer);
        Kitchen->addConnectedRoom(Forward, DiningRoom);

        DiningRoom->addConnectedRoom(Left, Hallway);
        DiningRoom->addConnectedRoom(Backward, Kitchen);

        KidsRoom->addConnectedRoom(Backward, LivingRoom);
        KidsRoom->addConnectedRoom(Right, Hallway);
        KidsRoom->addConnectedRoom(Forward, Office);

        MasterBedroom->addConnectedRoom(Backward, Hallway);
        MasterBedroom->addConnectedRoom(Left, Office);

        Office->addConnectedRoom(Backward, KidsRoom);
        Office->addConnectedRoom(Right, MasterBedroom);

        Exit->addConnectedRoom(Forward, Foyer);
    }

} // namespace Game
