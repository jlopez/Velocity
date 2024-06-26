#ifndef XEKEYS_H
#define XEKEYS_H

#include "winnames.h"
#include "XeCrypt.h"
#include "IO/FileIO.h"

#include <iostream>

#include "XboxInternals_global.h"

enum XeKeysRsaKeys
{
    PIRSKey = 0,
    LIVEKey = 1,
    DeviceKey = 2,
    UnknownKey = 3
};

static const BYTE PirsModulus1[0x100] =
{
    0xD7, 0x49, 0x2F, 0x13, 0xB1, 0xC1, 0x7F, 0xBF, 0x2C, 0x5B, 0x33, 0xE5,
    0x1C, 0xFA, 0x00, 0x02, 0xBB, 0x9D, 0x88, 0x16, 0x71, 0x64, 0x81, 0x07,
    0xA6, 0xE9, 0xA7, 0xC2, 0x78, 0xF5, 0xC0, 0xB8, 0xD4, 0xB7, 0x41, 0x9B,
    0x0A, 0x99, 0x60, 0x02, 0x7F, 0x95, 0x27, 0x1A, 0xCC, 0x7B, 0xAC, 0x29,
    0x16, 0x60, 0x1A, 0x8A, 0xC7, 0x4B, 0x68, 0x93, 0xED, 0x8C, 0x08, 0xED,
    0x25, 0x13, 0xCC, 0xBB, 0x9E, 0xC2, 0xA4, 0xCF, 0xB3, 0xEC, 0xC8, 0x05,
    0x9F, 0x18, 0xD0, 0x4D, 0xAD, 0xA5, 0x6E, 0xFC, 0xB0, 0x48, 0x4C, 0xF9,
    0x9E, 0x6F, 0xA4, 0x76, 0x40, 0x54, 0x22, 0x65, 0x44, 0x10, 0x2A, 0xD2,
    0xD5, 0x87, 0x66, 0x7B, 0xF2, 0x28, 0x9C, 0xB3, 0x72, 0x07, 0xDA, 0x63,
    0xAA, 0xF3, 0x3E, 0xED, 0x1E, 0xBC, 0xD8, 0x3D, 0x91, 0xA7, 0x89, 0x7C,
    0x66, 0x4E, 0x8B, 0xD0, 0x22, 0xAB, 0xDB, 0x90, 0xEF, 0xA0, 0x39, 0xEA,
    0x1C, 0xF9, 0x48, 0x66, 0x7D, 0xBC, 0x45, 0x59, 0xD0, 0xE3, 0xF2, 0x97,
    0x44, 0xF4, 0x8D, 0xC5, 0x84, 0x51, 0xC8, 0x1B, 0x4E, 0x3A, 0x81, 0x42,
    0xC5, 0x6E, 0xB9, 0x49, 0xB0, 0xE0, 0xF5, 0x1A, 0x8E, 0x80, 0x39, 0xC2,
    0xB8, 0xD9, 0xA3, 0xF1, 0x3B, 0x6E, 0x71, 0xDB, 0x56, 0x91, 0x0F, 0xF8,
    0xE8, 0xBD, 0x90, 0x4D, 0xCC, 0xBE, 0xD0, 0xC5, 0xA7, 0x43, 0xAA, 0x6C,
    0x4C, 0x5D, 0x85, 0x65, 0x98, 0x8C, 0x4C, 0x6B, 0xB8, 0x70, 0x5C, 0xC0,
    0xBE, 0x8F, 0x1B, 0x3D, 0x6D, 0x5D, 0x97, 0xFD, 0x73, 0x30, 0x76, 0x3A,
    0xE1, 0x76, 0x70, 0x61, 0xE6, 0xBE, 0x93, 0x27, 0x3E, 0x06, 0x70, 0x62,
    0x4A, 0xA2, 0xAD, 0x99, 0x84, 0xE7, 0xAB, 0x2E, 0xE4, 0xDB, 0xAE, 0x1E,
    0x64, 0x2F, 0x4E, 0x6C, 0x73, 0x99, 0xAC, 0xE5, 0xC9, 0x1C, 0x35, 0x77,
    0xC8, 0xBF, 0xA0, 0x6B
};
static const BYTE LiveModulus1[0x100] =//
{
    0xC9, 0x7B, 0x51, 0x8E, 0xC7, 0x35, 0xDC, 0xEF, 0xBD, 0x3D, 0x41, 0xC8,
    0xD0, 0x00, 0xF5, 0x7D, 0x82, 0x55, 0xBE, 0x12, 0x12, 0xD9, 0x87, 0xB3,
    0x29, 0x87, 0x5A, 0xE6, 0x7B, 0x2E, 0x7D, 0x86, 0x59, 0x0D, 0x46, 0x73,
    0xFB, 0x7B, 0x78, 0x88, 0x83, 0x85, 0xDE, 0x73, 0x6E, 0x7A, 0x0E, 0xAC,
    0xC7, 0xCF, 0x5B, 0x81, 0xBE, 0xB2, 0xB3, 0xAF, 0xB3, 0x1E, 0x20, 0x05,
    0xC5, 0xC0, 0x9C, 0x5D, 0x11, 0xC7, 0xEE, 0x35, 0x52, 0x72, 0xA4, 0xC2,
    0x59, 0xAC, 0x96, 0x18, 0x16, 0x0E, 0xE9, 0x6B, 0x7E, 0xAF, 0xA7, 0xA7,
    0x27, 0x25, 0x41, 0x70, 0x6C, 0xFB, 0xF6, 0x89, 0xC4, 0xB3, 0xEB, 0xD0,
    0xA7, 0x75, 0x21, 0x41, 0x08, 0xBB, 0x9B, 0x74, 0x55, 0x35, 0x39, 0x3F,
    0x8C, 0xDC, 0xC7, 0x57, 0x1E, 0x5B, 0x15, 0x5B, 0x49, 0xAA, 0x6A, 0xDC,
    0x9D, 0x98, 0xB9, 0xBF, 0xF3, 0x72, 0xFC, 0xC0, 0xEC, 0x08, 0xDD, 0x68,
    0x5F, 0xEA, 0x69, 0xAF, 0x75, 0x77, 0x1C, 0xB0, 0xCC, 0xFA, 0x04, 0xA3,
    0x5D, 0xCA, 0xCB, 0xF9, 0x98, 0x4B, 0x68, 0x15, 0x9A, 0x7A, 0xBE, 0xB9,
    0xB7, 0x91, 0x78, 0x0A, 0xF5, 0xB0, 0xAC, 0xAB, 0xC1, 0x0B, 0x09, 0x1D,
    0xF9, 0xF7, 0x10, 0x85, 0x7E, 0xEC, 0x5C, 0x35, 0x2E, 0x22, 0x17, 0xFA,
    0x75, 0x71, 0xA0, 0x74, 0xE0, 0x7E, 0x17, 0x23, 0x61, 0xFB, 0xFD, 0x36,
    0x3D, 0xFA, 0xC9, 0xA6, 0xCF, 0x2A, 0xA8, 0x4E, 0x4C, 0xAF, 0x2E, 0x18,
    0x01, 0x9F, 0x38, 0xB1, 0xCD, 0xA1, 0x00, 0xF8, 0x9C, 0xC4, 0xAD, 0x2D,
    0xCB, 0x2A, 0xF2, 0xA7, 0x02, 0x83, 0xE8, 0xAD, 0x9E, 0x01, 0x1D, 0xDA,
    0x5D, 0x16, 0x7E, 0x54, 0x04, 0x4E, 0x58, 0x6D, 0xFC, 0xFF, 0x16, 0x1C,
    0x20, 0xB6, 0xAB, 0x41, 0x90, 0x78, 0x9D, 0xA1, 0xF2, 0xE5, 0x3E, 0x3F,
    0x03, 0x75, 0xC2, 0xB3
};
static const BYTE DeviceModulus1[0x100] =//
{
    0xC7, 0x58, 0xC0, 0xA5, 0xAB, 0x89, 0x00, 0x86, 0x27, 0x3E, 0x2F, 0x92,
    0x27, 0xB6, 0x7C, 0x5C, 0x7D, 0xD9, 0xAF, 0x17, 0xD0, 0x3A, 0xBA, 0x3E,
    0xE2, 0xBA, 0xFA, 0x5F, 0x6E, 0x99, 0xFE, 0x7D, 0x6C, 0xFF, 0x81, 0x27,
    0x6A, 0xB6, 0xAD, 0xCC, 0x63, 0x60, 0x6C, 0xC0, 0x10, 0xFE, 0x14, 0x8A,
    0x8E, 0xE9, 0x09, 0x12, 0x3F, 0xD8, 0xC4, 0x6D, 0xB6, 0xA9, 0x45, 0x8A,
    0x14, 0xF2, 0xB5, 0x71, 0x7E, 0xC3, 0x72, 0x0F, 0xBD, 0x43, 0x1D, 0x5A,
    0x8E, 0xF1, 0x60, 0x9F, 0x08, 0x54, 0xF4, 0x1B, 0x5D, 0xAF, 0x47, 0x31,
    0x58, 0x1A, 0x3B, 0x1E, 0x3D, 0x5B, 0x35, 0x0D, 0x31, 0x6A, 0x19, 0xE3,
    0x2A, 0xE9, 0x88, 0x97, 0x74, 0x33, 0x66, 0x87, 0xCA, 0xA4, 0x02, 0x98,
    0x1A, 0x3F, 0x25, 0x19, 0x16, 0x59, 0x2C, 0x92, 0xC4, 0x21, 0x8C, 0x5C,
    0x51, 0x78, 0x5D, 0x57, 0xAA, 0x9E, 0x3B, 0xE2, 0x57, 0x67, 0xC4, 0xEA,
    0x8D, 0xC2, 0xFA, 0x64, 0x7E, 0x3F, 0x72, 0x7B, 0x7C, 0x04, 0xFE, 0x28,
    0xAE, 0x29, 0x7F, 0xAC, 0x16, 0xC4, 0x68, 0x66, 0x84, 0x2A, 0x5A, 0x8D,
    0x15, 0x14, 0xF4, 0xC3, 0xD9, 0x90, 0xCC, 0xAC, 0x83, 0x33, 0xE1, 0x21,
    0xD7, 0x13, 0xCB, 0x12, 0xA7, 0xB4, 0x59, 0xD0, 0xFA, 0x12, 0xB9, 0xD6,
    0x95, 0xE7, 0x1E, 0x4B, 0xDB, 0x8C, 0xEC, 0x34, 0x5B, 0x28, 0xEA, 0x20,
    0xD5, 0x36, 0x21, 0xB7, 0xC8, 0x5B, 0x01, 0x5E, 0x24, 0x0E, 0x8F, 0xF1,
    0xC0, 0x1B, 0xA4, 0xE2, 0xBC, 0x93, 0xC0, 0xA8, 0x92, 0xAB, 0xFD, 0xC8,
    0xC6, 0xD0, 0x60, 0xBE, 0x8E, 0xB5, 0x55, 0x90, 0xDC, 0x6E, 0x0D, 0x6F,
    0x8E, 0x52, 0x76, 0x35, 0x18, 0x9A, 0x4E, 0x07, 0x72, 0xCE, 0xDF, 0x24,
    0x82, 0xAB, 0x58, 0x9D, 0x83, 0x1E, 0xD8, 0xF7, 0xF4, 0x30, 0xE3, 0x52,
    0x4D, 0x53, 0x1C, 0xA1
};
static const BYTE UnknownModulus1[0x100] =//
{
    0xB2, 0xE1, 0xAF, 0xAC, 0x9C, 0x63, 0x6E, 0x18, 0xE2, 0x84, 0x6C, 0xBE,
    0xE9, 0xFF, 0x0E, 0x77, 0xDD, 0x99, 0x84, 0x53, 0x85, 0x0D, 0xB3, 0xD6,
    0x68, 0xFA, 0xFF, 0x79, 0xA2, 0x92, 0xD9, 0x83, 0xE2, 0xC1, 0xE8, 0xF7,
    0xDA, 0xB7, 0xAA, 0xB8, 0x6A, 0x68, 0x22, 0x35, 0x7A, 0xF9, 0x51, 0x08,
    0x7F, 0x3D, 0x5F, 0xD8, 0x54, 0x93, 0xAF, 0x94, 0xA8, 0x33, 0xCF, 0xC6,
    0xFC, 0x74, 0xC8, 0xE2, 0xD8, 0x2D, 0x5C, 0x7E, 0x38, 0x01, 0x3F, 0xB0,
    0x8E, 0x44, 0x86, 0x07, 0x50, 0x02, 0x05, 0x0F, 0xA8, 0xF9, 0xE1, 0xF4,
    0xCE, 0xBA, 0x62, 0x5F, 0x90, 0x0F, 0x18, 0x09, 0x70, 0x80, 0xAC, 0xF1,
    0x5B, 0xD6, 0xE7, 0xFE, 0xC2, 0x9D, 0xEB, 0xE4, 0xED, 0xC1, 0xFD, 0x3F,
    0x0A, 0x49, 0xF4, 0xB6, 0xF8, 0x4D, 0xBC, 0x27, 0xD9, 0xFD, 0x7F, 0x54,
    0xF8, 0xD9, 0x56, 0x7C, 0x42, 0x87, 0xAF, 0x4F, 0x12, 0x3C, 0xE3, 0x2F,
    0x9C, 0x48, 0x9F, 0x27, 0xF4, 0x0D, 0xEF, 0xDB, 0x70, 0x09, 0x33, 0x6D,
    0x4F, 0x30, 0x86, 0xF6, 0x17, 0x9E, 0xC1, 0x83, 0x38, 0x7E, 0x6A, 0x95,
    0x61, 0xEF, 0x5F, 0xE3, 0x21, 0xF2, 0xF9, 0xC2, 0x1C, 0xCE, 0xF9, 0x93,
    0xBE, 0x1D, 0xCC, 0x56, 0x96, 0xBE, 0x66, 0xF0, 0x73, 0x0E, 0xCA, 0xB0,
    0xD2, 0x92, 0xF6, 0x2F, 0x35, 0x26, 0x59, 0xE0, 0xAA, 0x44, 0x54, 0x1C,
    0x78, 0x7F, 0x9E, 0xE4, 0x65, 0xF8, 0x7B, 0x1F, 0x72, 0x89, 0x57, 0x02,
    0x30, 0xEC, 0x2A, 0x2C, 0xFA, 0x7F, 0x65, 0xBD, 0xC7, 0xC8, 0xA1, 0x3D,
    0xB4, 0x45, 0x5E, 0x98, 0x75, 0x65, 0x1F, 0xA3, 0x6B, 0x85, 0xEC, 0xBE,
    0xEC, 0xD5, 0xE6, 0xDD, 0x72, 0x49, 0x2E, 0xEC, 0x08, 0x26, 0xBE, 0x96,
    0xC5, 0xA0, 0xCF, 0x1C, 0xFE, 0x10, 0x73, 0x1F, 0x7E, 0x17, 0xD7, 0x46,
    0xE2, 0x47, 0x38, 0xDB
};
static const BYTE LiveDeviceModulus[0x100] =//
{
    0xB5, 0xFF, 0x62, 0xEB, 0xEC, 0x7B, 0xC3, 0x3D, 0xDD, 0xA0, 0xF6, 0xE6,
    0x06, 0x8E, 0x1C, 0x84, 0x1F, 0x3F, 0x35, 0xD5, 0x30, 0xA1, 0x4A, 0xC0,
    0x77, 0x58, 0xD6, 0x84, 0x4E, 0x58, 0x88, 0xC6, 0x96, 0x02, 0xF7, 0x82,
    0xCC, 0x49, 0xBC, 0xF7, 0x78, 0xE8, 0x98, 0xA8, 0xEF, 0xA8, 0x63, 0x6E,
    0x6E, 0x3C, 0x7A, 0xFF, 0x18, 0xB3, 0xAA, 0xFE, 0x8E, 0xFC, 0x76, 0x2A,
    0x97, 0xC5, 0xE8, 0x00, 0x63, 0xD2, 0x61, 0x5B, 0x31, 0xBA, 0xDD, 0xB4,
    0x5C, 0xA7, 0xEE, 0x6F, 0x80, 0xDA, 0x78, 0x33, 0x7D, 0xD6, 0x9D, 0x90,
    0xBD, 0xDC, 0xD1, 0x56, 0xDD, 0xA1, 0x3F, 0x87, 0x21, 0x76, 0xB0, 0xB1,
    0xA7, 0x4D, 0xFA, 0x7B, 0x91, 0x11, 0xF5, 0xA9, 0x82, 0xEF, 0x91, 0x74,
    0x68, 0xB0, 0x55, 0x5D, 0x7D, 0x05, 0x19, 0x4F, 0xBE, 0x39, 0x99, 0x77,
    0x77, 0x82, 0xE2, 0x5C, 0x30, 0x90, 0x24, 0xCE, 0xA8, 0xF7, 0x04, 0xC7,
    0x02, 0xF9, 0xF3, 0x95, 0xB8, 0x1A, 0x5E, 0xEE, 0x23, 0x92, 0x7D, 0xB4,
    0x4E, 0x44, 0xA9, 0x56, 0xA3, 0xD2, 0xFD, 0x40, 0x07, 0xCA, 0x71, 0xA3,
    0x97, 0x3E, 0xD3, 0x8D, 0x25, 0x9E, 0x98, 0x42, 0x43, 0x3C, 0xB2, 0x63,
    0xFB, 0x8A, 0x31, 0x54, 0x32, 0xCC, 0x52, 0x88, 0x6D, 0xC5, 0x86, 0xAE,
    0x48, 0x4C, 0xF9, 0x19, 0xCA, 0xAE, 0x81, 0x04, 0x19, 0x29, 0xF0, 0x04,
    0x62, 0xDD, 0x92, 0x59, 0x42, 0x6D, 0xE9, 0x3E, 0xC4, 0x26, 0xC8, 0x39,
    0x61, 0x3C, 0xEC, 0xE5, 0x78, 0x07, 0x38, 0xB2, 0xF9, 0xEB, 0x64, 0x18,
    0xC1, 0x0A, 0x46, 0x16, 0x66, 0x54, 0x43, 0xAC, 0x2F, 0x5B, 0x2F, 0x7F,
    0x63, 0x89, 0xA9, 0x94, 0x65, 0x30, 0x62, 0xB2, 0xD1, 0xB4, 0x2D, 0x7E,
    0xB3, 0xBA, 0xD1, 0xDD, 0x2F, 0x59, 0xA8, 0x3F, 0x92, 0x12, 0xCD, 0x87,
    0x27, 0xF1, 0x29, 0xA5
};
static const BYTE UnknownModulus2[0x100] =//
{
    0xBA, 0x66, 0x3B, 0x8C, 0xD4, 0x3C, 0x04, 0xC8, 0xCD, 0xFC, 0x3E, 0xCE,
    0x59, 0xA0, 0xF3, 0x6E, 0x27, 0x8A, 0x3B, 0xAC, 0x51, 0xD8, 0x79, 0x72,
    0x47, 0xEC, 0x87, 0x04, 0x72, 0x1C, 0x22, 0x3E, 0x15, 0x91, 0x1F, 0x91,
    0xE4, 0x8B, 0x90, 0x39, 0x52, 0x96, 0x11, 0x02, 0x86, 0x69, 0x5E, 0x00,
    0xFE, 0x19, 0x43, 0xBB, 0xFE, 0x30, 0x62, 0xAF, 0x87, 0x19, 0x07, 0xF6,
    0xFF, 0x01, 0xEA, 0x83, 0xB8, 0x96, 0xC0, 0x51, 0xDD, 0x5A, 0xD1, 0xCE,
    0x9D, 0xC4, 0xDA, 0x24, 0xEC, 0xA3, 0x31, 0x85, 0x2F, 0xF7, 0x6E, 0x1E,
    0x45, 0xDB, 0x6E, 0x92, 0xF5, 0x8E, 0xAD, 0x65, 0x5D, 0x9B, 0x45, 0x17,
    0x9E, 0xCC, 0x4B, 0x9D, 0xC7, 0xBD, 0x62, 0x49, 0xFA, 0xC0, 0x88, 0x4A,
    0x29, 0xB8, 0xC9, 0x04, 0xE5, 0xB0, 0x84, 0x2D, 0x2D, 0x86, 0x1A, 0x29,
    0x2A, 0x47, 0x5E, 0x8B, 0x72, 0x67, 0x7D, 0x79, 0x59, 0x1E, 0x6B, 0x60,
    0x04, 0x61, 0x49, 0xF6, 0xC8, 0xFA, 0x37, 0xB8, 0xAD, 0xE8, 0x6C, 0x8D,
    0x04, 0x74, 0xC5, 0x18, 0xB1, 0xEC, 0xF2, 0xA4, 0x73, 0x6C, 0x5E, 0xB6,
    0xEA, 0xAB, 0x14, 0x7A, 0xDC, 0x76, 0xB7, 0x6E, 0x3C, 0xC3, 0x80, 0xF9,
    0xE5, 0xF1, 0xAA, 0x30, 0x66, 0xA3, 0x4E, 0x41, 0x9B, 0xDB, 0xBF, 0xFD,
    0x30, 0xD1, 0xA0, 0x5A, 0x26, 0xB5, 0x4A, 0xEC, 0x51, 0x51, 0x27, 0x26,
    0xBC, 0xAF, 0x0B, 0xC7, 0xD5, 0xAA, 0x04, 0x1F, 0x6E, 0x83, 0xAF, 0xD0,
    0x17, 0x8E, 0x40, 0x50, 0x8E, 0xCC, 0xA5, 0x63, 0xE5, 0xA6, 0x94, 0x68,
    0xBF, 0x56, 0x6B, 0x4B, 0xAC, 0x3D, 0x16, 0xAA, 0xEE, 0x91, 0x26, 0x08,
    0x23, 0x9D, 0x95, 0x6D, 0xE7, 0xC9, 0x2A, 0x60, 0x9E, 0x5C, 0x96, 0x0A,
    0x1A, 0xB0, 0x69, 0x23, 0xEB, 0xDE, 0x65, 0xBB, 0x32, 0xB4, 0xEE, 0x99,
    0x6A, 0x4A, 0xB0, 0x3F
};

class XBOXINTERNALSSHARED_EXPORT XeKeys
{
public:
    static bool VerifyRSASignature(XeKeysRsaKeys key, BYTE *pbMessage, DWORD cbMessage,
            BYTE *signature);

};

#endif
