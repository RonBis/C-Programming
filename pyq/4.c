#include <stdio.h>

typedef struct DATE {
  int dd;
  int mm;
  int yy;
} date;

int main() {
  date curr = (date){.dd = 12, .mm = 3, .yy = 2023};
  date bday;

  int nd[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  printf("Birthday: (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &bday.dd, &bday.mm, &bday.yy);

  int days = 0, months = 0, years = 0;
  int dd = bday.dd, mm = bday.mm, yy = bday.yy;

  int no_of_leap = 0;
  while (1) {
    days++, dd++;

    if (dd > nd[mm]) {
      mm++, months++;
      if (mm == 13) {
        mm = 1;
        yy++, years++;

        if (yy % 100 != 0 && yy % 4 == 0 || yy % 400 == 0) {
          nd[2] = 29;
          no_of_leap++;
        } else {
          nd[2] = 28;
        }
      }
      dd = 1;
    }

    if (dd == curr.dd && mm == curr.mm && yy == curr.yy) {
      break;
    }
  }

  days = days - no_of_leap;

  years = days / 365;
  int rem_days = days % 365;
  months = rem_days / 30;
  days = rem_days % 30;

  printf("%d days %d months %d years\n", days, months, years);

  return 0;
}
