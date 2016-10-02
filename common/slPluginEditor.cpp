#include "slPluginEditor.h"
#include "slLookAndFeel.h"

slAudioProcessorEditor::slAudioProcessorEditor (slProcessor& p) noexcept
  : AudioProcessorEditor (p)
{
    setLookAndFeel (slLookAndFeel::getInstance());
}

slAudioProcessorEditor::slAudioProcessorEditor (slProcessor* p) noexcept
  : AudioProcessorEditor (p)
{
    setLookAndFeel (slLookAndFeel::getInstance());
}

void slAudioProcessorEditor::paint (Graphics& g)
{
    
}