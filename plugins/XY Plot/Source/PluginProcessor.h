/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

using namespace juce::dsp;

class PluginEditor;

#define PARAM_MODE     "mode"
#define PARAM_LOG      "log"

//==============================================================================
/**
*/
class PluginProcessor : public gin::GinProcessor
{
public:
    //==============================================================================
    PluginProcessor();
    ~PluginProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    
    CriticalSection lock;
    PluginEditor* editor = nullptr;

private:    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginProcessor)
};
