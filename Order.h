#include "Item.h"
#include <vector>

class Order {
public:
	Order(std::vector<Item> order);

	std::vector<Item> myOrder;

	void addItems(Item item);
};

double getTotalPrice(Order order);