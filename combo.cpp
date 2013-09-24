//Copyright (c) 2013 Bradley M. Small 
#include "combo.h"

Combo::Combo(Cut cut, int Count) : count(Count) , comb(Count,cut), rolled(false){}

Combo::Combo(const Combo& other) : count(other.count), comb(other.comb), rolled(false){}

Combo& Combo::operator++() {
	int rollCount( 0 );
	for (std::vector<Cut>::reverse_iterator x = comb.rbegin(); x < comb.rend(); ++x){
		++(*x);
		if(!(*x).isRolled()) break;
		++rollCount;
	}
	if (rollCount == count) 
		rolled = true;
	return *this;
}

Combo& Combo::operator--() {
	int rollCount( 0 );
	for (std::vector<Cut>::reverse_iterator x = comb.rbegin(); x < comb.rend(); ++x){
		--(*x);
		if(!(*x).isRolled()) break;
		++rollCount;
	}
	if (rollCount == count) 
		rolled = true;

	return *this;
}

Combo Combo::operator++(int) {
	Combo c(*this);
	++(*this);
	return c;
}

Combo Combo::operator--(int) {
	Combo c(*this);
	--(*this);
	return c;
}

bool Combo::isRolled() {
	return (rolled)?rolled=false, true:false;
}

std::ostream& operator<<(std::ostream& stream, const Combo &c) {

	for (std::vector<Cut>::const_iterator x = c.comb.begin(); x < c.comb.end(); ++x){
		stream << (*x);
	}
	stream << std::endl;
	return stream;
}

