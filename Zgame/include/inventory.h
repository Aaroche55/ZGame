#pragma once
#include <vector>
#include <stdexcept> // Added this line to include the stdexcept library

namespace Game {
    template<typename T>
    class Inventory {
    public:
        void addItem(const T& item);
        const T& getItem(int index) const;
    private:
        std::vector<T> items;
    };

    template<typename T>
    void Inventory<T>::addItem(const T& item) {
        items.push_back(item);
    }

    template<typename T>
    const T& Inventory<T>::getItem(int index) const {
        if (index < 0 || index >= items.size()) {
            throw std::out_of_range("Index out of range");
        }
        return items[index];
    }
}
