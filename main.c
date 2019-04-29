#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int i;/*
    printf("\n\n\n\n             ::::::::  :::::::::  :::   ::: ::::::::: ::::::::::: ::::::::  ::::::::: \n");
    usleep(300000);
    printf("           :+:    :+: :+:    :+: :+:   :+: :+:    :+:    :+:    :+:    :+: :+:    :+: \n");
    usleep(300000);
    printf("          +:+        +:+    +:+  +:+ +:+  +:+    +:+    +:+    +:+    +:+ +:+    +:+  \n");
    usleep(300000);
    printf("         +#+        +#++:++#:    +#++:   +#++:++#+     +#+    +#+    +:+ +#++:++#:    \n");
    usleep(300000);
    printf("        +#+        +#+    +#+    +#+    +#+           +#+    +#+    +#+ +#+    +#+    \n");
    usleep(300000);
    printf("       #+#    #+# #+#    #+#    #+#    #+#           #+#    #+#    #+# #+#    #+#     \n");
    usleep(300000);
    printf("       ########  ###    ###    ###    ###           ###     ########  ###    ###      \n");
    usleep(300000);
    printf("      ");
    for(i=0; i<74; ++i){
        printf("=");
        usleep(5000);
    }
    printf("\n\n\n\n");
    usleep(50000);*/
    int menuopt;
    printf("     Enter (1) to encrypt via rotation cipher\n\n     Enter (2) to decrypt a rotation cipher with a known key\n\n     Enter (3) to decrypt a rotation cipher without the key\n\n     Enter (4) to encrypt using a substitution cipher\n\n     Enter (5) to decrypt a substitution cipher with the key\n\n     Enter (6) to decrypt a substitution cipher without the key\n\n");
    scanf("%d", &menuopt);//gets user selected option, stores in menuopt
    switch(menuopt){//begins subprogram related to input
        case 1 :
            encRot();
            break;
        case 2 :
            decRotKey();
            break;
        case 3 :
            decRotNo();
            break;
        case 4 :
            encSub();
            break;
        case 5 :
            decSub();
            break;
        case 6 :
            printf("\ndec:\n");
            dec();
            break;
    }
}
void encRot(){
    system("@cls||clear");//clears the screen
    char userInp[999999], cha;//max user input length is 999999 characters, excluding terminal value
	int i, key;
	printf("Enter a message to encrypt: ");
	getchar();//stops previous input from carrying over
	fgets(userInp, 999999, stdin);
	strupr(userInp);//converts input to upperase
	printf("Enter key: ");
	scanf("%d", &key);
	for(i = 0; userInp[i] != '\0'; ++i){
		cha = userInp[i];
		if(cha >= 'A' && cha <= 'Z'){//if the character is a letter, it is shifted according to the key
			cha = cha + key;

			if(cha > 'Z'){//loops the character to the beginning of the alphabet again, rather than  using a symbol
				cha = cha - 'Z' + 'A' - 1;
			}

			userInp[i] = cha;
		}
	}

	printf("Encrypted message: %s", userInp);

	return 0;
}
void decRotKey(){
    system("@cls||clear");
    char userInp[999999], chr;
	int i, key;

	printf("Enter a message to decript: ");
	getchar();
	fgets(userInp, 999999, stdin);
	printf("Enter key: ");
	scanf("%d", &key);
    strupr(userInp);
	for(i = 0; userInp[i] != '\0'; ++i){//functionally the same as encoder, except it takes away the key
		chr = userInp[i];
		if(chr >= 'A' && chr <= 'Z'){
			chr = chr - key;

			if(chr < 'A'){
				chr = chr + 'Z' - 'A' + 1;
			}

			userInp[i] = chr;
		}
	}

	printf("Decrypted userInp: %s", userInp);
}
void decRotNo(){
    system("@cls||clear");
    int selection;
    printf("\nEnter 1 to force a solution (will guess all possible solutions)\nOr enter 2 for an educated solution (will guess a solution based on statistical analysis)\n");
    scanf("%d", &selection);
    switch(selection){
        case 1 :;
            char userInp[999999], temp[100], chr;
            int i, key=-25;
            printf("Enter a message to decrypt: ");
                getchar();
                fgets(userInp, 999999, stdin);
                strupr(userInp);
                strncpy(temp, userInp, 100);
            for(key = 0; key < 27; ++key){//tests all possible keys
                for(i = 0; userInp[i] != '\0'; ++i){
                    chr = userInp[i];
                    if(chr >= 'A' && chr <= 'Z'){
                        chr = chr - key;

                        if(chr < 'A'){
                            chr = chr + 'Z' - 'A' + 1;
                        }

                        userInp[i] = chr;
                    }
                }
                printf("\nDecrypted guess %d: %s", key, userInp);
                strncpy(userInp, temp, 100);
            }
            break;
    }
}
void encSub(){
    system("@cls||clear");
    printf("\nPlease enter the message you would like to have encrypted.\n");
    char userInp[999999];
    int ch, i, key;
    getchar();
    fgets(userInp, 999999, stdin);
    strupr(userInp);
    printf("\nWhat key would you like to use?");
    scanf("%d", &key);
    printf("\nye key is %d", key);
    if(key = 1){
        char sub1[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
        for(i = 0; userInp[i] != '\0'; ++i){// '\0' is the terminal value
            ch = (int)userInp[i];
            if(ch>64 && ch<91){//if it's a letter, it is swapped. Otherwise, it is not.
                ch = ch-65;//converts the index to fit within the target array, which starts at 0 (not 65 like A in ascii)
                userInp[i] = sub1[ch];
            }
        }
        printf("\nEncripted userInp: %s", userInp);
    }
    else if(key = 2){
        char sub2[26] = "MNBVCXZLKJHGFDSAPOIUYTREWQ";//note only 2 keys so as to save time coding in more.
        for(i = 0; userInp[i] != '\0'; ++i){
            ch = (int)userInp[i];
            if(ch>64 && ch<91){
                ch = ch-65;
                userInp[i] = sub2[ch];
            }
        }
        printf("\nEncripted userInp: \n%s", userInp);
    }
    printf("\n\nEncryption finished.\n");
}
void decSub(){
    system("@cls||clear");
    printf("\nPlease enter the   message you would like to have decripted.\n");
    char userDec[999999];
    int ch, i, key;
    getchar();
    fgets(userDec, 999999, stdin);
    strupr(userDec);
    printf("\nWhat is the key?\n");
    scanf("%d", &key);
    if(key = 1){
        char sub1[26] = "KXVMCNOPHQRSYZOJADLEGWBUFT";//this is the alphabetically ordered opposite of the original sub[]
        for(i = 0; userDec[i] != '\0'; ++i){//functionally the same as the original sub, except it is subbing in a new sub[]
            ch = (int)userDec[i];
            if(ch>64 && ch<91){
                ch = ch-65;
                userDec[i] = sub1[ch];
            }
        }
          printf("\nDecripted message: %s", userDec);
    }
    else if(key = 2){
        char sub2[26] = "PCENXMLKSJIHABRQZWOVTDYFUG";
        for(i = 0; userDec[i] != '\0'; ++i){
            ch = (int)userDec[i];
            if(ch>64 && ch<91){
                ch = ch-65;
                userDec[i] = sub2[ch];
            }
        }
        printf("\nEncripted message: \n%s", userDec);
    }
    printf("\n\nFinished.\n");
}
void dec(){
    system("@cls||clear");
    printf("\nPlease enter the message you would like to have decripted.\n Be warned that the message must be of a significant length in order to achieve an accurate result.\nThere is hwoever a maximum length of 999999 characters.\n");
    char userInp[999999], alph[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", natOrd[26]="ETAOINSRHLDCUMFPGWYBVKXJQZ", t, t2;
    int i = 0, count[26] = {0}, x, n, c, d, ch;//amount of variables due to strange compiler issues, it could be more efficient but not without unexplainable compiler errors
    getchar();
    fgets(userInp, 999999, stdin);
    strupr(userInp);
    while (userInp[i] != '\0') {//counts frequency of characters within the input, in alphabetical order
        if (userInp[i] >= 'A' && userInp[i] <= 'Z') {
            x = userInp[i] - 'A';
            count[x]++;
        }
        i++;
    }
    for(d=0; d < 26; ++d){//sorts the alphabet (alph) in order of most occuring to least occuring, via using count[] to sort and alph[] values shifted in coordination with it
        while ( d > 0 && count[d-1] < count[d]) {
            t = count[d];
            t2 = alph[d];
            count[d] = count[d-1];
            alph[d] = alph[d-1];
            count[d-1] = t;
            alph[d-1] = t2;
            d--;
        }
    }
    for(c=0; c < 26; ++c){
        d=c;//strange errors occured without this, best kept with d and c
        while ( d > 0 && (int)natOrd[d-1] > (int)natOrd[d]) {//orders the natural order (ie ETA...) back to alphabetical order, and shifting the values of the newly ordered alph[] with it,
            t = natOrd[d];                                  // this thus makes a new array of characters which can be subbed in, much like in the encSub() function, but this time according to
            t2 = alph[d];                                   // how much each caracter occurs and not a predetermined value
            natOrd[d] = natOrd[d-1];
            alph[d] = alph[d-1];
            natOrd[d-1] = t;
            alph[d-1] = t2;
            d--;
        }
    }
        for(i = 0; userInp[i] != '\0'; ++i){//functionally the same as what is seen in encSub() except using the newly made alph()
            ch = (int)userInp[i];
            printf("\nch: %d   i: %d", ch, i);
            if(ch>64 && ch<91){
                ch = ch-65;
                userInp[i] = alph[ch];
            }
        }
        printf("\nDecripted message guess: %s", userInp);
        getchar();
}
