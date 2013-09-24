//Copyright (c) 2013 Bradley M. Small 
#include <iostream>
#include "cut.h"
#include "combo.h"
#include "tests.h"
#include <algorithm>
#include <cmath>

const bool debug ( false );

bool isValid(Combo combo) {
	// apply rules here
	bool retVal (true);
	Tests t;
	const size_t mostContiguous ( 3 );
	const size_t mostPresent ( 4 );
	const size_t maxAdjacent ( 2 );
	
	if(t.MostContiguous(combo) > mostContiguous) {
		if(debug) std::cout << "\tMaxContig:" << combo;
		retVal = false;
	}
	if(t.MostPresent(combo) > mostPresent) {
		if(debug) std::cout << "\tMaxPresent:" << combo;
		retVal = false;
	}
	if(t.MaxAdjacent(combo) > maxAdjacent) {
		if(debug) std::cout << "\tMaxAdjacent:" << combo;
		retVal = false;
	}

	return retVal;
}

int main( void ) {
	Cut cut('A', 'A', 'E');
	Combo combo(cut, 6);
	
	std::vector<Combo> codeSeries;

	for(;!combo.isRolled();){
		if( isValid(combo) )
			codeSeries.push_back(combo);
		++combo;
	}
	
	std::random_shuffle(codeSeries.begin(), codeSeries.end());

	int width = ceil(log10(codeSeries.size()));
	int num(1);
	
	for (std::vector<Combo>::iterator x = codeSeries.begin(); x < codeSeries.end(); ++x) {
		std::cout.width(width);
		std::cout.fill('0');
		std::cout << num++ << " : " << *x;
	}
	return 0;
}
