#include "Framework.h"
#include "SoundManager.h"

void SoundManager::Initialize()
{
	FMOD::System_Create(&soundSystem);
	// ���� ä���� 32�� ���
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
	// �ҷ����� ���ϸ� ����ó��
	if (_check != FMOD_OK)
		assert(false);
}
void SoundManager::SoundPlay(SoundList _sound, SoundChannel _ch)
{
	bool isPlaying = false;
	soundChannel[(int)_ch]->isPlaying(&isPlaying);

	// ���� ��� ���� �Ҹ��� ����Ϸ��� �Ҹ��� �������� Ȯ���� ����
	FMOD::Sound* newSound = soundList[(int)_sound];

	// ���� ��� ���� �Ҹ��� �����ϱ� ���� �ӽ� ����
	FMOD::Sound* currentSound = nullptr;
	soundChannel[(int)_ch]->getCurrentSound(&currentSound);

	// ��� ���� �Ҹ��� �ְ�, ������ �Ҹ��� ����Ϸ��� ��� return
	if (isPlaying && currentSound == newSound) {
		return;
	}

	// �ٸ� �Ҹ��� ����Ϸ��� ��� ���� �Ҹ��� �ߴ�
	if (isPlaying) {
		soundChannel[(int)_ch]->stop();
	}

	// ���ο� �Ҹ��� ���
	soundSystem->playSound(newSound, NULL, 0, &soundChannel[(int)_ch]);

	// ���� ����
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