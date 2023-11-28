%{
    int flag = 0;
%}


%%
[a-z . 0-9]+@[a-z]+".com"|".in" { flag=1; }
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
    if (flag == 1) 
        printf("\n email Accepted"); 
    else
        printf("\n email Not Accepted"); 
    printf("\n");
    return (0);
}

int yywrap() {
    return (1);
}
