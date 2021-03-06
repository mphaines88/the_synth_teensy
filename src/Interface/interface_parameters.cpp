//
// Created by michael on 11/9/19.
//

#include <stdint.h>
#include <system/HD44780.h>
#include "interface_parameters.h"
#include "interface.h"
#include "interface_patches.h"

struct interfaceParam_s{
    interfaceParamType_e type;
    uint8_t number;
    const char * shortName;
    const char * longName;
    const char * values[8];
};

const struct interfaceParam_s interfaceParameters[PARAMETER_PAGES][8] = {
        {
                {.type=parameterCont, .number=oscAfreq, .shortName="AFrq", .longName="Osc A Frequancy", .values={""}},
                {.type=parameterCont, .number=oscACrse, .shortName="ACrs", .longName="Osc A Coarse", .values={""}},
                {.type=parameterCont, .number=oscAVol, .shortName="AVol", .longName="Osc A Volume", .values={""}},
                {.type=parameterCont, .number=oscAMod, .shortName="AMod", .longName="Osc A Lfo Mod", .values={""}},
                {.type=parameterCont, .number=oscARamp, .shortName="ARmp", .longName="Osc A Ramp Mod", .values={""}},
                {.type=parameterStep, .number=spOscSync, .shortName="Sync", .longName="Osc Sync", .values={"Off ", "Hard", "Ring", "Soft"}},
                {.type=parameterStep, .number=spOscAWave, .shortName="Awav", .longName="Osc A Waveform", .values={""}},
                {.type=parameterStep, .number=spOscATyp, .shortName="Type", .longName="Osc A Type", .values={"Smpl", "Wave"}},
        },
        {
                {.type=parameterCont, .number=oscBfreq, .shortName="BFrq", .longName="Osc B Frequancy", .values={""}},
                {.type=parameterCont, .number=oscBCrse, .shortName="BCrs", .longName="Osc B Coarse", .values={""}},
                {.type=parameterCont, .number=oscBVol, .shortName="BVol", .longName="Osc B Volume", .values={""}},
                {.type=parameterCont, .number=oscBMod, .shortName="BMod", .longName="Osc B Lfo Mod", .values={""}},
                {.type=parameterCont, .number=oscBRamp, .shortName="BRmp", .longName="Osc B Ramp Mod", .values={""}},
                {.type=parameterCont, .number=oscFMMod, .shortName="Fmod", .longName="Osc B FM Mod", .values={""}},
                {.type=parameterStep, .number=spOscBWave,.shortName="Bwav", .longName="Osc B Waveform", .values={""}},
                {.type=parameterStep, .number=spOscBTyp, .shortName="Type", .longName="Osc B Type", .values={"Smpl", "Wave"}},
        },
        {
                {.type=parameterCont, .number=oscAStart, .shortName="AStt", .longName="Osc A Tbl Strt", .values={""}},
                {.type=parameterCont, .number=oscAWvLfo, .shortName="AWMd", .longName="Osc A Wave Mod", .values={""}},
                {.type=parameterCont, .number=oscAWvRmp, .shortName="AWRp", .longName="Osc A Wave Rmp", .values={""}},
                {.type=parameterNone,},
                {.type=parameterCont, .number=oscBStart, .shortName="BStt", .longName="Osc B Tbl Strt", .values={""}},
                {.type=parameterCont, .number=oscBWvLfo, .shortName="BWMd", .longName="Osc B Wave Mod", .values={""}},
                {.type=parameterCont, .number=oscBWvRmp, .shortName="BWRp", .longName="Osc B Wave Rmp", .values={""}},
                {.type=parameterNone,},
        },
        {
                {.type=parameterCont, .number=fltrCutoff, .shortName="FCut", .longName="Filter Cutoff", .values={""}},
                {.type=parameterCont, .number=fltrResonance, .shortName="FRes", .longName="Filter Resonance", .values={""}},
                {.type=parameterCont, .number=fltrEnvMnt, .shortName="FEnv", .longName="Filter Env Amount", .values={""}},
                {.type=parameterCont, .number=fltrMod, .shortName="FMod", .longName="Filter Modulation", .values={""}},
                {.type=parameterNone},
                {.type=parameterNone},
                {.type=parameterNone},
                {.type=parameterNone},
        },
        {
                {.type=parameterCont, .number=fltrAtt, .shortName="FAtk", .longName="Filter Attack", .values={""}},
                {.type=parameterCont, .number=fltrDec, .shortName="FDec", .longName="Filter Decay", .values={""}},
                {.type=parameterCont, .number=fltrSus, .shortName="FSus", .longName="Filter Sustain", .values={""}},
                {.type=parameterCont, .number=fltrRel, .shortName="FRel", .longName="Filter Release", .values={""}},
                {.type=parameterCont, .number=fltrAmp, .shortName="FAmp", .longName="Filter Env Amp", .values={""}},
                {.type=parameterStep, .number=spFltrEnvTrig, .shortName="FTrg", .longName="Filter Env Trig", .values={"Sngl", "Mlti"}},
                {.type=parameterStep, .number=spFltrEnvSpd, .shortName="FSpd", .longName="Filter Env Speed", .values={"Fast", "Slow"}},
                {.type=parameterNone},
        },
        {
                {.type=parameterCont, .number=AmpAtt, .shortName="AAtk", .longName="Ampitude Attack", .values={""}},
                {.type=parameterCont, .number=AmpDec, .shortName="ADec", .longName="Amplitude Decay", .values={""}},
                {.type=parameterCont, .number=AmpSus, .shortName="ASus", .longName="Amplitude Sustain", .values={""}},
                {.type=parameterCont, .number=AmpRel, .shortName="ARel", .longName="Amplitude Release", .values={""}},
                {.type=parameterCont, .number=AmpAmp, .shortName="AAmp", .longName="Amplitude Env Amp", .values={""}},
                {.type=parameterStep, .number=spAmpEnvTrig, .shortName="ATrg", .longName="Amplitude Env Trig", .values={"Sngl","Mlti"}},
                {.type=parameterStep, .number=spAmpEnvSpd, .shortName="ASpd", .longName="Amplitude Env Speed", .values={"Fast", "Slow"}},
                {.type=parameterNone},
        },
        {
                {.type=parameterCont, .number=AuxAtt, .shortName="XAtk", .longName="Auxiliry Attack", .values={""}},
                {.type=parameterCont, .number=AuxDec, .shortName="XDec", .longName="Auxiliry Decay", .values={""}},
                {.type=parameterCont, .number=AuxSus, .shortName="XSus", .longName="Auxiliry Sustain", .values={""}},
                {.type=parameterCont, .number=AuxRel, .shortName="XRel", .longName="Auxiliry Release", .values={""}},
                {.type=parameterCont, .number=AuxAmp, .shortName="XAmp", .longName="Auxiliry Env Amp", .values={""}},
                {.type=parameterStep, .number=spAuxEnvTrig, .shortName="XTrg", .longName="Auxiliry Env Trig", .values={"Sngl", "Mlti"}},
                {.type=parameterStep, .number=spAuxEnvSpd, .shortName="XSpd", .longName="Auxiliry Env Speed", .values={"Fast", "Slow"}},
                {.type=parameterNone},
        },
        {
                {.type=parameterCont, .number=lfoAPitch, .shortName="AAmp", .longName="LFO A Amplitude", .values={""}},
                {.type=parameterCont, .number=lfoARate, .shortName="ARte", .longName="LFO A Rate", .values={""}},
                {.type=parameterStep, .number=spLfoAShape, .shortName="AShp", .longName="LFO A Shape", .values={"Sqr ","Tri ", "Saw ", "Sine"}},
                {.type=parameterStep, .number=spLfoAspeed, .shortName="Aspd", .longName="LFO A Speed", .values={"Fast", "Slow"}},
                {.type=parameterStep, .number=spLfoATrk, .shortName="ATrk", .longName="LFO A Tracking", .values={"Off ", "On  "}},
                {.type=parameterStep, .number=spLfoATrig, .shortName="ATrg", .longName="LFO A Trig", .values={"Sngl", "Mlti"}},
                {.type=parameterCont, .number=rampRate, .shortName="RRte", .longName="Ramp Rate", .values={""}},
                {.type=parameterNone, },
        },
        {
                {.type=parameterCont, .number=lfoBPitch, .shortName="BAmp", .longName="LFO B Amplitude", .values={""}},
                {.type=parameterCont, .number=lfoBRate, .shortName="BRte", .longName="LFO B Rate", .values={""}},
                {.type=parameterStep, .number=spLfoBShape, .shortName="BShp", .longName="LFO B Shape", .values={"Sqr ", "Tri ", "Saw ", "Sine" }},
                {.type=parameterStep, .number=spLfoBspeed, .shortName="Bspd", .longName="LFO B Speed", .values={"Fast", "Slow"}},
                {.type=parameterStep, .number=spLfoBTrk, .shortName="BTrk", .longName="LFO B Tracking", .values={"Off ", "On  "}},
                {.type=parameterStep, .number=spLfoBTrig, .shortName="BTrg", .longName="LFO B Trig", .values={"Sngl", "Mlti"}},
                {.type=parameterNone},
                {.type=parameterNone},
        },
};

