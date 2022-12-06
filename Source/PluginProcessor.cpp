#include "PluginProcessor.h"
#include "PluginEditor.h"

AudioProcessorEditor* PreAmpProcessor::createEditor(){
    return new PreAmpEditor (*this);
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter(){
    return new PreAmpProcessor();
}
