#include "username.hpp"

static void decrypt_name(uint64_t player_state, wchar_t* string)
{
	unsigned __int64 a1, a2, a3, a4;
	a1 = read<unsigned __int64>(base_addr + 0x263A2FD);
	a2 = read<unsigned __int64>(base_addr + 0x263A303);
	a3 = read<unsigned __int64>(base_addr + 0x263A30A);
	a4 = read<unsigned __int64>(base_addr + 0x263A31E);

	unsigned __int16 a5, a6;
	a5 = read<unsigned __int16>(player_state + 0x1337);
	a6 = read<unsigned __int16>(base_addr + 0x263A34F);

	unsigned __int64 v1, v2;
	v1 = a1 + ~a5;
	a2 ^= a6;
	a2 *= a3 << 6;
	--a6;
	a4 += ~a5;
	v2 = ~a4;
	v2 ^= a6 - (a2 << 8);

	unsigned __int64 b1;
	b1 = read<unsigned __int64*>(v2 + 0x1337);//APlayerState->PlayerNamePrivate

	wchar_t* c1; unsigned __int32 c2;//FString
	c1 = read<wchar_t**>(b1);
	c2 = read<unsigned __int32*>(b1 + 0x1337);

	*string = c1;
}
