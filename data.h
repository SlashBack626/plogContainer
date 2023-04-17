#ifndef H_data
#define H_data

#include <string>
#include "plog/Record.h"

namespace Space
{
    struct data
    {
        int i;
        std::string s;
    };

} // namespace Space

namespace plog
{
#ifndef FIXCUSTOMCONTAINER
    Record &operator<<(Record &record, const Space::data &data)
    {
        return record << "\n"
                      << "struct data {\n"
                      << "      int i: " << data.i << "\n"
                      << "      std::string s: " << data.s << "\n"
                      << "}";
    }
#endif
#ifdef FIXCUSTOMCONTAINER
    void operator<<(util::nostringstream &record, const Space::data &data)
    {
        record << "\n"
               << "struct data {\n"
               << "      int i: " << data.i << "\n"
               << "      std::string s: " << data.s << "\n"
               << "}";
    }
    template <class T>
    inline typename detail::meta::enableIf<
        detail::meta::isContainer<T>::value &&
            !detail::meta::isConvertibleToNString<T>::value &&
            !detail::meta::isConvertibleToString<T>::value &&
            !detail::meta::isFilesystemPath<T>::value,
        void>::type
    operator<<(util::nostringstream &stream, const T &data)
    {
        stream << "[";

        for (typename T::const_iterator it = data.begin(); it != data.end();)
        {
            stream << *it;

            if (++it == data.end())
            {
                break;
            }

            stream << ", ";
        }

        stream << "]";
    }
#endif

}

#endif