uint8_t interfaceParameterHandleUserInput(int8_t input, uint16_t pot_value, uint8_t paramPage) {


    //Serial.print("Update Parameters: ");
    //Serial.print(input);
    //Serial.print(", ");
    //Serial.println(pot_value);
    switch (input){
        case 3:{
            interfacePatchesSavePatch(patchInfo.number);

            lcdClearScreen();
            lcdChangePos(0,0);
            interfacePatchesSavePatch(patchInfo.number);
            lcdSendCharArray((char *) "Saving Patch");
            delay(3000);

            interfaceParameterUpdatePage(paramPage);
            return 0;
        }
        case 4:{
            //interfacePatchesSetWriteProtect(static_cast<uint8_t>(!patchInfo.writeProtect));

            lcdClearScreen();
            lcdChangePos(0,0);
            interfacePatchesInitPatch(patchInfo.number);
            lcdSendCharArray((char *) "Initializing Patch");
            delay(3000);

            interfaceParameterUpdatePage(paramPage);
            return 0;
        }
        case 5:{
            interfacePatchesUpdateName(10);
            return 1;
        }
        default:break;
    }

    if (input < 0) {

        input = -input - 1;

        uint8_t parameterNumber = interfaceParameters[paramPage][input].number;

        static char dv[5] = {0};
        switch (interfaceParameters[paramPage][input].type) {
            case parameterNone:
                return 0;
            case parameterCont:
                cpParameterList[parameterNumber] = pot_value;
                sprintf(dv, "%4d", cpParameterList[parameterNumber] >> 8);
                break;
            case parameterStep: {
                uint8_t v = pot_value >> (16 - spParameterBits[parameterNumber]);
                spParameterList[parameterNumber] = v;
                if (!(interfaceParameters[paramPage][input].number == spOscAWave ||
                      interfaceParameters[paramPage][input].number == spOscBWave)) {

                    sprintf(dv, "%4s", interfaceParameters[paramPage][input].values[spParameterList[parameterNumber]]);

                } else {
                    sprintf(dv, "%4d", spParameterList[parameterNumber]);
                }
                break;
            }
            default:
                break;
        }
        if (input < NUM_OF_POTS / 2) {
            lcdChangePos(input * 5, 1);
        } else {
            lcdChangePos((input - 4) * 5, 3);
        }
        lcdSendCharArray(dv);
    }

    return 0;
}

