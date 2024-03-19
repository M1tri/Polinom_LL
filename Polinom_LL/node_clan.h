#pragma once

struct info
{
	double coef;
	int exp;

	info(double coef, int exp): coef(coef), exp(exp) {}
	info() : exp(0), coef(0) {}

	info& operator=(const info& inf)
	{
		coef = inf.coef;
		exp = inf.exp;

		return *this;
	}
};

class node_clan
{
private:
	info sadrzaj;
	node_clan* link;

public:
	node_clan()
	{
		sadrzaj = { 0, 0 };
		link = nullptr;
	}
	node_clan(double coef, int exp, node_clan* next = nullptr): 
		sadrzaj(coef, exp), link(next) {}
	node_clan(const node_clan& clan): 
		link(nullptr)
	{
		sadrzaj = clan.get_info();
		if (clan.link)
		{
			link = new node_clan(clan.link->get_info().coef, clan.link->get_info().exp);
		}
	};
	~node_clan() {}


	node_clan& operator=(const node_clan* clan)
	{
		sadrzaj = clan->get_info();
		if (clan->link)
		{
			link = new node_clan();
			*link = clan->link;
		}
		else
		{
			link = nullptr;
		}

		return *this;
	}

	info get_info() const
	{
		return sadrzaj;
	}
	
	node_clan* get_link() const
	{
		return link;
	}

	node_clan& operator*(const node_clan& op2)
	{
		node_clan* novi = new node_clan();
		novi->sadrzaj.coef = sadrzaj.coef * op2.sadrzaj.coef;
		novi->sadrzaj.exp = sadrzaj.exp + op2.sadrzaj.exp;

		return *novi;
	}

	void add_coef(double x)
	{
		sadrzaj.coef += x;
	}
	void add_link(node_clan* novi)
	{
		link = novi;
	}
};

