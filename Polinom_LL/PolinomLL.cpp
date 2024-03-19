#include "PolinomLL.h"

// Mislim da oce da ubacimo element sa odgovarajuci exponent 
// nema smisla po koeficijent jer oni ne govori nista o uredjenju

PolinomLL::PolinomLL(const PolinomLL& pol) : head(nullptr)
{
	if (pol.is_empty())
	{
		return;
	}

	// samim kopiranje glave rekurzivno se naprave kopija citave liste
	head = new node_clan();
	*head = pol.head;
}

PolinomLL::~PolinomLL()
{
	node_clan* tmp;
	while (head)
	{
		tmp = head->get_link();
		delete head;
		head = tmp;
	}
}

void PolinomLL::Coef(double coef, int exp)
{
	if (coef == 0.0)
		return;

	if (is_empty())
	{
		node_clan* novi = new node_clan(coef, exp);
		head = novi;
		return;
	}

	if (head->get_info().exp > exp)
	{
		node_clan* novi = new node_clan(coef, exp, head);
		head = novi;

		return;
	}

	node_clan* tmp = head;

	while (tmp)
	{
		// Isti eksponent tako da samo se sabiraju koeficijenti
		if (tmp->get_info().exp == exp)
		{
			tmp->add_coef(coef);
			return;
		}

		// Na kraju smo polinoma tkd novi clan ima najveci eksponent sada
		if (tmp->get_link() == nullptr)
		{
			node_clan* novi = new node_clan(coef, exp);
			tmp->add_link(novi);
			return;
		}

		// trenutni ima manji eksponent a sledeci ima veci
		// trenutni treba ukazuje na novi a novi na sledeci
		if (tmp->get_link()->get_info().exp > exp)
		{
			node_clan* novi = new node_clan(coef, exp, tmp->get_link());
			tmp->add_link(novi);
			return;
		}

		// Ako smo dosli ovde onda trenutni ima sigurno manji eksponent
		// sledeci ima veci ili jednak i znamo da postoji pa idemo u sledecu iteraciju

		tmp = tmp->get_link();
	}

	// ako smo dosli ovde nesto smo zajebali
	std::cerr << "Ovo ne sme da se izvrsi\n";
}

void PolinomLL::print() const
{
	node_clan* tmp = head;

	std::cout << head->get_info().coef;
	if (head->get_info().exp != 0)
		std::cout << "*x^" << head->get_info().exp << " ";

	tmp = head->get_link();

	while (tmp)
	{
		std::cout << " + " << tmp->get_info().coef;
		if (tmp->get_info().exp != 0)
			std::cout << "*x^" << tmp->get_info().exp;
		tmp = tmp->get_link();
	}
	std::cout << '\n';
}

PolinomLL& PolinomLL::operator+(const PolinomLL& op2)
{
	PolinomLL* novi = new PolinomLL(*this);

	if (op2.is_empty())
		return *novi;

	node_clan* tmp = op2.head;

	while (tmp)
	{
		novi->Coef(tmp->get_info().coef, tmp->get_info().exp);
		tmp = tmp->get_link();
	}

	return *novi;
}

PolinomLL& PolinomLL::operator*(const PolinomLL& op2)
{
	PolinomLL* novi = new PolinomLL();

	node_clan* pom1 = head;
	node_clan* pom2;

	while (pom1)
	{
		pom2 = op2.head;
		while (pom2)
		{
			double coef = pom1->get_info().coef * pom2->get_info().coef;
			int exp = pom1->get_info().exp + pom2->get_info().exp;

			novi->Coef(coef, exp);
			pom2 = pom2->get_link();
		}
		pom1 = pom1->get_link();
	}

	return *novi;
}
