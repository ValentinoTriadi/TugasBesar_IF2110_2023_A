#ifndef DRAF_H
#define DRAF_H
#include "stack.h"
#include <stdio.h>

extern Stack Draf;

void CreateDraft();
void ViewLastDraft();
void UpdateDraft();
void DeleteDraft();
void PublishDraft();

#endif