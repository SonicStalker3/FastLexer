char ignore_char_list[] = { ' ', '\n' };

namespace ignore_list
{
	bool haveIgnoreList(char symbol)
	{
		for (char& ch : ignore_char_list)
		{
			if (ch == symbol) return true;
		}
		return false;
	}
}
