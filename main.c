#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
int char_i = 14, char_j = 1; //starting positions

char mat_1[16][64] = {
        "             > :*      3 :$     ? :=         t:                 ",
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
        "1#              33            44 6 446 446 446  1          22  1",
        "1111111111111111111111111111111111111111111111111111111111111111"
};

char mat_2[28][64] = {
        "             > :*      3 :$     ? :=         t:                 ",
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

int is_logged = 0;
int wins = 0 , lose = 0 ;
int hit_status = 0 ;
int score = 0;
int coins = 0 ;
int heart = 3;
int is_double;
int reminder_time;
int game_over = 0 ;
int time_left = 300;
int add_gamer(const char* name, const char* email, const char* password);
void sign_in(const char* name, const char* email, const char* password);
int delete_account(const char* name, const char* email, const char* password);
int get_password(char *password, int max_length);
void save_all_players();
void load_all_players();
void print_grid1();
int rand_num();
int timer();
void move_character(char mat[][64]);
void lets_start();
void coins_score (char mat[][64]);
void gamee_over();
int doublle (char mat[][64]);
void moving_double(char mat[][64]);
void coin_block ( char mat[][64]);
int score_of_heart ();
int hit_the_shield();
void sitting_mario(char mat[][64]);
int heart_lose(char mat[][64]);
void gotoxy(int x, int y);
void print_grid2();
void gravity (char mat[][64]);
void gravity_for_double_size(char mat[][64]);
void orange_cube(char mat[][64]);
void green_pipe1(char mat[][64]);
void green_pipe2 (char mat[][64]);
void move_enemy(char mat[][64]);
void double_mario(char mat[][64] );
void win_game1();
void all_function_for_map_1();
void end_game_for_time_or_heart();



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct gamer {
    char* name;
    char* email;
    char* password;
    int wins;
    int lose;
    int coins;
};

struct allgamer {
    struct gamer player;
    struct allgamer *pNext;
} *pHead = NULL;

int get_password(char *password, int max_length) {
    char password1[100], password2[100];
    int i;
    char ch;

    while (1) {
        // دریافت پسورد اول
        printf("Enter your password (minimum 8 characters): ");
        i = 0;
        while (1) {
            ch = getch();

            if (ch == '\r' || ch == '\n') {
                password1[i] = '\0';  // پایان رشته پسورد
                break;
            } else if (ch == '\b' && i > 0) {
                i--;
                printf("\b \b");  // کاراکتر قبلی را پاک کن
            } else if (i < max_length - 1) {  // اگر فضای کافی وجود دارد
                password1[i] = ch;
                i++;
                printf("*");  // نمایش '*' به جای کاراکتر واقعی
            }
        }

        // بررسی طول پسورد
        if (strlen(password1) < 8) {
            printf("\nPassword must be at least 8 characters long.\n");
            continue;
        }

        // دریافت پسورد دوم
        printf("\nConfirm your password: ");
        i = 0;
        while (1) {
            ch = getch();

            if (ch == '\r' || ch == '\n') {
                password2[i] = '\0';  // پایان رشته پسورد
                break;
            } else if (ch == '\b' && i > 0) {
                i--;
                printf("\b \b");  // کاراکتر قبلی را پاک کن
            } else if (i < max_length - 1) {  // اگر فضای کافی وجود دارد
                password2[i] = ch;
                i++;
                printf("*");  // نمایش '*' به جای کاراکتر واقعی
            }
        }

        // بررسی تطابق دو پسورد
        if (strcmp(password1, password2) == 0) {
            strcpy(password, password1); // پسورد معتبر را کپی کن
            printf("\nPassword is valid and confirmed.\n");
            return 0; // موفقیت
        } else {
            printf("\nPasswords do not match. Please try again.\n");
        }
    }
}

// تابع ثبت نام کاربر
/*int add_gamer(const char* name, const char* email, const char* password) {
    struct allgamer *pTmp, *pNew = (struct allgamer*)malloc(sizeof(struct allgamer));
    pNew->player.name = strdup(name);
    pNew->player.email = strdup(email);
    pNew->player.password = strdup(password);
    pNew->player.wins = 0;
    pNew->player.lose = 0;
    pNew->player.coins = 0;
    pNew->pNext = NULL;
    while (pTmp != NULL) {
        if (strcmp(pTmp->player.name, name) == 0) {
            printf("Error: Name '%s' is already taken. please try again\n", name);
            return -1;
        }
        pTmp = pTmp->pNext;

        if (pHead) { // اگر لیست خالی نباشد
            pTmp = pHead;
            while (pTmp->pNext) {
                pTmp = pTmp->pNext;
            }
            pTmp->pNext = pNew;
        } else {
            pHead = pNew;
        }
    }
    // ذخیره اطلاعات کاربر در فایل جداگانه
    FILE *file;
    char filename[100];
    sprintf(filename, "%s.txt", name);
    file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "Name: %s\nEmail: %s\nPassword: %s\nWins: %d\nLose: %d\nCoins: %d\n",
                name, email, password, pNew->player.wins, pNew->player.lose, pNew->player.coins);
        fclose(file);
    } else {
        perror("Error opening file");
        return -1;
    }

    // ذخیره اطلاعات تمام بازیکنان در فایل کلی
    save_all_players();

    printf("Registration successful!\n");
    return 0;
}*/
int add_gamer(const char* name, const char* email, const char* password) {
    struct allgamer *pTmp = pHead; // Initialize pTmp to pHead
    struct allgamer *pNew = (struct allgamer*)malloc(sizeof(struct allgamer));

    // Check if memory allocation failed
    if (pNew == NULL) {
        printf("Error: Memory allocation failed.\n");
        return -1;
    }

    // Initialize the new player
    pNew->player.name = strdup(name);
    pNew->player.email = strdup(email);
    pNew->player.password = strdup(password);
    pNew->player.wins = 0;
    pNew->player.lose = 0;
    pNew->player.coins = 0;
    pNew->pNext = NULL;

    // Check if the name is already taken
    while (pTmp != NULL) {
        if (strcmp(pTmp->player.name, name) == 0) {
            printf("Error: Name '%s' is already taken. Please try again.\n", name);
            // Free allocated memory to avoid memory leak
            free(pNew->player.name);
            free(pNew->player.email);
            free(pNew->player.password);
            free(pNew);
            return -1;
        }
        pTmp = pTmp->pNext;
    }

    // Insert the new player into the linked list
    if (pHead == NULL) {
        // If the list is empty, make pNew the head
        pHead = pNew;
    } else {
        // Traverse to the end of the list and add pNew
        pTmp = pHead;
        while (pTmp->pNext != NULL) {
            pTmp = pTmp->pNext;
        }
        pTmp->pNext = pNew;
    }

    // Save the player's data to a file
    FILE *file;
    char filename[100];
    sprintf(filename, "%s.txt", name);
    file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "Name: %s\nEmail: %s\nPassword: %s\nWins: %d\nLose: %d\nCoins: %d\n",
                name, email, password, pNew->player.wins, pNew->player.lose, pNew->player.coins);
        fclose(file);
    } else {
        perror("Error opening file");
        return -1;
    }

    // Save all players to the main file
    save_all_players();

    printf("Registration successful!\n");
    return 0;
}
// تابع ورود به سیستم
void sign_in(const char* name, const char* email, const char* password) {
    struct allgamer *pTmp = pHead;
    while (pTmp) {
        if (strcmp(pTmp->player.name, name) == 0) {
            if (strcmp(pTmp->player.password, password) == 0) {
                printf("Login successful!\n");
                is_logged = 1 ;
                return;
            } else {
                printf("Wrong password.\n");
                return;
            }
        }
        pTmp = pTmp->pNext;
    }
    printf("Username not found.\n");
}

