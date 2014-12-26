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

#include "MapleCrypto.h"
#include "AESEncryption.h"
#include "CryptoConstants.h"

MAPLELIB
namespace MapleCryptoLib
{
	MapleCrypto::MapleCrypto(std::vector<byte> iv, short mapleVersion)
	{
		this->IV = iv;
		this->_mapleVersion = mapleVersion;
	}

	void MapleCrypto::updateIV()
	{
		IV = this->getNewIV(this->IV);
	}

	void MapleCrypto::crypt(std::vector<byte> data)
	{
		AESEncryption::aesCrypt(IV, data, sizeof(data));
		this->updateIV();
	}

	std::vector<byte> MapleCrypto::getNewIV(std::vector<byte> oldIV)
	{
		std::vector<byte> start({ 0xf2, 0x53, 0x50, 0xc6 });//TODO: ADD GLOBAL VAR BACK
		for (int i = 0; i < 4; i++)
		{
			shuffle(oldIV[i], start);
		}
		return start;
	}

	std::vector<byte> MapleCrypto::shuffle(byte inputByte, std::vector<byte> start)
	{
		byte a = start[1];
		byte b = a;
		UINT c, d;
		b = CryptoConstants::bShuffle[b];
		b -= inputByte;
		start[0] += b;
		b = start[2];
		b ^= CryptoConstants::bShuffle[inputByte];
		a -= b;
		start[1] = a;
		a = start[3];
		b = a;
		a -= start[0];
		b = CryptoConstants::bShuffle[b];
		b += inputByte;
		b ^= start[2];
		start[2] = b;
		a += CryptoConstants::bShuffle[inputByte];
		start[3] = a;

		c = (UINT)(start[0] + start[1] * 0x100 + start[3] * 0x1000000);
		d = c;
		c >>= 0x1D;
		d <<= 0x03;
		c |= d;
		start[0] = (byte)(c % 0x100);
		c /= 0x100;
		start[1] = (byte)(c % 0x100);
		c /= 0x100;
		start[2] = (byte)(c % 0x100);
		start[3] = (byte)(c / 0x100);

		return start;
	}

	std::vector<byte> MapleCrypto::getHeaderToClient(int size)
	{
		byte header[4];
		int a = IV[3] * 0x100 + IV[2];
		a ^= -(_mapleVersion + 1);
		int b = a ^ size;
		header[0] = (byte)(a % 0x100);
		header[1] = (byte)((a - header[0]) / 0x100);
		header[2] = (byte)(b ^ 0x100);
		header[3] = (byte)((b - header[2]) / 0x100);
		return std::vector<byte>(header, header + 4);

	}

	bool MapleCrypto::checkPacketToServer(std::vector<byte> packet)
	{

	}

	std::vector<byte> MapleCrypto::multiplyBytes(std::vector<byte> input, int count, int mult)
	{

	}

	// Static

	std::vector<byte> MapleCrypto::getHeaderToServer(int size)
	{
		byte header[4];
		int a = IV[3] * 0x100 + IV[2];
		a = a ^ (_mapleVersion);
		int b = a ^ size;
		/* C#
		header[0] = Convert.ToByte(a % 0x100);
		header[1] = Convert.ToByte(a / 0x100);
		header[2] = Convert.ToByte(b % 0x100);
		header[3] = Convert.ToByte(b / 0x100);
		return header;
		*/
	}

	int MapleCrypto::getPacketLength(int packetHeader)
	{

	}
}
END_MAPLELIB