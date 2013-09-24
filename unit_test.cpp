#include "tests.h"
#include "combo.h"
#include "cut.h"
#define BOOST_TEST_MODULE CodeSeriesTests
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( test_class_cut )
BOOST_AUTO_TEST_CASE( test_cut_ctor0 ) 
{
	Cut a;

	BOOST_CHECK_EQUAL( a.GetHigh(), 'Z' );
	BOOST_CHECK_EQUAL( a.GetLow() , 'A' );
	BOOST_CHECK_EQUAL( a.GetVal() , 'A' );
}
BOOST_AUTO_TEST_CASE( test_cut_ctor1 ) 
{
	Cut b('Q', 'P', 'R');

	BOOST_CHECK_EQUAL( b.GetHigh(), 'R' );
	BOOST_CHECK_EQUAL( b.GetLow() , 'P' );
	BOOST_CHECK_EQUAL( b.GetVal() , 'Q' );
}
BOOST_AUTO_TEST_CASE( test_cut_ctor2 ) 
{
	Cut c('J');

	BOOST_CHECK_EQUAL( c.GetHigh(), 'Z' );
	BOOST_CHECK_EQUAL( c.GetLow() , 'A' );
	BOOST_CHECK_EQUAL( c.GetVal() , 'J' );

}
BOOST_AUTO_TEST_CASE( test_cut_plusminus ) 
{
	Cut d;

	BOOST_CHECK_EQUAL( d.GetVal() , 'A' );
	d++;
	BOOST_CHECK_EQUAL( d.GetVal() , 'B' );
	++d;
	BOOST_CHECK_EQUAL( d.GetVal() , 'C' );
	--d;
	BOOST_CHECK_EQUAL( d.GetVal() , 'B' );
	d--;
	BOOST_CHECK_EQUAL( d.GetVal() , 'A' );
	d--;
	BOOST_CHECK_EQUAL( d.GetVal() , 'Z' );
	d++;
	BOOST_CHECK_EQUAL( d.GetVal() , 'A' );

}
BOOST_AUTO_TEST_SUITE_END()
