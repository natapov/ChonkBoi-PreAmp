#pragma once
#include <JuceHeader.h>
using namespace juce;
using namespace dsp;
struct PreAmpProcessor  : public AudioProcessor
{
    float v1;
    float v2;
    enum {
        fftOrder  = 11,             
        fftSize   = 1 << fftOrder,  
        scopeSize = 512,
    };

    PreAmpProcessor::PreAmpProcessor()
        : AudioProcessor (BusesProperties()
            .withInput  ("Input",  AudioChannelSet::stereo(), true)
            .withOutput ("Output", AudioChannelSet::stereo(), true)){ }
            
    ~PreAmpProcessor(){}

    void getStateInformation(MemoryBlock& destData){ }
    void setStateInformation(const void* data, int sizeInBytes){ }

    void prepareToPlay(double sampleRate, int samplesPerBlock){
    }

    void releaseResources(){
    }

    void PreAmpProcessor::processBlock(AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages){
        ScopedNoDenormals noDenormals;
        int in_num  = getTotalNumInputChannels();
        int out_num = getTotalNumOutputChannels();

        //jassert(in_num  == 2);
        //jassert(out_num == 2);
        for(int i = 0; i < out_num; ++i){
           // buffer.clear(i, 0, buffer.getNumSamples());
        }

    }
    
    AudioProcessorEditor* createEditor() override;
    const String getName() const {return JucePlugin_Name;}
    const String getProgramName(int id) {return {};}
    bool hasEditor() const {return true;}
    bool acceptsMidi()  const {return false;}
    bool producesMidi() const {return false;}
    bool isMidiEffect() const {return false;}
    double getTailLengthSeconds() const {return 0;}
    int getNumPrograms() {return 1;}
    int getCurrentProgram() {return 0;}
    void setCurrentProgram (int id) {}
    void changeProgramName (int id, const String& s){}
    bool isBussesLayoutSupported(const BusesLayout& layouts) const {return true;}
    AudioProcessor* JUCE_CALLTYPE createPluginFilter();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PreAmpProcessor)
};

