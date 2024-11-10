    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    
    const int MAX_GROUP_SIZE = 10000;
    char *OCTAL = "Octal";
    char *HEXA = "Hexadecimal";
    char *DECIMAL = "Decimal";
    char *ERROR = "Inválido";

    // Estados posibles
    typedef enum {
        Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10
    } states;

    // Obtiene el tipo asociado según el estado final
    char* getType(int state) {
        if (state == Q2) return OCTAL;
        if (state == Q4) return HEXA;
        if (state == Q5 || state == Q9) return DECIMAL;
        return ERROR; 
    }

    int nextQ7(char c) {
        if (c >= '0' && c <= '9') return Q9;
        return Q10;
    }

    int nextQ9(char c) {
        return nextQ7(c);
    }

    int nextQ8(char c) {
        return nextQ7(c);
    }

    int nextQ6(char c) {
        if (c >= '0' && c <= '9') return Q5;
        return Q10;
    }

    int nextQ5(char c) {
        if (c >= '0' && c <= '9') return Q5;
        if (c == '.') return Q7;
        return Q10;
    }

    int nextQ4(char c) {
        if (c >= '0' && c <= '9') return Q4;
        if (toupper(c) >= 'A' && toupper(c) <= 'F') return Q4;
        return Q10;
    }

    int nextQ3(char c) {
        if (c >= '0' && c <= '9') return Q4;
        if (toupper(c) >= 'A' && toupper(c) <= 'F') return Q4;
        return Q10;
    }

    int nextQ2(char c) {
        if (c >= '0' && c <= '7') return Q2;
        return Q10;
    }

    int nextQ1(char c) {
        if (c == 'x') return Q3;
        if (c == '.') return Q5;
        if (c >= '1' && c <= '7') return Q2;
        if (c == '0' || c == '8' || c == '9') return Q5;
        return Q10;    
    }

    int nextQ0(char c) {
        if (c == '0') return Q1;
        if (c >= '1' && c <= '9') return Q5;
        if (c == '+' || c == '-') return Q6;
        if (c == '.') return Q7;
        return Q10;
    }

    void groupScan(char *group, char **groupType) {
        int state = Q0;

        for(int i = 0; i < strlen(group); i++) {
            switch(state) {
                case Q0: state = nextQ0(group[i]); 
                    break;
                case Q1: state = nextQ1(group[i]); 
                    break;
                case Q2: state = nextQ2(group[i]);
                    break;
                case Q3: state = nextQ3(group[i]);
                    break;
                case Q4: state = nextQ4(group[i]);
                    break;
                case Q5: state = nextQ5(group[i]);
                    break;
                case Q6: state = nextQ6(group[i]);
                    break;
                case Q7: state = nextQ7(group[i]);
                    break;
                case Q8: state = nextQ8(group[i]);
                    break;
                case Q9: state = nextQ9(group[i]);
                    break;
                default: state = Q10;
                    break;                                        
            }
        }
        *groupType = getType(state);
    }

    void scan(char *input, int *nTotal, char **groupTypes) {
        int i = 0, j = 0;
        char group[MAX_GROUP_SIZE];
        char *groupType = "";

        while(input[i] != '\0') { 
            int groupCounter = 0;

            while (input[i] != '#' && input[i] != '\0') {
                group[groupCounter++] = input[i++];
            }
            group[groupCounter] = '\0'; // Seteo el fin de cada group

            groupScan(group, &groupType);
            nTotal[j] = groupCounter;
            groupTypes[j] = groupType;
            j++;
            
            if (input[i] == '#') {
                i++;  // Saltear el '#'
            }
        } 
    }