#pragma once
#include <JuceHeader.h>
using namespace juce;
using namespace dsp;
struct PreAmpProcessor  : public AudioProcessor
{
    vector
    float v1;
    float v2;
    enum {
        fftOrder  = 11,             
        fftSize   = 1 << fftOrder,  
        scopeSize = 512,
    };
    int samples_per_block;
    int sample_rate;

    PreAmpProcessor::PreAmpProcessor()
        : AudioProcessor (BusesProperties()
            .withInput  ("Input",  AudioChannelSet::stereo(), true)
            .withOutput ("Output", AudioChannelSet::stereo(), true)){ }
    ~PreAmpProcessor(){}

    void getStateInformation(MemoryBlock& destData){ }
    void setStateInformation(const void* data, int sizeInBytes){ }

    void prepareToPlay(double sampleRate, int samplesPerBlock){
        samples_per_block = samplesPerBlock;
        sample_rate = sampleRate;
    }

    void releaseResources(){

    }

    void PreAmpProcessor::processBlock(AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages){
        ScopedNoDenormals noDenormals;
        int in_num  = getTotalNumInputChannels();
        int out_num = getTotalNumOutputChannels();


        buffer.applyGain(0, samples_per_block, v1);
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

