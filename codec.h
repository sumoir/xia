/*
 * codec.h
 *
 *  Created on: 2022年8月31日
 *      Author: xia
 */

#ifndef CODEC_H_
#define CODEC_H_

#include <stdint.h>

typedef struct frame{
    uint8_t header;
    uint8_t type;
    uint8_t length;
    char data[200];
}Frame;
int encode_frame(Frame frame, char data[]);
int decode_frame(Frame *frame, char data[]);

int find_header(int len, char data[]);

int encode_string(char data[], char *info);
int decode_string(char *dest, uint32_t len, char data[]);

int encode_int(char data[], int value);
int decode_int(int *value, char data[]);


#endif /* CODEC_H_ */
