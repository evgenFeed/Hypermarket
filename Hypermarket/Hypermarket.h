#pragma once

#include <vector>
#include "Product.h"

class Hypermarket
{
public:
	Hypermarket();



private:
	std::vector<Product*> m_availableProds;

};

