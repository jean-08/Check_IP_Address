#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 250

void head()
{
    printf("Content-Type: text/html\n\n");
    printf("<html><head><title>Vérifier l'adresse IP</title><meta charset=\"UTF-8\" />");
    printf("<style>");
    printf("body { font-family: Arial, sans-serif; background-color: #f4f4f4; color: #333; margin: 0; padding: 0; display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; }");
    printf("h1 { color: #4CAF50; text-align: center; }");
    printf("p { font-size: 18px; }");
    printf("form { background: #fff; padding: 20px; border-radius: 8px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); margin-top: 20px; }");
    printf("input[type='text'] { width: calc(100% - 22px); padding: 10px; margin-bottom: 20px; border: 1px solid #ddd; border-radius: 4px; }");
    printf("input[type='submit'] { background-color: #4659c7; color: #fff; border: none; padding: 10px 20px; border-radius: 4px; cursor: pointer; font-size: 16px; }");
    printf("input[type='submit']:hover { background-color: #3c5496; }");
    printf("</style>");
    printf("</head><body>");
}

char* compare_ip(int a, int b, int c, int d)
{
    static char class[20];
    if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255) 
    {
        strcpy(class, "IP Invalide");
    }
    else if (a >= 0 && a <= 127) {
        strcpy(class, "class A");
    }
    else if (a >= 128 && a <= 191) 
    {
        strcpy(class, "class B");
    }
    else if (a >= 192 && a <= 223) 
    {
        strcpy(class, "class C");
    }
    else if (a >= 224 && a <= 239) 
    {
        strcpy(class, "class D");
    }
    else if (a >= 240 && a <= 255) 
    {
        strcpy(class, "class E");
    }
    else {
        strcpy(class, "IP Invalide");
    }

    return class;
}

void get_post()
{
    char ip[MAX_CHAR];
    char *classe;
    int a,b,c,d;
    int ip_string;

    if (fgets(ip, MAX_CHAR, stdin) != NULL) 
    {
        ip_string = sscanf(ip, "IP=%d.%d.%d.%d", &a,&b,&c,&d);
        if (ip_string == 4) 
        {
            printf("<h1>Adresse IP reçue : </h1>");
            printf("<p>%s</p>", ip);
            classe = compare_ip(a,b,c,d);
            printf("<h1>Type %s</h1>", classe);           
        }
        else if (ip_string != 4 )
        {
            printf("<p>IP invalide, essayez à nouveau ! </p>");
        }
    }
}

int main()
{
    head();
    get_post();
    printf("</body></html>");
    return 0;
}
