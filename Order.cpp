#include "Order.h"

Order::Order(std::vector<Item> order)
	: myOrder { order } { 
}

void Order::addItems(Item item) {
	myOrder.push_back(item);
}

double getTotalPrice(Order order) {
	std::vector<Item> items = order.myOrder;
	double total = 0;

	for (std::size_t i = 0; i < items.size(); i++) {
		Item item = items[i];
		total += item.myItemPrice;
	}

	return total;
}
