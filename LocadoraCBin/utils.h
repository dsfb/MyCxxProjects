#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

int starts_with(const char *a, const char *b);
int pause();

#ifdef linux
char *strupr(char *data);
#endif // linux

#endif // UTILS_H_INCLUDED
