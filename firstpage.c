#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// پروتوتایپ توابع
int add_gamer(const char* name, const char* email, const char* password);
void sign_in(const char* name, const char* email, const char* password);
int delete_account(const char* name, const char* email, const char* password);
int get_password(char *password, int max_length);
void save_all_players();
void load_all_players();

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

int main() {
    char name[100], email[100], password[100];
    char cmd;

    // بارگذاری اطلاعات تمام بازیکنان از فایل
    load_all_players();

    while (1) {
        printf("\nENTER A NUMBER:\n");
        printf("1. Sign up\n");
        printf("2. Log in\n");
        printf("3. Exit\n");
        printf("4. Score\n");
        printf("5. Start game\n");
        printf("6. Delete account\n");
        cmd = getchar();
        getchar(); // حذف newline از بافر ورودی

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
                }
                break;

            case '3':
                // ذخیره اطلاعات تمام بازیکنان در فایل قبل از خروج
                save_all_players();
                return 0;

            case '6':
                printf("Please enter your username: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Please enter your email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';

                if (get_password(password, sizeof(password)) == 0) {
                    delete_account(name, email, password);
                }
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

// تابع دریافت پسورد و بررسی تطابق
int get_password(char *password, int max_length) {
    char password1[100], password2[100];
    int i;
    char ch;

    while (1) {
        // دریافت پسورد اول
        printf("Enter your password (minimum 8 characters): ");
        i = 0;
        while (1) {
            ch = getch();  // دریافت کاراکتر بدون نمایش روی صفحه

            if (ch == '\r' || ch == '\n') {  // اگر Enter زده شد
                password1[i] = '\0';  // پایان رشته پسورد
                break;
            } else if (ch == '\b' && i > 0) {  // اگر Backspace زده شد
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
            continue; // دوباره پسورد دریافت کن
        }

        // دریافت پسورد دوم
        printf("\nConfirm your password: ");
        i = 0;
        while (1) {
            ch = getch();  // دریافت کاراکتر بدون نمایش روی صفحه

            if (ch == '\r' || ch == '\n') {  // اگر Enter زده شد
                password2[i] = '\0';  // پایان رشته پسورد
                break;
            } else if (ch == '\b' && i > 0) {  // اگر Backspace زده شد
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
int add_gamer(const char* name, const char* email, const char* password) {
    struct allgamer *pTmp, *pNew = (struct allgamer*)malloc(sizeof(struct allgamer));
    pNew->player.name = strdup(name);
    pNew->player.email = strdup(email);
    pNew->player.password = strdup(password);
    pNew->player.wins = 0;
    pNew->player.lose = 0;
    pNew->player.coins = 0;
    pNew->pNext = NULL;

    if (pHead) { // اگر لیست خالی نباشد
        pTmp = pHead;
        while (pTmp->pNext) {
            pTmp = pTmp->pNext;
        }
        pTmp->pNext = pNew;
    } else {
        pHead = pNew;
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
}

// تابع ورود به سیستم
void sign_in(const char* name, const char* email, const char* password) {
    struct allgamer *pTmp = pHead;
    while (pTmp) {
        if (strcmp(pTmp->player.name, name) == 0 && strcmp(pTmp->player.email, email) == 0) {
            if (strcmp(pTmp->player.password, password) == 0) {
                printf("Login successful!\n");
                return;
            } else {
                printf("Wrong password.\n");
                return;
            }
        }
        pTmp = pTmp->pNext;
    }
    printf("Username or email not found.\n");
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