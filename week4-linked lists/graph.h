#include <stdio.h>

void graph_script(int ds, int deco, int dms, int java, int mpi){
    FILE* fp = fopen("graph.py", "w");
    fprintf(fp, "import pandas as pd \n");
    fprintf(fp, "import matplotlib.pyplot as plt \n");
    fprintf(fp, "a = [%d,%d,%d,%d,%d] \n", ds, deco, dms, java, mpi);
    fprintf(fp, "b = ['Data Structures', 'Digital Electronics', 'Discrete Mathematics', 'OOP-Java', 'Microprocessor'] \n");
    fprintf(fp, "plt.bar(b, a) \n");
    fprintf(fp, "plt.show()");
    fclose(fp);
}

