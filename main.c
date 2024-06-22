/*
 ============================================================================
 Name        : main.c
 Author      : Mark Mikhailov
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "fms.h"

int main(void) {
	FMS FMS = generate_fms_data();

	Generate_Time_Table(&FMS);

	printf("\n");						//Separation of tables;

	Generate_Duration_Table(&FMS);

	printf("\n");						//Separation of tables;

	Generate_Distance_Table(&FMS);

	return EXIT_SUCCESS;
}


