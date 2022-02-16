struct Param
{

	long int a;
	long int b;
};

program CAL_BIN_PROG
{
	version CAL_VERS_ONE
	{
		void CALNULL(void) = 0;
		long int PUISS(Param) = 1;
		long int DEC2BIN(int) = 2;
	}
	= 1;
	version CAL_VERS_TWO
	{
		long int PUISS(Param) = 1;
		long int DEC2BIN(int) = 2;
		char DEC2HEX(int) = 3;
	}
	= 2;
}
= 0x20002201;
