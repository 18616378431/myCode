#ifndef NAMES_ST_H_
#define NAMES_ST_H_

#define SLEN 32

struct names{
	char first[SLEN];
	char last[SLEN];
};

typedef struct names NAMES;

void getName(NAMES *);
void showName(NAMES *);

#endif