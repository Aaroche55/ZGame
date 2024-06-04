#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class ItemContainer {
public:
    void addItem(const T& item) {
        items.push_back(item);
    }

    const std::vector<T>& getItems() const {
        return items;
    }

    void clearItems() {
        items.clear();
    }

    T removeItem(const std::string& itemName) {
        auto it = std::find_if(items.begin(), items.end(), [&itemName](const T& item) {
            return item.getName() == itemName;
        });
        if (it != items.end()) {
            T removedItem = *it;
            items.erase(it);
            return removedItem;
        }
        throw std::runtime_error("Item not found");
    }

private:
    std::vector<T> items;
};

#endif // ITEMCONTAINER_H
