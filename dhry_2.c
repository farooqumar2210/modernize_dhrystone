#include <string.h>
#include "dhry.h"

/* External globals */
extern Record *Ptr_Glob;
extern Record *Next_Ptr_Glob;
extern int Int_Glob;
extern int Bool_Glob;
extern char Ch_1_Glob;
extern char Ch_2_Glob;
extern int Arr_1_Glob[50];
extern int Arr_2_Glob[50][50];

/* Fully compliant Dhrystone procedures */

void Proc_1(Record *Ptr_Val_Par) {
    Record *Next_Record = Ptr_Val_Par->Ptr_Comp;
    Ptr_Val_Par->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    Ptr_Val_Par->variant.var_1.Int_Comp = 17;

    Next_Record->variant.var_1.Int_Comp = Ptr_Val_Par->variant.var_1.Int_Comp;
    Next_Record->variant.var_1.Enum_Comp = Ident_2;
    Next_Record->Discr = Ident_1;
}

void Proc_2(int *Int_Par_Ref) {
    *Int_Par_Ref += 10;
}

void Proc_3(Record **Ptr_Ref_Par) {
    if (Ptr_Glob != NULL)
        *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
}

void Proc_4(void) {
    Bool_Glob = (Ch_1_Glob == 'A');
    Ch_2_Glob = 'B';
}

void Proc_5(void) {
    Ch_1_Glob = 'A';
    Bool_Glob = 1;
}

Enumeration Func_1(char Ch_1_Par_Val, char Ch_2_Par_Val) {
    if (Ch_1_Par_Val == Ch_2_Par_Val)
        return Ident_1;
    else
        return Ident_2;
}

int Func_2(char Str_1_Par_Ref[31], char Str_2_Par_Ref[31]) {
    return strcmp(Str_1_Par_Ref, Str_2_Par_Ref) == 0;
}

int Func_3(Enumeration Enum_Par_Val) {
    return Enum_Par_Val == Ident_3;
}
