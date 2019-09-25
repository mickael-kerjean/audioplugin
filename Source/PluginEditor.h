/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AudioPluginLearning0AudioProcessorEditor  : public AudioProcessorEditor,
                                                  private Slider::Listener
{
public:
    AudioPluginLearning0AudioProcessorEditor (AudioPluginLearning0AudioProcessor&);
    ~AudioPluginLearning0AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
private:
    Slider inputSlider, outputSlider, offsetSlider;
    AudioPluginLearning0AudioProcessor& processor;

    void sliderValueChanged (Slider* slider) override {
        if (slider == &inputSlider){
            processor.UIInput = slider->getValue();
        } else if(slider == &outputSlider){
            processor.UIOutput = slider->getValue();
        } else if(slider == &offsetSlider){
            processor.UIOffset = slider->getValue();            
        }
    };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginLearning0AudioProcessorEditor)
};
