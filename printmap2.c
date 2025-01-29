#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

char mat_1[16][64] = {
        "             > :*      3 :$     ? :=                            ",
        "1111111111111111111111111111111111111111111111111111111111111111",
        "1                     22                                       1",
        "1                     22                                       1",
        "1                    2222                                      1",
        "1                                           7                  1",
        "1                 9      33               4444                 1",
        "1                111     111               44                  1",
        "1                    111              4444 44                  1",
        "1                                      44  44                  1",
        "1   11133                          7   44  44                  1",
        "1      11&1                       4444 44  44   1881           1",
        "1          111                     44  44  44   1  1      2222 1",
        "1                            4444  44  44  44   1  1       22  1",
        "1   #           33            44 6 446 446 446  1          22  1",
        "1111111111111111111111111111111111111111111111111111111111111111"
};

char mat_2[28][64] = {
        "             > :*      3 :$     ? :=                            ",
        "1111111111111111111111111111111111111111111111111111111111111111",
        "1                                                       1    @ 1",
        "1                                                       1    @@1",
        "1                                                       1    @@1",
        "1                      @@@@        118                  1    @ 1",
        "1                       @@  111                         1 9    1",
        "1       11811           @@ 1   111     1&1              11111111",
        "1                      11111     11        6                   1",
        "1   111   1                     3 111111111111111!11111        1",
        "1  3                             1                    11       1",
        "1  1                      2222  11                 11 1 11  (111",
        "1                          22 11      111111111111111 1  111   1",
        "1              3           22                     1   3        1",
        "1111111111111111111111111111 11111111111111111111 11111111111111",
        "1111111111111111111111111111 11111111111111111111 11111111111111",
        "                           1                     21",
        "                           1                     21",
        "                           1                     21",
        "                           1                     21",
        "                           1                     21",
        "                           1                   3 21",
        "                           1                  31 21",
        "                           1             611 11  21",
        "                           1           6111      21",
        "                           1         311        221",
        "                           1         1         3221",
        "                           111111111111111111111111",

};
int koofteh=0;
int dontlook=0;
int wins = 0 , lose = 0 ;
int hit_status = 0 ;
int score = 0;
int coins = 0 ;
int mapaddress=1;
int heart;
int add_gamer(const char* name, const char* email, const char* password);
void sign_in(const char* name, const char* email, const char* password);
int delete_account(const char* name, const char* email, const char* password);
int get_password(char *password, int max_length);
void save_all_players();
void load_all_players();
void print_grid1();
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int rand_num(){
    srand(time(NULL));
    int random_num = rand();
    random_num = random_num % 5 + 1 ;
    return random_num;
}
void downy (int *i, int *j, char mat[][128]) {
    while (!(*i < 13 && (mat[*i + 1][*j] == ' ' || mat[*i + 1][*j] == 8 || mat[*i + 1][*j] == 9 || mat[*i + 1][*j] == 3 || mat[*i + 1][*j] == '#' || mat[*i + 1][*j] == '*'))) {
        mat[*i][*j] = ' ';
        (*i)++;
        mat[*i][*j] = '#';
        print_grid1(mat , score , coins);
        Sleep(10);
    }
}
void move_character(int *i, int *j, char mat[][128]) {
    char ch;
    int ch2;
    if (_kbhit())
        ch = _getch();
    gotoxy(*j*2 , *i);
    if (ch == 'd' && *j < 127 && (mat[*i][*j + 1] == ' ' || mat[*i][*j + 1] == 8 || mat[*i][*j + 1] == 9 || mat[*i][*j + 1] == 3 || mat[*i][*j + 1] == '#' || mat[*i][*j + 1] == '*')) {
        mat[*i][*j] = ' ';
        (*j)++;
    } else if (ch == 'a' && *j > 0 && (mat[*i][*j - 1] == ' ' || mat[*i][*j - 1] == 8 || mat[*i][*j - 1] == 9 || mat[*i][*j - 1] == 3 || mat[*i][*j - 1] == '#' || mat[*i][*j - 1] == '*')) {
        mat[*i][*j] = ' ';
        (*j)--;
    } else if (ch == 's' && *i < 13 && (mat[*i + 1][*j] == ' ' || mat[*i + 1][*j] == 8 || mat[*i + 1][*j] == 9 || mat[*i + 1][*j] == 3 || mat[*i + 1][*j] == '#' || mat[*i + 1][*j] == '*')) {
        while (ch == 's' && *i < 13 && (mat[*i + 1][*j] == ' ' || mat[*i + 1][*j] == 8 || mat[*i + 1][*j] == 9 || mat[*i + 1][*j] == 3 || mat[*i + 1][*j] == '#' || mat[*i + 1][*j] == '*')) {
            mat[*i][*j] = ' ';
            (*i)++;
            mat[*i][*j] = '#';
            print_grid1(mat , score , coins);
            Sleep(10);
        }
    }
    else if (ch == 'w' && *i > 0 && (mat[*i - 1][*j] == ' ' || mat[*i - 1][*j] == 8 || mat[*i - 1][*j] == 9 || mat[*i - 1][*j] == 3 || mat[*i - 1][*j] == '#' || mat[*i - 1][*j] == '*')) {
        for(int ooo = 0; ooo < 4; ooo++)
        {
            mat[*i][*j] = ' ';
            (*i)--;
            ch=0;
            ch = _getch();
            if (ch == 'd' && *j < 127 && (mat[*i][*j + 1] == ' ' || mat[*i][*j + 1] == 8 || mat[*i][*j + 1] == 9 || mat[*i][*j + 1] == 3 || mat[*i][*j + 1] == '#' || mat[*i][*j + 1] == '*')) {
                mat[*i][*j] = ' ';
                (*j)++;
            } else if (ch == 'a' && *j > 0 && (mat[*i][*j - 1] == ' ' || mat[*i][*j - 1] == 8 || mat[*i][*j - 1] == 9 || mat[*i][*j - 1] == 3 || mat[*i][*j - 1] == '#' || mat[*i][*j - 1] == '*')) {
                mat[*i][*j] = ' ';
                (*j)--;
            } else if (ch == 's' && *i < 13 && (mat[*i + 1][*j] == ' ' || mat[*i + 1][*j] == 8 || mat[*i + 1][*j] == 9 || mat[*i + 1][*j] == 3 || mat[*i + 1][*j] == '#' || mat[*i + 1][*j] == '*')) {
                while (ch == 's' && *i < 13 && (mat[*i + 1][*j] == ' ' || mat[*i + 1][*j] == 8 || mat[*i + 1][*j] == 9 || mat[*i + 1][*j] == 3 || mat[*i + 1][*j] == '#' || mat[*i + 1][*j] == '*')) {
                    mat[*i][*j] = ' ';
                    (*i)++;
                    mat[*i][*j] = '#';
                    print_grid1(mat , score , coins);
                    Sleep(10);
                }
                break;
            }
            mat[*i][*j] = '#';
            print_grid1(mat , score , coins);
            Sleep(10);
        }
    }
    downy(i,j,mat);
}
void coins_score (char mat[][128],int i , int j ,int coins ,int score){
    int time1;
    int *last_destroy_time = 0 ;
    if(mat[i][j] == 3){
        coins ++;
    }
    if (mat[i - 1][j] == 5) {
        time1 = time(NULL);
        int time_diff = time1 - *last_destroy_time;

        if (time_diff < 5) {

            score *= 2;
        } else {

            score += 100;
        }

        *last_destroy_time = time1;
        mat[i - 1][j] = ' ';
    }
}
void orange_cube(char mat[][128] , int *i ,int *j ){
    if (koofteh == 1){
        mat[*i-1][*j] = ' ';
        if(rand_num() == 3){
            mat[*i-1][*j] == 3;
        }

    }

}
void green_pipe1(char mat[][128] ,int *i , int *j){
    if(mat[9][61] = '#'){
        mat[9][61] = ' ';
        mat[4][23] = '#';
        *i = 4;
        *j = 23;
    }
}
void green_pipe2 (char mat[][122] , int *i , int *j) {
    if(mat[9][27] == '#'){
        mat[9][27] = ' ';
        mat[13][27] ='#';
        *i = 13 ;
        *j = 27 ;
    }
    else if (mat[25][47] == '#'){
        mat[25][47] = ' ';
        mat[11][46] = '#';
        *i = 11;
        *j = 46;
    }
    else if(mat[3][24] == '#'){
        mat[3][24] = ' ';
        mat[3][57] = '#';
        *i = 3 ;
        *j = 24 ;
    }
}
void move_enemy(int *i, int *j, int *direction, char mat[][128]) {
    // پاک کردن موقعیت فعلی اختاپوس
    mat[*i][*j] = ' ';

    // حرکت اختاپوس بر اساس جهت
    if (*direction == 1 && *j < 127 && (mat[*i][*j + 1] == ' ' || mat[*i][*j + 1] == 3)) {
        (*j)++;  // حرکت به راست
    } else if (*direction == -1 && *j > 0 && (mat[*i][*j - 1] == ' ' || mat[*i][*j - 1] == 3)) {
        (*j)--;  // حرکت به چپ
    } else {
        *direction *= -1;  // تغییر جهت در صورت برخورد با مانع
    }


    mat[*i][*j] = '5';
}
void double_mario(char mat[][128] , int i , int j){
    if(mat[i][j]  == '*'){
        mat[i-1][j] == '#';
    }
    koofteh=1;
}
int game_over(){
    lose ++ ;

    printf("\033[1;31mGAME OVER !\033[0m\n");
    printf("\033[1;31mYOU LOSE \033[0m\n");
    printf("YOUR SCORE : %d \n YOUR COINS : %d" , score , coins);
    printf("\033[1;34mSTART AGAIN?\033[0m\n");
    printf("1.YES \n2.NO\n");
    return 1;
}
void win_game1( int coins , int score , int wins , int lose){////////////////////
    dontlook=1;

    int num;

    printf("\033[1;32mYOU HAVE SUCCESSFULLY COMPLETED THIS LEVEL!\033[0m\n");
    printf("YOUR COINS : %d \n YOUR SCORE : %d" , coins , score);
    printf("\033[1;32m1.GOING TO NEXT LEVEL\033[0m\n");
    printf("\033[1;31m2.EXIT\033[0m\n");
    printf("\033[1;32m13.REPEAT THIS LEVEL\033[0m\n");
    if (_kbhit())
        num = _getch();
    switch(num){
        case 1:
            print_grid1(mat_2 , score , coins);
        case 2 :
            return;
        case 3 :
            print_grid1(mat_1 , score , coins);
    }
}
void print_grid1()
{

    for (int i = 0; i < 16 ; i++)
    {
        for (int j = 0; j < 64 ; j++)
        {
            switch (mat_1[i][j])
            {
                case '1':
                    printf("🧱");
                    break;
                case '2':
                    printf("🟩");
                    break;
                case '3':
                    printf("🪙");
                    break;
                case '4':
                    printf("🟪");
                    break;
                case '5':
                    printf("🐙");
                    break;
                case '6':
                    printf("🦖");
                    break;
                case '7':
                    printf("🌱");
                    break;
                case '8':
                    printf("🟧");
                    break;
                case '9':
                    printf("🚩");
                    break;
                case '!':
                    printf("🟨");
                    break;
                case '&':
                    printf("🟨");
                    break;
                case '#':
                    printf("🥸");
                    break;
                case ' ':
                    printf("  ");
                    break;
                case '(':
                    printf("🛡");
                    break;
                case '@':
                    printf("🟦");
                    break;
                case '^':
                    printf("🍄");
                    break;
                case '>':
                    printf("❤️");
                    break;
                case '?':
                    printf("⭐");
                    break;
                case ':' :
                    printf(":");
                    break;
                case '*':
                    printf("%d" ,heart);
                    break;
                case '$':
                    printf("%d" , coins);
                case '=':
                    printf("%d" , score);
            }
        }
        printf("\n");
    }
}

