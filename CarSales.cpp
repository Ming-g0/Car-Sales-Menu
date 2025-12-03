#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mobil {
    char brand[50];
    char model[50];
    char harga[20];
    int year;
} ;

void clrscr() {
    system("cls");
}

void displayStocks(struct mobil MBL[], int BnyakData) {
    printf("\n%-17s%-15s%-15s%-15s\n", "Brand", "Model", "Year", "Price");
    for (int i = 0; i < BnyakData; i++) {
        if (MBL[i].year != 0 && MBL[i].harga[0] != '\0') {
            printf("%-17s%-15s%-15d%-15s\n", MBL[i].brand, MBL[i].model,
                   MBL[i].year, MBL[i].harga);
        }
    }
}

void Readstock(char *fileStock,struct mobil MBL[], int *BnyakData) {
    FILE *fp = fopen(fileStock, "r");
    if (fp == NULL) {
        printf("FILE NOT EXISTED\n");
        return;
    }

    char header[256];
    fgets(header, sizeof(header), fp);

    while (fgets(header, sizeof(header), fp) != NULL) {
        sscanf(header, "%s %s %d %s", MBL[*BnyakData].brand, MBL[*BnyakData].model,
               &MBL[*BnyakData].year, MBL[*BnyakData].harga);
        (*BnyakData)++;
    }

    fclose(fp);
}

