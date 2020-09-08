#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main()
{
    int selection;
    char path[50] = "jobs/";
    char program[50];

    bool running = true;
    bool valid = false;

    while (running) {
        printf("\n-------------------------------------------------------\n"
               "Please enter a choice: \n");
        printf("1 : List jobs\n"
               "2 : Set jobs directory\n"
               "3 : Compile and run specific program\n"
               "4 : Compile and run all jobs in a specific directory.\n"
               "5 : Shutdown\n"
               "6 : List program options\n"
               "7 : help\n"
               "-------------------------------------------------------\n");
        scanf("%d", &selection);


        while (!valid) {
            if ((selection >= 0) && (selection <= 7)) {
                valid = true;
            } else {
                printf("\nError: Invalid Selection. ");
                main();
            }
        }

        switch (selection) {
            case 1 :
                printf("Loading...........\n");
                fflush(stdout);
                sleep(2);
                printf("List of Jobs: %s\n", path);
                DIR *d;
                struct dirent *dir;
                d = opendir(path);
                if (d){
                    while ((dir = readdir(d)) != NULL){
                        char * file = dir->d_name;
                        if(strstr(file, ".c") != NULL){
                            printf("%s\n", file);
                        }
                    }
                    closedir(d);
                }
                break;

            case 2 :
                printf("Enter a job path: ");
                scanf("%s", path);
                printf("New jobs path: %s\n", path);
                break;

            case 3 :
                printf("Enter name of job to run: ");
                scanf("%s", program);
                char run[200];
                char out[200];
                strcpy(run, "gcc -o");
                strcat(run, path);
                strcat(run, program);
                strcat(run, ".out ");
                strcat(run, path);
                strcat(run, program);
                system(run);

                strcpy(out, path);
                strcat(out, program);
                strcat(out, ".out");

                system(run);
                printf("Running the job ........\n");
                fflush(stdout);
                sleep(1);
                printf("Output of Job: \n");
                system(out);
                printf("Job Completed!!\n\n");
                break;

            case 4:
                printf("\nCompleting all Jobs: \n");
                d = opendir(path);
                if (d){
                    while ((dir = readdir(d)) != NULL){
                        char * file = dir->d_name;


                        char *e;
                        int index;
                        e = strchr(file, '.');
                        index = (int)(e - file);
                        int len = strlen(file);
                        int pos = len - index;

                        /* unsigned int len = strlen(file);
                      unsigned int pos = len - index; */

                        if(pos == 2 && strstr(file, ".c") != NULL){
                            printf("Completing:- %s\n", file);

                            char run[200];
                            char out[200];

                            strcpy(run, "gcc -o");
                            strcat(run, path);
                            strcat(run, file);
                            strcat(run, ".out ");
                            strcat(run, path);
                            strcat(run, file);
                            system(run);

                            strcpy(out, path);
                            strcat(out, file);
                            strcat(out, ".out");

                            system(run);
                            system(out);

                        }
                    }
                    printf("Completed all Jobs in the batch! \n");
                    closedir(d);
                }
                break;

            case 5 :
                printf("Terminating Program ............\n");
                fflush(stdout);
                sleep(2);
                printf("Program Terminated\n");
                running = false;
                break;

            case 6 :
                printf("List of program options :");
                break;

            case 7 :
                printf("LOADING......\n");
                fflush(stdout);
                sleep(1);
                printf("This is  Batch OS simulator Program .... \n"
                       "Instructions:\n "
                       ": 1 to List all the jobs\n "
                       ": 2 to Set jobs directory\n "
                       ": 3 to Compile and run specific program\n "
                       ": 4 to Compile and run all jobs in a specific directory.\n "
                       ": 5 to Shutdown\n "
                       ": 6 to List program options\n "
                       ": 7 For HELP \n");
                break;

            default:
                /*code to be executed if n doesn't match any cases */
                running = false;
                break;
        }
    }
}
