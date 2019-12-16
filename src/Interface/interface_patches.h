//
// Created by michael on 11/9/19.
//

#ifndef THE_SYNTH_TEENSY_INTERFACE_PATCHES_H
#define THE_SYNTH_TEENSY_INTERFACE_PATCHES_H

#include <stdint.h>

#define EEPROM_SIZE 32000
#define EEPROM_RESERVED 6400
#define EEPROM_DATA_BUFFER 64
#define EEPROM_NUM_OF_PATCHES (EEPROM_SIZE - EEPROM_RESERVED)/128
#define PATCH_NAME_LENGTH 8

struct patch_struct_t {
    char * name[PATCH_NAME_LENGTH];
    uint8_t number;
    uint8_t writeProtect;
};

extern patch_struct_t patchInfo;

int8_t interfacePatchesInitSystem();
int8_t interfacePatchesInitPatch(uint8_t patch);
int8_t interfacePatchesLoadPatch(uint8_t patch);
int8_t interfacePatchesSavePatch(uint8_t patch);
void interfacePatchesUpdatePage(uint8_t patch);

#endif //THE_SYNTH_TEENSY_INTERFACE_PATCHES_H