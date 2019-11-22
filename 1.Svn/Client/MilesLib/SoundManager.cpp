//Find
	m_bInitialized			= FALSE;
	
///Add
	m_isMuted				= false;
	
//Find in void CSoundManager::FadeInMusic(const char * c_szFileName, float fVolumeSpeed)
	FadeOutAllMusic();
	
///Add
	if (m_isMuted)
		MuteSound(false);
	
//Find

float CSoundManager::GetSoundVolume()
{
	return m_fSoundVolume;
}

///Change
#include"../UserInterface/AbstractChat.h"
float CSoundManager::GetSoundVolume()
{
	return m_isMuted ? 0.0f : m_fSoundVolume;
}

void CSoundManager::MuteSound(bool b)
{
	m_isMuted = !m_isMuted;
	if (m_isMuted) {
		StopAllSound3D();
		for (int i = 0; i < CSoundManager2D::INSTANCE_MAX_COUNT; ++i) {
			ISoundInstance* pInstance = ms_SoundManager2D.GetInstance(i);
			if (pInstance) pInstance->Stop();
		}
	}
	if (b) {
		for (int i = 0; i < CSoundManagerStream::MUSIC_INSTANCE_MAX_NUM; ++i) {
			TMusicInstance& rMusicInstance = m_MusicInstances[i];
			if (MUSIC_STATE_OFF == rMusicInstance.MusicState || MUSIC_STATE_FADE_OUT == rMusicInstance.MusicState)
				continue;
			auto pInstance = ms_SoundManagerStream.GetInstance(i);
			if (pInstance) m_isMuted ? pInstance->Pause() : pInstance->Resume();
		}
	}
	char buf[15];
	snprintf(buf, sizeof(buf), "Mute %s", m_isMuted ? "Enabled." : "Disabled.");
	IAbstractChat::GetSingleton().AppendChat(1, buf);
}
