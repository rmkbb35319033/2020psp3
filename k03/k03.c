#include <stdio.h>
#include<string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart wink highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start,pos;       /*start..比較開始位置、pos..比較位置*/
    int text_len = strlen(text);
    int key_len = strlen(key);

    for(start = 0; start<(text_len - key_len); start++){
        for(pos = 0; pos<key_len; pos++ ){
            if(text[start + pos] == key[pos]){
                if(key_len == pos+1)
                    return &text[start];
            }else{
                break;
            }
        }
    }
    return NULL;

}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int start,pos;      //start..比較開始位置、pos..比較位置
    char table[256];
    int text_len = strlen(text);
    int key_len = strlen(key);
    int i,j,start2 = 0;

    for(int i; i<256; i++){
        table[i] = key_len;
    }
    for(int i = key_len - 1; i>=0; i--){

             table[key[i]] = j;    //key文字の後ろの順番から数値を代入していく。
             j++;
    }

    start = key_len - 1;
    while(start <= text_len){    //開始位置がtextの一番後ろに来るまで操作を続ける。
        for(pos = key_len - 1; pos >= 0; pos--){  
            start2 = start;  //start2にstartの数値を保持しておく。
            if(text[start] == key[pos]){
                start--;
                if(pos == 0)
                    return &text[start];   
            }else{
                break;
            }
        }

    start = start + table[text[start]];
    if(start <= start2){
        start = start2 + 1;
    }
    
    }
    return NULL;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}