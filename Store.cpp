#include <iostream>
#include "Store.h"

Store::Store(std::vector<Item> inventory)
	: myInventory { inventory } { }

void printStoreContents(Store inventory) {
	std::vector<Item> items = inventory.myInventory;
	std::cout << "Store:\n";

	for(std::size_t i = 0; i < items.size(); i++) {
		Item item = items[i];
		std::cout << item.myItemName << " x " << std::to_string(item.myItemStock) << "\n";
	}
}