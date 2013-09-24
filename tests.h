//Copyright (c) 2013 Bradley M. Small 
#ifndef _TESTS_H_
#define _TESTS_H_

#include "combo.h"
#include "cut.h"

class Tests {
public:
	size_t MostContiguous  ( const Combo & combo );
	size_t LeastContiguous ( const Combo & combo );
	size_t MostPresent     ( const Combo & combo );
	size_t LeastPresent    ( const Combo & combo );
	size_t MaxAdjacent     ( const Combo & combo );
	size_t MinAdjacent     ( const Combo & combo );
private:
};

#endif
