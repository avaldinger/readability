#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
int isConnector(char c);

int main(void)
{
    string text = get_string("Please enter the text here: \n");
    //  printf("\nThe text you entered: %s\n", text);

    // counting the number of letters
    printf("\n%i letter(s)", count_letters(text));
    printf("\n%i word(s)\n", count_words(text));
    printf("%i sentence(s)\n",  count_sentences(text));

    float L = (count_letters(text) * 100)/count_words(text);
    float S = (count_sentences(text) * 100)/count_words(text);

    // Calculating the Coleman-Liau index
    int index = 0.0588 * L - 0.296 * S - 15.8;

    if(index <= 1){
        printf("Before Grade 1");
    }else if(index >= 16){
        printf("Grade 16+");
    }else{
        printf("Grade %i\n", index);
    }



}

int count_letters(string s){

    int numberOfLetters = 0;
    for(int i = 0, n = strlen(s); i < n; i++){
        // making the full text lowercase
        // tolower(s[i]);
        // iterating through the text's characters
        if(isalpha(s[i]) && !isspace(s[i])){
            // printf("Current char: %c\n", s[i]);
            numberOfLetters++;
        }

    }

    return numberOfLetters;
}

int count_words(string s){

    int numberOfWords = 0;
    char connectors[4] ={'\'', '_', '-', '~'};
    for(int i = 0, n = strlen(s); i < n; i++){
        // iterating through the text's characters
        if(i == 0){
            // do nothing
        }else if(i == n){
            numberOfWords++;
        }
        else if(!isalpha(s[i]) && isalpha(s[i-1])){
            if(isConnector(s[i]) > 0 && isalpha(s[i-1]) && isalpha(s[i+1])){
                // do nothing
            }else{
            numberOfWords++;
         }
        }
    }

    return numberOfWords;
}

int count_sentences(string s){

     int lengthOfArray = 3;
    char endOfSentence[3] ={'.', '?', '!'};

    int numberOfSentences = 0;
    for(int i = 0, n = strlen(s); i < n; i++){
        // iterating through the text's characters
        for(int j = 0; j < lengthOfArray; j++){
        if(s[i] == endOfSentence[j]){
            numberOfSentences++;
         }
        }
    }

    return numberOfSentences;
}

int isConnector(char c){

    int flag = 0;
    char connectors[4] ={'\'', '_', '-', '~'};
    for(int i = 0; i < 4; i++){
        if(connectors[i] == c){
            flag = 1;
        }
    }

    return flag;

}