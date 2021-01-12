#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#pragma warning (disable:4996)
#define LUV_LETTER 25.00
#define NUT_COOKIES 20.00
#define ASST_COOKIES 15.00
#define discountI 0.05
#define discountII 0.10
void menu();
void cookiesFact();
void orderCookies();

void date() {
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "\t\t\t\tToday's Date: %d %b %Y\n\n", timeinfo);
	printf(buffer);
}

void header() {
	printf("\t\t\t=========================================\n");
	printf("\t\t\t    WELCOME TO COOKIE ORDERING SYSTEM    \n");
	printf("\t\t\t            SYSTEM POWERED BY            \n\t\t\t      TARUC FESTIVE COOKIES SDN BHD      \n");
	printf("\t\t\t=========================================\n");
}

void footer() {
	printf("\t\t\t=========================================\n");
	printf("\t\t\t	MAY THE COOKIES BE WITH YOU\n");
	printf("\t\t\t=========================================\n");
}

void invalidChoice() {
	printf("\t\t\tInvalid Choice Found, Please Enter Again\n");
	system("pause");
	system("cls");
}

void endingScreenMsg() {
	printf("\n\t\t\t=========================================\n");
	printf("\t\t\t     Thank You For Using This System\n");
	printf("\t\t\t          For Further Feedback \n");
	printf("\t\t\t             Please Contact\n");
	printf("\t\t\t       <Admin> AT <+60123456789>\n");
	printf("\t\t\t=========================================\n");
}

void thankYouMsg(FILE** receiptPTR) {
	printf("Thank You For Your Order.\nPlease bring this Order Note when collecting your cookies. :-)\n");
	fprintf(*receiptPTR, "Thank You For Your Order.\nPlease bring this Order Note when collecting your cookies. :-)\n");
	printf("============================================================================\n");
	fprintf(*receiptPTR, "============================================================================\n");
}

int randNum() {
	int randomNumber;
	srand(time(NULL));
	randomNumber = rand() % 10 + 1;
	return randomNumber;
}

