/*  MapleLibNative - A general-purpose MapleStory library for C++ 11+
 * Copyright (C) 2014 DeadCode, Felix Lebel
   
 * This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include "AESEncryption.h"

#include <CryptoPP\aes.h>
#include <CryptoPP\secblock.h>
#include <CryptoPP\modes.h>
#include <CryptoPP\filters.h>
#include <sstream>

MAPLELIB
namespace MapleCryptoLib
{
	byte* AESEncryption::aesCrypt(byte* IV, byte* data, int length)
	{
		// TODO: CryptoConstants
		// For good compiling <TO CHANGE>
		return aesCrypt(IV, data, 0, new byte[] {0});
	}

	byte* AESEncryption::aesCrypt(byte* IV, byte* data, int length, byte* key)
	{
		using namespace CryptoPP;
		using namespace std;

		int remaining = length;
		int llenght = 0x5B0;
		int start = 0;
		while (remaining < llenght)
		{

		}
		
		/*ECB_Mode<AES>::Encryption e;
		e.SetKey(key, 32);
		string output;
		ArraySource ss(data, sizeof(data), true,
			new StreamTransformationFilter(e,
			new StringSink(output))
		);

		*/



		return new byte[] {4, 6, 4, 1};
	}
}
END_MAPLELIB
