#include <stdio.h>
#include <string.h>

#define MAX_CHARACTERS 10

typedef struct {
    char name[20];
    int energy;
    int loves;
    char type[20]; // Menambahkan tipe untuk Pet
} Human;

typedef struct {
    char name[20];
    int energy;
    int loves;
    char type[20]; // Menambahkan tipe untuk Pet
} Pet;

Human humans[MAX_CHARACTERS];
Pet pets[MAX_CHARACTERS];
int humanCount = 0;
int petCount = 0;

// Fungsi untuk mencari karakter berdasarkan nama
void* searchCharacter(char *characterName) {
    for (int i = 0; i < humanCount; i++) {
        if (strcmp(humans[i].name, characterName) == 0) {
            return &humans[i]; // Mengembalikan pointer ke Human
        }
    }
    for (int i = 0; i < petCount; i++) {
        if (strcmp(pets[i].name, characterName) == 0) {
            return &pets[i]; // Mengembalikan pointer ke Pet
        }
    }
    return NULL; // Karakter tidak ditemukan
}

void petting(char *petName) {
    Pet *pet = (Pet *)searchCharacter(petName);
    if (pet != NULL) {
        pet->loves += 10; // Meningkatkan loves
        printf("You are gaining the pet's loves!\n");
    } else {
        printf("Pet not found!\n");
    }
}

void help(char *humanName) {
    Human *human = (Human *)searchCharacter(humanName);
    if (human != NULL) {
        human->loves += 5; // Meningkatkan loves
        printf("%s received help! Loves is now: %d\n", human->name, human->loves);
    } else {
        printf("Human not found!\n");
    }
}

void showAttributes(char *characterName) {
    void *character = searchCharacter(characterName);
    if (character != NULL) {
        if (((Human *)character)->energy > 0 || ((Pet *)character)->energy > 0) { // Memeriksa apakah itu Human atau Pet
            printf("%s's Energy is %d\n", ((Human *)character)->energy > 0 ? ((Human *)character)->name : ((Pet *)character)->name, 
                   ((Human *)character)->energy > 0 ? ((Human *)character)->energy : ((Pet *)character)->energy);
            printf("%s's Loves is %d\n", ((Human *)character)->energy > 0 ? ((Human *)character)->name : ((Pet *)character)->name, 
                   ((Human *)character)->energy > 0 ? ((Human *)character)->loves : ((Pet *)character)->loves);
        }
    } else {
        printf("Character not found!\n");
    }
}

// Fungsi untuk menampilkan dan mengurutkan hewan peliharaan berdasarkan loves
void showSortedPetsByLoves(char *petType) {
    Pet sortedPets[MAX_CHARACTERS];
    int count = 0;

    // Mengumpulkan semua pets dengan tipe yang sesuai
    for (int i = 0; i < petCount; i++) {
        if (strcmp(pets[i].type, petType) == 0) {
            sortedPets[count++] = pets[i]; // Menyalin ke array sementara
        }
    }

    // Mengurutkan pets berdasarkan loves menggunakan bubble sort
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (sortedPets[j].loves < sortedPets[j + 1].loves) { // Urut dari yang tertinggi
                Pet temp = sortedPets[j];
                sortedPets[j] = sortedPets[j + 1];
                sortedPets[j + 1] = temp;
            }
        }
    }

    // Menampilkan hasil urutan
    printf("Sorted %s by loves:\n", petType);
    for (int i = 0; i < count; i++) {
        printf("%s: Loves = %d\n", sortedPets[i].name, sortedPets[i].loves);
    }
}

void addHuman(char *name, int energy, int loves) {
    strcpy(humans[humanCount].name, name);
    humans[humanCount].energy = energy;
    humans[humanCount].loves = loves;
    humanCount++;
}

void addPet(char *name, int energy, int loves, char *type) {
    strcpy(pets[petCount].name, name);
    pets[petCount].energy = energy;
    pets[petCount].loves = loves;
    strcpy(pets[petCount].type, type); // Menyimpan tipe hewan peliharaan
    petCount++;
}

int main() {
    // Menambahkan karakter
    addHuman("aisyah", 60, 80);
    addHuman("selma", 50, 70);
    addHuman("rohma", 40, 90);
    addHuman("absan", 90, 40);
    
    addPet("pou", 30, 50, "Cat");
    addPet("nou", 25, 60, "Cat");
    addPet("mou", 20, 55, "Cat");
    addPet("sou", 50, 25, "Cat");

    char command[50];
    
    printf("Welcome to our Pet Cafe!\n");
    printf("Enter commands (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Menghapus newline

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strncmp(command, "petting ", 8) == 0) {
            petting(command + 8);
        } else if (strncmp(command, "attr ", 5) == 0) {
            showAttributes(command + 5);
        } else if (strncmp(command, "help ", 5) == 0) {
            help(command + 5); // Memanggil fungsi help
        } else if (strncmp(command, "show ", 5) == 0 
        && strncmp(command + 5, "cat ", 4) == 0 && strcmp(command + 9, "loves") == 0) {
            showSortedPetsByLoves("Cat"); // Menampilkan hewan peliharaan Cat berdasarkan loves
        } else {
            printf("Unknown command!\n");
        }
    }

    printf("Thank you for your visit!\n");
    return 0;
}