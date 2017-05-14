#include <stdio.h>
#include <stdlib.h>

#define MAX 2048
#define WORDCHECK(x) (x == ' ' || x == ',' || x == ';' || x == '\n' || x == '\t' || x == ':' || x == '.' || x == '?' || x == EOF)
int main(int argc, char *argv[]) {
	int i, j, lc, ret;
	char a[MAX], c;
	FILE *fp;

	fp = fopen(argv[1], "r");

	for (i = 0; (ret = (fscanf(fp, "%c", &c))) != EOF; i++) {
		a[i] = c;
	}
	fclose(fp);

	fp = fopen(argv[1], "w");
	if (i == 0)
		return -1;

	lc = 1;
    fprintf(fp, "1. ");
	for (j = 0; j < i-1; j++) {
		fprintf(fp,"%c", a[j]);
		if (a[j] == '\n') {
			fprintf(fp, "%d. ", ++lc);
		}
	}
	fputc('\n', fp);
	fclose(fp);
	return 0;
}
