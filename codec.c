/*
 * code.c
 *
 *  Created on: 2022年8月31日
 *      Author: xia
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "codec.h"

int encode_frame(Frame frame, char data[])
{
    int index = 0;

    data[index++] = 0xFA;
    data[index++] = frame.type;
    data[index++] = frame.length;
    memcpy(data + index, frame.data, frame.length);

    return index + frame.length;
}

int decode_frame(Frame *frame, char data[])
{

    int index = 0;

    frame->header = data[index++];
    frame->type = data[index++];
    frame->length = data[index++];
    memcpy(frame->data, data + index, frame->length);

    return index + frame->length;
}

int find_header(int len, char data[])
{
    for (int i = 0; i < len; i++) {
        if ((uint8_t)data[i] == 0xFA) {
            return i;
        }
    }
    return -1;
}

int encode_string(char data[], char *info)
{
    int index = 0, length = 0;

    length = strlen(info);

    data[index] = length;
    index += 1;
    strncpy(data + index, info, length);
    index += length;

    return index;
}

int decode_string(char *dest, uint32_t len, char data[])
{
    strncpy(dest, data, len);

    return len + 1;
}

int encode_int(char data[], int value)
{
    data[0] = (char)(value >> 24);
    data[1] = (char)(value >> 16);
    data[2] = (char)(value >> 8);
    data[3] = (char)value;

    return 4;
}

int decode_int(int *value, char data[])
{
    *value = (int)(data[0] << 24) | (int)(data[1] << 16) | (int)(data[2] << 8) | (int)(data[3]);

    return 4;
}

