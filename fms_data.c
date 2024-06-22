/*
 ============================================================================
 Name        : fms_data.c
 Author      : Mark Mikhailov
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include "fms.h"

FMS generate_fms_data(){								//Function that allows access to the data;

	Time DepLH1 = {11,30}, ArrLH1 = {14,30},						//Definition of arrival and departure times;
		 DepLH2 = {15,30}, ArrLH2 = {16,30},
		 DepLH3 = {18,30}, ArrLH3 = {20,30},
		 DepLH4 = {20,45}, ArrLH4 = {22,00},
		 DepLH5 = {22,30}, ArrLH5 = {23,30},
		 DepEW1 = {3,00},  ArrEW1 = {4,15},
		 DepEW2 = {8,00},  ArrEW2 = {10,00},
		 DepEW3 = {10,12}, ArrEW3 = {13,15},
		 DepEW4 = {18,00}, ArrEW4 = {20,30},
		 DepEW5 = {21,45}, ArrEW5 = {23,30},
		 DepX31 = {8,00},  ArrX31 = {10,00},
		 DepX32 = {10,15}, ArrX32 = {13,00},
		 DepX33 = {13,10}, ArrX33 = {15,00},
		 DepX34 = {15,12}, ArrX34 = {17,00},
		 DepX35 = {22,00}, ArrX35 = {24,00};

	Coordinate BERlat = {52,21,44}, BERlon = {13,30,2},					//Definition of airport coordinates;
			   HAMlat = {53,37,49}, HAMlon = {9,59,18},
			   DUSlat = {51,16,51}, DUSlon = {6,45,26},
			   CGNlat = {50,51,57}, CGNlon = {7,8,34},
			   FRAlat = {50,2,0}, FRAlon = {8,34,14},
			   STRlat = {48,41,24}, STRlon = {9,13,19},
			   MUClat = {48,21,14}, MUClon = {11,47,10};

	Airport BER = {BERlat, BERlon, 47.5, "EDDB", "BER"},					//Data from the respective airport;
			HAM = {HAMlat, HAMlon, 11.0, "EDDH", "HAM"},
			DUS = {DUSlat, DUSlon, 36.0, "EDDL", "DUS"},
			CGN = {CGNlat, CGNlon, 77.0, "EDDK", "CGN"},
			FRA = {FRAlat, FRAlon, 111.0, "EDDF", "FRA"},
			STR = {STRlat, STRlon, 389.0, "EDDS", "STR"},
			MUC = {MUClat, MUClon, 448.0, "EDDM", "MUC"};

	FlightPath FPLH1 = {MUC, HAM, DepLH1, ArrLH1, "LH 2147"},				//Data from respective flight paths;
			   FPLH2 = {HAM, FRA, DepLH2, ArrLH2, "LH 2147"},
			   FPLH3 = {FRA, MUC, DepLH3, ArrLH3, "LH 2147"},
			   FPLH4 = {MUC, HAM, DepLH4, ArrLH4, "LH 2147"},
			   FPLH5 = {HAM, MUC, DepLH5, ArrLH5, "LH 2147"},
			   FPEW1 = {MUC, DUS, DepEW1, ArrEW1, "EW 5953"},
			   FPEW2 = {DUS, BER, DepEW2, ArrEW2, "EW 5953"},
			   FPEW3 = {BER, CGN, DepEW3, ArrEW3, "EW 5953"},
			   FPEW4 = {CGN, MUC, DepEW4, ArrEW4, "EW 5953"},
			   FPEW5 = {MUC, DUS, DepEW5, ArrEW5, "EW 5953"},
			   FPX31 = {HAM, STR, DepX31, ArrX31, "X3 2174"},
			   FPX32 = {STR, BER, DepX32, ArrX32, "X3 2174"},
			   FPX33 = {BER, FRA, DepX33, ArrX33, "X3 2174"},
			   FPX34 = {FRA, HAM, DepX34, ArrX34, "X3 2174"},
			   FPX35 = {HAM, FRA, DepX35, ArrX35, "X3 2174"};

	Airplane A380 = {"A380", "D-AIMA", {FPLH1,FPLH2,FPLH3,FPLH4,FPLH5}, 5},			//Data from respective airplane;
			 A320 = {"A320", "D-AIAB", {FPEW1,FPEW2,FPEW3,FPEW4,FPEW5}, 5},
			 B747 = {"B747", "D-ABCD", {FPX31,FPX32,FPX33,FPX34,FPX35}, 5};

	Airline Lufthansa = {"Lufthansa", A380, 1},						//Data from respective airline;
			EuroWings = {"EuroWings", A320, 1},
			TUIFly = {"TUIFly", B747, 1};

	FMS FMS = {{Lufthansa, EuroWings, TUIFly}, 3};

	return FMS;
}




