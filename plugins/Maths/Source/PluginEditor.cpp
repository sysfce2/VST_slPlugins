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
MathsAudioProcessorEditor::MathsAudioProcessorEditor (MathsAudioProcessor& p)
    : GinAudioProcessorEditor (p), mathsProcessor (p)
{
    addAndMakeVisible (l);
    addAndMakeVisible (r);
    addAndMakeVisible (lLabel);
    addAndMakeVisible (rLabel);

    l.addListener (this);
    r.addListener (this);
    
    l.setText (p.lEquation, dontSendNotification);
    r.setText (p.rEquation, dontSendNotification);
    
    int count = 0;
    for (Parameter* pp : p.getPluginParameters())
    {
        if (count == 4)
        {
            auto* pc = new Switch (pp);
            addAndMakeVisible (pc);
            controls.add (pc);
        }
        else
        {
            auto* pc = new Knob (pp, count == 2 || count == 3);
            addAndMakeVisible (pc);
            controls.add (pc);
        }
        
        count++;
    }
    
    setGridSize (9, 1);
}

MathsAudioProcessorEditor::~MathsAudioProcessorEditor()
{
}

//==============================================================================
void MathsAudioProcessorEditor::refresh()
{
    l.setText (mathsProcessor.lEquation, dontSendNotification);
    r.setText (mathsProcessor.rEquation, dontSendNotification);
}

void MathsAudioProcessorEditor::resized()
{
    GinAudioProcessorEditor::resized();
    
    componentForId (PARAM_P1)->setBounds (getGridArea (4, 0));
    componentForId (PARAM_P2)->setBounds (getGridArea (5, 0));
    componentForId (PARAM_P3)->setBounds (getGridArea (6, 0));
    componentForId (PARAM_P4)->setBounds (getGridArea (7, 0));
    componentForId (PARAM_LIMITER)->setBounds (getGridArea (8, 0));
    
    auto rc = getGridArea (0, 0, 4, 1);
    rc = rc.withSizeKeepingCentre(rc.getWidth() - 4, 54);
    
    auto rcLabels = rc.removeFromLeft (50);
    lLabel.setBounds (rcLabels.removeFromTop (25));
    rLabel.setBounds (rcLabels.removeFromBottom (25));

    l.setBounds (rc.removeFromTop (25));
    r.setBounds (rc.removeFromBottom (25));
}

void MathsAudioProcessorEditor::textEditorReturnKeyPressed (TextEditor& ed)
{
    if (&ed == &l)
    {
        mathsProcessor.lEquation = ed.getText();
        mathsProcessor.setupParsers();
    }
    else if (&ed == &r)
    {
        mathsProcessor.rEquation = ed.getText();
        mathsProcessor.setupParsers();
    }
}

void MathsAudioProcessorEditor::textEditorEscapeKeyPressed (TextEditor& ed)
{
    if (&ed == &l)
        l.setText (mathsProcessor.lEquation, dontSendNotification);
    else if (&ed == &r)
        r.setText (mathsProcessor.rEquation, dontSendNotification);
}

void MathsAudioProcessorEditor::textEditorFocusLost (TextEditor& ed)
{
    textEditorReturnKeyPressed (ed);
}

