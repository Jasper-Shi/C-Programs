#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[],
                                                     const char co[], const char number[]);

int main(void) {
  FILE* fptr = fopen("starwars_directory.csv", "r");
  char name[31];
  char npa[4];
  char co[4];
  char number[5];
  char formatted[45];
  if (fptr) {
    while (fscanf(fptr, "%[^,],%s%s%s\n", name, npa, co, number) == 4) {
      formatJediPhoneRecord(formatted, name, npa, co, number);
      printf("%s\n", formatted);
    }
    fclose(fptr);
  }
  else {
    printf("File not found!\n");
  }
  return 0;
}

/*
output:

Nien Nunb        (403) 555-0163
Baron Notluwis.. (587) 555-0155
Bib Fortuna      (780) 555-0179
Salacious B Cr.. (902) 555-0167
Jar Jar Binks    (867) 555-0149
Biggs Darkligh.. (226) 555-0119
Wilhelm Scream.. (249) 555-0122
Maximilian Veers (289) 555-0128
Cornelius Evazan (343) 555-0180
Anakin Skywalker (365) 555-0110 Jedi Master
General Grievous (416) 555-0147
Darth Maul       (437) 555-0160
Grand Moff Tar.. (519) 555-0131
Mon Mothma       (613) 555-0196
Count Dooku      (647) 555-0140
Lando Calrissian (705) 555-0132
Admiral Motti    (807) 555-0102
Wedge Antilles   (905) 555-0100
Padme Amidala    (418) 555-0105
Mace Windu       (438) 555-0155 Jedi Master
Emperor Palpat.. (450) 555-0143
Qui-Gon Jinn     (514) 555-0138 Jedi Master
Jabba the Hutt   (579) 555-0178
Admiral Ackbar   (581) 555-0120
Chewbacca        (819) 555-0168
Yoda             (873) 555-0153 Jedi Master
Boba Fett        (306) 555-0131
Luke Skywalker   (639) 555-0176
R2-D2            (867) 555-0121
C-3PO            (403) 555-0113
Han Solo         (250) 555-0161
Princess Leia    (604) 555-2121
Obi-Wan Kenobi   (365) 555-3113 Jedi Master
Darth Vader      (416) 555-4161

*/