void interfaceParameterUpdatePage(uint8_t paramPage) {

    lcdCmd(0x01);
    delay(2);
    const char *space = " ";
    lcdChangePos(0, 0);
    for (int i = 0; i < 4; ++i) {
        //sprintf(dv, "%-4s", interfaceParameters[interface.param_page][i].shortName);
        if (interfaceParameters[paramPage][i].type != parameterNone) {
            lcdSendCharArray(interfaceParameters[paramPage][i].shortName);
            lcdSendCharArray(space);
        }
    }

    lcdChangePos(0, 1);
    for (int i = 0; i < 4; ++i) {
        static char dv[5] = {0};
        //sprintf(dv, "%-4s", interfaceParameters[interface.param_page][i].shortName);
        if (interfaceParameters[paramPage][i].type == parameterCont) {
            sprintf(dv, "%4d", cpParameterList[interfaceParameters[paramPage][i].number] >> 8);
            lcdSendCharArray(dv);
            lcdSendCharArray(space);
        } else if (interfaceParameters[paramPage][i].type == parameterStep) {
            //sprintf(dv, "%4d", interfaceParameters[interface.param_page][i].values[spParameterList[interfaceParameters[interface.param_page][i].number]]);
            lcdSendCharArray(
                    interfaceParameters[paramPage][i].values[spParameterList[interfaceParameters[paramPage][i].number]]);
            lcdSendCharArray(space);
        }
    }

    lcdChangePos(0, 2);
    for (int i = 4; i < 8; ++i) {
        if (interfaceParameters[paramPage][i].type != parameterNone) {
            lcdSendCharArray(interfaceParameters[paramPage][i].shortName);
            lcdSendCharArray(space);
        }
    }

    lcdChangePos(0, 3);
    for (int i = 4; i < 8; ++i) {
        static char dv[5] = {0};
        //sprintf(dv, "%-4s", interfaceParameters[interface.param_page][i].shortName);
        if (interfaceParameters[paramPage][i].type == parameterCont) {
            sprintf(dv, "%4d", cpParameterList[interfaceParameters[paramPage][i].number] >> 8);
            lcdSendCharArray(dv);
            lcdSendCharArray(space);
        } else if (interfaceParameters[paramPage][i].type == parameterStep) {
            //sprintf(dv, "%4d", spParameterList[interfaceParameters[interface.param_page][i].number]);
            if (!(interfaceParameters[paramPage][i].number == spOscAWave ||
                  interfaceParameters[paramPage][i].number == spOscBWave)) {
                //lcdSendCharArray(interfaceParameters[paramPage][i].values[spParameterList[interfaceParameters[paramPage][i].number]]);
                sprintf(dv, "%4s", interfaceParameters[paramPage][i].values[spParameterList[interfaceParameters[paramPage][i].number]]);
            }else{
                sprintf(dv, "%4d", spParameterList[interfaceParameters[paramPage][i].number]);
            }
            lcdSendCharArray(dv);
            lcdSendCharArray(space);
        }
    }
}

