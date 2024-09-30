#include "Framework.h"
#include "SoundManager.h"

void SoundManager::Initialize()
{
	FMOD::System_Create(&soundSystem);
	// 사운드 채널을 32개 사용
	soundSystem->init(32, FMOD_INIT_NORMAL, 0);
}
void SoundManager::Update()
{
	soundSystem->update();
}
void SoundManager::Finalize()
{
	soundSystem->release();
	soundSystem->close();
}
void SoundManager::AddSound(SoundList _sound, const char* _path, bool _loop)
{
	FMOD_RESULT _check;
	if (_loop)
		_check = soundSystem->createSound(_path, FMOD_LOOP_NORMAL, 0, &soundList[(int)_sound]);
	else
		_check = soundSystem->createSound(_path, FMOD_LOOP_OFF, 0, &soundList[(int)_sound]);
	// 불러오지 못하면 예외처리
	if (_check != FMOD_OK)
		assert(false);
}
void SoundManager::SoundPlay(SoundList _sound, SoundChannel _ch)
{
	bool isPlaying = false;
	soundChannel[(int)_ch]->isPlaying(&isPlaying);

	// 현재 재생 중인 소리와 재생하려는 소리가 동일한지 확인할 변수
	FMOD::Sound* newSound = soundList[(int)_sound];

	// 현재 재생 중인 소리를 추적하기 위한 임시 변수
	FMOD::Sound* currentSound = nullptr;
	soundChannel[(int)_ch]->getCurrentSound(&currentSound);

	// 재생 중인 소리가 있고, 동일한 소리를 재생하려는 경우 return
	if (isPlaying && currentSound == newSound) {
		return;
	}

	// 다른 소리를 재생하려는 경우 현재 소리를 중단
	if (isPlaying) {
		soundChannel[(int)_ch]->stop();
	}

	// 새로운 소리를 재생
	soundSystem->playSound(newSound, NULL, 0, &soundChannel[(int)_ch]);

	// 볼륨 설정
	soundChannel[(int)_ch]->setVolume((float)volume / (float)100);
}

void SoundManager::SoundcutPlay(SoundList _sound, SoundChannel _ch)
{

	soundChannel[(int)_ch]->stop();
	soundSystem->playSound(soundList[(int)_sound], NULL, 0, &soundChannel[(int)_ch]);
	soundChannel[(int)_ch]->setVolume((float)volume / (float)100);
}

void SoundManager::SoundStop(SoundChannel _ch)
{
	soundChannel[(int)_ch]->stop();
}

void SoundManager::SetVolume(int _val)
{
	volume = _val;
	for (FMOD::Channel* _ch : soundChannel)
	{
		_ch->setVolume((float)volume / (float)100);
	}
}