#include <stdio.h>
#include <stdlib.h> 

//////tu piszemy opis
int n;
int m;
enum State { Q0, Q1, Q2, Q3, Q4, Q5, Q6 };
char tape[1000];
int head = 400;
enum State state = Q0;
int step = 0;

void print_state(int step) {
    int i;

    printf("\nStep %d\n", step);
    printf("State: Q%d\n", state);

   
    for (i = head - 10; i <= head + 10; i++) {
        if (i < 0 || i >= 1000)
            printf(" ");
        else
            printf("%c", tape[i]);
    }

    printf("\n");

   
    for (i = head - 10; i <= head + 10; i++) {
        if (i == head)
            printf("^");
        else
            printf(" ");
    }

    printf("\n");
}

void change_state(int current_state, char tasma[], int current_head) {
    //for (int g = head; g<m+n+5 && g>398;  )
    switch (state) {
        

            case Q0:
                if (tape[head] == '0') {
                    tape[head] = 'B';
                    state = Q1;
                    head++;
                }
                else if (tape[head] == '1') {
                    tape[head] = 'B';
                    state = Q5;
                    head++;
                }
               /* else {
                    state = Q6;
                }*/
                break;

            case Q1:
                if (tape[head] == '0') {
                    tape[head] = '0';
                    state = Q1;
                    head++;
                }
                else if (tape[head] == '1') {
                    tape[head] = '1';
                    state = Q2;
                    head++;
                }
                else {
                    state = Q6;
                }
                break;

            case Q2:
                if (tape[head] == '0') {
                    tape[head] = '1';
                    state = Q3;
                    head--;
                }
                else if (tape[head] == '1') {
                    tape[head] = '1';
                    state = Q2;
                    head++;
                }
                else if (tape[head] == 'B') {
                    tape[head] = 'B';
                    state = Q4;
                    head--;
                }
                break;

            case Q3:
                if (tape[head] == '0') {
                    tape[head] = '0';
                    state = Q3;
                    head--;
                }
                else if (tape[head] == '1') {
                    tape[head] = '1';
                    state = Q3;
                    head--;
                }
                else if (tape[head] == 'B') {
                    tape[head] = 'B';
                    state = Q0;
                    head++;
                }
                break;

            case Q4:
                if (tape[head] == '0') {
                    tape[head] = '0';
                    state = Q4;
                    head--;
                }
                else if (tape[head] == '1') {
                    tape[head] = 'B';
                    state = Q4; 
                    head--;
                }
                else if (tape[head] == 'B') {
                    tape[head] = '0';
                    state = Q6;
                    head++;
                }
                break;

            case Q5:
                if (tape[head] == '0') {
                    tape[head] = 'B';
                    state = Q5;
                    head++;
                }
                else if (tape[head] == '1') {
                    tape[head] = 'B';
                    state = Q5;
                    head++;
                }
                else if (tape[head] == 'B') {
                    tape[head] = 'B';
                    state = Q6;
                    head++;
                }
                break;

            case Q6:
                // stan koñcowy – brak przejœæ
                break;
            }
        }



int main(void) {

    printf("Enter m:\n");
    scanf_s("%d", &m);
    printf("Enter n:\n");
    scanf_s("%d", &n);

    //tasma
    for (int i = 0; i < sizeof(tape) / sizeof(tape[0]); i++) {
        tape[i] = 'B'; // blank symbol
    }
    for (int j = 400; j < 400 + m; j++) {
        tape[j] = '0';
    }
    tape[400 + m] = '1';
    for (int k = 401 + m; k < 401 + m + n; k++) {
        tape[k] = '0';
    }

    //test
	printf("Initial tape content:\n");
    for (int t = 395; t < 500; t++) {
        printf("%c", tape[t]);
    }






    while (state != Q6) {
        change_state(state, tape, head);
        print_state(step);
        step++;
    }


    int resultZeros = 0;
    for (int t = 400; t < 1000; t++) {
        if (tape[t] == '0') resultZeros++;
        else if (tape[t] == '1') break; 
    }
    if (resultZeros == 0) {
        printf("Turing machine produced 0 zeroes (m<n)");
        
    }
    else {
    printf("\nTuring machine produced %d zeros\n", resultZeros);
    printf("Expected m - n = %d\n", m - n);
    }
    return 0;
}

