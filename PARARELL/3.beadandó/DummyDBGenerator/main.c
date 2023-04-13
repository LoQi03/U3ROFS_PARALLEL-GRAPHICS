#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_CITY_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_EMAIL_LENGTH 30

char *generate_random_string(int length)
{
    char *str = (char *)malloc((length + 1) * sizeof(char));
    int i;
    for (i = 0; i < length; i++)
    {
        int r = rand() % 26;
        str[i] = 'A' + r;
    }
    str[length] = '\0';
    return str;
}

char *generate_random_email(char *name, char *domain)
{
    int name_length = strlen(name);
    int domain_length = strlen(domain);
    char *email = (char *)malloc((name_length + domain_length + 2) * sizeof(char));
    int i;
    for (i = 0; i < name_length; i++)
    {
        email[i] = name[i];
    }
    email[name_length] = '@';
    for (i = 0; i < domain_length; i++)
    {
        email[name_length + i + 1] = domain[i];
    }
    email[name_length + domain_length + 1] = '\0';
    return email;
}

int main()
{
    srand(time(NULL)); // inicializáljuk a random generátort a rendszeróra alapján

    FILE *f = fopen("dummy_data.csv", "w"); // megnyitjuk a fájlt írásra

    // kiírjuk a fájl fejlécét
    fprintf(f, "id,name,city,email,password,age\n");

    int i;
    for (i = 1; i <= 1000; i++)
    {
        // generálunk egy véletlenszerű nevet
        char *name = generate_random_string(MAX_NAME_LENGTH - 1);

        // generálunk egy véletlenszerű települést
        char *city = generate_random_string(MAX_CITY_LENGTH - 1);

        // generálunk egy véletlenszerű e-mail címet
        char domain[] = "example.com";
        char *email = generate_random_email(name, domain);

        // generálunk egy véletlenszerű jelszót
        char *password = generate_random_string(MAX_PASSWORD_LENGTH - 1);

        // generálunk egy véletlenszerű életkort
        int age = rand() % 100;

        // kiírjuk az adatokat a fájlba
        fprintf(f, "%d,%s,%s,%s,%s,%d\n", i, name, city, email, password, age);

        free(name);
        free(city);
        free(email);
        free(password);
    }

    fclose(f); // befejezzük a fájl írását

    printf("Az adatbázis elkészült!\n");

    return 0;
}