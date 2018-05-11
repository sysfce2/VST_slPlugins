/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

using namespace juce::dsp;

class MathsAudioProcessorEditor;
//==============================================================================
/**
*/
class MathsAudioProcessor : public gin::GinProcessor
{
public:
    //==============================================================================
    MathsAudioProcessor();
    ~MathsAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    String lEquation = "(l + r) / 2", rEquation = "(l + r) / 2";
    bool refreshEquations = false;

private:
    //==============================================================================
    void setupParsers();
    
    gin::EquationParser lParser, rParser;
    double l = 0, r = 0;
    
    Component::SafePointer<MathsAudioProcessorEditor> editor;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MathsAudioProcessor)
};
