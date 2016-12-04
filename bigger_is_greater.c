#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char ** test_cases; 

int lexicographic_ordering(char * str, char * lexbigstr) {	
				int len = strlen(str); 
				if(len == 1)
								return 0; 

				// char * lexbigstr = malloc(sizeof(char) * (len + 1)); 
				strcpy(lexbigstr, str);
				lexbigstr[len] = '\0'; 

				int i = len - 2, j; 
				while(i >= 0) { 
								j = i + 1;
								char tmp;  
								while(j < len)  { 
												if((lexbigstr[j] > lexbigstr[i])) { 
																tmp = lexbigstr[i]; 
																lexbigstr[i] = lexbigstr[j]; 
																lexbigstr[j] = tmp;
																return 1; 
												}
												j++;  
								}
								tmp = lexbigstr[i];
								for(int k = i; k < (len - 1); k++) 
												lexbigstr[k] = lexbigstr[k+1]; 
								//printf("Replacing %c with %c\n", lexbigstr[len-1], tmp); 
								lexbigstr[(len - 1)] = tmp; 
								i--;   	
				}

				return 0; 
} 


int main() {
				char * line = malloc(101 * sizeof(char));
				size_t len = 100; 
				size_t len_read;  

				/* Test for no t */ 
				if(getline(&line, &len, stdin) == -1) { 
								line[strcspn(line, "\n")] = 0;
								printf("No input provided. Please enter n::INT followed by a list of n test strings \n");
								return 0; 
				} 

				/* Test for invalid t */ 
				int n = atoi(line); 
				if (n <= 0 || n > 100000) { 
								printf("Invalid number of input string, please enter a number 1 <= n <= 10,000 \n"); 
								return 0; 
				} 

				test_cases = malloc(n * 101 * sizeof(char)); 

				int chars_to_copy; 
				/* Read test cases */ 
				for(int i = 0; i < n; i++) {
								//printf("%d", i); 
								len_read = getline(&line, &len, stdin); 
								line[strcspn(line, "\n")] = 0;
								if(len_read <= 0){ 
												printf("No input received."); 
								} else {   
												if(len_read < 101) 
																chars_to_copy = len_read; 
												else 
																chars_to_copy = 100; 
												test_cases[i] = malloc((len_read + 1) * sizeof(char)); 
												strncpy(test_cases[i], line, chars_to_copy);
												test_cases[i][chars_to_copy] = '\0';  
								}

				} 

				char * lexbigstr = malloc(101 * sizeof(char)); 
				for(int i = 0; i <n ; i++) { 
								if(lexicographic_ordering(test_cases[i], lexbigstr))
												printf("%s\n", lexbigstr);
								else printf("no answer\n"); 
				}  

				//printf("--- Done ---\n"); 

				free(line); 
				free(lexbigstr); 
				for(int i=0; i < n; i++) 
								free(test_cases[i]); 

				free(test_cases);  
				return 0;
}

