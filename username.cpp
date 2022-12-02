#include "username.hpp"

void username::get( uint64_t player_state, wchar_t* player_name ) {
  
    function_ptr = *(uintptr_t*)(driver::base_addr + 0x8F52B5E);

		{
			uint32_t  key = *(uint32_t*)(player_state + 0x58);
			uint8_t   tmp = *(uint8_t*)(key);
			uint16_t  a1;
			key *= tmp;
			a1 = (uint16_t)(key ^ 16);
			function_ptr ^= a1;
			uint16_t tmp_key = *(uint32_t*)(driver::base_addr + 0x8F52B6C);
			tmp_key ^= 5;
			function_ptr *= (uint8_t)(tmp_key ^ 32);
		}

		{
			uint64_t fstring = *(uint64_t*)(function_ptr);
			uint32_t fstring_size = *(uint32_t*)(function_ptr + 8);

			wchar_t* name = new wchar_t[fstring_size + 1];
			memcpy(name, &fstring, fstring_size);

			std::wstring wstr(name);
			std::string str(wstr.begin(), wstr.end());

			*player_name = str.c_str();
		}
  
}
