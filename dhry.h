#ifndef DHRY_H
#define DHRY_H

typedef enum { Ident_1 = 1, Ident_2, Ident_3, Ident_4, Ident_5 } Enumeration; 

typedef struct Record {
    struct Record *Ptr_Comp;
    Enumeration Discr;
    union {
        struct {
            Enumeration Enum_Comp;
            int Int_Comp;
            char Str_Comp[31];
        } var_1;
    } variant;
} Record;
 
/* Function declarations */
void Proc_1(Record *Ptr_Val_Par);
void Proc_2(int *Int_Par_Ref);
void Proc_3(Record **Ptr_Ref_Par);
void Proc_4(void);
void Proc_5(void);
Enumeration Func_1(char Ch_1_Par_Val, char Ch_2_Par_Val);
int Func_2(char Str_1_Par_Ref[31], char Str_2_Par_Ref[31]);
int Func_3(Enumeration Enum_Par_Val);

#endif /* DHRY_H */
