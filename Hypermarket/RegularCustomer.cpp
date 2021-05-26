#include "RegularCustomer.h"

double RegularCustomer::personalDiscount()
{
	double disc = (m_totalCost / 1000 <= 15) ? m_totalCost / 1000 : 15;
	return disc;
}
