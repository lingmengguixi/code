#pragma once

#include <Ws2spi.h>
#include <nspapi.h>
#include <Mswsock.h>
#include <stdio.h>
int haha();
bool myinit();
void tip(const wchar_t *s);
void AnsiToUnicode(const char* szStr, wchar_t* pResult);
