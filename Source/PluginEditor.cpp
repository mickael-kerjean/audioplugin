/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginLearning0AudioProcessorEditor::AudioPluginLearning0AudioProcessorEditor (AudioPluginLearning0AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    addAndMakeVisible(inputSlider);
    inputSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    inputSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    inputSlider.setRange(0, 50);
    inputSlider.setValue(1);
    inputSlider.setSkewFactorFromMidPoint(1);
    inputSlider.addListener(this);
    
    addAndMakeVisible(outputSlider);
    outputSlider.setSliderStyle(Slider::SliderStyle::Rotary);
    outputSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    outputSlider.setRange(0, 3);
    outputSlider.setValue(1);
    outputSlider.addListener(this);
    
    addAndMakeVisible(offsetSlider);
    offsetSlider.setRange(0, 50);
    offsetSlider.setValue(0);
    offsetSlider.addListener(this);
}

AudioPluginLearning0AudioProcessorEditor::~AudioPluginLearning0AudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginLearning0AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void AudioPluginLearning0AudioProcessorEditor::resized()
{
    const int padding = 20;
    const int rotarySize = 70;
    inputSlider.setBounds(padding, padding, rotarySize, rotarySize);
    outputSlider.setBounds(getWidth() - rotarySize - padding, padding, rotarySize, rotarySize);
    offsetSlider.setBounds(padding, padding*4, getWidth() - 2*padding, 100);
}
