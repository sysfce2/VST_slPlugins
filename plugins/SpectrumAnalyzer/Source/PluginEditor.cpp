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
PluginEditor::PluginEditor (PluginProcessor& p)
    : GinAudioProcessorEditor (p), proc (p)
{
    addAndMakeVisible (&scopeL);
    addAndMakeVisible (&scopeR);

    addAndMakeVisible (&sonogramL);
    addAndMakeVisible (&sonogramR);
    
    thread.addTimeSliceClient (&scopeL);
    thread.addTimeSliceClient (&scopeR);
    thread.addTimeSliceClient (&sonogramL);
    thread.addTimeSliceClient (&sonogramR);
    thread.startThread();
    
    scopeL.setColour (drow::Spectroscope::traceColourId, Colours::white.overlaidWith (Colours::blue.withAlpha (0.3f)));
    scopeR.setColour (drow::Spectroscope::traceColourId, Colours::white.overlaidWith (Colours::yellow.withAlpha (0.3f)));
    
    for (Parameter* pp : p.getPluginParameters())
    {
        ParamComponent* pc;
        
        if (pp->getUid() == PARAM_MODE)
            pc = new Select (pp);
        else if (pp->isOnOff())
            pc = new Switch (pp);
        else
            pc = new Knob (pp);
        
        addAndMakeVisible (pc);
        controls.add (pc);
    }
    
    setGridSize (7, 4);
    makeResizable (getWidth(), getHeight(), 2000, 1500);
    
    for (auto pp : proc.getPluginParameters())
        pp->addListener (this);
    
    updateScope();
}

PluginEditor::~PluginEditor()
{
    for (auto pp : proc.getPluginParameters())
        pp->removeListener (this);
    
    ScopedLock sl (proc.lock);
    proc.editor = nullptr;
}

//==============================================================================

Rectangle<int> PluginEditor::getGridArea (int x, int y, int w, int h)
{
    return Rectangle<int> (getWidth() - inset - cx + x * cx, headerHeight + y * cy + inset, w * cx, h * cy);
}

void PluginEditor::resized()
{
    GinAudioProcessorEditor::resized();

    auto rc = Rectangle<int> (inset, headerHeight + inset, getWidth() - cx - 2 * inset, getHeight() - headerHeight - 2 * inset);
    
    scopeL.setBounds (rc);
    scopeR.setBounds (rc);

    if (processor.getTotalNumInputChannels() == 1)
    {
        sonogramL.setBounds (rc);
        sonogramR.setBounds (Rectangle<int>());
    }
    else
    {
        int h = (rc.getHeight() - inset) / 2;
        sonogramL.setBounds (rc.removeFromTop (h));
        sonogramR.setBounds (rc.removeFromBottom (h));
    }
    
    componentForId (PARAM_MODE)->setBounds (getGridArea (0, 0));
    componentForId (PARAM_LOG)->setBounds (getGridArea (0, 1));
}

void PluginEditor::updateScope()
{
    int mode = proc.parameterIntValue (PARAM_MODE);
    
    scopeL.setVisible (mode == 0);
    scopeR.setVisible (mode == 0);
    
    sonogramL.setVisible (mode == 1);
    sonogramR.setVisible (mode == 1);
    
    bool log = proc.parameterIntValue (PARAM_LOG) != 0;
    
    scopeL.setLogFrequencyDisplay (log);
    scopeR.setLogFrequencyDisplay (log);
    sonogramL.setLogFrequencyDisplay (log);
    sonogramR.setLogFrequencyDisplay (log);
}
