#include "Serializer.h"

Error Serializer::pro(bool val)
{
	if (val)
	{
		out_ << "true" << Separator;
		return Error::NoError;
	}
	else if(!val)
	{
		out_ << "false" << Separator;
		return Error::NoError;
	}
	else
	{
		return Error::CorruptedArchive;
	}	
}

Error Serializer::pro(uint64_t val)
{
	out_ << val << Separator;
	return Error::NoError;
}

Error Deserializer::pro(bool& val)
{
	std::string letters;
	in_ >> letters;
	if (letters == "true")
	{
		val = true;
		return Error::NoError;
	}
	else if (letters == "false")
	{
		val = false;
		return Error::NoError;
	}
	else
	{
		return Error::CorruptedArchive;
	}
}

Error Deserializer::pro(uint64_t& val)
{
	std::string letters;
	in_ >> letters;
	val = 0;
	size_t l = letters.length();
	for (size_t i = 0; i < l; i++)
	{
		if (!isdigit(letters[i])) return Error::CorruptedArchive;
		val += (letters[i] - '0') * pow(10, l - i - 1);
	}	
	return Error::NoError;
}
