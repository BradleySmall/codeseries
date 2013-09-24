//Copyright (c) 2013 Bradley M. Small 
#ifndef _COMBO_H_
#define _COMBO_H_
#include <vector>

#include "cut.h"
class Combo {
public:
	Combo(Cut cut = Cut('A', 'A', 'E'), int Count = 6);
	Combo(const Combo & other);
	Combo& operator++();
	Combo& operator--();
	Combo  operator++(int);
	Combo  operator--(int);
	friend class Tests;
	friend std::ostream& operator<<(std::ostream& stream, const Combo& c);
	bool isRolled();
private:
	int count;
	std::vector<Cut> comb;
	bool rolled;
};
#endif