// تابع حذف حساب کاربری
int delete_account(const char* name, const char* email, const char* password) {
    struct allgamer *pPrev = NULL, *pCur = pHead;

    while (pCur) {
        if (strcmp(pCur->player.name, name) == 0 && strcmp(pCur->player.email, email) == 0) {
            if (strcmp(pCur->player.password, password) == 0) {
                if (pPrev) {
                    pPrev->pNext = pCur->pNext;
                } else {
                    pHead = pCur->pNext;
                }

                // حذف فایل کاربر
                char filename[100];
                sprintf(filename, "%s.txt", name);
                if (remove(filename) == 0) {
                    printf("User file deleted successfully.\n");
                } else {
                    perror("Error deleting user file");
                }

                // آزاد کردن حافظه
                free(pCur->player.name);
                free(pCur->player.email);
                free(pCur->player.password);
                free(pCur);

                // ذخیره اطلاعات تمام بازیکنان در فایل کلی
                save_all_players();

                printf("Account deleted successfully.\n");
                return 0;
            } else {
                printf("Wrong password. Deletion failed.\n");
                return -1;
            }
        }
        pPrev = pCur;
        pCur = pCur->pNext;
    }

    printf("Account not found.\n");
    return -1;
}

// تابع ذخیره اطلاعات تمام بازیکنان در فایل کلی
void save_all_players() {
    FILE *file = fopen("all_players.txt", "w");
    if (file == NULL) {
        perror("Error opening all_players.txt");
        return;
    }

    struct allgamer *pTmp = pHead;
    while (pTmp) {
        fprintf(file, "Name: %s\nEmail: %s\nPassword: %s\nWins: %d\nLose: %d\nCoins: %d\n\n",
                pTmp->player.name, pTmp->player.email, pTmp->player.password,
                pTmp->player.wins, pTmp->player.lose, pTmp->player.coins);
        pTmp = pTmp->pNext;
    }

    fclose(file);
}

