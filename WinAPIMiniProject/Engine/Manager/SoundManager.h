#pragma once

#ifndef _WIN64
#include "Engine/FMOD/fmod.hpp"
#pragma comment (lib, "Engine/FMOD/fmod_vc.lib")
#endif
#ifdef _WIN64
#include "Engine/FMOD/fmod.hpp"
#pragma comment (lib, "Engine/FMOD/fmod_vc.lib")
#endif

class SoundManager : public Singleton<SoundManager>
{
private:

	friend class Singleton;
	SoundManager() = default;
	~SoundManager() = default;

public:

	void Initialize();
	void Update();
	void Finalize();

	void AddSound(SoundList _sound, const char* _path, bool _loop = false);
	void SoundPlay(SoundList _sound, SoundChannel _ch);
	void SoundcutPlay(SoundList _sound, SoundChannel _ch);
	void SoundStop(SoundChannel _ch);
	void SetVolume(int _val);
	int GetVolume() { return volume; }

private:

	int volume = 50;

	FMOD::System*  soundSystem = nullptr;
	FMOD::Channel* soundChannel[(int)SoundChannel::Size];
	FMOD::Sound*   soundList[(int)SoundList::Size];

};

