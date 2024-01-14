#include <stdio.h>
#include <string.h>

int countVowels(char *str) {
    int count = 0;
    while (*str) {
        switch (*str) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                count++;
                break;
        }
        str++;
    }
    return count;
}

int countNonVowels(char *str) {
    int count = 0;
    while (*str) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
            switch (*str) {
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    break;
                default:
                    count++;
                    break;
            }
        }
        str++;
    }
    return count;
}

int main() {
    char input;
    char months[][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int index, vowelCount, nonVowelCount;
    int matchingMonths[12]; // Array untuk menyimpan indeks bulan yang cocok

    printf("Masukkan huruf (A-Z): ");
    scanf(" %c", &input);

    if ((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z')) {
        printf("Bulan-bulan dengan awalan '%c':\n", input);

        int matchCount = 0;
        for (int i = 0; i < 12; i++) {
            if (months[i][0] == input || months[i][0] == input + ('a' - 'A')) {
                printf("%d. %s\n", matchCount + 1, months[i]);
                matchingMonths[matchCount] = i;
                matchCount++;
            }
        }

        if (matchCount > 1) {
            printf("Pilih bulan (1-%d): ", matchCount);
            scanf("%d", &index);

            if (index >= 1 && index <= matchCount) {
                index = matchingMonths[index - 1]; // Ambil indeks yang sesuai
                vowelCount = countVowels(months[index]);
                nonVowelCount = countNonVowels(months[index]);

                printf("Jumlah karakter vokal: %d\n", vowelCount);
                printf("Jumlah karakter nonvokal: %d\n", nonVowelCount);
            } else {
                printf("Input bulan tidak valid.\n");
            }
        } else if (matchCount == 1) {
            // Jika hanya ada satu bulan yang cocok, lanjutkan dengan bulan tersebut
            index = matchingMonths[0];
            vowelCount = countVowels(months[index]);
            nonVowelCount = countNonVowels(months[index]);

            printf("Jumlah karakter vokal: %d\n", vowelCount);
            printf("Jumlah karakter nonvokal: %d\n", nonVowelCount);
        } else {
            printf("Tidak ada bulan dengan awalan tersebut.\n");
        }
    } else {
        printf("Input tidak valid. Masukkan huruf (A-Z).\n");
    }

    return 0;
}
