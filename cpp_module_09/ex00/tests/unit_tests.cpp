#include "acutest.h"
#include "../BitcoinExchange.hpp"
#include <string>

// Clase "amiga" que nos permite acceder a los métodos privados para el test
class UnitTest {
public:
    static bool checkDate(const BitcoinExchange& btc, const std::string& date) {
        return btc.isValidDate(date);
    }
    static bool checkValue(const BitcoinExchange& btc, const std::string& value) {
        return btc.isValidValue(value);
    }
};

void test_date_validation(void) {
    BitcoinExchange btc;

    // Fechas Válidas
    TEST_CHECK(UnitTest::checkDate(btc, "2011-01-03") == true);
    TEST_CHECK(UnitTest::checkDate(btc, "2024-02-29") == true); // Bisiesto
    TEST_CHECK(UnitTest::checkDate(btc, "2000-02-29") == true); // Bisiesto siglo

    // Fechas Inválidas - Formato
    TEST_CHECK(UnitTest::checkDate(btc, "2011-1-3") == false);
    TEST_CHECK(UnitTest::checkDate(btc, "2011/01/03") == false);
    TEST_CHECK(UnitTest::checkDate(btc, "2011-01-03 ") == false);

    // Fechas Inválidas - Calendario
    TEST_CHECK(UnitTest::checkDate(btc, "2011-13-01") == false); // Mes 13
    TEST_CHECK(UnitTest::checkDate(btc, "2011-00-01") == false); // Mes 00
    TEST_CHECK(UnitTest::checkDate(btc, "2011-01-32") == false); // Día 32
    TEST_CHECK(UnitTest::checkDate(btc, "2023-02-29") == false); // No bisiesto
    TEST_CHECK(UnitTest::checkDate(btc, "2100-02-29") == false); // No bisiesto siglo
}

void test_value_validation(void) {
    BitcoinExchange btc;

    // Valores Válidos
    TEST_CHECK(UnitTest::checkValue(btc, "100") == true);
    TEST_CHECK(UnitTest::checkValue(btc, "0.5") == true);
    TEST_CHECK(UnitTest::checkValue(btc, "1000") == true);
    TEST_CHECK(UnitTest::checkValue(btc, "0") == true);

    // Valores Inválidas
    TEST_CHECK(UnitTest::checkValue(btc, "-1") == true); // isValidValue solo chequea formato, el signo es opcional en el parser
    TEST_CHECK(UnitTest::checkValue(btc, "1.2.3") == false);
    TEST_CHECK(UnitTest::checkValue(btc, "abc") == false);
    TEST_CHECK(UnitTest::checkValue(btc, "123a") == false);
    TEST_CHECK(UnitTest::checkValue(btc, " ") == false);
}

TEST_LIST = {
    { "date_validation", test_date_validation },
    { "value_validation", test_value_validation },
    { NULL, NULL }
};
