

void search_in_file(char* search, queue files, char flag, int n);
void addfiles(char* dirname, queue* files);
void flag_c(char* here, char* search, FILE* fp, char* fname);
void flag_h(char* here, char* search, FILE* fp);
void flag_i(char* here, char* search, FILE* fp, char* fname);
void flag_l(char* here, char* search, FILE* fp, char* fname);
void flag_n(char* here, char* search, FILE* fp, int line_number, char* fname); // -r flag also calls this
void flag_w(char* here, char* search, FILE* fp, char* fname);
void flag_v(char* here, char* search, FILE* fp, char* fname);
void flag_L(char* here, char* search, FILE* fp, char* fname);
void flag_o(char* here, char* search, FILE* fp, char* fname);
void flag_H(char* here, char* search, FILE* fp, char* fname);
void flag_0(char* here, char* search, FILE* fp, char* fname);