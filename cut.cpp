//Copyright (c) 2013 Bradley M. Small 
#include <iostream>
#include "cut.h"

Cut::Cut(char Val, char Low, char High) : low(Low), high(High), val(Val), rolled(false) { } 

Cut::Cut(const Cut& other) : low(other.low), high(other.high), val(other.val), rolled(false) { }

Cut& Cut::operator++() {
	if(++val > high) {
		val = low;
		rolled=true;
	}
	return *this;
}

Cut& Cut::operator--() {
	if(--val < low) {
		val = high;
		rolled=true;
	}
	return *this;
}

Cut Cut::operator++(int) {
	Cut result(*this);
	++(*this);
	return result;
}

Cut Cut::operator--(int) {
	Cut result(*this);
	--(*this);
	return result;
}

bool Cut::isRolled() {
	return (rolled)?rolled=false, true:false;
}

bool Cut::operator==(const Cut & rhs) const {
	return (this->val == rhs.val);
}

bool operator<(const Cut & lhs, const Cut & rhs) {
	return (lhs.val < rhs.val);
}

std::ostream& operator<<(std::ostream& stream, const Cut& cut) {
	stream << cut.val;
	return stream;
}

int operator-(const Cut & lhs, const Cut & rhs) {
	return (lhs.val - rhs.val);
}
