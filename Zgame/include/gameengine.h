#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include "room.h" // Include Room header
#include "player.h" // Include Player header
#include "item.h"
#include <QObject> // Include QObject for signals and slots

namespace Game {

    enum Direction {
        Forward,
        Backward,
        Left,
        Right
    };

    class GameEngine : public QObject { // Inherit from QObject for signals and slots
    Q_OBJECT // Macro required for Qt's meta-object system
    public:
        GameEngine(); // Constructor declaration
        void start();
        void movePlayer(Direction direction);
        void takeItem();
        void lookAround();

    signals:
        void textOutput(const QString& text); // Signal to emit text messages

    private:
        void initializeRooms();
        std::vector<Room*> rooms; // Using base class Room
        int currentRoomIndex;
        Player player; // Player member variable
        std::vector<Item> items; // Items member variable

    };

}

#endif // GAMEENGINE_H