void swap(struct mobil *x,struct mobil *y) {
 	struct mobil temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSortharga(struct mobil MBL[], int BnyakData) {
    for (int i = 0; i < BnyakData - 1; i++) {
        for (int j = 0; j < BnyakData - i - 1; j++) {
            if (strcmp(MBL[j].harga, MBL[j + 1].harga) > 0) {
                swap(&MBL[j], &MBL[j + 1]);
            }
        }
    }
}

void BubbleSortYear(struct mobil MBL[], int BnyakData) {
    for (int i = 0; i < BnyakData - 1; i++) {
        for (int j = 0; j < BnyakData - i - 1; j++) {
            if (MBL[j].year < MBL[j + 1].year) {
                swap(&MBL[j], &MBL[j + 1]);
            }
        }
    }
}

void searchBrand(struct mobil MBL[], int BnyakData) {
    char brnd[30];
    printf("Masukkan Brand : ");
    scanf("%s", brnd);
    printf("\n%-17s%-15s%-15s%-15s\n", "Brand", "Model", "Year", "Price");
    printf("\n");
    int found = 0;
    for (int i = 0; i < BnyakData; i++) {
        if (strcmp(MBL[i].brand, brnd) == 0) {
            printf("%-17s%-15s%-15d%-15s\n", MBL[i].brand, MBL[i].model, MBL[i].year, MBL[i].harga);
            found = 1;
        }
    }
    if (!found) {
        printf("Data tidak ditemukan.\n");
    }
}

void searchYear(struct mobil MBL[], int BnyakData) {
    printf("Masukkan Tahun : ");
    int yr;
    scanf("%d", &yr);
    printf("\n%-17s%-15s%-15s%-15s\n", "Brand", "Model", "Year", "Price");
    printf("\n");
    int found = 0;
    for (int i = 0; i < BnyakData; i++) {
        if (MBL[i].year == yr) {
            printf("%-17s%-15s%-15d%-15s\n", MBL[i].brand, MBL[i].model, MBL[i].year, MBL[i].harga);
            found = 1;
        }
    }
    if (!found) {
        printf("Data tidak ditemukan.\n");
    }
}

void searchHarga(struct mobil MBL[], int BnyakData) {
    char hrg[50];
    printf("Masukkan Harga : ");
    scanf("%s", hrg);
    printf("\n%-17s%-15s%-15s%-15s\n", "Brand", "Model", "Year", "Price");
    printf("\n");
    int found = 0;
    for (int i = 0; i < BnyakData; i++) {
        if (strcmp(hrg, MBL[i].harga) == 0) {
            printf("%-17s%-15s%-15d%-15s\n", MBL[i].brand, MBL[i].model, MBL[i].year, MBL[i].harga);
            found = 1;
        }
    }
    if (!found) {
        printf("Data tidak ditemukan.\n");
    }
}

void searchModel(struct mobil MBL[], int BnyakData) {
    char mdl[50];
    printf("Masukkan Model : ");
    scanf("%s", mdl);
    printf("\n%-17s%-15s%-15s%-15s\n", "Brand", "Model", "Year", "Price");
    printf("\n");
    int found = 0;
    for (int i = 0; i < BnyakData; i++) {
        if (strcmp(mdl, MBL[i].model) == 0) {
            printf("%-17s%-15s%-15d%-15s\n", MBL[i].brand, MBL[i].model, MBL[i].year, MBL[i].harga);
            found = 1;
        }
    }
    if (!found) {
        printf("Data tidak ditemukan.\n");
    }
}
typedef struct Trans{
    char date[100];
    char customer[100];
    char brand[100];
    char model[100];
    int year;
    char harga[100];
};
void readTrans(char *fileTrans,struct Trans *tr, int *BnyakData) {
    FILE *fp = fopen(fileTrans, "r");

    if (fp== NULL) {
        fprintf(stderr, "Failed to open file.\n");
        return;
    }

    char header[256];
    fgets(header, sizeof(header), fp); // Read and discard the header

    while (fgets(header, sizeof(header), fp) != NULL) {
        (*BnyakData)++;
        sscanf(header, "%s %s %s %s %d %s",
               tr[*BnyakData].date, tr[*BnyakData].customer,
               tr[*BnyakData].brand, tr[*BnyakData].model,
               &tr[*BnyakData].year, tr[*BnyakData].harga);
    }

    fclose(fp);
}
void displayTransactions(struct Trans *tr, int BnyakData) {
    printf("\n%-1s%-15s%-15s%-15s%-8s%-18s\n", "Date", "Customer", "Brand", "Model", "Year", "Price");
    printf("\n");
	int i;
    for ( i = 1; i < BnyakData + 1; i++) {
        printf("%-17s%-15s%-15s%-15s%-8d%-18s\n", tr[i].date, tr[i].customer,
               tr[i].brand, tr[i].model,
               tr[i].year, tr[i].harga);
    }
}
void inputPayment(struct mobil MBL[], int BnyakData,struct Trans *tr, int *tC) {
    char mdl[50];
    int thn;
    char prc[20];
    int found = 0;
    char tanggal[20];
    int idx;
    char customer[100];

    printf("Please enter your name : ");
    scanf(" %[^\n]", customer);

    printf("Please enter the date with format mm/dd/yyyy : ");
    scanf("%s", tanggal);
	int i;
    do {
        printf("Model : ");
        scanf("%s", mdl);
        for ( i = 0; i < BnyakData; i++) {
            if (strcmp(mdl, MBL[i].model) == 0) {
                found = 1;
                break;
            }
        }
    } while (!found);

    do {
        printf("Year : ");
        scanf("%d", &thn);
        for ( i = 0; i < BnyakData; i++) {
            if (thn == MBL[i].year) {
                found = 1;
                break;
            }
        }
    } while (!found);

    do {
        printf("%-17s%-15s%-15s%-15s\n", "Brand", "Model", "Year", "Price");
        int found = 0;
        for (i = 0; i < BnyakData; i++) {
            if (strcmp(mdl, MBL[i].model) == 0 && thn == MBL[i].year) {
                printf("%-17s%-15s%-15d%-15s\n", MBL[i].brand, MBL[i].model,
                       MBL[i].year, MBL[i].harga);
                found = 1;
            }
        }
        if (!found) {
            printf("Data not found\n");
        }

        printf("Input the price : ");
        scanf("%s", prc);

        for ( i = 0; i < BnyakData; i++) {
            if (strcmp(mdl, MBL[i].model) == 0 && thn == MBL[i].year && strcmp(prc, MBL[i].harga) == 0) {
                idx = i;
                found = 1;
            }
        }

        strcpy(tr[*tC].date, tanggal);
        strcpy(tr[*tC].customer, customer);
        strcpy(tr[*tC].brand, MBL[idx].brand);
        strcpy(tr[*tC].model, MBL[idx].model);
        tr[*tC].year = MBL[idx].year;
        strcpy(tr[*tC].harga, MBL[idx].harga);
        (*tC)++;

        FILE *file, *tran;
        char buffer[1024];

        tran = fopen("trans.txt", "a");
        if (tran == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        fseek(tran, 0, SEEK_END);
        fprintf(tran, "%s        %s           %s         %s       %d   %s\n", tanggal, customer, MBL[idx].brand, MBL[idx].model, thn, MBL[idx].harga);
        fclose(tran);

        file = fopen("stck.txt", "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }

        int current_line = 0;
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            current_line++;
            if (current_line != idx + 1) {
                FILE *temp_file = fopen("temp.txt", "a");
                if (temp_file == NULL) {
                    perror("Error creating a temporary file");
                    fclose(file);
                    exit(EXIT_FAILURE);
                }
                fputs(buffer, temp_file);
                fclose(temp_file);
            }
        }

        fclose(file);

        remove("stck.txt");
        rename("temp.txt", "stck.txt");

        printf("\nTransaction Success\n");
        printf("Customer name : %s\n", customer);
        printf("%s\n", tanggal);
        printf("%-17s%-15s%-15s%-15s\n", "Brand", "Model", "Year", "Price");
        printf("\n");
        printf("%-17s%-15s%-15d%-15s\n", MBL[idx].brand, MBL[idx].model,
               MBL[idx].year, MBL[idx].harga);
        printf("Thank you for choosing our product\nGood day!\n");

    } while (!found);
}
void entriDATA(mobil MBL[], int *BnyakData) {
    FILE *fp = fopen("stck.txt", "a");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    printf("Input Brand : ");
    scanf("%s", MBL[*BnyakData].brand);
    printf("Input Model : ");
    scanf("%s", MBL[*BnyakData].model);
    printf("Input Year : ");
    scanf("%d", &MBL[*BnyakData].year);
    printf("Input Price : ");
    scanf("%s", MBL[*BnyakData].harga);

    fprintf(fp, "%s %s %d %s\n", MBL[*BnyakData].brand, MBL[*BnyakData].model,
            MBL[*BnyakData].year, MBL[*BnyakData].harga);
    fclose(fp);
    printf("Data saved to stck.txt.\n");

    (*BnyakData)++;
}

int main() {
    char *fileStock = "stck.txt";
    char *fileTrans = "trans.txt";
    Trans tr[100];
    int choice,c,d;
    struct mobil MBL[100];
    int BnyakData = 0;
    char user1[20] = {"Raka"};
	int pw1 = 4321;
	char user2[20] = {"Ar'an"};
	int pw2 = 2706;	
while (1)
	{
		printf("\n======================\n");
		printf("-----CAR SHOWROOM-----\n");
		printf("======================\n");
		printf("1. Admin\n");
		printf("2. Customer\n");
		printf("3. Exit\n");
		printf("Your Choice : ");
		scanf("%d",&c);
		if (c==3)
		{
			printf("Enjoy your day!!");
			break;
		}
		switch (c)
		{
			case 1:
				{
					int pw;
					printf("Inpur your Password : ");
					scanf("%d", &pw);
					if(pw==pw1)
					{
						printf("===============\n");
						printf("  Welcome %s\n",user1);
						printf("===============\n");
					}
					else if(pw==pw2)
					{
						printf("===============\n");
						printf("  Welcome %s\n",user2);
						printf("===============\n");
					}
					else
					{
						printf("Your Password is Wrong\n");
						break;
					}
					printf("What do you want today boss?\n");
					printf("1. Read Data Stock\n");
					printf("2. Read Data Transaction\n");
					printf("3. Entri Data Stock\n");
					printf("4. Buy\n");
					printf("5. Exit\n");
					printf("Select your activity : ");
					scanf("%d", &d);
					if(d==5)
					{
						printf("Exit Program");
						break;
					}
					switch (d)
					{
						case 1:
							{
								Readstock(fileStock, MBL, &BnyakData);
				                displayStocks(MBL, BnyakData);
				                int dl;
				                printf("Jika sudah melihat ketik 1\n");
				                scanf("%d", &dl);
				                if (dl == 1) {
				                    clrscr();
				                }
				                break;
							}
						case 2: 
						{
								readTrans(fileTrans,tr,&BnyakData);
								displayTransactions(tr,BnyakData);
								int Cl;
				                printf("Jika sudah melihat ketik 1\n");
				                scanf("%d", &Cl);
				                if (Cl == 1) {
				                    clrscr();
				                }
								break;
						}
						case 3: 
						{
								Readstock(fileStock, MBL, &BnyakData);
				                entriDATA(MBL, &BnyakData);
				                break;
						}
						case 4 : 
						Readstock(fileStock, MBL, &BnyakData);
						inputPayment(MBL,BnyakData,tr,&BnyakData);
						break;
						
						default :
							break;
					}
					break;
				}case 2: 
				{
					printf("=====================\n");
					printf("| Welcome Customer! |\n");
					printf("=====================\n");
					printf("1. Search by Brand\n");
			        printf("2. Search by Year\n");
			        printf("3. Search by Price\n");
			        printf("4. Search by Model\n");
			        printf("5. Sorting Price\n");
			        printf("6. Sorting Year\n");
			        printf("7. Display Stocks\n");
			        printf("8. Exit\n");
			        printf("Select number : ");
			        scanf("%d", &choice);
			        switch (choice)
			        {
			        	case 1 :
			        		Readstock(fileStock, MBL, &BnyakData);
			                searchBrand(MBL, BnyakData);
			                break;
			        	case 2:
			                Readstock(fileStock, MBL, &BnyakData);
			                searchYear(MBL, BnyakData);
			                break;
			        	case 3 :
							Readstock(fileStock, MBL, &BnyakData);
			                searchHarga(MBL, BnyakData);
			                break;	
			        	case 4 :
				        	Readstock(fileStock, MBL, &BnyakData);
			                searchModel(MBL, BnyakData);
			                break;
						case 5: 	
							Readstock(fileStock, MBL, &BnyakData);
			                BubbleSortharga(MBL, BnyakData);
			                printf("\n%-17s%-15s%-15s%-15s\n", "Brand", "Model", "Year", "Price");
			                for (int i = 0; i < BnyakData; i++) {
			                    if (MBL[i].year != 0 && MBL[i].brand[0] != '\0') {
			                        printf("%-17s%-15s%-15d%-15s\n", MBL[i].brand, MBL[i].model, MBL[i].year, MBL[i].harga);
			                    }
			                }
			                int dl;
			                printf("Jika sudah melihat ketik 1\n");
			                scanf("%d", &dl);
			                if (dl == 1) {
			                    clrscr();
			                }
			                break;
			            case 6 :
			            	Readstock(fileStock, MBL, &BnyakData);
			                BubbleSortYear(MBL, BnyakData);
			                printf("\n%-17s%-15s%-15s%-15s\n", "Brand", "Model", "Year", "Price");
			                for (int i = 0; i < BnyakData; i++) {
			                    if (MBL[i].year != 0 && MBL[i].brand[0] != '\0') {
			                        printf("%-17s%-15s%-15d%-15s\n", MBL[i].brand, MBL[i].model, MBL[i].year, MBL[i].harga);
			                    }
			                }
			                  int kl;
			                printf("Jika sudah melihat ketik 1\n");
			                scanf("%d", &kl);
			                if (kl == 1) {
			                    clrscr();
			                }
			                break;
			            case 7:
						{
				            Readstock(fileStock, MBL, &BnyakData);
			                displayStocks(MBL, BnyakData);
			                int ml;
			                printf("Jika sudah melihat ketik 1\n");
			                scanf("%d", &ml);
			                if (ml == 1) {
			                    clrscr();
			                }
			                break;
			            }
							
						default : 
						break;
			        }
					break;
				}
				default : 
				printf("Please Select Number Between 1 until 3\n");
				break;
		}
	}
	return 0;
}
