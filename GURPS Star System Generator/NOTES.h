#pragma once

/*

** STAR.CPP **
- complete 'get' methods
- add generators to constructor
- make sure mass generator for companion star is accurate in how it steps down the mass chart
- add mass generator for garden stars



ECCENTRICITY GENERATOR

		int roll{ Dice::roll_D6(3) };

		switch (roll) {
			case (3)	:
				eccentricity = 0;
				break;
			case (4)	:
				eccentricity = 0.1;
				break;
			case (5)	:
				eccentricity = 0.2;
				break;
			case (6)	:
				eccentricity = 0.3;
				break;
			case (7)	:
			case (8)	:
				eccentricity = 0.4;
				break;
			case (9)	:
			case (10)	:
			case (11)	:
				eccentricity = 0.5;
				break;
			case (12)	:
			case (13)	:
				eccentricity = 0.6;
				break;
			case (14)	:
			case (15)	:
				eccentricity = 0.7;
				break;
			case (16)	:
				eccentricity = 0.8;
				break;
			case (17)	:
				eccentricity = 0.9;
				break;
			default		: // anything 18 and up
				eccentricity = 0.95;
		}

*/