#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#pragma warning (disable:4996)
#define LUV_LETTER 25
#define NUT_COOKIES 20
#define ASST_COOKIES 15

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
	printf("\t\t\t       <Zhi Hong> AT <+60102012687>\n");
	printf("\t\t\t=========================================\n");
}

void thankYouMsg() {
	printf("Thank You For Your Order.\nPlease bring this Order Note when collecting your cookies. :-)\n");
}

int randNum() {
	int randomNumber;
	srand(time(NULL));
	randomNumber = rand() % 10 + 1;
	return randomNumber;
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
	int quantity;
	int orderNumber = 0;
	float deposit, grandTotal;
	float subTotal = 0, total = 0;
	do {
		orderNumber++;
		printf("======================================================================\n");
		printf("Order No: %d\n", orderNumber);
		printf("\tItem\t\t\t  Quantity Required\n\n");
		printf("LOVE LETTERS @ RM 25.00 per tin : ");
		scanf("%d", &quantity);
		total = quantity * LUV_LETTER;
		subTotal += total;
		printf("\tLove Letter Order  = \t\t\t\tRM%9.2f\n", total);
		printf("\tOrder SubTotal     = RM%.2f\n\n", subTotal);
		printf("NUT COOKIES @ RM 20.00 per jar  : ");
		scanf("%d", &quantity);
		total = quantity * NUT_COOKIES;
		subTotal += total;
		printf("\tNut Cookies Order  = \t\t\t\tRM%9.2f\n", total);
		printf("\tOrder SubTotal     = RM%.2f\n\n", subTotal);
		printf("ASST COOKIES @ RM 15.00 per jar : ");
		scanf("%d", &quantity);
		total = quantity * ASST_COOKIES;
		subTotal += total;
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
			printf("\t\t\t          DISCOUNT (0%)\t     :\tRM%9.2f\n", 0.00);
			printf("\t\t\t          AMOUNT TO PAY\t     :\tRM%9.2f\n", subTotal);
			printf("\t\t\t                DEPOSIT\t     :\tRM   ");
			scanf("%f", &deposit);
			printf("\t\t\t           DEPOSIT PAID\t     :\tRM%9.2f\n", deposit);
			grandTotal = subTotal - deposit;
			printf("\t\t\t                BALANCE\t     :\tRM%9.2f\n", grandTotal);
			thankYouMsg();
		}

		else {
			endingScreenMsg();
			exit(0);
		}

		printf("Next Order (Y = Yes)? ");
		rewind(stdin);
		scanf("%c", &userDecision);
		if (toupper(userDecision) == 'Y') {
			deposit = 0, grandTotal = 0, subTotal = 0, total = 0, quantity = 0;
		}
		else {
			
		}

	} while (userDecision != toupper('N'));

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