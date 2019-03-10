#include "stdafx.h"
#include "../Core/Console.h"
#include "../Core/IAudioDevice.h"
#include "../Core/EmuSettings.h"
#include "../Core/SettingTypes.h"

extern shared_ptr<Console> _console;
extern unique_ptr<IAudioDevice> _soundManager;
static string _returnString;

extern "C" {
	DllExport void __stdcall SetVideoConfig(VideoConfig config)
	{
		_console->GetSettings()->SetVideoConfig(config);
	}

	DllExport void __stdcall SetAudioConfig(AudioConfig config)
	{
		_console->GetSettings()->SetAudioConfig(config);
	}
	
	DllExport const char* __stdcall GetAudioDevices()
	{
		_returnString = _soundManager ? _soundManager->GetAvailableDevices() : "";
		return _returnString.c_str();
	}
}