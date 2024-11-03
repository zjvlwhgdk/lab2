#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*sum)(int, int);
    int (*minus)(int, int);
    int (*multiply)(int, int);
    double (*divide)(int, int);
    char *error;

    handle = dlopen("./libmath.so", RTLD_LAZY);
    if (!handle) {
        fputs(dlerror(), stderr);
        exit(1);
    }

    sum = dlsym(handle, "sum");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    minus = dlsym(handle, "minus");
if ((error = dlerror()) != NULL) {
    fprintf(stderr, "%s\n", error);
    exit(1);
}


    multiply = dlsym(handle, "multiply");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    divide = dlsym(handle, "divide");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    printf("sum(4, 2) = %d\n", (*sum)(4, 2));
    printf("minus(4, 2) = %d\n", (*minus)(4, 2));
    printf("multiply(4, 2) = %d\n", (*multiply)(4, 2));
    printf("divide(4, 2) = %f\n", (*divide)(4, 2));

    dlclose(handle);
    return 0;
}

