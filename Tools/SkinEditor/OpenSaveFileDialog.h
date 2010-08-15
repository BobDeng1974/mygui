/*!
	@file
	@author		Albert Semenov
	@date		09/2008
*/
#ifndef __OPEN_SAVE_FILE_DIALOG_H__
#define __OPEN_SAVE_FILE_DIALOG_H__

#include <MyGUI.h>
#include "BaseLayout/BaseLayout.h"

namespace common
{

	class OpenSaveFileDialog :
		public wraps::BaseLayout
	{
	public:
		typedef MyGUI::delegates::CDelegate1<bool> EventHandle_Result;

	public:
		OpenSaveFileDialog();

		void setDialogInfo(const MyGUI::UString& _caption, const MyGUI::UString& _button);

		void setCurrentFolder(const MyGUI::UString& _value = "");
		const MyGUI::UString& getCurrentFolder() { return mCurrentFolder; }

		void setFileMask(const MyGUI::UString& _value);
		const MyGUI::UString& getFileMask() const { return mFileMask; }

		void setFileName(const MyGUI::UString& _value);
		const MyGUI::UString& getFileName() const { return mFileName; }

		void setVisible(bool _value);
		bool getVisible();

		bool getModeSave() { return mModeSave; }
		void setModeSave(bool _value) { mModeSave = _value; }

		EventHandle_Result eventEndDialog;

	private:
		void notifyWindowButtonPressed(MyGUI::Window* _sender, const std::string& _name);
		void notifyDirectoryAccept(MyGUI::Edit* _sender);
		void notifyListChangePosition(MyGUI::List* _sender, size_t _index);
		void notifyListSelectAccept(MyGUI::List* _sender, size_t _index);
		void notifyEditSelectAccept(MyGUI::Edit* _sender);
		void notifyMouseButtonClick(MyGUI::Widget* _sender);

		void update();
		void accept();

	private:
		MyGUI::Window* mWindow;
		MyGUI::List* mListFiles;
		MyGUI::Edit* mEditFileName;
		MyGUI::Edit* mEditCurrentFolder;
		MyGUI::Button* mButtonOpenSave;

		MyGUI::UString mCurrentFolder;
		MyGUI::UString mFileName;
		MyGUI::UString mFileMask;

		bool mModeSave;
	};

} // namespace common

#endif // __OPEN_SAVE_FILE_DIALOG_H__