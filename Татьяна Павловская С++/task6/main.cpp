#include <fstream>
#include <iostream>
#include <cstring>

struct NOTEBOOK {
    char model[21];     // наименование
    int memory;         // память
    float w;            // вес
    int price;          // цена
};

void processNotebooks(char *infile, char *outfile) {
    int count = 16;
    NOTEBOOK notebooks[count];

    // Открываем файл
    std::ifstream ifs(infile);
    for (int i = 0; i < count; i++) {
        // Читаем данные построчно
        char line[80];
        ifs.getline(line, 80);

        // Первые 20 символов - название
        strncpy(notebooks[i].model, line, 20);
        notebooks[i].model[20] = 0;

        // 21-24 цена
        line[24] = 0;
        notebooks[i].price = atoi(line + 20);

        // 26-28 вес
        line[28] = 0;
        notebooks[i].w = atof(line + 25);

        // 49-50 ОЗУ
        line[50] = 0;
        notebooks[i].memory = atoi(line + 48);
    }
    ifs.close();

    // Сортируем по уменьшению памяти
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < count - 1; i++) {
            if (notebooks[i].memory < notebooks[i + 1].memory) {
                NOTEBOOK tmp = notebooks[i];
                notebooks[i] = notebooks[i + 1];
                notebooks[i + 1] = tmp;
                sorted = false;
            }
        }
    }

    // Считаем количество ноутбуков с памятью не менее 40
    short mem40count = 0;
    for (int i = 0; i < count; i++) {
        if (notebooks[i].memory >= 40) {
            mem40count++;
        } else {
            break;
        }
    }

    std::ofstream ofs(outfile, std::ios::out | std::ios::binary | std::ios::app);
    ofs.write((char *) &mem40count, sizeof(short));
    for (int i = 0; i < mem40count; i++) {
        ofs.write((char *) notebooks[i].model, sizeof(notebooks[i].model));
        ofs.write((char *) &notebooks[i].memory, sizeof(int));
        ofs.write((char *) &notebooks[i].w, sizeof(float));
        ofs.write((char *) &notebooks[i].price, sizeof(int));
    }
    ofs.close();
}

int main() {
    processNotebooks("note.txt", "binary.bin");
}