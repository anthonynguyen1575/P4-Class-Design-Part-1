#include "Order.h"
#include <iostream>

Order::Order(std::vector<Item> order, std::vector<int> amountForEachItem)
	: myOrder{ order }, myItemCount{ amountForEachItem } { }

void Order::addItems(Item item, int amount) {
	myOrder.push_back(item);
	myItemCount.push_back(amount);
}

double getTotalPrice(Order order) {
	std::vector<Item> items = order.myOrder;
	std::vector<int> amount = order.myItemCount;
	double total = 0;

	for (std::size_t i = 0; i < items.size(); i++) {
		Item item = items[i];
		int count = amount[i];
		total += item.myItemPrice * count;
	}

	return total;
}
