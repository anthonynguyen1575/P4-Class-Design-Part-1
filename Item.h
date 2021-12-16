#pragma once
#include <string>

class Item {
public:
	Item(std::string name, long id, double price, int stock);

	std::string myItemName;
	long myItemID;
	double myItemPrice;
	int myItemStock;
};