#include <stdio.h>
#include <assert.h>

#include "consoleColorsConst.h"

void concantenate(FILE* fp);
FILE* openFile();
void closeFile(FILE* fp);

int main(void){
    FILE* fp = openFile();
    assert(fp);
    concantenate(fp);
    closeFile(fp);
}

void concantenate(FILE* fp){
    assert(fp);

    const char* guard = "CONSOLE_COLORS_H";
    fprintf(fp, "#ifndef %s\n", guard);
    fprintf(fp, "#define %s\n", guard);
    fprintf(fp, "\n#define RESET \"%s\"\n", RESET);
    
    for(size_t style = 0; style < (sizeof(styles) / sizeof(style_t)); style++){
        for(size_t ground = 0; ground < (sizeof(grounds) / sizeof(style_t)); ground++){
            
            fprintf(fp, "\n");
            for(size_t color = 0; color < (sizeof(colors) / sizeof(style_t)); color++){
                char buffer[100];
                sprintf(buffer, "#define SET_STYLE_%s_%s_%s ", 
                                                   styles[style].name, 
                                                   grounds[ground].name,
                                                   colors[color].name);
                char ch;
                int i = 0;
                while((ch = buffer[i]) != '\0'){
                    i++;
                }
                int j = 0;
                for(j = i; j < 52; j++){
                    buffer[j] = ' ';
                }
                sprintf(buffer+j, "\"%s%s;%s%sm\"", SET_STYLE,
                                styles[style].code,
                                grounds[ground].code,
                                colors[color].code);
                fprintf(fp, "%s\n", buffer);
            }
        }
    }

    fprintf(fp, "\n#endif /* %s */", guard);
}

FILE* openFile(){
    FILE* fp = fopen("consoleColors.h", "w");
    if (fp == NULL){
        printf("Ошибка открытия файла");
        return NULL;
    }
    return fp;
}

void closeFile(FILE* fp) {
    fclose(fp);
}
