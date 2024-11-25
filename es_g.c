#include <stdio.h>

int main()
{
    char *nomeFile1 = "testfiles/file_src";
    char *nomeFile2 = "testfiles/file_dst";
    int ch;

    FILE *pfile1 = fopen(nomeFile1, "r");
    FILE *pfile2 = fopen(nomeFile2, "w");

    while((ch=getc(pfile1)) != EOF)
    {
        putc(ch,pfile2);
    }

    fclose(pfile1);
    fclose(pfile2);

    return 0;

}