/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "slCommon.h"

//==============================================================================
/**
*/
class slToneAudioProcessorEditor  : public slAudioProcessorEditor
{
public:
    slToneAudioProcessorEditor (slToneAudioProcessor&);
    ~slToneAudioProcessorEditor();

    //==============================================================================
    void resized() override;
    void paint(Graphics& g) override;

private:
    slToneAudioProcessor& processor;
    
    OwnedArray<PluginSlider> sliders;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (slToneAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
