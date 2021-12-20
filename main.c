#include <stdio.h>

#define MAX 45
#define ENTER_KEY 13
int ch;
char patient_name[MAX];
char patient_surname[MAX];
char patient_disease[MAX];
int patient_age;
int i = 0;

char *patient_db = "db/patient_db.txt";

void create_patient(patient_name, patient_surname, patient_age, patient_disease)
{
	FILE *fp = fopen(patient_db, "a");
	if (fp == NULL)
    {
        printf("DB is not found: %s", patient_db);
        return -1;
    }

    // write to the text file
        fprintf(fp, "%s : %s | %s : %s | %s : %d | %s  : %s\n", "Patient Name",patient_name,"Patient Surname",patient_surname,"Patient Age",patient_age,"Patient Symptomps/Disase",patient_disease);

    // close the file
    fclose(fp);
	
	printf("Patient: %s %s %d created\nPatient Symptons is:%s\n\n\n", patient_name, patient_surname, patient_age, patient_disease);
}

main()
{

	do
	{
		printf("Welcome to New Hospital\n");
		printf("1) Start Patient  Admission Procedures\n");
		printf("2) Edit a Patient File\n");
		printf("3) Check for empty rooms\n");
		printf("4) Check vaccination status for new babies\n");
		printf("5) Look for medicine stock\n");
		printf("6) Make an appoitment\n");
		printf("7) Show Doctors\n");

		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
		{
			printf("Patient name please...\n");
			scanf(" %[^\n]s", patient_name);

			printf("Patient Surname please...\n");
			scanf("%s", patient_surname);

			printf("Patient Age please...\n");
			scanf("%d", &patient_age);

			printf("Patient Symptoms/Disease please...\n");
			scanf(" %[^\n]s", patient_disease);

			create_patient(patient_name, patient_surname, patient_age, patient_disease);

			sleep(5);
			system("cls");
		}
		break;
		default:
			break;
		}
	} while (i == 0);
}