// تابع بارگذاری اطلاعات تمام بازیکنان از فایل کلی
void load_all_players() {
    FILE *file = fopen("all_players.txt", "r");
    if (file == NULL) {
        perror("Error opening all_players.txt");
        return;
    }

    char line[256];
    struct gamer player;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "Name: %s", player.name) == 1) {
            fgets(line, sizeof(line), file);
            sscanf(line, "Email: %s", player.email);
            fgets(line, sizeof(line), file);
            sscanf(line, "Password: %s", player.password);
            fgets(line, sizeof(line), file);
            sscanf(line, "Wins: %d", &player.wins);
            fgets(line, sizeof(line), file);
            sscanf(line, "Lose: %d", &player.lose);
            fgets(line, sizeof(line), file);
            sscanf(line, "Coins: %d", &player.coins);

            // افزودن بازیکن به لیست
            add_gamer(player.name, player.email, player.password);
        }
    }

    fclose(file);
}


/////////////////////////////////////////////////GAME FUNCTION//////////////////////////////////////////////////
int rand_num(){
    srand(time(NULL));
    int random_num = rand();
    random_num = random_num % 5 + 1 ;
    return random_num;
}
void all_function_for_map_1(){
    print_grid1();
    rand_num();
    timer();
    move_character(mat_1);
    lets_start();
    coins_score(mat_1);
    gamee_over();
    coin_block(mat_1);
    score_of_heart();
    heart_lose(mat_1);
    gotoxy(char_i , char_j);
    gravity(mat_1);
    orange_cube(mat_1);
    green_pipe1(mat_1);
    move_enemy(mat_1);
    win_game1();

}
void all_function_for_map_2(){
    print_grid2();
    doublle(mat_2);
    moving_double(mat_2);
    hit_the_shield();
    sitting_mario(mat_2);
    gravity_for_double_size(mat_2);
    rand_num();
    timer();
    move_character(mat_2);
    lets_start();
    coins_score(mat_2);
    gamee_over();
    coin_block(mat_2);
    score_of_heart();
    heart_lose(mat_2);
    gotoxy(char_i , char_j);
    gravity(mat_2);
    orange_cube(mat_2);
    green_pipe2(mat_2);
    move_enemy(mat_2);


}
int timer(){
    while(time_left> 0){
        printf("%d" , time_left);
        Sleep(1);
        time_left -- ;
        if(time_left == 0){
            //  game_over();
        }
    }
}
void move_character(char mat[][64]) {
    while (1) {
        char ch;
        ch = _getch();
        if(mat_1[char_i][char_j] == '9'){
            win_game1();
        }
        if (ch == 'd' && char_j < 64 &&
            (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' || mat[char_i][char_j + 1] == '9' ||
             mat[char_i][char_j + 1] == '3' ||
             mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^'))
        {
            if ( mat_1[char_i][char_j + 1] == '3')
            {
                coins += 1;
            }
            if (mat_1[char_i][char_j + 1] != '1')
            {
                mat_1[char_i][char_j] = ' ';
                char_j ++;
                mat_1[char_i][char_j] = '#';
            }

        }
        else if (ch == 'a' && char_j > 0 &&
                 (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' || mat[char_i][char_j + 1] == '9' ||
                  mat[char_i][char_j + 1] == '3' ||
                  mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^'))
        {
            if ( mat_1[char_i][char_j - 1] == '3')
            {
                coins += 1;
            }
            if (mat_1[char_i][char_j - 1] != '1')
            {
                mat_1[char_i][char_j] = ' ';
                char_j--;
                mat_1[char_i][char_j] = '#';
            }
        }
        else if (ch == 's' && char_i < 15 &&
                 (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' || mat[char_i][char_j + 1] == '9' ||
                  mat[char_i][char_j + 1] == '3' ||
                  mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^')) {
            mat_1[char_i][char_j] = ' ';
            char_i++;
            mat_1[char_i][char_j] = '#';
        }

        if (ch == 'w' && char_i > 0 &&
            (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' || mat[char_i][char_j + 1] == '9' ||
             mat[char_i][char_j + 1] == '3' || mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^' ||
             mat[char_i][char_j] == 5)) {
            mat_1[char_i][char_j] = ' ';
            char_i -= 4;
            mat_1[char_i - 4][char_j] = '#';
            char ch;
            ch = _getch();


            if (ch == 'd' && char_j < 64 &&
                (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' || mat[char_i][char_j + 1] == '9' ||
                 mat[char_i][char_j + 1] == '3' ||
                 mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^' || mat[char_i][char_j] == 5)) {
                mat[char_i][char_j] = ' ';
                (char_j)++;
            } else if (ch == 'a' && char_j > 0 &&
                       (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' ||
                        mat[char_i][char_j + 1] == '9' ||
                        mat[char_i][char_j + 1] == '3' ||
                        mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^' || mat[char_i][char_j] == 5)) {
                mat[char_i][char_j] = ' ';
                (char_j)--;
            } else if (ch == 's' && char_i < 13 &&
                       (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' ||
                        mat[char_i][char_j + 1] == '9' ||
                        mat[char_i][char_j + 1] == '3' ||
                        mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^' || mat[char_i][char_j] == 5)) {
                mat[char_i][char_j] = ' ';
                char_i++;

            }
        }
        mat[char_i][char_j] = '#';
        print_grid1();
    }
}


void lets_start(){

    PlaySound(TEXT("C:\\Users\\JahanBakhsh\\Downloads\\smb_stage_clear.wav"), NULL, SND_FILENAME | SND_ASYNC);

    printf("%*s    ____  _________    ______  __   ___ \n", 20, "");
    printf("%*s   / __ \\/ ____/   |  / __ \\ \\/ /  /__ \\\n", 20, "");
    printf("%*s  / /_/ / __/ / /| | / / / /\\  /    / _/\n", 20, "");
    printf("%*s / _, _/ /___/ ___ |/ /_/ / / /    /_/  \n", 20, "");
    printf("%*s/_/ |_/_____/_/  |_/_____/ /_/    (_)   \n", 20, "");

    Sleep(3000);
    system("cls");

    printf("%*s 333333333333333   \n", 20, "");
    printf("%*s3:::::::::::::::33 \n", 20, "");
    printf("%*s3::::::33333::::::3\n", 20, "");
    printf("%*s3333333     3:::::3\n", 20, "");
    printf("%*s            3:::::3\n", 20, "");
    printf("%*s            3:::::3\n", 20, "");
    printf("%*s    33333333:::::3 \n", 20, "");
    printf("%*s    3:::::::::::3  \n", 20, "");
    printf("%*s    33333333:::::3 \n", 20, "");
    printf("%*s            3:::::3\n", 20, "");
    printf("%*s            3:::::3\n", 20, "");
    printf("%*s3333333     3:::::3\n", 20, "");
    printf("%*s3::::::33333::::::3\n", 20, "");
    printf("%*s3:::::::::::::::33 \n", 20, "");
    printf("%*s 333333333333333   \n", 20, "");

    Sleep(1000);
    system("cls");

    printf("%*s 222222222222222    \n", 20, "");
    printf("%*s2:::::::::::::::22  \n", 20, "");
    printf("%*s2::::::222222:::::2 \n", 20, "");
    printf("%*s2222222     2:::::2 \n", 20, "");
    printf("%*s            2:::::2 \n", 20, "");
    printf("%*s            2:::::2 \n", 20, "");
    printf("%*s         2222::::2  \n", 20, "");
    printf("%*s    22222::::::22   \n", 20, "");
    printf("%*s  22::::::::222     \n", 20, "");
    printf("%*s 2:::::22222        \n", 20, "");
    printf("%*s2:::::2             \n", 20, "");
    printf("%*s2:::::2       222222\n", 20, "");
    printf("%*s2::::::2222222:::::2\n", 20, "");
    printf("%*s2::::::::::::::::::2\n", 20, "");
    printf("%*s22222222222222222222\n", 20, "");

    Sleep(1000);
    system("cls");

    printf("%*s  1111111   \n", 20, "");
    printf("%*s 1::::::1   \n", 20, "");
    printf("%*s1:::::::1   \n", 20, "");
    printf("%*s111:::::1   \n", 20, "");
    printf("%*s   1::::1   \n", 20, "");
    printf("%*s   1::::1   \n", 20, "");
    printf("%*s   1::::1   \n", 20, "");
    printf("%*s   1::::1   \n", 20, "");
    printf("%*s   1::::1   \n", 20, "");
    printf("%*s   1::::1   \n", 20, "");
    printf("%*s   1::::1   \n", 20, "");
    printf("%*s   1::::1   \n", 20, "");
    printf("%*s111::::::111\n", 20, "");
    printf("%*s1::::::::::1\n", 20, "");
    printf("%*s1::::::::::1\n", 20, "");
    printf("%*s111111111111\n", 20, "");

    Sleep(1000);
    system("cls");

}

void coins_score (char mat[][64]){
    int time1;
    int *last_destroy_time = 0 ;
    if(mat_1[char_i][char_j] == 3){
        coins ++;
    }
    if (mat_1[char_i- 1][char_j] == 5) {
        time1 = time(NULL);
        int time_diff = time1 - *last_destroy_time;

        if (time_diff < 5) {

            score *= 2;
        } else {

            score += 100;
        }

        *last_destroy_time = time1;
        mat_1[char_i - 1][char_j] = ' ';
        print_grid1();
    }
}
void gamee_over(){
    lose ++ ;

    printf("\033[1;31mGAME OVER !\033[0m\n");
    printf("\033[1;31mYOU LOSE \033[0m\n");
    printf("YOUR SCORE : %d \n YOUR COINS : %d" , score , coins);
    printf("\033[1;34mSTART AGAIN?\033[0m\n");
    printf("1.YES \n2.NO\n");

}
void end_game_for_time_or_heart(){
    if(heart == 0 || time_left == 0){
        gamee_over();
    }
}
void win (){
    if(mat_1[char_i][char_j] == '9'){
        win_game1();
    }
}
void print_grid1()
{


    DWORD bytes_written;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD origin = {0, 0};
    SetConsoleCursorPosition(hStdout, origin);
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
                    printf("🛡️");
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
                    break;
                case '=':
                    printf("%d" , score);
                    break;
                case 't':
                    printf("%d" , time_left);
                    break;
            }
        }
        printf("\n");
    }
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    char name[100], email[100], password[100];
    char cmd;

    // بارگذاری اطلاعات تمام بازیکنان از فایل
    load_all_players();

    while (1) {
        system("cls");
        printf("\nENTER A NUMBER:\n");
        printf("1. Sign up\n");
        printf("2. Log in\n");
        printf("3. Delete account \n");
        printf("4. Score\n");
        printf("5. Start game\n");
        printf("6. Exit\n");
        cmd = getchar();
        getchar();

        switch (cmd) {
            case '1':
                printf("Please enter your username: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Please enter your email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';

                if (get_password(password, sizeof(password)) == 0) {
                    add_gamer(name, email, password);
                }
                break;

            case '2':
                printf("Please enter your username: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Please enter your email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';

                if (get_password(password, sizeof(password)) == 0) {
                    sign_in(name, email, password);
                    lets_start();
                    print_grid1();
                    move_character(mat_1);


                }
                break;

            case '3':
                printf("Please enter your username: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Please enter your email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';

                if (get_password(password, sizeof(password)) == 0) {
                    delete_account(name, email, password);
                }
                return 0;

            case '4':

                break;

            case '5':
                if (is_logged == 1){
                    lets_start();
                    print_grid1();
                    move_character(mat_1);

                }
                else{
                    printf("PLEASE LOG IN FIRST");
                    Sleep(2000);
                }


                break;

            case '6':

                save_all_players();
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }



    // موقعیت اولیه کاراکتر
    print_grid1();  // چاپ اولیه شبکه

    move_character(mat_1);  // حرکت کاراکتر


    Sleep(5000);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int doublle (char mat[][64]){
    if(mat[char_i][char_j] =='^'){
        return is_double = 1 ;
    }
    else{
        return is_double = 0 ;
    }
}
void moving_double(char mat[][64]){
    char ch ;
    ch = _getch();
    mat[char_i][char_j] = ' ';
    mat[char_i-1][char_j] = ' ';
    if (ch == 'd' && char_j < 64 && (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' || mat[char_i][char_j + 1] == 9 || mat[char_i][char_j + 1] == 3 ||
                                     mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^' || mat[char_i][char_j] == 5))
        char_j++;
    else if(ch == 'a' && char_j < 64 && (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' || mat[char_i][char_j + 1] == 9 || mat[char_i][char_j + 1] == 3 ||
                                         mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^'))
        char_j--;
    else if(ch == 'w' && char_j < 64 && (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' || mat[char_i][char_j + 1] == 9 || mat[char_i][char_j + 1] == 3 ||
                                         mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^' || mat[char_i][char_j] == 5))
        char_i--;
    else if(ch == 's' && char_j < 64 && (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == '(' || mat[char_i][char_j + 1] == 9 || mat[char_i][char_j + 1] == 3 ||
                                         mat[char_i][char_j + 1] == '#' || mat[char_i][char_j + 1] == '^' || mat[char_i][char_j] == 5))
        char_i++;
    mat[char_i][char_j] ='#';
    mat[char_i-1][char_j] = '#';
}
void coin_block ( char mat[][64]){
    int coin_block = 0 ;
    int jump = 0 ;
    if(mat[char_i-1][char_j] == '&'){
        while(jump != 5){
            jump ++;
            for(int z = 0 ; z <= jump ; ++z){
                mat[char_i][char_j - z] = 3 ;
            }
            coins_score(mat_1);
        }
    }
}
int score_of_heart (){
    if(game_over == 1){
        score += heart *1000 ;
        score+= (reminder_time%10) *100;
        return score;
    }
}
int hit_the_shield(){///////////////////////problem
    if(mat_2[char_i][char_j]= '('){
        return hit_status = 1;
    }
    else{
        return hit_status = 0;
    }

}
void sitting_mario(char mat[][64]){/////////jlogiri az harkatesh
    char ch;
    if(ch =='s'){
        mat[char_i-1][char_j] = ' ';
    }
}
int heart_lose(char mat[][64])
{
    if(mat_1[char_i][char_j] == 6 || mat_1[char_i][char_j] == 5){
        heart--;
    }
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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
                    printf("🛡️");
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
                case 't':
                    printf("%d" , time_left);
            }
        }
        printf("\n");
    }
}
void gravity (char mat[][64]) {
    while(1){
        if(mat[char_i+1][char_j] == ' '){
            mat[char_i][char_j] = ' ';
            mat[char_i+1][char_j] = '#';
            Sleep(10);
        }
    }
}
void gravity_for_double_size(char mat[][64]){
    if(is_double == 1){
        if(mat[char_i+1][char_j] == ' '){
            mat[char_i -2][char_j] = ' ';
            mat[char_i+1][char_j] = '#';
            mat[char_i][char_j] = '#';
            print_grid2();
        }
    }

}
void orange_cube(char mat[][64]){
    if (mat_1[char_i][char_j] == 8){
        mat[char_i-1][char_j] = ' ';
        if(rand_num() == 3){
            mat[char_i-1][char_j] = 3;
        }

    }

}
void green_pipe1(char mat[][64]){
    if(mat[12][60] == '#'){
        mat[12][60] = ' ';
        mat[4][24] = '#';
        char_i = 4;
        char_j = 24;
    }
}
void green_pipe2 (char mat[][64]) {
    if(mat[4][24] == '#'){
        mat[4][24] = ' ';
        mat[4][60] ='#';
        char_i = 4 ;
        char_j = 60 ;
    }
    else if (mat[10][28] == '#'){
        mat[10][28] = ' ';
        mat[16][28] = '#';
        char_i = 16;
        char_j = 28;
    }
    else if(mat[26][16] == '#'){
        mat[26][16] = ' ';
        mat[13][15] = '#';
        char_i = 13 ;
        char_j = 15 ;
    }
}
void move_enemy(char mat[][64]) {
    int direction = 1;
    // پاک کردن موقعیت فعلی اختاپوس
    mat[char_i][char_j] = ' ';

    // حرکت اختاپوس بر اساس جهت
    if (direction == 1 && char_j < 64 && (mat[char_i][char_j + 1] == ' ' || mat[char_i][char_j + 1] == 3)) {
        char_j++;  // حرکت به راست
    } else if (direction == -1 && char_j > 0 && (mat[char_i][char_j - 1] == ' ' || mat[char_i][char_j - 1] == 3)) {
        char_j--;  // حرکت به چپ
    } else {
        direction *= -1;  // تغییر جهت در صورت برخورد با مانع
    }


    mat[char_i][char_j] = '5';
}
void double_mario(char mat[][64] ){
    if(mat[char_i][char_j]  == '^'){
        mat[char_i-1][char_j] = '#';
    }

}
void win_game1(){////////////////////
    lets_start();
    print_grid1();
    move_character(mat_1);
    wins++;

    int num;

    printf("\033[1;32mYOU HAVE SUCCESSFULLY COMPLETED THIS LEVEL!\033[0m\n");
    printf("YOUR COINS : %d \n YOUR SCORE : %d" , coins , score);
    printf("\033[1;32m1.GOING TO NEXT LEVEL\033[0m\n");
    printf("\033[1;31m2.EXIT\033[0m\n");
    printf("\033[1;32m13.REPEAT THIS LEVEL\033[0m\n");

    num = _getch();
    switch(num){
        case 1:
            lets_start();
            print_grid2();
        case 2 :
            return;
        case 3 :
            lets_start();
            print_grid1();
    }
}
//void game_gravity(char mat[][64]){
//   char ch ;
//  ch = _getch();
//  while(1)
//   {
//        if(mat[char_i+1][char_j] == ' '){
//          mat[char_i][char_j] = ' ';
//          mat[char_i-1][char_j] ='#';
//          Sleep(1000);
/*}
        if(ch == 'd'){
            mat[char_i][char_j] = ' ';
            mat[char_i][char_j +1] = '#';
        }
        else if(ch == 'a'){
            mat[char_i][char_j] = ' ';
            mat[char_i][char_j-1] = '#';
        }
        else if(ch == 's'){
            mat[char_i][char_j] = ' ';
            mat[char_i+1][char_j] = '#';
        }
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

//void mashrom_block(char mat[][64]){
//    if(mat-2[char_i-1][char_j] == '!'){
//        mat[char_i-2][char_j] = '^';
//        if(rand_num() % 2 == 0)
//        {//problem
//            move_enemy();
//                while(1){
//                 if(mat-2[char_i +1][char_j] =' ')
//              { mat_2[char_i][char_j] = ' ' ;
//                 mat_2[char_i+1][char_j] = '^' ;
//            if(mat [char_i][char_j] == '^'){
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


*/