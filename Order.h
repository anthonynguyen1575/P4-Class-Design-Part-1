#include "Item.h"
#include <vector>

class Order {
public:
	Order(std::vector<Item> order, std::vector<int> amountForEachItem);

	std::vector<Item> myOrder;
	std::vector<int> myItemCount;

	void addItems(Item item, int amount);
};

double getTotalPrice(Order order);
