/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuAudio
*/

#ifndef MENUAUDIO_HPP_
#define MENUAUDIO_HPP_

static const int MENU_AUDIO_MAIN = 0;
static const int MENU_AUDIO_BACK = 1;

static const int BTN_AUDIO_MUSIC = 0;
static const int BTN_AUDIO_EFFECT = 1;

#include "Menu.hpp"

namespace IndieStudio
{
class MenuAudio : public Menu
{
public:
	MenuAudio(IGraphical &, Volume *, MenuSounds *);
	~MenuAudio();

	void setVolumeMusicBar(void) noexcept;
	void setVolumeEffectBar(void) noexcept;

public:
	void drawMenuManager(void) noexcept override;
	void returnActionManager(void) noexcept override;
	void escapeActionManager(void) noexcept override;
	void leftActionManager(void) noexcept override;
	void rightActionManager(void) noexcept override;
	void upActionManager(void) noexcept override;
	void downActionManager(void) noexcept override;
	void alphaActionManager(IndieStudio::Key) noexcept override;

private:
	void drawMenu(void) noexcept override;
	void createButtons(void) noexcept override;
	void drawButtons(void) noexcept override;
	void createImages(void) noexcept override;
	void drawImages(void) noexcept override;

	void checkActions(void) noexcept override;
	void returnAction(void) noexcept override;
	void escapeAction(void) noexcept override;
	void leftAction(void) noexcept override;
	void rightAction(void) noexcept override;
	void upAction(void) noexcept override;
	void downAction(void) noexcept override;
	void alphaAction(IndieStudio::Key) noexcept override;

	void refreshSkin(void) noexcept override;

private:
	int _leftMusicTime = 0;
	int _leftEffectTime = 0;
	int _rightMusicTime = 0;
	int _rightEffectTime = 0;

	Button *_music;
	Button *_effects;
	Button *_leftMusicArrow;
	Button *_rightMusicArrow;
	Button *_leftEffectArrow;
	Button *_rightEffectArrow;

	IEntity *_volumeBarMusicEmpty;
	IEntity *_volumeBarEffectEmpty;
	IEntity *_volumeBarMusicFilled;
	IEntity *_volumeBarEffectFilled;
	IEntity *_escapeInfo;
};
}; // namespace IndieStudio

#endif /* !MENUAUDIO_HPP_ */
