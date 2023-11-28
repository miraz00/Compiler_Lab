
%{
    int vow_count=0;
    int const_count =0;
%}
 
%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}
%%

int main(int argc, char **argv) {
    FILE *file;
    file = fopen("file.txt", "r");
    if (!file) {
        printf("could not open the file");
        exit(0);
    }
    yyin = file;
    yylex();
    printf("Number of Vowels in the file = %d\nNumber of consonants in the file= %d\n",vow_count,const_count);
    return (0);
}

int yywrap() {
    return (1);
}
