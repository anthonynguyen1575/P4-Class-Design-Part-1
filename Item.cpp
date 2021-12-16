#include "Item.h"

Item::Item(std::string name, long id, double price, int stock)
	: myItemName{ name }, myItemID{ id }, myItemPrice{ price },
	myItemStock{ stock } { }