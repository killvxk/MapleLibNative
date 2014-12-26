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

#pragma once
#include "Includes.h"

MAPLELIB
namespace MapleCryptoLib
{
	class MapleCrypto
	{
	private:
		short _mapleVersion;

	public:
		std::vector<byte> IV;

		MapleCrypto(std::vector<byte> iv, short mapleVersion);
		void updateIV();
		void crypt(std::vector<byte> data);
		std::vector<byte> getNewIV(std::vector<byte> oldIV);
		std::vector<byte> shuffle(byte inputByte, std::vector<byte> start);
		std::vector<byte> getHeaderToClient(int size);
		bool checkPacketToServer(std::vector<byte> packet);
		std::vector<byte> multiplyBytes(std::vector<byte> input, int count, int mult);
		std::vector<byte> getHeaderToServer(int size);
		
		static int getPacketLength(int packetHeader);

	};
}
END_MAPLELIB
