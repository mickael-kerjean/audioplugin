/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginLearning0AudioProcessor::AudioPluginLearning0AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

AudioPluginLearning0AudioProcessor::~AudioPluginLearning0AudioProcessor()
{
}

//==============================================================================
const String AudioPluginLearning0AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AudioPluginLearning0AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AudioPluginLearning0AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AudioPluginLearning0AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AudioPluginLearning0AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AudioPluginLearning0AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AudioPluginLearning0AudioProcessor::getCurrentProgram()
{
    return 0;
}

void AudioPluginLearning0AudioProcessor::setCurrentProgram (int index)
{
}

const String AudioPluginLearning0AudioProcessor::getProgramName (int index)
{
    return {};
}

void AudioPluginLearning0AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AudioPluginLearning0AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void AudioPluginLearning0AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AudioPluginLearning0AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AudioPluginLearning0AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);
        
        for(int sample = 0; sample<buffer.getNumSamples(); ++sample){
            *channelData *= UIInput;
            
            // arctan non linearity
            //*channelData = (2.f / float_Pi) * atan(*channelData) + UIOffset;
            
            // cubic soft clipper
            //std::cout << "====" << std::endl;
            //std::cout << *channelData << std::endl;

            if(*channelData >= 1){ *channelData = 2.f / 3; }
            else if(*channelData <= -1){ *channelData = -2.f / 3; }
            else{
                *channelData = *channelData - pow(*channelData, 3) / 3;
            }
            
            *channelData += UIOffset;
            *channelData *= UIOutput;
            if(*channelData > 1 || *channelData < -1){
                std::cout << "WARNING: CLIPPING" <<std::endl;
            }
            //std::cout << *channelData << std::endl;
            
            *channelData++;
        }
    }
}

//==============================================================================
bool AudioPluginLearning0AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AudioPluginLearning0AudioProcessor::createEditor()
{
    return new AudioPluginLearning0AudioProcessorEditor (*this);
}

//==============================================================================
void AudioPluginLearning0AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AudioPluginLearning0AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AudioPluginLearning0AudioProcessor();
}
