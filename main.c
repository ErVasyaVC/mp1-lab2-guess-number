#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int number = 1 + rand() % (1000), user_number = 1000000;
    int min = 1, max = 1000, attempts = 0;
    char mode, answer;
    printf("Выберите режим работы 1 или 2: ");
    scanf("%c", &mode);

    switch (mode) {
        case '1':
            printf("Программа загадала число от 1 до 1000. Попробуйте угадать его)) : ");
            do{
                scanf("%i", &user_number);
                if(user_number == number)
                    printf("Поздравляю, вы угадали число!");
                else if(user_number<number)
                    printf("Загаданное число больше. Повторите попытку: ");
                else
                    printf("Загаданное число меньше. Повторите попытку: ");
            } while (user_number != number);
            break;
        case '2':
            printf("Загадайте число от 1 до 1000 и введите его. Программа попробует его угадать: ");
            do{
                scanf("%i", &user_number);
                if(user_number > 1000 || user_number < 0){
                    printf("Введено не корректное число. Повторите попытку: ");
                }
            } while (user_number > 1000 || user_number < 0);
            while(user_number != number) {
                srand(time(NULL));
                number = min + rand() % (max-min+1);
                printf("Это число %i ? ", number);
                scanf("%c", &answer);
                if ( scanf("%c", &answer) != 1) {// != 1 means scanf failed
                    while ( ( answer = getchar()) != '\n' && answer != EOF) {
                        ;
                    }
                }
                attempts++;
                if(answer == '=')
                    printf("Программа отгадало число %i за %i попыток!", number, attempts);
                else if(answer == '>')
                    min = 1 + number;
                else if(answer == '<')
                    max = number - 1 ;
            }
            break;
    }

    return 0;
}