void receipt(int orderNumber, int luvLetter, int  nutKies, int asstKies, float subTotal, float discountedPrice, float amountToPay, float deposit, float grandTotal) {

	FILE* receiptPTR;

	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "\t                Order Date: %d %b %Y\n", timeinfo);

	receiptPTR = fopen("Receipt.txt", "a");

	if (receiptPTR == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printf("============================================================================\n");
	printf("TARUC FESTIVE COOKIES SDN BHD\t\tPhone     :  0123456789\n");
	printf("\tORDER NOTE");
	printf(buffer);
	printf("Your Order No is:	%d\t\tReady in 4 days.\n", orderNumber);
	printf("%2d   LOVE LETTERS @ RM25.00 per tin: RM%9.2f\n", luvLetter, luvLetter * LUV_LETTER);
	printf("%2d    NUT COOKIES @ RM20.00 per tin: RM%9.2f\n", nutKies, nutKies * NUT_COOKIES);
	printf("%2d   ASST COOKIES @ RM15.00 per tin: RM%9.2f\n\n", asstKies, asstKies * ASST_COOKIES);
	printf("\t\t\t          ORDER TOTAL\t     :\tRM%9.2f\n", subTotal);

	fprintf(receiptPTR, "============================================================================\n");
	fprintf(receiptPTR, "TARUC FESTIVE COOKIES SDN BHD\t\tPhone     :\n");
	fprintf(receiptPTR, "\tORDER NOTE");
	fprintf(receiptPTR, buffer);
	fprintf(receiptPTR, "Your Order No is:	%d\t\tReady in 4 days.\n", 1);
	fprintf(receiptPTR, "%2d   LOVE LETTERS @ RM25.00 per tin: RM%9.2f\n", luvLetter, luvLetter * LUV_LETTER);
	fprintf(receiptPTR, "%2d    NUT COOKIES @ RM20.00 per tin: RM%9.2f\n", nutKies, nutKies * NUT_COOKIES);
	fprintf(receiptPTR, "%2d   ASST COOKIES @ RM15.00 per tin: RM%9.2f\n\n", asstKies, asstKies * ASST_COOKIES);
	fprintf(receiptPTR, "\t\t\t          ORDER TOTAL\t     :\tRM%9.2f\n", subTotal);

	if (subTotal >= 500 && subTotal <= 1000) {
		discountedPrice = subTotal * discountI;
		printf("\t\t\t          DISCOUNT (5%%)\t     :\tRM%9.2f\n", discountedPrice);
		fprintf(receiptPTR, "\t\t\t          DISCOUNT (5%%)\t     :\tRM%9.2f\n", discountedPrice);
	}
	else if (subTotal > 1000) {
		discountedPrice = subTotal * discountII;
		printf("\t\t\t          DISCOUNT (10%%)     :\tRM%9.2f\n", discountedPrice);
		fprintf(receiptPTR, "\t\t\t          DISCOUNT (10%%)     :\tRM%9.2f\n", discountedPrice);
	}
	else {
		discountedPrice = 0.00;
		printf("\t\t\t          DISCOUNT (0%%)\t     :\tRM%9.2f\n", discountedPrice);
		fprintf(receiptPTR, "\t\t\t          DISCOUNT (0%%)\t     :\tRM%9.2f\n", discountedPrice);
	}

	amountToPay = subTotal - discountedPrice;
	printf("\t\t\t          AMOUNT TO PAY\t     :\tRM%9.2f\n", amountToPay);
	fprintf(receiptPTR, "\t\t\t          AMOUNT TO PAY\t     :\tRM%9.2f\n", amountToPay);
	printf("\t\t\t           DEPOSIT PAID\t     :\tRM%9.2f\n", deposit);
	fprintf(receiptPTR, "\t\t\t           DEPOSIT PAID\t     :\tRM%9.2f\n", deposit);
	grandTotal = amountToPay - deposit;
	printf("\t\t\t                BALANCE\t     :\tRM%9.2f\n", grandTotal);
	fprintf(receiptPTR, "\t\t\t                BALANCE\t     :\tRM%9.2f\n", grandTotal);
	thankYouMsg(&receiptPTR);
	fclose(receiptPTR);
}

void summaryReport(int orderNumber, int luvLetter, int nutKies, int asstKies, float totalSales, float totalDiscount, float totalNetSales, float totalDeposit, float totalBalance) {
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "(%d %b %Y)\n", timeinfo);
	printf("\t\t\tORDER SUMMARY FOR TODAY ");
	printf(buffer);
	printf("\t\t\t=====================================\n");
	printf("Total Number of Customer Orders : %d\n", orderNumber);
	printf("\tTotal Orders\t\t\tUnit Price\t    Amount \n");
	printf("\t%2d LOVE LETTERS\t\t@ RM 25.00 per tin  :  RM%9.2f\n", luvLetter, luvLetter * LUV_LETTER);
	printf("\t%2d NUT COOKIES\t\t@ RM 20.00 per jar  :  RM%9.2f\n", nutKies, nutKies * NUT_COOKIES);
	printf("\t%2d ASST COOKIES\t\t@ RM 15.00 per jar  :  RM%9.2f\n", asstKies, asstKies * ASST_COOKIES);
	printf("\t\t\t\t\t\t       -----------\n");
	printf("\t\t\t\tTOTAL SALES\t    :  RM%9.2f\n", totalSales);
	printf("\t\t\t\tTOTAL DISCOUNTS\t    :  RM%9.2f\n", totalDiscount);
	printf("\t\t\t\t\t\t       -----------\n");
	printf("\t\t\t\tTOTAL NET SALES     :  RM%9.2f\n", totalNetSales);
	printf("\t\t\t\t\t\t       ===========\n");
	printf("\t\t\t\tTOTAL DEPOSITS\t    :  RM%9.2f\n", totalDeposit);
	printf("\t\t\t\tTOTAL BALANCE\t    :  RM%9.2f\n", totalBalance);
}

