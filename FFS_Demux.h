#ifndef FFS_DEMUX_H
#define FFS_DEMUX_H

#include <Arduino.h>

class FFS_Demux16
{
public:
    FFS_Demux16(uint8_t ad0, uint8_t ad1, uint8_t ad2, uint8_t ad3, uint8_t en);
    void begin();
    void enable();
    void disable();
    void select(uint8_t addr);
private:
    uint8_t addr0;
    uint8_t addr1;
    uint8_t addr2;
    uint8_t addr3;
    uint8_t e;
};

class FFS_Demux8
{
public:
    FFS_Demux8(uint8_t ad0, uint8_t ad1, uint8_t ad2, uint8_t en);
    void begin();
    void enable();
    void disable();
    void select(uint8_t addr);
private:
    uint8_t addr0;
    uint8_t addr1;
    uint8_t addr2;
    uint8_t e;
};

#endif
