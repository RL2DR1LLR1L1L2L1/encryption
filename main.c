#include <stdio.h>
#include <stdlib.h>


void clear_buff(int size, char *buff)
{
 for(int j = 0; j < size; j++)
 {
     buff[j] = 0;
 }
}

char encode(int count1, char *input, char *output)
{
    char atob[88] = "abcdefghijklmnopqrstuvwyxzABCDEFGHIJKLMNOPQRSTUVWYXZ0123456789!@#$%^&*()-_=+[{]};:,<.>/?";
    char btoa[90]= "ababcdefghijklmnopqrstuvwyABABCDEFGHIJKLMNOPQRSTUVWYXZ0123456789!@#$%^&*()-_=+[{]};:,<.>/?";

//

    for(int i = 0; i < 20; i++)
    {
        char k = 0;
        while(1)
        {
            if(atob[k] == input[i])
            {
                output[i] = btoa[k];
                break;
            }
            k++;
        }

    }

    return 0;
}

int main()
{

    printf("Enter your desired file to encrypt(text files: *.txt* |): ");
    char filename[20];
    scanf("%s", filename);

    FILE * rfPointer;
    rfPointer = fopen(filename, "r");
    char contents[225];
    char output[225];


    while(!feof(rfPointer))
    {
        fgets(contents, 225, rfPointer);

    }

    fclose(rfPointer);
    int len = strlen(contents);

    clear_buff(225, output);
    encode(len, &contents, &output);

    FILE * wfPointer;
    wfPointer = fopen("output.txt", "w");

    //encode();

    fputs(output, rfPointer);

    fclose(wfPointer);


    return 0;
}
