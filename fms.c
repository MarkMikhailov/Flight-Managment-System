/*
 ============================================================================
 Name        : fms.c
 Author      : Mark Mikhailov
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fms.h"

int Calculate_Duration(FMS * pFMS, int indexAirline, int indexFlightPath){																			//Function for calculating the flight duration;
	int secondsDep = pFMS->pAirline[indexAirline].pAirplane.pFlightPath[indexFlightPath].departure.hour * 60 * 60 + pFMS->pAirline[indexAirline].pAirplane.pFlightPath[indexFlightPath].departure.minute,			//Conversion of the departure time in seconds;
		secondsArr = pFMS->pAirline[indexAirline].pAirplane.pFlightPath[indexFlightPath].arrival.hour * 60 * 60 + pFMS->pAirline[indexAirline].pAirplane.pFlightPath[indexFlightPath].arrival.minute,			//Conversion of the arrival time in seconds;
		secondsTotal = secondsArr - secondsDep;																						//Calculation of the total flight time (in seconds);
	return secondsTotal;
};

void Generate_Time_Table(FMS * pFMS){																								//Function for outputting the time table;
	printf("%10s|%10s|%4s|%4s|%9s|%8s|%8s\n", "Airline", "Flight No.", "from", "to", "Departure", "Arrival", "Airplane");													//Output of the table header;
	printf("----------|----------|----|----|---------|--------|--------\n");

	for(int i = 0; i < pFMS->cntAirline; i++){																						//The for-loop for retrieving all airlines;
		for(int j = 0; j < pFMS->pAirline[i].pAirplane.cntFlightPath; j++){																		//The for-loop for retrieving all flight paths;
			printf("%10s|%10s|%4s|%4s|    %02d:%02d|   %02d:%02d|%8s\n",																		//Output of the table content;
			pFMS->pAirline[i].airlineName,																						//Pointer-path that allows defining the variables in the "printf" without having to re-specify the data every time otherwise;
			pFMS->pAirline[i].pAirplane.pFlightPath[j].flightPathName,																		//For this, the program always knows where the data is located and with the help of the data structure, it knows in which order it needs to retrieve the data; *1
			pFMS->pAirline[i].pAirplane.pFlightPath[j].pDepartureAirport.iata,
			pFMS->pAirline[i].pAirplane.pFlightPath[j].pArrivalAirport.iata,																	//In general: [i] and [j] are responsible for calling respective airline (i) and flight path (j);
			pFMS->pAirline[i].pAirplane.pFlightPath[j].departure.hour, pFMS->pAirline[i].pAirplane.pFlightPath[j].departure.minute,
			pFMS->pAirline[i].pAirplane.pFlightPath[j].arrival.hour, pFMS->pAirline[i].pAirplane.pFlightPath[j].arrival.minute,
			pFMS->pAirline[i].pAirplane.airVehicleRegestration);
		}
	}
}

void Generate_Duration_Table(FMS * pFMS){																							//Function for outputting the duration table;
	for(int i = 0; i < pFMS->cntAirline; i++){																						//The for-loop for retrieving all airlines;
		printf("%10s|%10s|%4s|%4s|%8s\n", "Airline", "Flight No.", "from", "to", "Duration");																//Output of the table header; Separation of the table into 3 parts with one airline each;
		printf("----------|----------|----|----|--------\n");
		unsigned int sum = 0;
		for(int j = 0; j < pFMS->pAirline[i].pAirplane.cntFlightPath; j++){																		//The for-loop for retrieving all flight paths;
			sum += Calculate_Duration(&*pFMS, i, j);																				//Calculation of the total flight time per airline;
			printf("%10s|%10s|%4s|%4s|  %02d:%02d\n",																				//Output of the table content;
					pFMS->pAirline[i].airlineName,																				// *1 The same as in the "printf" before;
					pFMS->pAirline[i].pAirplane.pFlightPath[j].flightPathName,
					pFMS->pAirline[i].pAirplane.pFlightPath[j].pDepartureAirport.iata,
					pFMS->pAirline[i].pAirplane.pFlightPath[j].pArrivalAirport.iata,
					Calculate_Duration(&*pFMS, i, j) / 60 / 60, Calculate_Duration(&*pFMS, i, j) % 60 % 60);												//Calculation of the flight time per flight path;
		}
		printf("\nTotal flight Time for %s %s is %02d:%d\n\n", pFMS->pAirline[i].airlineName, pFMS->pAirline[i].pAirplane.airplaneName, sum / 60 / 60, sum % 60 % 60);							//Output of the total flight time per airline;
	}

}

void Generate_Distance_Table(FMS * pFMS){																							//Function for outputting the duration table;
	for(int i = 0; i < pFMS->cntAirline; i++){
		printf("%10s|%10s|%4s|%4s|%8s\n", "Airline", "Flight No.", "from", "to", "Distance");																//Output of the table header;
		printf("----------|----------|----|----|--------\n");
		float sum = 0;
		for(int j = 0; j < pFMS->pAirline[i].pAirplane.cntFlightPath; j++){
			sum += Calculate_Degree(&*pFMS, i, j);																					//Calculation of the total flight distance per airline;
			printf("%10s|%10s|%4s|%4s| %0.2f\n",																					//Output of the table content;
					pFMS->pAirline[i].airlineName,																				// *1 The same as in the "printf" before;
					pFMS->pAirline[i].pAirplane.pFlightPath[j].flightPathName,
					pFMS->pAirline[i].pAirplane.pFlightPath[j].pDepartureAirport.iata,
					pFMS->pAirline[i].pAirplane.pFlightPath[j].pArrivalAirport.iata,
					Calculate_Degree(&*pFMS, i, j));																			//Calculation of the flight distance per flight path;
		}
		printf("\nTotal flight distance for %s %s is %.2f\n\n", pFMS->pAirline[i].airlineName, pFMS->pAirline[i].pAirplane.airplaneName, sum);										//Output of the total flight distance per airline;
	}

}

double Calculate_Degree(FMS * pFMS, int indexAirline, int indexFlightPath){																			//Function for converting coordinates and calculating the flight distance;
	Coordinate
	lat1 = pFMS->pAirline[indexAirline].pAirplane.pFlightPath[indexFlightPath].pDepartureAirport.latitude,															//Definition of the respective latitude and longitude;
	lat2 = pFMS->pAirline[indexAirline].pAirplane.pFlightPath[indexFlightPath].pArrivalAirport.latitude,
	lon1 = pFMS->pAirline[indexAirline].pAirplane.pFlightPath[indexFlightPath].pDepartureAirport.longtiude,
	lon2 = pFMS->pAirline[indexAirline].pAirplane.pFlightPath[indexFlightPath].pArrivalAirport.longtiude;

	double
	latDep = lat1.degree + (lat1.minute / 60) + (lat1.second / 3600),																			//Calculation of the degree of latitude and longitude;
	latArr = lat2.degree + (lat2.minute / 60) + (lat2.second / 3600),
	lonDep = lon1.degree + (lon1.minute / 60) + (lon1.second / 3600),
	lonArr = lon2.degree + (lon2.minute / 60) + (lon2.second / 3600);

	return 6378.388 * acos(Sin_Deg(latDep) * Sin_Deg(latArr) + Cos_Deg(latDep) * Cos_Deg(latArr) * Cos_Deg(lonArr - lonDep));												//Calculation of the distance;
}

double Sin_Deg(double x){																									//Auxiliary functions for converting degrees, minutes and seconds into angles;
	return sin((x)*M_PI/180.0);
}

double Cos_Deg(double x){																									//Auxiliary functions for converting degrees, minutes and seconds into angles;
	return cos((x)*M_PI/180.0);
}
