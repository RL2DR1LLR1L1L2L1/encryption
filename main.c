#include <stdio.h>
#include <stdlib.h>

// clears the buffer of a specified array
void clear_buff(int size, char *buff)
{
 
 for(int j = 0; j < size; j++)
 {
     buff[j] = 0;
 }
}

char encode(int count1, char *input, char *output)
{
    
    //an array of encrypted and unencrypted characters on the qwerty keyboard
    char atob[88] = "abcdefghijklmnopqrstuvwyxzABCDEFGHIJKLMNOPQRSTUVWYXZ0123456789!@#$%^&*()-_=+[{]};:,<.>/?"; //unencrypted
    char btoa[90] = "ababcdefghijklmnopqrstuvwyxzABCDEFGHIJKLMNOPQRSTUVWYXZ0123456789!@#$%^&*()-_=+[{]};:,<.>"; //encrypted


    for(int i = 0; i < 20; i++)
    {
        char k = 0;
        while(1)
        {
            // check what characters from the alhpabet matches from the input
            if(atob[k] == input[i])
            {
                // i is what characters were checked
                // every character from unencrypted alphabet is going to turn to the character in the encrypted one
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

    // input the filename
    printf("Enter your desired file to encrypt(text files: *.txt* |): ");
    char filename[20];
    scanf("%s", filename);

    // read file pointer (It's there because we need to keep track of the file location)
    FILE * rfPointer;
    // file pointer gets the file's name and what to do with it ( "r" to read and "w" to write )
    rfPointer = fopen(filename, "r");
    // contents of your file ( size is the max size for a single line )
    char contents[225];
    // output is the array where we are gonna store our encrypted text in
    char output[225];

    // while the file pointer did not end
    while(!feof(rfPointer))
    {
        // stores the content of our file in our "contents" array, 2nd par. is max line size and the 3rd parameter is to get the filename from our pointer
        fgets(contents, 225, rfPointer);
    }
    
    // closing our read file pointer (we don't need to keep track of it anymore)
    fclose(rfPointer);
    // get the lenght of our file contents
    int len = strlen(contents);

    // clears our "output" array before we are gonna store our encrypted content there
    clear_buff(225, output);
    // encrypts are file contents and stores them in output
    encode(len, &contents, &output);

    // create another file pointer (this time for "writing" or creating the encrypted file)
    FILE * wfPointer;
    // pass the name of the file we want to create and that we want to write it to the file pointer
    wfPointer = fopen("output.txt", "w");

    // puts the encrypted content to our newly created file
    fputs(output, rfPointer);

    // closes write file pointer
    fclose(wfPointer);


    return 0;
}
