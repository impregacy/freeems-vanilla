/*	globalConstants.h

	Copyright 2008 Fred Cooke

	This file is part of the FreeEMS project.

	FreeEMS software is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	FreeEMS software is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with any FreeEMS software.  If not, see <http://www.gnu.org/licenses/>.

	We ask that if you make any changes to this file you send them upstream to us at admin@diyefi.org

	Thank you for choosing FreeEMS to run your engine! */

/* Header file multiple inclusion protection courtesy eclipse Header Template	*/
/* and http://gcc.gnu.org/onlinedocs/gcc-3.1.1/cpp/ C pre processor manual		*/
#ifndef FILE_GLOBAL_CONSTANTS_H_SEEN
#define FILE_GLOBAL_CONSTANTS_H_SEEN


/* Types summary
 *
 * BEWARE : Be explicit!!
 *
 * char			8 bit (defaults to unsigned, but always specify signed/unsigned anyway)
 * short		16 bit (defaults to signed, but always specify signed/unsigned anyway)
 * int			16 bit DO NOT USE! (current compile flags make this 16 bits, but a change of flags could will change your program if you use this because they will all be 32 bit all of a sudden)
 * long			32 bit (defaults to signed, but always specify signed/unsigned anyway)
 * long long	64 bit (inefficient, avoid these, if using : defaults to signed, but always specify signed/unsigned anyway)
 * float		32 bit IEEE floating point numbers (inefficient, avoid these, used fixed point math)
 * double		64 bit IEEE floating point numbers (inefficient, avoid these, used fixed point math)
 */


/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&& Arrays here &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/

#ifndef NO_CONST_ARRAYS

/* Thermistor ADC to temperature transfer tables as generated by FreeTherm */
EXTERN const volatile unsigned short IATTransferTable[1024]; /* 2k */
EXTERN const volatile unsigned short CHTTransferTable[1024]; /* 2k */
EXTERN const volatile unsigned short MAFTransferTable[1024]; /* 2k */
EXTERN const volatile unsigned char TestTransferTable[2048]; /* 2k */

EXTERN const unsigned short memdumplength;
EXTERN const unsigned short maxBasicDatalogLength;

/* Interface version field 8 bit number, 8 bit number, 8 bit number, string of arbitrary length */
EXTERN const unsigned char interfaceVersionAndType[20]; /* Should be unique for serial comms */

/* Firmware version string of arbitrary length for display and human ID purposes */
EXTERN const unsigned char firmwareVersion[47]; /* Should change with even the slightest code change */

EXTERN const unsigned short dwellStartMasks[IGNITION_CHANNELS];
EXTERN const unsigned short ignitionMasks[IGNITION_CHANNELS];

EXTERN const unsigned char injectorMainOnMasks[INJECTION_CHANNELS];
EXTERN const unsigned char injectorMainOffMasks[INJECTION_CHANNELS];
EXTERN const unsigned char injectorMainEnableMasks[INJECTION_CHANNELS];
EXTERN const unsigned char injectorMainDisableMasks[INJECTION_CHANNELS];
EXTERN const unsigned char injectorMainGoHighMasks[INJECTION_CHANNELS];
EXTERN const unsigned char injectorMainGoLowMasks[INJECTION_CHANNELS];


#endif


/*&&&&&&&&&&&&&&&&&&&&&&&&&&& NON Arrays here &&&&&&&&&&&&&&&&&&&&&&&&&&&&*/

/* Main lookup tables */ // TODO volatile here or not?
EXTERN const volatile mainTable VETableMainFlash;
EXTERN const volatile mainTable VETableSecondaryFlash;
EXTERN const volatile mainTable VETableTertiaryFlash;
EXTERN const volatile mainTable LambdaTableFlash;

EXTERN const volatile mainTable IgnitionAdvanceTableMainFlash;
EXTERN const volatile mainTable IgnitionAdvanceTableSecondaryFlash;
EXTERN const volatile mainTable InjectionAdvanceTableMainFlash;
EXTERN const volatile mainTable InjectionAdvanceTableSecondaryFlash;

