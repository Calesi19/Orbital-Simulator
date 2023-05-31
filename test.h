#pragma once

/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/


#include "testPosition.h"
#include "testSatellite.h"
#include "testVelocity.h"

 /*****************************************************************
  * TEST RUNNER
  * Runs all the unit tests
  ****************************************************************/
void testRunner()
{
	TestPosition().run();
	//TestSatellite().run();
	TestVelocity().run();
}
