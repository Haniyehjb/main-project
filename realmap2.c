# include <stdio.h>
int main (){
char mat[28][122] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '^', ':', '%', ' ', ' ', ' ', ' ',3, ':', ' ', '@', ' ', ' ', ' ',' '  ,' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' '},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 , 1 , 1 , 1},
    {1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '  ,' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ', ' ', ' ', 1, ' ', ' ', ' ',2, ' ', 1},
    {1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ', ' ', ' ', ' ', 1, ' ', ' ', ' ',2, 2, 1},
    {1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', 2, 2, 1},
    {1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ' ,2, 2, 2, 2,' ', ' ', ' ',' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', 1, 1, 8, ' ', ' ',' ' ,' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ', ' ', ' ', 1, ' ', ' ', ' ', 2, ' ', 1},
    {1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ' ,' ' ,2, 2, ' ', ' ' , ' ', ' ',1 ,1 ,1 , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ',' ', ' ', 1 , ' ', ' ', '!', ' ', ' ', 1},
    {1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, 1, 8, 1, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',2, 2, ' ',' ' , ' ', ' ', ' ', 1, ' ', ' ', 1, 1, 1, ' ', ' ', ' ', ' ',1 , 9, 1, ' ',' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ', ' ', ' ', ' ', 1,1 ,1 ,1 ,1 ,1 , 1},
    {1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, 1, 1, 1, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ',1,1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 7, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', 1},
    {1, ' ', ' ', ' ',1,1 ,1,' ' ,' ' ,' '  , 1,' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 3, 1,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 , 9, 1, 1, 1, 1, ' ', ' ',' ', ' ',' ', ' ', ' ', ' ', 1},
    {1, ' ', ' ', 3, ' ', ' ', ' ', ' ',' ' , ' ',' ' ,' ' , ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', 1,' ' , ' ', ' ',' ' , ' ', ' ', ' ', ' ', ' ',' ', ' ' ,1, ' ', ' ', ' ', ' ',' ',' ' , ' ', ' ', 1, 1, ' ',' ', ' ', ' ', ' ', ' ', 1},
    {1, ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ' ,' ' ,' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ', ' ',' ' , ' ',' ', ' ',2,2, 2, ' ', 1, 1, ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ',' ',' ', ' ', ' ',' ',5 , 1, 1 , ' ', ' ', 1, 1, 1, ' ', ' ', '$', 1, 1, 1},
    {1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ',' ',' ', 2, 2, 1, 1,' ', ' ', ' ', ' ', 1,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 , 1,' ' , ' ', 1, ' ', 1, 1, 1, ' ', ' ', ' ', 1},
    {1, ' ','#' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 5, ' ', ' ',3 , ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ',' ', 2, 2, ' ', ' ',' ' , ' ', ' ' ,' ',' ',' ', ' ',' ' , ' ',5 ,' ' , ' ', ' ', ' ', ' ', ' ',' ' , 1, ' ', ' ', ' ', 3, ' ', ' ',' ' , ' ',  ' ',' ', ' ' , 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, ' ', 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, ' ', 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 , 1 , 1 , 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, ' ', 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, ' ', 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 3, ' ', 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 3, 1, ' ', 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 7, 1, 1, ' ', 1, 1, ' ', ' ', 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',7, 1, 1, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 3, 1, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 2, 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, ' ', ' ', ' ', ' ', ' ', ' ', 5, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 3, 2, 2, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 1, 1,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,' ' ,1 ,1 ,1 , 1, 1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}

    };
for(int i = 0 ; i < 28 ; ++i){
    for(int j = 0 ; j < 122 ; j++){


if (mat[i][j] == 1){
    printf("🧱");
}
else if ( mat[i][j] == 2){
    printf("🟩");
}
else if ( mat[i][j] == 3){
    printf("🪙 ");
}
else if ( mat[i][j] == 4){
    printf("🌱");
}
else if ( mat[i][j] == 5){
    printf("🐙");
}
else if ( mat[i][j] == 6){
    printf("🟪");
}
else if ( mat[i][j] == 7){
    printf("🦖");
}
else if ( mat[i][j] == 8){
    printf("🟧");
}
else if ( mat[i][j] == 9){
    printf("🟨");
}
else if ( mat[i][j] == '!'){
    printf("🚩");
}
else if ( mat[i][j] == '#'){
    printf("🥸 ");
}
else if ( mat[i][j] == '$'){
    printf("🛡️ ");
}
else if (mat[i][j] == ' '){
    printf("  ");
}


    }
    printf("\n");
}
return 0 ;
}
