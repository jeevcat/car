#include "BlocksLibrary.h"

void UBlocksLibrary::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	const UEnum* Enum = StaticEnum<EBlockType>();
	const int64 Max = Enum->GetMaxEnumValue();
	for (int64 Value = 0L; Value < Max; ++Value)
	{
		const EBlockType Type = static_cast<EBlockType>(Value);
		Blocks.FindOrAdd(Type, nullptr);
	}
}