void mainMenu() {
	int selection, invalidCounter = 0;

	do {
		system("cls");
		header();
		printf("\t\t\t\t\t   MENU\n\n");
		printf("\t\t\t\t1 - Order Cookies Now\n");
		printf("\t\t\t\t2 - View Our Menu\n");
		printf("\t\t\t\t3 - Cookies Fact!\n");
		printf("\t\t\t\t4 - Exit The Program\n\n\n");
		footer();
		date();
		printf("\t\t\t Enter Your Choice > ");
		rewind(stdin);
		scanf("%d", &selection);

		if (selection < 1 || selection > 4) {
			invalidCounter++;
			invalidChoice();
		}
		else {
			break;
		}

	} while (invalidCounter != 0);

	switch (selection) {
	case 1:
		orderCookies();
		break;
	case 2:
		menu();
		break;
	case 3:
		cookiesFact();
		break;
	case 4:
		endingScreenMsg();
		exit(0);
	}
}

void orderCookies() {
	char userDecision, confirmation;
	int quantity, luvLetter, nutKies, asstKies, totalLuv = 0, totalNut = 0, totalAsst = 0;
	int orderNumber = 0, validate = 0, invalidCounter;
	float deposit, grandTotal, discountedPrice, amountToPay, totalSales = 0, totalDeposit = 0, totalDiscount = 0, totalBalance = 0, totalNetSales = 0;
	float subTotal = 0, total = 0;

	do {
		orderNumber++;
		do {
			invalidCounter = 0;
			printf("============================================================================\n");
			printf("Order No: %d\n", orderNumber);
			printf("\tItem\t\t\t  Quantity Required\n\n");
			printf("LOVE LETTERS @ RM 25.00 per tin : ");
			rewind(stdin);
			validate = scanf("%d", &quantity);
			if (validate != 1) {
				invalidCounter++;
			}

			luvLetter = quantity;
			total = quantity * LUV_LETTER;
			subTotal += total;
			printf("\tLove Letter Order  = \t\t\t\tRM%9.2f\n", total);
			printf("\tOrder SubTotal     = RM%.2f\n\n", subTotal);
			printf("NUT COOKIES @ RM 20.00 per jar  : ");
			rewind(stdin);
			validate = scanf("%d", &quantity);
			if (validate != 1) {
				invalidCounter++;
			}

			nutKies = quantity;
			total = quantity * NUT_COOKIES;
			subTotal += total;
			printf("\tNut Cookies Order  = \t\t\t\tRM%9.2f\n", total);
			printf("\tOrder SubTotal     = RM%.2f\n\n", subTotal);
			printf("ASST COOKIES @ RM 15.00 per jar : ");
			rewind(stdin);

			validate = scanf("%d", &quantity);
			if (validate != 1) {
				invalidCounter++;
			}

			asstKies = quantity;
			total = quantity * ASST_COOKIES;
			subTotal += total;

			if (invalidCounter != 0) {
				quantity = 0;
				luvLetter = 0;
				nutKies = 0;
				asstKies = 0;
				subTotal = 0;
				total = 0;

				printf("Please Enter Number Only\n");
				system("pause");
				system("cls");
			}

		} while (invalidCounter != 0);
	
		printf("\tAsst Cookies Order = \t\t\t\tRM%9.2f\n", total);
		printf("\t\t\t\t\t\t\t-----------\n");
		printf("\t\t\t          ORDER TOTAL\t     :\tRM%9.2f\n", subTotal);
		printf("Confirm / Cancel Order (Y = Confirm)? ");
		rewind(stdin);
		scanf("%c", &confirmation);
		

		while (toupper(confirmation) != 'N' && toupper(confirmation) != 'Y') {
			printf("Please Enter Y or N ONLY");
			rewind(stdin);
			scanf("%c", &confirmation);
		}

		if (toupper(confirmation) == 'Y') {
			if (subTotal >= 500 && subTotal <= 1000) {
				discountedPrice = subTotal * discountI;
				printf("\t\t\t          DISCOUNT (5%%)\t     :\tRM%9.2f\n", discountedPrice);

			}
			else if (subTotal > 1000) {
				discountedPrice = subTotal * discountII;
				printf("\t\t\t          DISCOUNT (10%%)     :\tRM%9.2f\n", discountedPrice);

			}
			else {
				discountedPrice = 0.00;
				printf("\t\t\t          DISCOUNT (0%%)\t     :\tRM%9.2f\n", discountedPrice);
			}

			amountToPay = subTotal - discountedPrice;
			printf("\t\t\t          AMOUNT TO PAY\t     :\tRM%9.2f\n", amountToPay);
			printf("\t\t\t                DEPOSIT\t     :\tRM   ");
			scanf("%f", &deposit);
			printf("\t\t\t           DEPOSIT PAID\t     :\tRM%9.2f\n", deposit);
			grandTotal = amountToPay - deposit;
			printf("\t\t\t                BALANCE\t     :\tRM%9.2f\n", grandTotal);
			totalDeposit += deposit, totalAsst += asstKies, totalLuv += luvLetter, totalBalance += grandTotal, totalNetSales += amountToPay, totalDiscount += discountedPrice, totalNut += nutKies;
			receipt(orderNumber, luvLetter, nutKies, asstKies, subTotal, discountedPrice, amountToPay, deposit, grandTotal);
		}

		else if (toupper(confirmation) == 'N') {
			system("cls");
			deposit = 0, grandTotal = 0, subTotal = 0, total = 0, quantity = 0, discountedPrice = 0, amountToPay = 0;
		}

		printf("Next Order (Y = Yes)? ");
		rewind(stdin);
		scanf("%c", &userDecision);
		if (toupper(userDecision) == 'Y') {
			deposit = 0, grandTotal = 0, subTotal = 0, total = 0, quantity = 0, discountedPrice = 0, amountToPay = 0;
		}

	} while (userDecision != toupper('N'));
	summaryReport(orderNumber, totalLuv, totalNut, totalAsst, totalSales, totalDiscount, totalNetSales, totalDeposit, totalBalance);
}


