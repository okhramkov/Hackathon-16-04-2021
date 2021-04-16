#include "libmx.h"

bool mx_isutf(wchar_t c){
    setlocale(LC_ALL, "ru_RU.utf8");
    if(c >= 33 && c<= 126)
        return 1;
    else if(c == L'А' || c == L'Б')
        return 1;
	else return 0;
}