void print_grid2()
{

    for (int i = 0; i < 48 ; i++)
    {
        for (int j = 0; j < 64 ; j++)
        {
            switch (mat_2[i][j])
            {
                case '1':
                    printf("🧱");
                    break;
                case '2':
                    printf("🟩");
                    break;
                case '3':
                    printf("🪙");
                    break;
                case '4':
                    printf("🟪");
                    break;
                case '5':
                    printf("🐙");
                    break;
                case '6':
                    printf("🦖");
                    break;
                case '7':
                    printf("🌱");
                    break;
                case '8':
                    printf("🟧");
                    break;
                case '9':
                    printf("🚩");
                    break;
                case '!':
                    printf("🟨");
                    break;
                case '&':
                    printf("🟨");
                    break;
                case '#':
                    printf("🥸");
                    break;
                case ' ':
                    printf("  ");
                    break;
                case '(':
                    printf("🛡");
                    break;
                case '@':
                    printf("🟪");
                    break;
                case '^':
                    printf("🍄");
                    break;
                case '>':
                    printf("❤️");
                    break;
                case '?':
                    printf("⭐");
                    break;
                case ':' :
                    printf(":");
                    break;
                case '*':
                    printf("%d" ,heart);
                    break;
                case '$':
                    printf("%d" , coins);
                case '=':
                    printf("%d" , score);
            }
        }
        printf("\n");
    }
}

