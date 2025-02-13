#include "Serializer.hpp"

int main()
{
    Data myData;
    uintptr_t raw = Serializer::serialize(&myData);
    Data* newPtr = Serializer::deserialize(raw);
    uintptr_t new_raw = Serializer::serialize(newPtr);

    if (newPtr == &myData && new_raw == raw)
        std::cout << "Serialization and deserialization successful!" 
            << std::endl;
}