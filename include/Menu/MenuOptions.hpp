/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuOptions
*/

#ifndef MENUOPTIONS_HPP_
#define MENUOPTIONS_HPP_

static const int MENU_OPTIONS_MAIN = 0;
static const int MENU_OPTIONS_AUDIO = 1;
static const int MENU_OPTIONS_VIDEO = 2;
static const int MENU_OPTIONS_CONTROLS = 3;
static const int MENU_OPTIONS_BACK = 4;

static const int BTN_OPTIONS_AUDIO = 0;
static const int BTN_OPTIONS_VIDEO = 1;
static const int BTN_OPTIONS_CONTROLS = 2;
static const int BTN_OPTIONS_BACK = 3;

#include "Menu.hpp"
#include "MenuAudio.hpp"
#include "MenuVideo.hpp"
#include "MenuControls.hpp"

namespace IndieStudio
{
class MenuOptions : public Menu
{
public:
	MenuOptions(IGraphical &, Volume *, MenuSounds *, Config *);
	~MenuOptions();

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
	MenuAudio *_menuAudio;
	MenuVideo *_menuVideo;
	MenuControls *_menuControls;

	Button *_audio;
	Button *_video;
	Button *_controls;
	Button *_back;
};
}; // namespace IndieStudio

#endif /* !MENUOPTIONS_HPP_ */