void game_gravity(char mat[][128] ,int *i ,int *j , char ch){
    while(1)
    {
        if(mat[*i-1][*j] == ' '){
            mat[*i][*j] = ' ';
            mat[*i-1][*j] ='#';
            Sleep(1000);
        }
        if(ch == 'd'){
            mat[*i][*j] = ' ';
            mat[*i][*j +1] = '#';
        }
        else if(ch == 'a'){
            mat[*i][*j] = ' ';
            mat[*i][*j-1] = '#';
        }
        else if(ch == 's'){
            mat[*i][*j] = ' ';
            mat[*i+1][*j] = '#';
        }
    }

}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int char_i = 13, char_j = 2;  // موقعیت اولیه کاراکتر
    print_grid2();  // چاپ اولیه شبکه

    scanf("%d", char_i);
//    char input;
//    while (1) {
//
//        if (_kbhit()) { // بررسی آیا کلیدی فشار داده شده است یا خیر
//            input = _getch(); // گرفتن کاراکتر بدون نمایش آن در صفحه
//        if (dontlook) {
//            move_character(&char_i, &char_j, mat_2);  // حرکت کاراکتر
//            print_grid1(mat_2 , score , coins);  // چاپ شبکه پس از حرکت
//        }
//        else
//        {
//            move_character(&char_i, &char_j, mat_1);  // حرکت کاراکتر
//            print_grid1(mat_1, score , coins);  // چاپ شبکه پس از حرکت
//        }
//
//        Sleep(500);  // تاخیر برای مشاهده بهتر حرکت
//    }
//    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int is_double (char mat[][122] , int*i , int*j){
    if(mat[*i][*j] =='*'){
        return 1 ;
    }
}
void moving_double(char mat[][122] , int* i ,int*j , char ch){
    mat[*i][*j] = ' ';
    mat[*i-1][*j] = ' ';
    if (ch == 'd' && *j < 127 && (mat[*i][*j + 1] == ' ' || mat[*i][*j + 1] == 8 || mat[*i][*j + 1] == 9 || mat[*i][*j + 1] == 3 || mat[*i][*j + 1] == '#' || mat[*i][*j + 1] == '*'))
        (*j)++;
    else if(ch == 'a' && *j < 127 && (mat[*i][*j - 1] == ' ' || mat[*i][*j - 1] == 8 || mat[*i][*j - 1] == 9 || mat[*i][*j - 1] == 3 || mat[*i][*j - 1] == '#' || mat[*i][*j - 1] == '*'))
        (*j)--;
    else if(ch == 'w' && *j < 127 && (mat[*i-1][*j] == ' ' || mat[*i-1][*j] == 8 || mat[*i-1][*j] == 9 || mat[*i-1][*j] == 3 || mat[*i-1][*j] == '#' || mat[*i-1][*j] == '*'))
        (*i)--;
    else if(ch == 's' && *j < 127 && (mat[*i + 1][*j] == ' ' || mat[*i + 1][*j] == 8 || mat[*i + 1][*j] == 9 || mat[*i + 1][*j] == 3 || mat[*i + 1][*j] == '#' || mat[*i + 1][*j] == '*'))
        (*i)++;
    mat[*i][*j] ='#';
    mat[*i-1][*j] = '#';
}
void coin_block ( char mat[][128], int i , int j){
    int coin_block = 0 ;
    int jump = 0 ;
    if(mat[i-1][j] == 9){
        while(jump != 5){
            jump ++;
            for(int z = 0 ; z <= jump ; ++z){
                mat[i][j - z] = 3 ;
            }
            coins_score(mat_1, i, j, coins, score);
        }
    }
}


