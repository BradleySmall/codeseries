//Copyright (c) 2013 Bradley M. Small 
#ifndef _CUT_H_
#define _CUT_H_
#include<iostream>
class Cut {
public:
	Cut(char Val='A', char Low='A', char High='Z');
	Cut(const Cut& other);
	bool isRolled(); 
	Cut& operator++();
	Cut& operator--();
	Cut  operator++(int);
	Cut  operator--(int);
	bool operator==(const Cut & rhs) const ;
	friend bool operator<(const Cut & lhs, const Cut & rhs);
	friend int operator-(const Cut&, const Cut& );
	friend std::ostream& operator<<(std::ostream& stream, const Cut& cut);
	char GetHigh() const {return high;};
	char GetLow()  const {return low; };
	char GetVal()  const {return val; };
private:
	char low;
	char high;
	char val;
	bool rolled;
};
#endif
