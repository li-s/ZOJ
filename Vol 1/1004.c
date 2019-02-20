#include <stdio.h>
#include <string.h>

int main()
{
    char target[10] = {};
    char change[10] = {};
    char stack[10][10] = {};
    int string_length = 0;
    
    scanf("%s", change);
    scanf("%s", target);
    
    if(strcmp(target, change) == 0)
    {
        printf("[\n]\n");
    }
    
    if(strlen(target) != strlen(change))
    {
        printf("[\n]\n");
    }
    
    return 0;
}
