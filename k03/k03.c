#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int text_len=0;
    int key_len=0;
    int i;
    int start,pos;
    char* p;

    for(i=0;text[i]!='\0';i++){
        text_len++;
    }
    
    for(i=0;key[i]!='\0';i++){
        key_len++;
    }

    for(start=0;start<=text_len-key_len;start++){
        for(pos=0;pos<=key_len;pos++){
            if(text[start+pos]!=key[pos]){
                break;
            }else if(pos==key_len-1){
                p=&text[start];
                return p;
            }
        }
    }

    return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int text_len=0;
    int key_len=0;
    int i,j;
    int start=0;
    int pos,prev_start;
    char* p;
    int table[ALPHABET_LEN];

    for(i=0;text[i]!='\0';i++){
        text_len++;
    }
    
    for(i=0;key[i]!='\0';i++){
        key_len++;
    }
    
    for(i=0;i<=ALPHABET_LEN;i++){
        table[i]=key_len;

    }
    for(j=0;j<=key_len-1;j++){
        table[key[j]]=key_len-j-1;
    }

    while(start<=text_len-key_len){
        for(pos=key_len-1;0<=pos;pos--){
            if(text[start+pos]!=key[pos]){
                prev_start=start;
                start=pos+table[text[start+pos]];
                if(start<=prev_start){
                start=prev_start+1;
                }
                break;
            }else if(pos==0){
                p=&text[start];
                return p;
            }
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