#include <vector>
#include "Item.h"

class Store {
public:
	Store(std::vector<Item> inventory);

	std::vector<Item> myInventory;
};

void printStoreContents(Store inventory);