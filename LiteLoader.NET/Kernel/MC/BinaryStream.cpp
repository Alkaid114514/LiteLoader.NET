#pragma once
#include "../../Header/MC/BinaryStream.hpp"

namespace MC::NetWork
{
	inline BinaryStream::BinaryStream(String^ str, bool b)
		:ReadOnlyBinaryStream((void*)nullptr)
	{
		NativePtr = new ::BinaryStream(marshalString(str), b);
		OwnsNativeInstance = true;
	}

	inline BinaryStream::BinaryStream()
		:ReadOnlyBinaryStream((void*)nullptr)
	{
		NativePtr = new ::BinaryStream;
		OwnsNativeInstance = true;
	}

	inline String^ BinaryStream::GetAndReleaseData() {
		return marshalString(NativePtr->getAndReleaseData());
	}

	inline __string^ BinaryStream::GetAndReleaseData_Native()
	{
		return gcnew __string(NativePtr->getAndReleaseData());
	}

	inline void BinaryStream::Reset()
	{
		NativePtr->reset();
	}

	inline void BinaryStream::WriteBool(bool val)
	{
		NativePtr->writeBool(val);
	}

	inline void BinaryStream::WriteByte(unsigned char val)
	{
		NativePtr->writeByte(val);
	}

	inline void BinaryStream::WriteDouble(double val)
	{
		NativePtr->writeDouble(val);
	}

	inline void BinaryStream::WriteFloat(float val)
	{
		NativePtr->writeFloat(val);
	}

	inline void BinaryStream::WriteSignedBigEndianInt(int val)
	{
		NativePtr->writeSignedBigEndianInt(val);
	}

	inline void BinaryStream::WriteSignedInt(int val)
	{
		NativePtr->writeSignedInt(val);
	}

	inline void BinaryStream::WriteSignedInt64(__int64 val)
	{
		NativePtr->writeSignedInt64(val);
	}

	inline void BinaryStream::WriteSignedShort(short val)
	{
		NativePtr->writeSignedShort(val);
	}

	inline void BinaryStream::WriteString(String^ val)
	{
		NativePtr->writeString(marshalString(val));
	}

	inline void BinaryStream::WriteUnsignedChar(unsigned char val)
	{
		NativePtr->writeUnsignedChar(val);
	}

	inline void BinaryStream::WriteUnsignedInt(unsigned int val)
	{
		NativePtr->writeUnsignedInt(val);
	}

	inline void BinaryStream::WriteUnsignedInt64(unsigned __int64 val)
	{
		NativePtr->writeUnsignedInt64(val);
	}

	inline void BinaryStream::WriteUnsignedShort(unsigned short val)
	{
		NativePtr->writeUnsignedShort(val);
	}

	inline void BinaryStream::WriteUnsignedVarInt(unsigned int val)
	{
		NativePtr->writeUnsignedVarInt(val);
	}

	inline void BinaryStream::WriteUnsignedVarInt64(unsigned __int64 val)
	{
		NativePtr->writeUnsignedVarInt64(val);
	}

	inline void BinaryStream::WriteVarInt(int val)
	{
		NativePtr->writeVarInt(val);
	}

	inline void BinaryStream::WriteVarInt64(__int64 val)
	{
		NativePtr->writeVarInt64(val);
	}

	inline void BinaryStream::Write(void const* p, unsigned __int64 size)
	{
		NativePtr->write(p, size);
	}

	inline void BinaryStream::Write(array<System::Byte>^ arr)
	{
		pin_ptr<System::Byte> p = &arr[0];
		NativePtr->write(p, arr->Length);
	}

}