EXTERN const volatile mainTable VETableMainFlash2;
EXTERN const volatile mainTable VETableSecondaryFlash2;
EXTERN const volatile mainTable VETableTertiaryFlash2;
EXTERN const volatile mainTable LambdaTableFlash2;

EXTERN const volatile mainTable IgnitionAdvanceTableMainFlash2;
EXTERN const volatile mainTable IgnitionAdvanceTableSecondaryFlash2;
EXTERN const volatile mainTable InjectionAdvanceTableMainFlash2;
EXTERN const volatile mainTable InjectionAdvanceTableSecondaryFlash2;

EXTERN const volatile SmallTables1 SmallTablesAFlash;
EXTERN const volatile SmallTables2 SmallTablesBFlash;
EXTERN const volatile SmallTables3 SmallTablesCFlash;
EXTERN const volatile SmallTables4 SmallTablesDFlash;

EXTERN const volatile SmallTables1 SmallTablesAFlash2;
EXTERN const volatile SmallTables2 SmallTablesBFlash2;
EXTERN const volatile SmallTables3 SmallTablesCFlash2;
EXTERN const volatile SmallTables4 SmallTablesDFlash2;

EXTERN const volatile fixedConfig1 fixedConfigs1;
EXTERN const volatile fixedConfig2 fixedConfigs2;

//EXTERN const twoDTableUS ; // ?

/* Fuel correction tables */
EXTERN const volatile twoDTableUS primingVolumeTableFlash; // perhaps micro litres (cubic milli meters) would be good, 5 - 100 seem to be the norm 327.68 = 65535/200
EXTERN const volatile twoDTableUS injectorDeadTimeTableFlash; // display as ms, units in native 0.8us ticks
EXTERN const volatile twoDTableUS postStartEnrichmentTableFlash; // ?
EXTERN const volatile twoDTableUS engineTempEnrichmentTableFixedFlash; // ?
EXTERN const volatile twoDTableUS engineTempEnrichmentTablePercentFlash; // ?


/* Ignition correction tables */
EXTERN const volatile twoDTableUS dwellDesiredVersusVoltageTableFlash; // desired dwell vs voltage
EXTERN const volatile twoDTableUS dwellMaxVersusRPMTableFlash; // maximum dwell vs rpm


/* Fueling constants */
EXTERN const unsigned long masterFuelConstant;
EXTERN const unsigned long MAFFuelConstant;


/* These need to be changed if the timer period is changed at all */
/* The number of timer units it takes for the switch on scheduling code to run */
EXTERN const unsigned short injectorSwitchOnCodeTime;
/* The number of timer units it takes for the switch off scheduling code to run */
EXTERN const unsigned short injectorSwitchOffCodeTime;
/* The maximum a requested pulsewidth can be before it is truncated to this amount */
EXTERN const unsigned short injectorMaximumPulseWidth;
/* The minimum a requested pulsewidth can be before it is not switched on at all */
EXTERN const unsigned short injectorMinimumPulseWidth;


/* Ignition limits */
/* Ignition maximum dwell in timer units */
EXTERN const unsigned short ignitionMaximumDwell;

/* Ignition minimum dwell in timer units */
EXTERN const unsigned short ignitionMinimumDwell;

/* Ignition maximum delay post schedule tooth in timer units */
EXTERN const unsigned short ignitionMaximumDelayToDwellStartAfterTooth;


/* Time in ticks taken to run */
EXTERN const unsigned short leadingEdgePrimaryRPMInputCodeTime;
EXTERN const unsigned short trailingEdgePrimaryRPMInputCodeTime;
EXTERN const unsigned short leadingEdgeSecondaryRPMInputCodeTime;
EXTERN const unsigned short trailingEdgeSecondaryRPMInputCodeTime;

#else
	/* let us know if we are being untidy with headers */
	#warning "Header file GLOBAL_CONSTANTS_H seen before, sort it out!"
/* end of the wrapper ifdef from the very top */
#endif
