#include <stdio.h>
#include <time.h>

int main()
{
    struct tm *data_atual;
    time_t ano;
    time(&ano);
    data_atual = localtime(&ano);
    int year = data_atual->tm_year + 1900;
    printf("\nAno..........: %d\n\n", year);
    return 0;
}