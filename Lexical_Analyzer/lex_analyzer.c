#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    FILE *filein = fopen("filein.txt", "r"); // open file for the input
    FILE *fileout = fopen("fileout.txt", "w"); // open file for output
    int lineno = 1, tokno = 0, i,j, flag = 0; // lineno to count the number of lines have been covered and tokno is the count of tokens that is read
    char ch, str[100], keyword[50][50] = {"int", "main", "if", "else", "while", "for", "return", "do", "switch", "FILE", "printf", "scanf"}; // Common keywords in C language
    fprintf(fileout,"Line \t\t Token no. \t Token \t\t Lexeme\n"); //printing the header of the table

    while (!feof(filein))
    {
        i = 0; flag = 0;
        ch = fgetc(filein);
        if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%')
        {
                        fprintf(fileout,"%d\t\t %d\t\t Operator\t %c\n",lineno,tokno,ch);
                        tokno++;
        }
        
        else if ( ch==';' || ch=='{' || ch=='}' || ch=='?' || ch=='|' || ch=='[' || ch==']'|| ch==':')
        {
            fprintf(fileout,"%d\t\t %d\t\t Special Symbol\t %c\n",lineno,tokno,ch);
            tokno++;
        }

        else if(isdigit(ch))
        {
                        fprintf(fileout,"%d\t\t %d\t\t Digit\t\t %c\n",lineno,tokno,ch);
                        tokno++;
        }
        
        else if (isalpha(ch))
        {
            str[i] = ch;
            i++;
            ch = fgetc(filein);

            while (isalnum(ch) && ch!=' ') 
            {
                str[i] = ch;
                i++;
                ch = fgetc(filein);
            }
            str[i] = '\0';

            for ( j = 0; j<50; j++)
            {
                if(strcmp(str, keyword[j]) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 1)
            {
                fprintf(fileout,"%d\t\t %d\t\t Keyword\t %s\n",lineno,tokno,str);
            }
            else {fprintf(fileout,"%d\t\t %d\t\t Identifier\t %s\n",lineno,tokno,str);}

            tokno++;
            
        }
        else if(ch == '\n')
        {
            lineno++;
        }
        
    }
    

    fclose(fileout);
    fclose(filein);

    return 0;
}
