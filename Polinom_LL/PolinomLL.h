#pragma once

#include "node_clan.h"

#include <iostream>

class PolinomLL
{
private:
	node_clan* head;

public:
	PolinomLL(node_clan* head = nullptr) : head(head) {}
	PolinomLL(const PolinomLL& pol);
	~PolinomLL();

	void Coef(double coef, int exp);
	void print() const;
	bool is_empty() const
	{
		return head == nullptr;
	}
	// Zadatak 1.
	PolinomLL& operator+(const PolinomLL& op2);

	// Zadatak 2.
	PolinomLL& operator*(const PolinomLL&op2);
};

