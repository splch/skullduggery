#include "hUGEDriver.h"
#include <stddef.h>

static const unsigned char order_cnt = 32;

static const unsigned char P0[] = {
    DN(C_4,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,2,0x027),
    DN(___,0,0x037),
    DN(C_5,2,0xC00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,2,0x027),
    DN(___,0,0x037),
    DN(C_5,2,0xC00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,2,0x027),
    DN(___,0,0x037),
    DN(C_5,2,0xC00),
    DN(___,0,0x000),
    DN(C_5,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,2,0x037),
    DN(___,0,0x037),
    DN(C_5,2,0xC00),
    DN(___,0,0x000),
    DN(C_4,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,2,0x027),
    DN(___,0,0x037),
    DN(C_5,2,0xC00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,2,0x027),
    DN(___,0,0x037),
    DN(C_5,2,0xC00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,2,0x025),
    DN(___,0,0x025),
    DN(C_5,2,0xC00),
    DN(___,0,0x000),
    DN(As4,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,2,0x025),
    DN(___,0,0x025),
    DN(C_5,2,0xC00),
    DN(___,0,0x000),
};
static const unsigned char P1[] = {
    DN(C_4,2,0xC00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P2[] = {
    DN(C_4,1,0xF03),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(C_5,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0xC00),
    DN(G_4,1,0x000),
    DN(___,0,0xC00),
    DN(Fs4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(F_4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(Ds4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Fs4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(C_5,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0xC00),
    DN(G_4,1,0x000),
    DN(___,0,0xC00),
    DN(Fs4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(F_4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0x436),
    DN(___,0,0x400),
    DN(___,0,0x400),
    DN(___,0,0x400),
    DN(___,0,0x403),
    DN(___,0,0x400),
    DN(___,0,0x400),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P3[] = {
    DN(B_5,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Cs7,4,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Cs7,5,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(B_5,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(B_5,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Cs7,4,0x000),
    DN(___,0,0x000),
    DN(Cs7,5,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Cs7,4,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(B_5,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Cs7,4,0x000),
    DN(___,0,0x000),
    DN(B_5,3,0x000),
    DN(___,0,0x000),
    DN(Cs7,5,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(B_5,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(B_5,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Cs7,4,0x000),
    DN(___,0,0x000),
    DN(Cs7,5,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Cs7,4,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P4[] = {
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P8[] = {
    DN(C_4,2,0xC00),
    DN(C_4,2,0xC00),
    DN(C_4,2,0xC00),
    DN(C_4,2,0xC01),
    DN(C_4,2,0xC01),
    DN(C_4,2,0xC01),
    DN(C_4,2,0xC01),
    DN(C_4,2,0xC02),
    DN(C_4,2,0xC02),
    DN(C_4,2,0xC02),
    DN(C_4,2,0xC02),
    DN(C_4,2,0xC03),
    DN(C_4,2,0xC03),
    DN(C_4,2,0xC03),
    DN(C_4,2,0xC03),
    DN(C_4,2,0xC04),
    DN(C_4,2,0xC04),
    DN(C_4,2,0xC04),
    DN(C_4,2,0xC04),
    DN(C_4,2,0xC05),
    DN(C_4,2,0xC05),
    DN(C_4,2,0xC05),
    DN(C_4,2,0xC05),
    DN(C_4,2,0xC05),
    DN(C_4,2,0xC06),
    DN(C_4,2,0xC06),
    DN(C_4,2,0xC06),
    DN(C_4,2,0xC06),
    DN(C_4,2,0xC07),
    DN(C_4,2,0xC07),
    DN(C_4,2,0xC07),
    DN(C_4,2,0xC07),
    DN(C_4,2,0xC08),
    DN(C_4,2,0xC08),
    DN(C_4,2,0xC08),
    DN(C_4,2,0xC08),
    DN(C_4,2,0xC09),
    DN(C_4,2,0xC09),
    DN(C_4,2,0xC09),
    DN(C_4,2,0xC09),
    DN(C_4,2,0xC0A),
    DN(C_4,2,0xC0A),
    DN(C_4,2,0xC0A),
    DN(C_4,2,0xC0A),
    DN(C_4,2,0xC0A),
    DN(C_4,2,0xC0B),
    DN(C_4,2,0xC0B),
    DN(C_4,2,0xC0B),
    DN(C_4,2,0xC0B),
    DN(C_4,2,0xC0C),
    DN(C_4,2,0xC0C),
    DN(C_4,2,0xC0C),
    DN(C_4,2,0xC0C),
    DN(C_4,2,0xC0D),
    DN(C_4,2,0xC0D),
    DN(C_4,2,0xC0D),
    DN(C_4,2,0xC0D),
    DN(C_4,2,0xC0E),
    DN(C_4,2,0xC0E),
    DN(C_4,2,0xC0E),
    DN(C_4,2,0xC0E),
    DN(C_4,2,0xC0F),
    DN(C_4,2,0xC0F),
    DN(C_4,2,0xC0F),
};
static const unsigned char P9[] = {
    DN(___,0,0xD01),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds4,6,0xC00),
    DN(Ds4,6,0xC00),
    DN(Ds4,6,0xC01),
    DN(Ds4,6,0xC01),
    DN(Ds4,6,0xC02),
    DN(Ds4,6,0xC02),
    DN(Ds4,6,0xC03),
    DN(Ds4,6,0xC03),
    DN(Ds4,6,0xC04),
    DN(Ds4,6,0xC04),
    DN(Ds4,6,0xC05),
    DN(Ds4,6,0xC05),
    DN(Ds4,6,0xC06),
    DN(Ds4,6,0xC06),
    DN(Ds4,6,0xC07),
    DN(Ds4,6,0xC07),
    DN(Ds4,6,0xC08),
    DN(Ds4,6,0xC08),
    DN(Ds4,6,0xC09),
    DN(Ds4,6,0xC09),
    DN(Ds4,6,0xC0A),
    DN(Ds4,6,0xC0A),
    DN(Ds4,6,0xC0B),
    DN(Ds4,6,0xC0B),
    DN(Ds4,6,0xC0C),
    DN(Ds4,6,0xC0C),
    DN(Ds4,6,0xC0D),
    DN(Ds4,6,0xC0D),
    DN(Ds4,6,0xC0E),
    DN(Ds4,6,0xC0E),
    DN(Ds4,6,0xC0F),
    DN(Ds4,6,0xC0F),
};
static const unsigned char P10[] = {
    DN(C_4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(C_5,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0xC00),
    DN(G_4,1,0x000),
    DN(___,0,0xC00),
    DN(Fs4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(C_4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(C_5,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0xC00),
    DN(G_4,1,0x000),
    DN(___,0,0xC00),
    DN(Fs4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(C_4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(C_5,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0xC00),
    DN(G_4,1,0x000),
    DN(___,0,0xC00),
    DN(Fs4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(C_4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(C_5,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0xC00),
    DN(G_4,1,0x000),
    DN(___,0,0xC00),
    DN(Fs4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
};
static const unsigned char P11[] = {
    DN(___,0,0xF06),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xF05),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xF04),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xF03),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P12[] = {
    DN(B_5,6,0x102),
    DN(C_6,0,0x310),
    DN(C_6,0,0x310),
    DN(C_6,0,0x310),
    DN(C_6,0,0x310),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x443),
    DN(C_6,6,0x000),
    DN(___,0,0xA0F),
    DN(As5,6,0x000),
    DN(___,0,0xA0F),
    DN(Fs5,6,0x104),
    DN(G_5,0,0x310),
    DN(G_5,0,0x310),
    DN(___,0,0xA0F),
    DN(Fs5,6,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(F_5,6,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
};
static const unsigned char P13[] = {
    DN(B_4,6,0x104),
    DN(C_5,0,0x310),
    DN(C_5,0,0x310),
    DN(C_5,0,0x320),
    DN(C_5,0,0x320),
    DN(C_5,0,0x320),
    DN(C_5,0,0x320),
    DN(___,0,0x000),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(Ds6,6,0x000),
    DN(___,0,0xA0F),
    DN(F_6,6,0x000),
    DN(___,0,0xA0F),
};
static const unsigned char P14[] = {
    DN(Fs6,6,0x102),
    DN(G_6,0,0x310),
    DN(G_6,0,0x310),
    DN(G_6,0,0x3F0),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(As6,6,0x000),
    DN(___,0,0xA0F),
    DN(G_6,6,0x000),
    DN(___,0,0xA0F),
    DN(F_6,6,0x104),
    DN(Fs6,0,0x310),
    DN(Fs6,0,0x310),
    DN(___,0,0xA0F),
    DN(F_6,6,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As5,6,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
};
static const unsigned char P15[] = {
    DN(B_5,6,0x102),
    DN(C_6,0,0x310),
    DN(C_6,0,0x310),
    DN(C_6,0,0x310),
    DN(C_6,0,0x310),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0x443),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0x000),
    DN(___,0,0xA01),
    DN(___,0,0xB02),
};
static const unsigned char P17[] = {
    DN(C_5,2,0xC07),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(Ds5,2,0xC07),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(D_5,2,0xC07),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(___,0,0x047),
    DN(As4,2,0xC07),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
    DN(___,0,0x037),
};
static const unsigned char P18[] = {
    DN(C_4,1,0xF03),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(C_5,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0xC00),
    DN(G_4,1,0x000),
    DN(___,0,0xC00),
    DN(Fs4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(Ds4,1,0xF03),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(Ds5,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0xC00),
    DN(G_4,1,0x000),
    DN(___,0,0xC00),
    DN(Fs4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(D_4,1,0xF03),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(D_5,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0xC00),
    DN(G_4,1,0x000),
    DN(___,0,0xC00),
    DN(Fs4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As3,1,0xF03),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0x000),
    DN(___,0,0xA0F),
    DN(___,0,0xA0F),
    DN(As4,1,0x000),
    DN(___,0,0xC00),
    DN(As5,1,0x000),
    DN(___,0,0xC00),
    DN(As4,1,0x000),
    DN(___,0,0x000),
    DN(As6,1,0x000),
    DN(___,0,0x000),
};
static const unsigned char P19[] = {
    DN(A_5,2,0x000),
    DN(Gs5,2,0x000),
    DN(G_5,2,0x000),
    DN(Fs5,2,0x000),
    DN(F_5,2,0x000),
    DN(E_5,2,0x000),
    DN(Ds5,2,0x000),
    DN(D_5,2,0x000),
    DN(Cs5,2,0x000),
    DN(C_5,2,0x000),
    DN(As4,2,0x000),
    DN(A_4,2,0x000),
    DN(Gs4,2,0x000),
    DN(G_4,2,0x000),
    DN(Fs4,2,0x000),
    DN(F_4,2,0x000),
    DN(E_4,2,0x000),
    DN(Ds4,2,0x000),
    DN(D_4,2,0x000),
    DN(Cs4,2,0x000),
    DN(C_4,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P20[] = {
    DN(E_4,2,0x000),
    DN(F_4,2,0x000),
    DN(Fs4,2,0x000),
    DN(G_4,2,0x000),
    DN(Gs4,2,0x000),
    DN(A_4,2,0x000),
    DN(As4,2,0x000),
    DN(C_5,2,0x000),
    DN(Cs5,2,0x000),
    DN(D_5,2,0x000),
    DN(Ds5,2,0x000),
    DN(E_5,2,0x000),
    DN(F_5,2,0x000),
    DN(Fs5,2,0x000),
    DN(G_5,2,0x000),
    DN(Gs5,2,0x000),
    DN(A_5,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P21[] = {
    DN(C_4,7,0xC00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P22[] = {
    DN(As6,7,0xF03),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xD01),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P23[] = {
    DN(C_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(A_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Fs6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P24[] = {
    DN(C_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As5,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(B_5,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P25[] = {
    DN(C_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(As6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(A_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Fs6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_6,8,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(Ds6,8,0x000),
    DN(D_6,8,0x000),
    DN(Cs6,8,0x000),
    DN(C_6,8,0x000),
    DN(B_5,8,0x000),
    DN(As5,8,0x000),
    DN(A_5,8,0x000),
    DN(Gs5,8,0x000),
};

static const unsigned char* const order1[] = {P8,P0,P0,P0,P0,P0,P0,P0,P0,P19,P17,P17,P17,P17,P17,P17};
static const unsigned char* const order2[] = {P9,P1,P1,P12,P13,P14,P15,P1,P1,P20,P1,P1,P24,P23,P25,P4};
static const unsigned char* const order3[] = {P10,P2,P2,P2,P2,P2,P2,P2,P2,P21,P18,P18,P18,P18,P18,P2};
static const unsigned char* const order4[] = {P11,P3,P3,P3,P3,P3,P3,P3,P3,P22,P3,P3,P3,P3,P3,P3};

static const unsigned char duty_instruments[] = {
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,192,240,128,
8,128,240,128,
7,0,242,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
};
static const unsigned char wave_instruments[] = {
0,32,0,128,
0,32,1,128,
0,32,2,128,
0,32,3,128,
0,32,4,128,
0,32,5,128,
0,32,6,128,
0,32,7,128,
0,32,8,128,
0,32,9,128,
0,32,10,128,
0,32,11,128,
0,32,12,128,
0,32,13,128,
0,32,14,128,
};
static const unsigned char noise_instruments[] = {
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
241,104,0,0,0,0,0,0,
145,119,0,0,0,0,0,0,
242,41,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,40,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
};

static const unsigned char waves[] = {
    212,16,0,0,0,11,222,238,238,217,100,33,0,1,43,238,
    186,82,24,29,58,227,235,187,177,82,17,64,82,195,56,70,
    105,37,108,173,176,82,103,97,117,219,130,165,151,196,195,97,
    186,92,22,171,199,29,234,166,83,110,7,21,156,10,151,76,
    94,26,125,116,113,64,129,20,116,201,113,200,176,35,121,72,
    45,128,131,52,142,44,82,215,155,99,124,91,200,70,90,129,
    16,50,108,146,78,84,48,1,61,236,122,58,69,110,167,198,
    192,76,233,41,1,135,122,94,102,112,220,179,140,92,64,53,
    30,117,221,210,215,145,225,215,165,192,85,161,155,178,30,217,
    46,235,90,126,230,235,220,9,38,43,194,209,46,214,9,86,
    150,1,103,233,58,183,45,209,68,233,228,146,229,104,139,233,
    1,235,157,84,184,25,53,150,184,21,153,7,55,130,44,186,
    182,25,67,183,44,119,53,218,197,217,32,198,199,181,39,145,
    232,40,19,203,39,24,41,65,28,174,125,146,230,33,70,130,
    203,72,184,109,40,157,234,134,157,155,222,27,182,117,161,221,
    125,106,116,7,169,181,57,179,194,72,180,154,59,23,144,76,
};

const hUGESong_t wellerman = {7, &order_cnt, order1, order2, order3,order4, duty_instruments, wave_instruments, noise_instruments, NULL, waves};
