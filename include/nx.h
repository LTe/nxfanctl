#ifndef NX_H
#define NX_H

int configRead();
void fanOff(char *path);
void fanOn(char *path);
char** fanConfig(int n);

#endif