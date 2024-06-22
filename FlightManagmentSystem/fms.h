/*
 ============================================================================
 Name        : fms.h
 Author      : Mark Mikhailov
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */


#ifndef FMS_H_
#define FMS_H_
											//Declaration of data types;
typedef struct time{
	unsigned char hour, minute;
}Time;

typedef struct coordinate{
	double degree, minute, second;
}Coordinate;

typedef struct airport{
	Coordinate latitude, longtiude;
	float heightAMSL;
	char icao[6], iata[5];								//Strings: number of characters + \0 = the number in the bracket;
}Airport;

typedef struct flightPath{
	Airport pDepartureAirport, pArrivalAirport;
	Time departure, arrival;
	char flightPathName[9];								//Strings: number of characters + \0 = the number in the bracket;
}FlightPath;

typedef struct airplane{
	char airplaneName[6], airVehicleRegestration[8];				//Strings: number of characters + \0 = the number in the bracket;
	FlightPath pFlightPath[5];							//An array that enters the number of units;
	unsigned int cntFlightPath;
}Airplane;

typedef struct airline{
	char airlineName[11];								//Strings: number of characters + \0 = the number in the bracket;
	Airplane pAirplane;
	unsigned int cntAirplane;
}Airline;

typedef struct fms{
	Airline pAirline[3];								//An array that enters the number of units
	unsigned int cntAirline;
}FMS;

FMS generate_fms_data();								//Declaration of functions;
void Generate_Time_Table(FMS * pFMS);
void Generate_Distance_Table(FMS * pFMS);
void Generate_Duration_Table(FMS * pFMS);
double Calculate_Degree(FMS * pFMS, int indexAirline, int indexFlightPath);
double Sin_Deg(double x);
double Cos_Deg(double x);

#endif /* FMS_H_ */
