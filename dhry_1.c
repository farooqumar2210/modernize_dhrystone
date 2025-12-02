#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dhry.h"
 
/* Global variables */
Record *Ptr_Glob, *Next_Ptr_Glob;
int Int_Glob;
int Bool_Glob;
char Ch_1_Glob='\0';
char Ch_2_Glob='\0';
int Arr_1_Glob[50];
int Arr_2_Glob[50][50];
 
int main(int argc, char *argv[])
{
    unsigned long Number_Of_Runs = 500000;
    if (argc > 1) {
        char *endptr = NULL;
        unsigned long val = strtoul(argv[1], &endptr, 10);
        if (endptr != argv[1] && val > 0)
            Number_Of_Runs = val;
    }

    /* Allocate records */
    Ptr_Glob = malloc(sizeof(Record));
    Next_Ptr_Glob = malloc(sizeof(Record));
 
    Ptr_Glob->Ptr_Comp = Next_Ptr_Glob;
    Ptr_Glob->Discr = Ident_1;
    Ptr_Glob->variant.var_1.Enum_Comp = Ident_3;
    Ptr_Glob->variant.var_1.Int_Comp = 40;
    strncpy(Ptr_Glob->variant.var_1.Str_Comp, "DHRYSTONE PROGRAM, SOME STRING", 30);
    Ptr_Glob->variant.var_1.Str_Comp[30] = '\0';

    Next_Ptr_Glob->Ptr_Comp = Ptr_Glob;
    Next_Ptr_Glob->Discr = Ident_2;
    Next_Ptr_Glob->variant.var_1.Enum_Comp = Ident_2;
    Next_Ptr_Glob->variant.var_1.Int_Comp = 20;
    strncpy(Next_Ptr_Glob->variant.var_1.Str_Comp, "DHRYSTONE PROGRAM, SOME STRING", 30);
    Next_Ptr_Glob->variant.var_1.Str_Comp[30] = '\0';

    Int_Glob = 5;
    Bool_Glob = 1;
    Ch_1_Glob = 'A';
    Ch_2_Glob = 'B';
    for (int i=0; i<50; ++i) {
        Arr_1_Glob[i] = i;
        for (int j=0; j<50; ++j)
            Arr_2_Glob[i][j] = i*j;
    }
 
    /* Timing start */
    struct timespec start_ts, end_ts;
    clock_gettime(CLOCK_MONOTONIC, &start_ts);
 
    /* Benchmark loop */
    for(unsigned long i=0; i<Number_Of_Runs; ++i) {
        int Int_1_Loc = 5;
        int Int_2_Loc = 13;
        int Int_3_Loc = 7;
        char Str_1_Loc[31] = "DHRYSTONE PROGRAM, 1'ST STRING";
        char Str_2_Loc[31] = "DHRYSTONE PROGRAM, 2'ND STRING";
        Enumeration Enum_Loc = Ident_2;
 
        Proc_5();
        Proc_4();
        Proc_1(Ptr_Glob);
        Proc_2(&Int_1_Loc);

        Int_2_Loc = Int_2_Loc * Int_1_Loc;
        Enum_Loc = Func_1(Ch_1_Glob, Ch_2_Glob);
        if (Func_2(Str_1_Loc, Str_2_Loc))
            Int_1_Loc += 1;
        if (Func_3(Enum_Loc))
            Proc_3(&Ptr_Glob->Ptr_Comp);
    }

    clock_gettime(CLOCK_MONOTONIC, &end_ts);
 
    long total_us = (end_ts.tv_sec - start_ts.tv_sec)*1000000L +
                    (end_ts.tv_nsec - start_ts.tv_nsec)/1000L;
 
    double secs = total_us / 1e6;
    double dhrystones_per_sec = Number_Of_Runs / secs;

    printf("Dhrystone 2.1 (modernized)\n");
    printf("Runs: %lu\n", Number_Of_Runs);
    printf("Total time: %ld microseconds (%.6f seconds)\n", total_us, secs);
    printf("Dhrystones per second: %.2f\n", dhrystones_per_sec);
    printf("DMIPS: %.2f\n", dhrystones_per_sec / 1757.0);

    /* Verification output */
    printf("\nFinal values of the variables used in the benchmark:\n\n");

    printf("Int_Glob:           %d\n        should be:   5\n", Int_Glob);
    printf("Bool_Glob:          %d\n        should be:   1\n", Bool_Glob);
    printf("Ch_1_Glob:          %c\n        should be:   A\n", Ch_1_Glob);
    printf("Ch_2_Glob:          %c\n        should be:   B\n", Ch_2_Glob);

    printf("Arr_1_Glob[8]:      %d\n        should be:   7\n", Arr_1_Glob[8]);
    printf("Arr_2_Glob[8][7]:   %d\n        should be:   %lu\n", Arr_2_Glob[8][7], Number_Of_Runs + 10);

    printf("Ptr_Glob->\n");
    printf("  Ptr_Comp:         %p\n", (void*)Ptr_Glob->Ptr_Comp);
    printf("  Discr:            %d\n        should be:   0\n", Ptr_Glob->Discr);
    printf("  Enum_Comp:        %d\n        should be:   2\n", Ptr_Glob->variant.var_1.Enum_Comp);
    printf("  Int_Comp:         %d\n        should be:   17\n", Ptr_Glob->variant.var_1.Int_Comp);
    printf("  Str_Comp:         %s\n        should be:   DHRYSTONE PROGRAM, SOME STRING\n", Ptr_Glob->variant.var_1.Str_Comp);

    printf("Next_Ptr_Glob->\n");
    printf("  Ptr_Comp:         %p\n", (void*)Next_Ptr_Glob->Ptr_Comp);
    printf("  Discr:            %d\n        should be:   0\n", Next_Ptr_Glob->Discr);
    printf("  Enum_Comp:        %d\n        should be:   1\n", Next_Ptr_Glob->variant.var_1.Enum_Comp);
    printf("  Int_Comp:         %d\n        should be:   18\n", Next_Ptr_Glob->variant.var_1.Int_Comp);
    printf("  Str_Comp:         %s\n        should be:   DHRYSTONE PROGRAM, SOME STRING\n", Next_Ptr_Glob->variant.var_1.Str_Comp);

    /* Free memory */
    free(Ptr_Glob);
    free(Next_Ptr_Glob);

    return 0;
}
