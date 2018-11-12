//*** DO NOT MODIFY OR SUBMIT THIS FILE ***//

#ifndef PAIR_H_
#define PAIR_H_

//a key-value pair
//this simple class is pretty much self-explanatory
//all its implementation is already given
template<typename KeyType, typename ValueType>
class Pair
{
public:
	Pair(KeyType k, ValueType v) :
			key(k), value(v)
    {
	}

	KeyType getKey() const
	{
		return key;
	}

	void setKey(KeyType key)
	{
		this->key = key;
	}

	ValueType getValue() const
	{
		return value;
	}

	void setValue(ValueType value)
	{
		this->value = value;
	}

private:
	KeyType key;
	ValueType value;
};

#endif /* PAIR_H_ */
