#include "FFS_Demux.h"

FFS_Demux16::FFS_Demux16(uint8_t ad0, uint8_t ad1, uint8_t ad2, uint8_t ad3, uint8_t en)
{
    addr0 = ad0;
    addr1 = ad1;
    addr2 = ad2;
    addr3 = ad3;
    e = en;
}

void FFS_Demux16::begin()
{
    pinMode(addr0, OUTPUT);
    pinMode(addr1, OUTPUT);
    pinMode(addr2, OUTPUT);
    pinMode(addr3, OUTPUT);
    pinMode(e, OUTPUT);
    enable();
}

void FFS_Demux16::enable()
{
    digitalWrite(e, HIGH);
}

void FFS_Demux16::disable()
{
    digitalWrite(e, LOW);
}

void FFS_Demux16::select(uint8_t addr)
{
    disable();
    digitalWrite(addr0, addr & 0b0001);
    digitalWrite(addr1, addr & 0b0010);
    digitalWrite(addr2, addr & 0b0100);
    digitalWrite(addr3, addr & 0b1000);
    enable();
}

FFS_Demux8::FFS_Demux8(uint8_t ad0, uint8_t ad1, uint8_t ad2, uint8_t en)
{
    addr0 = ad0;
    addr1 = ad1;
    addr2 = ad2;
    e = en;
}

void FFS_Demux8::begin()
{
    pinMode(addr0, OUTPUT);
    pinMode(addr1, OUTPUT);
    pinMode(addr2, OUTPUT);
    pinMode(e, OUTPUT);
    enable();
}

void FFS_Demux8::enable()
{
    digitalWrite(e, HIGH);
}

void FFS_Demux8::disable()
{
    digitalWrite(e, LOW);
}

void FFS_Demux8::select(uint8_t addr)
{
    disable();
    addr &= 0b111;
    const uint8_t map[8] = {
        0b010,
        0b001,
        0b000,
        0b011,
        0b101,
        0b111,
        0b110,
        0b100
    };
    digitalWrite(addr0, map[addr] & 0b001);
    digitalWrite(addr1, map[addr] & 0b010);
    digitalWrite(addr2, map[addr] & 0b100);
    enable();
}