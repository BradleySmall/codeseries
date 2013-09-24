//Copyright (c) 2013 Bradley M. Small 
#include "tests.h"
#include "combo.h"
#include "cut.h"
#include <vector>
#include <cstdlib>
#include <map>

size_t Tests::MostContiguous( const Combo & combo ){
	size_t High (1), CurrentCount( 1 );

	for (std::vector<Cut>::const_iterator x = combo.comb.begin() + 1; x < combo.comb.end(); ++x) {
		if(*x == *(x-1)) {
			++CurrentCount;
			if(CurrentCount > High)
				High = CurrentCount;
		} else {
			CurrentCount = 1;
		}
	}
	return (High);
}

size_t Tests::LeastContiguous ( const Combo & combo ){
	size_t Low(combo.comb.size()), CurrentCount(1);
	for (std::vector<Cut>::const_iterator x = combo.comb.begin() + 1; x < combo.comb.end(); ++x) {
		if(*x == *(x-1)) {
			++CurrentCount;
		} else {
			if(CurrentCount < Low)
				Low = CurrentCount;
			CurrentCount = 1;
		}
	}
	return (Low);
}

size_t Tests::MostPresent ( const Combo & combo ){
	std::map<Cut,size_t> cutMap;
	size_t Max ( 1 );
	for (std::vector<Cut>::const_iterator x = combo.comb.begin(); x < combo.comb.end(); ++x) {
	if(cutMap.find(*x) == cutMap.end()) {
			cutMap[*x] = 1;
		} else {
			++cutMap[*x];
		}
	}
	for(std::map<Cut, size_t>::const_iterator x = cutMap.begin(); x != cutMap.end(); ++x) {
		if(x->second > Max)
			Max = x->second;
	}
	return (Max);
}

size_t Tests::LeastPresent ( const Combo & combo ){
	std::map<Cut,size_t> cutMap;
	size_t Min ( combo.comb.size() );
	for (std::vector<Cut>::const_iterator x = combo.comb.begin(); x < combo.comb.end(); ++x) {
		if(cutMap.find(*x) == cutMap.end()) {
			cutMap[*x] = 1;
		} else {
			++cutMap[*x];
		}
	}
	for(std::map<Cut, size_t>::const_iterator x = cutMap.begin(); x != cutMap.end();++x) {
		if(x->second < Min)
			Min = x->second;
	}
	return(Min);
}

size_t Tests::MaxAdjacent ( const Combo & combo ){
	size_t Max ( 0 );
	size_t CurrentDiff ( 0 );
	for (std::vector<Cut>::const_iterator x = combo.comb.begin() + 1; x < combo.comb.end(); ++x) {
		
		CurrentDiff = abs(*x - *(x-1));
		if (CurrentDiff > Max)
			Max = CurrentDiff;
	}
	return (Max);
}

size_t Tests::MinAdjacent ( const Combo & combo ){
	size_t Min ( 25 );
	size_t CurrentDiff ( 0 );
	for (std::vector<Cut>::const_iterator x = combo.comb.begin() + 1; x < combo.comb.end(); ++x) {
		CurrentDiff = abs(*x - *(x-1));
		if (CurrentDiff < Min)
			Min = CurrentDiff;
	}
	return (Min);
}
