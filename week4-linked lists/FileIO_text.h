#include <stdio.h>

void fileWritetxtSingle(int rollNo, int ds, int dms, int mpi, int java, int deco, int per){
    FILE *fptr;
    fptr = fopen("singlerecord.txt", "w");
    fprintf(fptr,"\n\nDETAILS OF STUDENT IS AS BELLOW: ");
    fprintf(fptr,"\nROLL NO:    %d",rollNo);
    fprintf(fptr,"\nDS MARKS:   %d",ds);
    fprintf(fptr,"\nDMS MARKS:  %d",dms);
    fprintf(fptr,"\nMPI MARKS:  %d",mpi);
    fprintf(fptr,"\nJAVA MARKS: %d",java);
    fprintf(fptr,"\nDECO MARKS: %d",deco);
    fprintf(fptr,"\nPERCENTAGE: %.2f",per);
    fclose(fptr);
}

void fileWritecsvSingle(int rollNo, int ds, int dms, int mpi, int java, int deco, int per){
    FILE *fptr;
    fptr = fopen("singlerecord.csv", "w");
    fprintf(fptr,"ROLL NO,DS MARKS,DMS MARKS,MPI MARKS,JAVA MARKS,DECO MARKS,PERCENTAGE");
    fprintf(fptr,"\n%d,%d,%d,%d,%d,%d,%.2f",rollNo,ds,dms,mpi,java,deco,per);
    fclose(fptr);
}