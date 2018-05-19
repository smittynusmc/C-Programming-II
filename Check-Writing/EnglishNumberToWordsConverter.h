#ifndef _EnglishNumberToWordsConverter_h_
#define _EnglishNumberToWordsConverter_h_

#include <map>                                  // std::map

namespace Humanizer
{
namespace Localisation
{
namespace NumberToWords
{
    class EnglishNumberToWordsConverter
    {
    private:
        static const std::string UnitsMap[];
        static const std::string TensMap[];

        static const std::map<int, std::string> OrdinalExceptions;

    public:
		int number;

		EnglishNumberToWordsConverter(int);

		void print(int, std::string);

		std::string Convert() const;

        std::string Convert(int number) const;

        std::string ConvertToOrdinal(int number) const;

    private:

        std::string Convert(int number, bool isOrdinal) const;

        static std::string GetUnitValue(int number, bool isOrdinal);

        static std::string RemoveOnePrefix(const std::string & toWords);

        static bool ExceptionNumbersToWords(int number, std::string & words );
    };
}
}
}

#endif // _EnglishNumberToWordsConverter_h_
