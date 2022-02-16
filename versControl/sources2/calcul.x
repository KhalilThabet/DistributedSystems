struct Param
{

	int a;
	int b;
};

program CAL_BIN_PROG
{
	version CAL_VERS_ONE
	{
		void CALNULL(void) = 0;
		long PUISS(Param) = 1;
		long DEC2BIN(int) = 2;
	}
	= 1;
	version CAL_VERS_TWO
	{
		long int PUISS(Param) = 1;
		long int DEC2BIN(int) = 2;
		unsigned char DEC2HEX(int) = 3;
	}
	= 2;
}
= 0x2000229;
