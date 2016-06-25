const int Len = 40;

class sword
{
	private:
		char fullname[Len];
		int enchantment;
	public:
		sword(const char *n = "FaceStabber Deluxe", int e = 0);
		int reset();
		void reenchant(int e);
		void showSword();
};
