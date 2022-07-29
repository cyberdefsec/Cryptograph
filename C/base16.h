#ifndef __BASE16_H__
#define __BASE16_H__


unsigned char *encode(char *plain, size_t plain_len);

char *decode(unsigned char *encoded, size_t encoded_len);

#endif