int score_of_heart (int *heart ,int *reminder_time){
    if(game_over() == 1){
        score += *heart *1000 ;
        score+= (*reminder_time%10) *100;
        return score;
    }
}
int hit_the_shield( char mat [][122] ,int *i , int *j){///////////////////////problem
    if(mat[*i][*j]= '$'){
        return hit_status = 1;
    }
    else{
        return hit_status = 0;
    }

}
void sitting_mario(int *i , int *j , char mat[][122]){/////////jlogiri az harkatesh
    char ch;
    if(ch =='s' && koofteh == 1){
        mat[*i-1][*j] = ' ';
    }
}
int heart_lose(char mat1 ,int *i , int*j)
{
    if(mat_1[*i][*j] == 6 || mat_1[*i][*j] == 7){
        heart--;
    }
}

//void shield_is_on(char mat[][122] , int*i , int*j)
//{
//    if(hit_the_sheild(mat , *i , *j) == 1)
//    {
//        if(mat[*i][*j] == 4 || mat[*i][*j] == 5 || mat[*i][*j] == 7){
//            *hit_status = 0;
//        }
//    }
//}

//void mashrom_block(char mat[][122] , int *i , int *j){
//    if(mat[*i-1][*j] == 9){
//        mat[*i-2][*j] = '*';
//        if(rand_num() % 2 == 0)
//        {//problem
//            move_enemy();
//            if(mat [*i][*j] == '*'){
//                is_double(mat ,i ,j);
//            }
//        }
//
//
//    }
//}


