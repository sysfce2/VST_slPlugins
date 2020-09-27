/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

using namespace gin;

//==============================================================================
AddInvertAudioProcessorEditor::AddInvertAudioProcessorEditor (AddInvertAudioProcessor& p)
    : gin::ProcessorEditor (p), aiProcessor (p)
{
    addAndMakeVisible (&scope);
    
    setGridSize (4, 2);
    
    scope.setNumChannels (2);
    scope.setNumSamplesPerPixel (2);
    scope.setVerticalZoomFactor (1.0f);
}

AddInvertAudioProcessorEditor::~AddInvertAudioProcessorEditor()
{
}

//==============================================================================
void AddInvertAudioProcessorEditor::resized()
{
    gin::ProcessorEditor::resized();

    scope.setBounds (getGridArea (0, 0, 4, 2));
}
