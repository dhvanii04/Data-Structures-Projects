#include "stack.h"
#include <stdio.h>

void popRecords(int arr[100], int top){
    for(int i=0; i<top; i++){
        pop(arr, top);
    }
}