//void move_character(int *i, int *j, char ch, char mat[][128]) {
//    gotoxy(*j*2 , *i);
//    // پاک کردن موقعیت فعلی کاراکتر
//    mat[*i][*j] = ' ';
//
//    // حرکت کاراکتر بر اساس ورودی کاربر
//    if (ch == 'd' && *j < 127 && (mat[*i][*j + 1] == ' ' || mat[*i][*j + 1] == 8 || mat[*i][*j + 1] == 9 || mat[*i][*j + 1] == 3 || mat[*i][*j + 1] == '#' || mat[*i][*j + 1] == '*')) {
//        (*j)++;  // حرکت به راست
//    } else if (ch == 'a' && *j > 0 && (mat[*i][*j - 1] == ' ' || mat[*i][*j - 1] == 8 || mat[*i][*j - 1] == 9 || mat[*i][*j - 1] == 3 || mat[*i][*j - 1] == '#' || mat[*i][*j - 1] == '*')) {
//        (*j)--;  // حرکت به چپ
//    } else if (ch == 's' && *i < 13 && (mat[*i + 1][*j] == ' ' || mat[*i + 1][*j] == 8 || mat[*i + 1][*j] == 9 || mat[*i + 1][*j] == 3 || mat[*i + 1][*j] == '#' || mat[*i + 1][*j] == '*')) {
//        (*i)++;  // حرکت به پایین
//    } else if (ch == 'w' && *i > 0 && (mat[*i - 1][*j] == ' ' || mat[*i - 1][*j] == 8 || mat[*i - 1][*j] == 9 || mat[*i - 1][*j] == 3 || mat[*i - 1][*j] == '#' || mat[*i - 1][*j] == '*')) {
//        *i=(*i)-4;  // حرکت به بالا
//    } else if(mat[*i - 1][*j] == 8){
//        orange_cube(mat , *i , *j);
//    } else if(mat[*i][*j] == '*'){
//        double_mario(mat,*i , *j);
//    }
//
//
//    mat[*i][*j] = '#';
//}


//char map1(){
//
//    return mat[15][128];
//}


//char map2(){
//
//    return mat[28][122];
//}

//void print_grid2(char mat[][64])
//{
//    for (int i = 0; i < 28 ; i++)
//    {
//        for (int j = 0; j < 64 ; j++)
//        {
//            switch (mat_2[i][j])
//            {
//            case '1':
//                printf("🧱");
//                break;
//            case '2':
//                printf("🟩");
//                break;
//            case '3':
//                printf("🪙");
//                break;
//            case '4':
//                printf("🟪");
//                break;
//            case '5':
//                printf("🐙");
//                break;
//            case '6':
//                printf("🦖");
//                break;
//            case '7':
//                printf("🌱");
//                break;
//            case '8':
//                printf("🟧");
//                break;
//            case '9':
//                printf("🚩");
//                break;
//            case '!':
//                printf("🟨");
//                break;
//            case '&':
//                printf("🟨");
//                break;
//            case '$':
//                printf("🥸");
//                break;
//            case ' ':
//                printf("  ");
//                break;
//            case '(':
//                printf("🛡");
//                break;
//            case '@':
//                printf("🟦");
//                break;
//            case '^':
//                printf("🍄");
//                break;
//            case '>':
//                printf("❤️");
//                break;
//            case '?':
//                printf("⭐");
//                break;
//            case ':' ;
//                printf(":");
//                break;
//            }
//        }
//        printf("\n");
//    }
//
//}