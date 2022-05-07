#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		fprintf(stderr, "%s: error: Not enough arguments.", argv[0]);
		return EXIT_FAILURE;
	}	
	if (argc >= 3)
	{
		char arg[2];
		for (int iCnt = 1; iCnt <= 2; iCnt++)
		{
			if (((strcmp(argv[iCnt], "C")) && (strcmp(argv[iCnt], "c")) && (strcmp(argv[iCnt], "Celsius")) && (strcmp(argv[iCnt], "celsius")) && (strcmp(argv[iCnt], "°C"))) == 0)
			{
				arg[iCnt - 1] = 'C';
			}
			else if (((strcmp(argv[iCnt], "F")) && (strcmp(argv[iCnt], "f")) && (strcmp(argv[iCnt], "Fahrenheit")) && (strcmp(argv[iCnt], "fahrenheit")) && (strcmp(argv[iCnt], "°F"))) == 0)
			{
				arg[iCnt - 1] = 'F';
			}
			else if (((strcmp(argv[iCnt], "K")) && (strcmp(argv[iCnt], "k")) && (strcmp(argv[iCnt], "Kelvin")) && (strcmp(argv[iCnt], "kelvin"))) == 0)
			{
				arg[iCnt - 1] = 'K';
			}
			else
			{
				fprintf(stderr, "Unrecognized temperature scale %s", argv[iCnt]);
				return EXIT_FAILURE;
			}
		}
		if (argc == 3)
		{
			return EXIT_SUCCESS;
		}
		if (arg[0]=='C')
		{
			if (arg[1] == 'F')
			{				
				for (int iCount = 3; iCount < argc; iCount++)
				{
					float fTemp = atof(argv[iCount]);
					fTemp = (fTemp * 9 / 5) + 32;
					printf("%.2f\n",fTemp);
				}
			}
			else if (arg[1]=='K')
			{
				for (int iCount = 3; iCount < argc; iCount++)
				{
					float fTemp = atof(argv[iCount]);
					fTemp = fTemp + 273.15f;
					printf("%.2f\n", fTemp);
				}
			}			
		}
		else if (arg[0]=='F')
		{
			if (arg[1]=='C')
			{
				for (int iCount = 3; iCount < argc; iCount++)
				{
					float fTemp = atof(argv[iCount]);
					fTemp = (fTemp - 32) * 5 / 9;
					printf("%.2f\n", fTemp);
				}
			}
			else if (arg[1]=='K')
			{
				for (int iCount = 3; iCount < argc; iCount++)
				{
					float fTemp = atof(argv[iCount]);
					fTemp = (fTemp - 32) * (5 / 9) + 273.15f;
					printf("%.2f\n", fTemp);
				}
			}
		}
		else if (arg[0]=='K')
		{
			if (arg[1]=='C')
			{
				for (int iCount = 3; iCount < argc; iCount++)
				{
					float fTemp = atof(argv[iCount]);
					fTemp = fTemp - 273.15f;
					printf("%.2f\n", fTemp);
				}
			}
			else if (arg[1]=='F')
			{
				for (int iCount = 3; iCount < argc; iCount++)
				{
					float fTemp = atof(argv[iCount]);
					fTemp = (fTemp - 273.15f) * (9 / 5) + 32;
					printf("%.2f\n", fTemp);
				}
			}
		}		
	}
	return(EXIT_SUCCESS);
}