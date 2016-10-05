/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "slCommon.h"
#include "crossfeed.h"

#define PARAM_ENABLE        "enable"

//==============================================================================
/**
*/
class slCrossfeedAudioProcessor : public slProcessor
{
public:
    //==============================================================================
    slCrossfeedAudioProcessor();
    ~slCrossfeedAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    
    LevelTracker& getOutputLevel() { return outputLevel; }

private:
    LevelTracker outputLevel {48.0};
    LinearSmoothedValue<float> enableVal;
    LinearSmoothedValue<float> disableVal;
    
    AudioSampleBuffer scratch;
    
    crossfeed_t crossfeed;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (slCrossfeedAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