void menu() {
	int invalidCounter = 0, selection;
	do {
		system("cls");
		header();
		printf("\n\t\t\t\t\tOUR MENU\n");
		printf("\t\t\t     -------------------------------\n");
		printf("\t\t\t     |No.|      Item         |Price|\n");
		printf("\t\t\t     -------------------------------\n");
		printf("\t\t\t     |01.|  Love Letter      |25.00|\n");
		printf("\t\t\t     -------------------------------\n");
		printf("\t\t\t     |02.|  Nut Cookies      |20.00|\n");
		printf("\t\t\t     -------------------------------\n");
		printf("\t\t\t     |03.|  Assorted Cookies |15.00|\n");
		printf("\t\t\t     -------------------------------\n\n");
		footer();
		date();
		printf("\t\t\t Back To Main Menu (1 = Yes | 2 = No)? ");
		scanf("%d", &selection);
		rewind(stdin);

		if (selection < 1 || selection > 2) {
			invalidCounter++;
			invalidChoice();
		}
		else {
			break;
		}

	} while (invalidCounter != 0);

	switch (selection) {
	case 1:
		mainMenu();
		break;
	case 2:
		endingScreenMsg();
		exit(0);
	}

}

void cookiesFact() {
	char userDecision;
	int randomNumber, choice, invalidCounter = 0;
	randomNumber = randNum();
	do {
		invalidCounter = 0;
		system("cls");
		header();
		printf("\t\t\t\t        COOKIES FACT!\n\n");
		printf("\t\t\t       1 - Generate Cookies Facts\n");
		printf("\t\t\t       2 - Back To Main Menu\n");
		printf("\t\t\t       3 - Exit The Program\n\n\n");
		footer();
		date();
		printf("\t\t\t Enter Your Choice > ");
		rewind(stdin);
		scanf("%d", &choice);

		if (choice < 1 || choice > 4) {
			invalidCounter++;
			invalidChoice();
		}
		else {
			break;
		}

	} while (invalidCounter != 0);

	switch (choice) {
	case 1:
		system("cls");
		header();
		printf("\t\t\t\t\t   FACTS\n\n");
		switch (randomNumber) {
		case 1:
			printf("\t\t\t    Facts %d - The first commercial cookie\n\t\t\t\t\t\b\bin the U.S. was the\n\t\t\t\t\t\b\bAnimal Cracker\n\t\t\t\t\t\b\bintroduced in 1902.\n\n", randomNumber);
			break;
		case 2:
			printf("\t\t\t    Facts %d - The Oreo, the best-selling\n\t\t\t\t\t\b\bcookie of the 20th century\n\t\t\t\t\t\b\bwas developed and\n\t\t\t\t\t\b\bintroduced by the\n\t\t\t\t\t\b\bAmerican company Nabisco, \n\t\t\t\t\t\b\bin 1912.\n\n", randomNumber);
			break;
		case 3:
			printf("\t\t\t    Facts %d - July 9th is National Sugar\n\t\t\t\t\t\b\bCookie Day.\n\n", randomNumber);
			break;
		case 4:
			printf("\t\t\t    Facts %d - December 4th is National\n\t\t\t\t\t\b\bCookie Day.\n\n", randomNumber);
			break;
		case 5:
			printf("\t\t\t    Facts %d - The U.S. leads the world as \n\t\t\t\t\t\b\bthe biggest cookie bakers and\n\t\t\t\t\t\b\beaters spending more than\n\t\t\t\t\t\b\b$550 million annually on\n\t\t\t\t\t\b\bOreos alone.\n\n", randomNumber);
			break;
		case 6:
			printf("\t\t\t    Facts %d - The Girl Scouts first began\n\t\t\t\t\t\b\bselling cookies\n\t\t\t\t\t\b\bIn the 1920s.\n\n", randomNumber);
			break;
		case 7:
			printf("\t\t\t    Facts %d - The world's biggest\n\t\t\t\t\t\b\bchocolate chip cookie\n\t\t\t\t\t\b\bweighed over 40,000 pounds.\n\n", randomNumber);
			break;
		case 8:
			printf("\t\t\t    Facts %d - Fortune cookies are not served\n\t\t\t\t\t\b\bin China. They are mostly an\n\t\t\t\t\t\b\bAmerican phenomenon.\n\n", randomNumber);
			break;
		case 9:
			printf("\t\t\t    Facts %d - Oreos are knock-offs of\n\t\t\t\t\t\b\bHydrox biscuits,\n\t\t\t\t\t\b\bwhich predate\n\t\t\t\t\t\b\bOreos by four years.\n\n", randomNumber);
			break;
		case 10:
			printf("\t\t\t    Facts %d - Famous Amos cookies were\n\t\t\t\t\t\bborn when the founder,\n\t\t\t\t\t\bWally Amos began using them\n\t\t\t\t\t\bto recruit celebrities\n\t\t\t\t\t\bto his agency.\n\n", randomNumber);
			break;
		}
		footer();
		date();
		printf("\t\t     Do You Wish To Continue? (Y = Yes & N = No) > ");
		rewind(stdin);
		scanf("%c", &userDecision);
		while (toupper(userDecision) != 'Y' && toupper(userDecision) != 'N') {
			printf("\t\t\t         Please Enter Y or N only\n");
			printf("\t\t     Do You Wish To Continue? (Y = Yes & N = No) > ");
			rewind(stdin);
			scanf("%c", &userDecision);
		}
		if (toupper(userDecision) == 'Y') {
			system("cls");
			mainMenu();
		}
		else if (toupper(userDecision) == 'N') {
			endingScreenMsg();
		}
		break;
	case 2:
		system("cls");
		mainMenu();
	case 3:
		endingScreenMsg();
	}
}
