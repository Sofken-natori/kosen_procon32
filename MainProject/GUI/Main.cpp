#include"GUI.hpp"

void Main()
{

	Window::Resize(1280, 800);
	Window::SetStyle(WindowStyle::Sizable);
	Window::SetTitle(U"KosenProcon32-GUI_unit");
	Scene::SetBackground(ColorF(0.8, 0.9, 1.0));

	const Font bigFont = Font(32, Typeface::Bold);
	const Font smallFont = Font(20, Typeface::Bold);

	const FilePath Path_ProblemInfo = U"Game/ProblemInformation.txt";
	const FilePath Path_ProblemImage = U"Game/ProblemImage.jpg";
	const FilePath Path_RestoreImage = U"Game/RestoreImage.jpg";
	const FilePath Path_AfterImage = U"Game/AfterImage.jpg";

	const FilePath fullPath_ProblemInfo = FileSystem::FullPath(Path_ProblemInfo);
	const FilePath fullPath_ProblemImage = FileSystem::FullPath(Path_ProblemImage);
	const FilePath fullPath_RestoreImage = FileSystem::FullPath(Path_RestoreImage);
	const FilePath fullPath_AfterImage = FileSystem::FullPath(Path_AfterImage);

	const FilePath Directory_ProblemInfo = FileSystem::ParentPath(Path_ProblemInfo);
	const FilePath Directory_ProblemImage = FileSystem::ParentPath(Path_ProblemImage);
	const FilePath Directory_RestoreImage = FileSystem::ParentPath(Path_RestoreImage);
	const FilePath Directory_AfterImage = FileSystem::ParentPath(Path_AfterImage);

	const DirectoryWatcher watcher_ProblemInfo{ Directory_ProblemInfo };
	const DirectoryWatcher watcher_ProblemImage{ Directory_ProblemImage };
	const DirectoryWatcher watcher_RestoreImage{ Directory_RestoreImage };
	const DirectoryWatcher watcher_AfterImage{ Directory_AfterImage };

	String textProblebInfo;

	Texture ProblemImage;
	Texture RestoreImage;
	Texture AfterImage;

	Procon32::GUI gui;

	while (System::Update())
	{
		gui.draw();

		for (auto [path, action] : watcher_ProblemInfo.retrieveChanges())
		{
			if ((path == fullPath_ProblemInfo) && (action == FileAction::Added || action == FileAction::Modified))
			{
				Console << U"ProblemInfoが更新されました";
				TextReader readProblebInfo(Path_ProblemInfo);
				textProblebInfo = readProblebInfo.readAll();
			}
		}

		for (auto [path, action] : watcher_ProblemImage.retrieveChanges())
		{
			if ((path == fullPath_ProblemImage) && (action == FileAction::Added || action == FileAction::Modified))
			{
				Console << U"ProblemImageが更新されました";
				ProblemImage = Texture(Path_ProblemImage, TextureDesc::Mipped);
			}
		}

		for (auto [path, action] : watcher_RestoreImage.retrieveChanges())
		{
			if ((path == fullPath_RestoreImage) && (action == FileAction::Added || action == FileAction::Modified))
			{
				Console << U"RestoreImageが更新されました";
				RestoreImage = Texture(Path_RestoreImage, TextureDesc::Mipped);
			}
		}

		for (auto [path, action] : watcher_AfterImage.retrieveChanges())
		{
			if ((path == fullPath_AfterImage) && (action == FileAction::Added || action == FileAction::Modified))
			{
				Console << U"AfterImageが更新されました";
				AfterImage = Texture(Path_AfterImage, TextureDesc::Mipped);
			}
		}

		smallFont(textProblebInfo).draw(900, 10, Palette::Red);
		ProblemImage.scaled(0.1).draw(100, 70).drawFrame(2, 2, Palette::Orange);
		RestoreImage.scaled(0.5).draw(100, 400).drawFrame(2, 2, Palette::Orange);
		AfterImage.scaled(0.5).draw(600, 400).drawFrame(2, 2, Palette::Orange);


		Circle{ Cursor::Pos(), 10 }.draw(ColorF(1, 0, 0, 0.5));
	}
}
