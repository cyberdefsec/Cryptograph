#ifndef __BASE16_H__
#define __BASE16_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char TABLE[] = "0123456789ABCDEF";

unsigned char *encode(char *plain, size_t plain_len){
    size_t pos = 0;
    size_t index = 0;
    unsigned char *encoded = NULL;
    if(plain_len > 0){
        if((encoded = (unsigned char*)calloc(plain_len * 2, sizeof(unsigned char))) != NULL){
            while(pos < plain_len){
                encoded[index++] = TABLE[plain[pos] >> 4];
                encoded[index++] = TABLE[plain[pos] & 15];
                pos++;
            }
            return encoded;
        }
    }
    return NULL;
}

char *decode(unsigned char *encoded, size_t encoded_len){
    size_t pos = 0;
    size_t index = 0;
    char *plain = NULL;
    if(encoded_len > 0){
        if((plain = (char*)calloc((encoded_len / 2), sizeof(char))) != NULL){
            while(pos < encoded_len){
                plain[index++] = ((int)(strchr(TABLE, encoded[pos]) - TABLE) << 4) | (int)(strchr(TABLE, encoded[pos + 1]) - TABLE);
                pos += 2;
            }
            return plain;
        }
    }
    return NULL;
}

#endif
