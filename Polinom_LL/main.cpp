#include <iostream>

#include "PolinomLL.h"

int main(void)
{
	PolinomLL l1(new node_clan(1, 0));

	l1.print();

	l1.Coef(2, 6);
	l1.Coef(6, 2);
	l1.Coef(3, 4);
	l1.Coef(0, 69);

	l1.print();

	PolinomLL l2(new node_clan(3, 1));
	l2.Coef(2, 5);
	l2.Coef(3, 2);

	l2.print();

	PolinomLL l3 = l1 + l2;
	l3.print();

	PolinomLL l4 = l1 * l2;
	l4.print();

	return 0;
}