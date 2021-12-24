#include <stdio.h>
#include <sqlite3.h>


#define ENTER_KEY 13
int ch;
char patient_name[99];
char patient_surname[99];
char patient_disease[99];
char patient_symptoms[99];
char patient_doctor[99];

int patient_age;
int i = 0;

char *patient_db = "db/patient_db.txt";
char sqlStr[256];

create_patient(patient_name, patient_surname, patient_age, patient_disease, patient_symptoms,patient_doctor)
{
	
	//printf("Patient: %s %s %d created\nPatient Symptons is:%s\n\n\n", patient_name, patient_surname, patient_age, patient_disease);

    // write to the text file
		add_to_database(patient_name,patient_surname,patient_age,patient_symptoms,patient_disease,patient_doctor);
	// fprintf(fp, "%s : %s | %s : %s | %s : %d | %s  : %s\n", "Patient Name",patient_name,"Patient Surname",patient_surname,"Patient Age",patient_age,"Patient Symptomps/Disase",patient_disease);
}
main(int argc, char *argv[])
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
			printf("Patient's name please...\n");
			scanf(" %[^\n]s", patient_name);

			printf("Patient's Surname please...\n");
			scanf("%s", patient_surname);

			printf("Patient's Age please...\n");
			scanf("%d", &patient_age);

			printf("Patient's Doctor please...\n");
			scanf(" %[^\n]s", patient_doctor);

			printf("Patient's Disease please...\n");
			scanf(" %[^\n]s", patient_disease);

			printf("Patient's Symptoms please...\n");
			scanf(" %[^\n]s", patient_symptoms);

			add_to_database(patient_name, patient_surname, patient_age, patient_disease, patient_symptoms,patient_doctor);
			
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


int add_to_database(patient_name,patient_surname,patient_age,patient_symptoms,patient_disease,patient_doctor){
	 
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("db/hospital.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }
    

	char *sql = "DROP TABLE IF EXISTS Patient;" 
                "CREATE TABLE Patient(PatientId INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE, PatientName TEXT NOT NULL,PatientSurname TEXT NOT NULL,PatientAge INTEGER NOT NULL,PatientSymptoms TEXT NOT NULL, PatientDisease TEXT NOT NULL,PatientDoctor TEXT NOT NULL);" 
				//"INSERT INTO Patient (PatientId,PatientName,PatientSurname,PatientAge,PatientSymptoms,PatientDisease,PatientDoctor) VALUES (NULL,'sss','akoraler',19,'High Fever','Infection','Dr.Sait');";
   				"INSERT INTO Patient (PatientId,PatientName,PatientSurname,PatientAge,PatientSymptoms,PatientDisease,PatientDoctor) VALUES (NULL,'%s','%s',%d,'%s','%s','%s');",patient_name,patient_surname,patient_age,patient_symptoms,patient_disease,patient_doctor;


    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
	return 0;
}