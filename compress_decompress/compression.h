#define MAX 16

char padding;

unsigned char N;

typedef struct codeTable{
    char x;
    char code[MAX];
}codeTable;

char compressed_extension[] = ".spd";
char decompressed_extension[] = ".txt";
