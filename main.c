#include <stdio.h>
#include <sqlite3.h>


#define MAX 45
#define ENTER_KEY 13
int ch;
char patient_name[MAX];
char patient_surname[MAX];
char patient_disease[MAX];
char patient_symptoms[MAX];

int patient_age;
int i = 0;

char *patient_db = "db/patient_db.txt";

create_patient(patient_name, patient_surname, patient_age, patient_disease, patient_symptoms)
{
	
	//printf("Patient: %s %s %d created\nPatient Symptons is:%s\n\n\n", patient_name, patient_surname, patient_age, patient_disease);

    // write to the text file
		addToDatabase(patient_name,patient_surname,patient_age,patient_symptoms,patient_disease);
	// fprintf(fp, "%s : %s | %s : %s | %s : %d | %s  : %s\n", "Patient Name",patient_name,"Patient Surname",patient_surname,"Patient Age",patient_age,"Patient Symptomps/Disase",patient_disease);
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

			printf("Patient Disease please...\n");
			scanf(" %[^\n]s", patient_disease);

			printf("Patient Symptoms please...\n");
			scanf(" %[^\n]s", patient_symptoms);

			create_patient(patient_name, patient_surname, patient_age, patient_disease, patient_symptoms);
			
			sleep(5);
			system("cls");
		}
		break;
		case 2:
		{
			printf("Edit a Patient File\n");
			

		}
		break;
		default:
			printf("Invalid choice\n");
		}
		}
		while (i == 0);
	} 


addToDatabase(patient_name,patient_surname,patient_age,patient_symptoms,patient_disease){
	 
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("db/hospital.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
    }
    
    char *sql = "DROP TABLE IF EXISTS Patient;" 
                "CREATE TABLE Cars(PatientId INT, PatientName STRING, PatientSurname STRING, PatientAge INT, PatientSymptoms TEXT, PatientDisease TEXT, PatientDoctor STRING);" 
                "INSERT INTO Cars VALUES(patient_name,patient_surname,patient_age,patient_symptoms,patient_disease,'Prof. Dr. Mehmet sait');"; 
              

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        

    } 
    
    sqlite3_close(db);
}