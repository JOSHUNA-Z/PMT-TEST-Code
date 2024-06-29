#include "AnalyzeWaveform.h"

int Analysis(const char* Filename)
{
    AnalyzeWaveform aw;
    aw.GetFileName(Filename);
    aw.read_data();    


    return 0;
}