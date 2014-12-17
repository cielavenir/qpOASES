/*
 *	This file is part of qpOASES.
 *
 *	qpOASES -- An Implementation of the Online Active Set Strategy.
 *	Copyright (C) 2007-2014 by Hans Joachim Ferreau, Andreas Potschka,
 *	Christian Kirches et al. All rights reserved.
 *
 *	qpOASES is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU Lesser General Public
 *	License as published by the Free Software Foundation; either
 *	version 2.1 of the License, or (at your option) any later version.
 *
 *	qpOASES is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *	See the GNU Lesser General Public License for more details.
 *
 *	You should have received a copy of the GNU Lesser General Public
 *	License along with qpOASES; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


/**
 *	\file debugging/cpp/debug_janick1.cpp
 *	\author Hans Joachim Ferreau
 *	\version 3.0
 *	\date 2007-2014
 *
 *	Example that causes troubles when hotstarting.
 */



#include <qpOASES.hpp>
#include <qpOASES/UnitTesting.hpp>

#include <stdio.h>


//#define __MAKE_POS_DEF__
#undef __MAKE_POS_DEF__

int main( )
{
	USING_NAMESPACE_QPOASES

	int nWSR = 100;
	/* Setting up QProblem object. */
	SQProblem example( 11,3 );

	Options options;
	options.setToFast();
	//options.setToDefault();
	//options.initialStatusBounds = qpOASES::ST_INACTIVE;
	example.setOptions( options );


	/* Setup data of first QP. */
	real_t H[11*11] = {
	6.20100988531485e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	-3.84861756786704e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	-7.43268431723266e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 1.00000000000000e-01,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 2.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	-3.84861756786704e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 5.41188294952735e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 4.61304826562310e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 2.10000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 1.00000000000000e-01,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 2.01000000000000e+01,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 2.10000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	-7.43268431723266e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 4.61304826562310e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	-1.73544778892019e+01,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 2.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 2.00000000000000e+01
	};
	real_t g[11] =	{
	-1.28196485091041e-07,	 1.13322235104306e-08,	 4.52417455660281e-06,	 1.95881304363781e-07,	 1.61991589634459e-06,	 2.69786724710014e-09,	 0.00000000000000e+00,	 0.00000000000000e+00,	-1.18185813270785e+02,	 9.58903285459640e-06,	 3.82276791847511e-06
	};
	real_t zLow[11] =	{
	-1.07876236159966e+01,	-1.00000000002784e+12,	-1.00000000000000e+12,	 0.00000000000000e+00,	-7.00000000000000e+00,	-2.60479553037772e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	-4.50000000000000e+01,	-1.00000000000000e+12
	};
	real_t zUpp[11] =	{
	9.99999999989212e+11,	 9.99999999972157e+11,	 1.00000000000000e+12,	 4.68471854329546e+01,	 7.00000000000000e+00,	 9.99999999997395e+11,	 1.00000000000000e+12,	 1.00000000000000e+12,	 0.00000000000000e+00,	 4.50000000000000e+01,	 1.00000000000000e+12
	};
	real_t D[11*3] =	{
	1.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	-1.00000000000000e-02,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	-1.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,	-1.00000000000000e-02,	-0.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 1.00000000000000e+00,	 0.00000000000000e+00,	-1.00000000000000e-02,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00
	};
	real_t dLow[3] =	{
	-1.00000000000000e+12,	-1.00000000000000e+12,	-1.00000000000000e+12
	};
	real_t dUpp[3] =	{
	2.12376384003361e-01,	 4.78762361599664e+00,	 8.95204469622285e-01
	};

	#ifdef __MAKE_POS_DEF__
	H[9*11+9] += 30;
	#endif
	returnValue status = example.init( H,g,D,zLow,zUpp,dLow,dUpp, nWSR );
	printf("\nqpOASES_status = %d\n", (int)status );

	/* Get and print solution of first QP. */
	real_t xOpt[11];
	real_t yOpt[11+3];
	example.getPrimalSolution( xOpt );
	example.getDualSolution( yOpt );
	printf("first QP:\n");
	for (int ii =0; ii<11; ++ii )	{
		printf("x[%d] = %.3e\n", ii, xOpt[ii]);
	}

	/* Compute KKT tolerances */
	real_t stat, feas, cmpl;

	getKKTResidual(	11,3,
					H,g,D,zLow,zUpp,dLow,dUpp,
					xOpt,yOpt,
					stat,feas,cmpl
					);
	printf( "\nstat = %e\nfeas = %e\ncmpl = %e\n", stat,feas,cmpl );

	QPOASES_TEST_FOR_TOL( stat,1e-9 );
	QPOASES_TEST_FOR_TOL( feas,1e-7 );
	QPOASES_TEST_FOR_TOL( cmpl,1e-15 );



	nWSR = 100;

	/* Setup data of second QP. */
	real_t H2[11*11] = {
	6.20100988531485e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	-3.84861756786704e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	-7.43268433147671e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 1.00000000000000e-01,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 2.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	-3.84861756786704e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 5.41188294952735e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 4.61304827446359e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 2.10000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 1.00000000000000e-01,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 2.01000000000000e+01,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 2.10000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	-7.43268433147671e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 4.61304827446359e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	-1.73544778550554e+01,	 0.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 2.00000000000000e+00,	 0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 2.00000000000000e+01
	};
	real_t g2[11] =	{
	-6.57752219998813e-04,	 3.61759517784935e-04,	-7.51224940044046e-05,	 6.01232615232452e-04,	 1.23562395380546e-04,	 4.59040118744990e-05,	 0.00000000000000e+00,	 0.00000000000000e+00,	-1.18185813270785e+02,	 3.38813178901720e-21,	 0.00000000000000e+00
	};
	real_t zLow2[11] =	{
	-2.41857058824735e-08,	-2.77410094895458e-10,	-9.90563843681406e-09,	-3.85694249871449e-08,	 4.50633213817586e-14,	-2.22044604925031e-15,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	-4.49999952054836e+01,	-1.00000000000000e+12
	};
	real_t zUpp2[11] =	{
	-2.41857058824735e-08,	-2.77410094895458e-10,	-9.90563843681406e-09,	-3.85694249871449e-08,	 4.50633213817586e-14,	-2.22044604925031e-15,	 1.00000000000000e+12,	 1.00000000000000e+12,	 0.00000000000000e+00,	 4.50000047945164e+01,	 1.00000000000000e+12,
	};
	real_t D2[11*3] =	{
	1.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	-1.00000000000000e-02,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,
	-1.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,	-1.00000000000000e-02,	-0.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,	-0.00000000000000e+00,
	0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00,	 1.00000000000000e+00,	 0.00000000000000e+00,	-1.00000000000000e-02,	 0.00000000000000e+00,	 0.00000000000000e+00,	 0.00000000000000e+00
	};
	real_t dLow2[3] =	{
	-1.00000000000000e+12,	-1.00000000000000e+12,	-1.00000000000000e+12
	};
	real_t dUpp2[3] =	{
	2.12376363329877e-01,	 4.78762363667012e+00,	 8.95204496600957e-01
	};
	#ifdef __MAKE_POS_DEF__
	H2[9*11+9] += 30;
	#endif


	status = example.hotstart( H2,g2,D2,zLow2,zUpp2,dLow2,dUpp2, nWSR );
	printf("qpOASES_status = %d\n", (int)status );

	example.getPrimalSolution( xOpt );
	example.getDualSolution( yOpt );
	printf("second QP:\n");
	for (int ii =0; ii<11; ++ii )	{
		printf("x[%d] = %.3e\n", ii, xOpt[ii]);
	}

	/* Compute KKT tolerances */
	getKKTResidual(	11,3,
					H2,g2,D2,zLow2,zUpp2,dLow2,dUpp2,
					xOpt,yOpt,
					stat,feas,cmpl
					);
	printf( "stat = %e\nfeas = %e\ncmpl = %e\n", stat,feas,cmpl );

	QPOASES_TEST_FOR_TOL( stat,1e-9 );
	QPOASES_TEST_FOR_TOL( feas,1e-7 );
	QPOASES_TEST_FOR_TOL( cmpl,1e-12 );


	return TEST_PASSED;
}


/*
 *	end of file
 */
