#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
using namespace juce;

const int s1_size = 200;
struct PreAmpEditor  : public AudioProcessorEditor{
    PreAmpProcessor& audioProcessor;
    Slider s1;
    PreAmpEditor(PreAmpProcessor& p) : AudioProcessorEditor(&p), audioProcessor(p)
    {
        setResizable (true, true);
        setSize(800, 600);
        {
            addAndMakeVisible(s1);
            s1.setRange(0.0, 100.0, 0.1);
            s1.setValue(50.0, dontSendNotification);
            s1.setSliderStyle(Slider::RotaryVerticalDrag);
            s1.setTextBoxStyle(Slider::NoTextBox, false, 100, 20);            
            s1.onValueChange = [this] {
                audioProcessor.v1 = s1.getValue();
            };
        }

        resized();
    }

    PreAmpEditor::~PreAmpEditor(){}

    void paint(Graphics& g) {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

        g.setColour(Colours::white);
        g.setFont(15.0f);
    }

    void resized(){
        s1.centreWithSize(s1_size ,s1_size);

        // This is generally where you'll want to lay out the positions of any
        // subcomponents in your editor..
    }



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PreAmpEditor)
};


